//ROOT includes
#include <TFile.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include "Math/VectorUtil.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/Math/interface/LorentzVector.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/L1DTTrackFinder/interface/L1MuDTChambPhContainer.h"
#include "DataFormats/L1DTTrackFinder/interface/L1MuDTChambThContainer.h"

#include "DataFormats/L1TrackTrigger/interface/L1TkMuonParticle.h"
#include "DataFormats/L1TrackTrigger/interface/L1TkMuonParticleFwd.h"
#include "DataFormats/L1TrackTrigger/interface/L1TkGlbMuonParticle.h"
#include "DataFormats/L1TrackTrigger/interface/L1TkGlbMuonParticleFwd.h"

#include "DataFormats/L1Trigger/interface/Muon.h"
#include "DataFormats/L1TMuon/interface/RegionalMuonCand.h"
#include "DataFormats/L1TMuon/interface/L1MuKBMTrack.h"

#include "DataFormats/L1TrackTrigger/interface/TTTrack.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticle.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticleFwd.h"

#include "L1Trigger/L1TMuon/interface/MicroGMTConfiguration.h"
  
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
 
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "DataFormats/L1TMuon/interface/BayesMuCorrelatorTrack.h"

#include "DataFormats/HepMCCandidate/interface/GenStatusFlags.h"
#include "SimTracker/TrackTriggerAssociation/interface/TTTrackAssociationMap.h"

typedef math::XYZTLorentzVector LorentzVector;
typedef vector<TTTrack<edm::Ref<edm::DetSetVector<Phase2TrackerDigi>,Phase2TrackerDigi,edm::refhelper::FindForDetSetVector<Phase2TrackerDigi> > > > TTTracksCollection;

typedef TTTrack< Ref_Phase2TrackerDigi_ >  L1TTTrackType;
typedef std::vector< L1TTTrackType >       TTTrackCollection;

#include "L1MuGlobalNtupleMaker.h"

 
// constructors and destructor
L1MuGlobalNtupleMaker::L1MuGlobalNtupleMaker(const edm::ParameterSet& iConfig) :
  _RunningOnData(iConfig.getParameter<bool>("RunningOnData")),
  _PU_scenario(iConfig.getParameter<int>("PileUpScenario")),
  _PileupSrc(iConfig.getParameter<edm::InputTag>("PileupSrc")),
  _maxGenMuons(iConfig.getParameter<int>("maxGenMuons")),
  _genParticleToken(consumes<reco::GenParticleCollection>(iConfig.getParameter<edm::InputTag>("genParticle"))),


  _TkMuonToken(consumes<l1t::L1TkMuonParticleCollection>(iConfig.getParameter<edm::InputTag>("tkMuon"))),
  _TkMuonStubsBMTFToken(consumes<l1t::L1TkMuonParticleCollection>(iConfig.getParameter<edm::InputTag>("tkMuonStubsBMTF"))),
  _TkMuonStubsEMTFToken(consumes<l1t::L1TkMuonParticleCollection>(iConfig.getParameter<edm::InputTag>("tkMuonStubsEMTF"))),
  _TkMuonStubsOMTFToken(consumes<l1t::BayesMuCorrTrackBxCollection>(iConfig.getParameter<edm::InputTag>("tkMuonStubsOMTF"))),
  _TkGlbMuonToken(consumes<l1t::L1TkGlbMuonParticleCollection>(iConfig.getParameter<edm::InputTag>("tkGlbMuon"))),
  _TTTracksToken(consumes<TTTracksCollection>(iConfig.getParameter<edm::InputTag>("tttracks"))),
   _TTTracksTruthToken(consumes< TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > >(iConfig.getParameter<edm::InputTag>("MCTruthTrackInputTag")))

 // _TrkG4PartsToken(consumes<TrackingParticleCollection>(iConfig.getParameter<edm::InputTag>("trkG4Parts")))
{
  _pileupSummaryToken = consumes<std::vector<PileupSummaryInfo> >(edm::InputTag(_PileupSrc));


  _h_Global_Info = fs->make<TH1F>("h_Global_Info", "General information about the sample", 8, 0., 8.);
  _Nevents_processed = 0;

  create_trees();
}

L1MuGlobalNtupleMaker::~L1MuGlobalNtupleMaker()
{
}

//*************************************************************//
//                                                             //
//---------------------- Create the tree ----------------------//
//                                                             //
//*************************************************************//
void L1MuGlobalNtupleMaker::create_trees()
{
  _mytree = fs->make<TTree>("mytree", "Tree containing L1 info");

  //Save run number info when running on data
  if(_RunningOnData){
    _mytree->Branch("run_number",&_run_number);
  }
  else{
    _mytree->Branch("NTruePU",&_NTruePU);
  }

  //Generated muons
  _mytree->Branch("genpart_pt",&_genpart_pt);
  _mytree->Branch("genprt_eta",&_genpart_eta);
  _mytree->Branch("genpart_phi",&_genpart_phi);
  _mytree->Branch("genpart_id", &_genpart_id);
  _mytree->Branch("genpart_parent", &_genpart_parent);
  _mytree->Branch("genpart_charge", &_genpart_charge);
  _mytree->Branch("genpart_dxy", &_genpart_dxy);
  _mytree->Branch("genpart_Vz", &_genpart_Vz);
  _mytree->Branch("genpart_status",&_genpart_status);
  _mytree->Branch("genpart_status_isLast", &_genpart_status_isLast);

  _mytree->Branch("genpart_Npart",&_genpart_Npart);


  //Track muons
  _mytree->Branch("tkmu_pt",&_tkmu_pt);
  _mytree->Branch("tkmu_eta",&_tkmu_eta);
  _mytree->Branch("tkmu_phi",&_tkmu_phi);
  _mytree->Branch("tkmu_charge",&_tkmu_charge);
  _mytree->Branch("tkmu_tkiso",&_tkmu_tkiso);

  _mytree->Branch("tkmu_Nmuons",&_tkmu_Nmuons);

  //TkMuStubs BMTF muons
  _mytree->Branch("tkmuStubsBMTF_pt",&_tkmuStubsBMTF_pt);
  _mytree->Branch("tkmuStubsBMTF_eta",&_tkmuStubsBMTF_eta);
  _mytree->Branch("tkmuStubsBMTF_phi",&_tkmuStubsBMTF_phi);
  _mytree->Branch("tkmuStubsBMTF_charge",&_tkmuStubsBMTF_charge);
  _mytree->Branch("tkmuStubsBMTF_tkiso",&_tkmuStubsBMTF_tkiso);
  _mytree->Branch("tkmuStubsBMTF_Vz", &_tkmuStubsBMTF_Vz);

  _mytree->Branch("tkmuStubsBMTF_Nmuons",&_tkmuStubsBMTF_Nmuons);

  //TkMuStubs OMTF muons
  _mytree->Branch("tkmuStubsOMTF_pt",&_tkmuStubsOMTF_pt);
  _mytree->Branch("tkmuStubsOMTF_eta",&_tkmuStubsOMTF_eta);
  _mytree->Branch("tkmuStubsOMTF_phi",&_tkmuStubsOMTF_phi);
  _mytree->Branch("tkmuStubsOMTF_charge",&_tkmuStubsOMTF_charge);
  _mytree->Branch("tkmuStubsOMTF_tkiso",&_tkmuStubsOMTF_tkiso);
  _mytree->Branch("tkmuStubsOMTF_Vz", &_tkmuStubsOMTF_Vz);

  _mytree->Branch("tkmuStubsOMTF_Nmuons",&_tkmuStubsOMTF_Nmuons);

  //TkMuStubs EMTF muons
  _mytree->Branch("tkmuStubsEMTF_pt",&_tkmuStubsEMTF_pt);
  _mytree->Branch("tkmuStubsEMTF_eta",&_tkmuStubsEMTF_eta);
  _mytree->Branch("tkmuStubsEMTF_phi",&_tkmuStubsEMTF_phi);
  _mytree->Branch("tkmuStubsEMTF_charge",&_tkmuStubsEMTF_charge);
  _mytree->Branch("tkmuStubsEMTF_tkiso",&_tkmuStubsEMTF_tkiso);
  _mytree->Branch("tkmuStubsEMTF_Vz", &_tkmuStubsEMTF_Vz);

  _mytree->Branch("tkmuStubsEMTF_Nmuons",&_tkmuStubsEMTF_Nmuons);

  //Track global muons
  _mytree->Branch("tkglbmu_pt",&_tkglbmu_pt);
  _mytree->Branch("tkglbmu_eta",&_tkglbmu_eta);
  _mytree->Branch("tkglbmu_phi",&_tkglbmu_phi);
  _mytree->Branch("tkglbmu_charge",&_tkglbmu_charge);
  _mytree->Branch("tkglbmu_tkiso",&_tkglbmu_tkiso);

  _mytree->Branch("tkglbmu_Nmuons",&_tkglbmu_Nmuons);

  //TTTracks
  _mytree->Branch("tttracks_pt",&_tttracks_pt);
  _mytree->Branch("tttracks_eta",&_tttracks_eta);
  _mytree->Branch("tttracks_phi",&_tttracks_phi);
  _mytree->Branch("tttracks_chi2",&_tttracks_chi2);
  _mytree->Branch("tttracks_z0",&_tttracks_z0);
  _mytree->Branch("tttracks_bendchi2",&_tttracks_bendchi2);
  _mytree->Branch("tttracks_qual", &_tttracks_qual);
  _mytree->Branch("tttracks_gen_TP_ID",  &_tttracks_gen_TP_ID_);
  _mytree->Branch("tttracks_gen_TP_pt",  &_tttracks_gen_TP_pt_);
  _mytree->Branch("tttracks_gen_TP_eta", &_tttracks_gen_TP_eta_);
  _mytree->Branch("tttracks_gen_TP_phi", &_tttracks_gen_TP_phi_);
  _mytree->Branch("tttracks_gen_TP_m",   &_tttracks_gen_TP_m_);


  _mytree->Branch("tttracks_Nmuons",&this_l1track);
/*
  //TrkG4Parts

  _mytree->Branch("trkG4Parts_pt",&_trkG4Parts_pt);
  _mytree->Branch("trkG4Parts_eta",&_trkG4Parts_eta);
  _mytree->Branch("trkG4Parts_phi",&_trkG4Parts_phi);
  _mytree->Branch("trkG4Parts_pdgId",&_trkG4Parts_pdgId);

  _mytree->Branch("trkG4Parts_Nmuons",&_trkG4Parts_Nmuons);
*/
}

void L1MuGlobalNtupleMaker::beginJob()
{
}


void L1MuGlobalNtupleMaker::endJob() 
{
  _h_Global_Info->Fill(0.5,_Nevents_processed);
  _h_Global_Info->Fill(1.5,_PU_scenario);

  _h_Global_Info->GetXaxis()->SetBinLabel(1,"Events processed");
  _h_Global_Info->GetXaxis()->SetBinLabel(2,"PU scenario in the MC sample");
}

// ------------ method called for each event  ------------
void L1MuGlobalNtupleMaker::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  _Nevents_processed++;

  edm::Handle<reco::GenParticleCollection> genParticles;
  edm::Handle<l1t::L1TkMuonParticleCollection> TkMuon; 
  edm::Handle<l1t::L1TkMuonParticleCollection> TkMuonStubsBMTF;
  edm::Handle<l1t::L1TkMuonParticleCollection> TkMuonStubsEMTF;
  edm::Handle<l1t::BayesMuCorrTrackBxCollection> TkMuonStubsOMTF;
  edm::Handle<l1t::L1TkGlbMuonParticleCollection> TkGlbMuon;
  edm::Handle<TTTracksCollection> Tttrack;
  //edm::Handle<TrackingParticleCollection> TrkG4Part;
  //edm::Handle<TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > > TttrackTruth;
  edm::Handle< TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > > MCTruthTTTrackHandle;
  iEvent.getByToken(_TTTracksTruthToken, MCTruthTTTrackHandle);



  iEvent.getByToken(_genParticleToken, genParticles);
  iEvent.getByToken(_TkMuonToken,      TkMuon);
  iEvent.getByToken(_TkMuonStubsBMTFToken,TkMuonStubsBMTF);
  iEvent.getByToken(_TkMuonStubsEMTFToken,TkMuonStubsEMTF);
  iEvent.getByToken(_TkMuonStubsOMTFToken,TkMuonStubsOMTF);
  iEvent.getByToken(_TkGlbMuonToken,   TkGlbMuon);
  iEvent.getByToken(_TTTracksToken,    Tttrack);

  //iEvent.getByToken(_TrkG4PartsToken,  TrkG4Part);
  //iEvent.getByToken(_TTTracksTruthToken, TttrackTruth);
  //const auto &tttracktruth = (*TttrackTruth.product());
  //cout << "******The truth object is " << TttrackTruth.isValid() << endl;
  if(genParticles.isValid()){
    SetGenMuons(genParticles, _maxGenMuons);
 } else {
    edm::LogWarning("MissingProduct") << "Generated Muons not found. Branch will not be filled" << std::endl;
  }
  if(TkMuon.isValid()){
    SetTkMuons(TkMuon);
  } else {
    edm::LogWarning("MissingProduct") << "L1 Phase2 TkMuons not found. Branch will not be filled" << std::endl;
  }
  cout << "The tkMuStub BMTF is Valid is: " << TkMuonStubsBMTF.isValid() << endl;
  if (TkMuonStubsBMTF.isValid()){
      SetTkMuonStubsBMTF(TkMuonStubsBMTF,1);
  } else {
    edm::LogWarning("MissingProduct") << "L1PhaseII TkMuonStubsBMTF not found. Branch will not be filled" << std::endl;
  }
  if (TkMuonStubsOMTF.isValid()){
      SetTkMuonStubsOMTF(TkMuonStubsOMTF, 2);

  } else {
    edm::LogWarning("MissingProduct") << "L1PhaseII TkMuonStubsOMTF not found. Branch will not be filled" << std::endl;
  }
  cout << "The tkMuStub OMTF is Valid is: " << TkMuonStubsOMTF.isValid() << endl;
  if (TkMuonStubsEMTF.isValid()){
      SetTkMuonStubsEMTF(TkMuonStubsEMTF,  3);
    } else{
    edm::LogWarning("MissingProduct") << "L1PhaseII TkMuonStubsEMTF not found. Branch will not be filled" << std::endl;
  }
  cout << "The tkMuStub EMTF is Valid is: " << TkMuonStubsEMTF.isValid() << endl;
  if(TkGlbMuon.isValid()){
    SetTkGlbMuons(TkGlbMuon);
  } else {
    edm::LogWarning("MissingProduct") << "L1 Phase2 TkGlbMuons not found. Branch will not be filled" << std::endl;
  }
  if(Tttrack.isValid()){
    SetTTTracks(Tttrack, MCTruthTTTrackHandle);
  }
   else{
    edm::LogWarning("MissingProduct") << "L1 Phase2 Tttrack not found. Branch will not be filled" << std::endl;
  }
  cout << "The TTTracks is Valid is: " << Tttrack.isValid() << endl;

/*  if(TrkG4Part.isValid()){
    SetTrkG4Parts(TrkG4Part);
  } else{
    edm::LogWarning("MissingProduct") << "L1 Phase2 TrkG4Part not found. Branch will not be filled" << std::endl;
  }
*/
  //Retrieve the run number
  if(_RunningOnData){
    _run_number = iEvent.id().run();
  }

  //*************************************************************//
  //                                                             //
  //--------------------------- Pile Up -------------------------//
  //                                                             //
  //*************************************************************//
  _NTruePU = -1;
  if(!_RunningOnData){
    edm::Handle<std::vector< PileupSummaryInfo>>  PupInfo;
    iEvent.getByLabel(_PileupSrc, PupInfo);
  
    std::vector<PileupSummaryInfo>::const_iterator PVI; 
 
    for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
      const int BX = PVI->getBunchCrossing();
      if(BX == 0) {
	_NTruePU = PVI->getTrueNumInteractions();
	break;
      }
    }
  }

  _mytree->Fill();

}

void L1MuGlobalNtupleMaker::SetGenMuons(const edm::Handle<reco::GenParticleCollection> genParticles, int maxGenMu)
{
  _genpart_pt.clear();
  _genpart_eta.clear();
  _genpart_phi.clear();
  _genpart_id.clear();
  _genpart_parent.clear();
  _genpart_charge.clear();
  _genpart_dxy.clear();
  _genpart_Vz.clear();
  _genpart_status.clear();
  _genpart_status_isLast.clear();

  _genpart_Npart = 0;

  for(size_t i = 0; i < genParticles->size() && _genpart_Npart < maxGenMu ; ++ i) {
    const reco::GenParticle & p = (*genParticles)[i];
    int id = p.pdgId();
    if(fabs(id) != 13 && fabs(id) != 15 && fabs(id) !=24) continue;
    // See if the parent was interesting
    //int parentID = -10000;
    //unsigned int nMo=p.numberOfMothers();
    //for(unsigned int i=0;i<nMo;++i){
   //   int thisParentID = dynamic_cast
   //     <const reco::GenParticle*>(p.mother(i))->pdgId();
    //    int hundredsIndex = abs(thisParentID)/100;
    //    int thousandsIndex = abs(thisParentID)/1000;
    //    if ( ((abs(thisParentID) >= 23) &&
    //          (abs(thisParentID) <= 25)) ||
    //         (abs(thisParentID) == 6) ||
    //         (hundredsIndex == 5) ||
    //         (hundredsIndex == 4) ||
    //         (thousandsIndex == 5) ||
    //         (thousandsIndex == 4)
    //         )
    //      parentID = thisParentID;
    //  }
    //  if ((parentID == -10000) && (nMo > 0))
    //    parentID = dynamic_cast
    //    <const reco::GenParticle*>(p.mother(0))->pdgId();

    _genpart_pt.push_back(p.pt());
    _genpart_eta.push_back(p.eta());
    _genpart_phi.push_back(p.phi());
    _genpart_id.push_back(p.pdgId());
    _genpart_parent.push_back(p.mother(0)->pdgId());
    _genpart_dxy.push_back(-p.vertex().x()*sin(p.phi()) + p.vertex().y()*cos(p.phi()));
    _genpart_Vz.push_back(p.vertex().x());
    _genpart_charge.push_back(p.charge());
    _genpart_status.push_back(p.status());
    _genpart_status_isLast.push_back(p.statusFlags().isLastCopy());
   
    _genpart_Npart++;
  }
}

void L1MuGlobalNtupleMaker::SetTkMuons(const edm::Handle<l1t::L1TkMuonParticleCollection> muon)
{
      //cout << "****** The max tkMu number is " << maxTkMuons << endl;


  _tkmu_pt.clear();
  _tkmu_eta.clear();
  _tkmu_phi.clear();
  _tkmu_charge.clear();
  _tkmu_tkiso.clear();

  _tkmu_Nmuons = 0;

  for (l1t::L1TkMuonParticleCollection::const_iterator it=muon->begin(); it!=muon->end() ; it++){
    if (it->pt() > 0){
      _tkmu_pt.push_back(it->pt());
      _tkmu_eta.push_back(it->eta());
      _tkmu_phi.push_back(it->phi());
      _tkmu_charge.push_back(it->charge());
      _tkmu_tkiso.push_back(it->getTrkIsol());

      _tkmu_Nmuons++;

    }
  }

}


void L1MuGlobalNtupleMaker::SetTkMuonStubsBMTF(const edm::Handle<l1t::L1TkMuonParticleCollection> muon, unsigned int muonDetector)
{
      _tkmuStubsBMTF_pt.clear();
      _tkmuStubsBMTF_eta.clear();
      _tkmuStubsBMTF_phi.clear();
      _tkmuStubsBMTF_charge.clear();
      _tkmuStubsBMTF_tkiso.clear();
      _tkmuStubsBMTF_Vz.clear();
      _tkmuStubsBMTF_Nmuons=0;

  for(l1t::L1TkMuonParticleCollection::const_iterator it=muon->begin(); it!=muon->end() ; it++){

    if (it->pt() > 0 && fabs(it->eta())>=0 && fabs(it->eta())<0.8){
      _tkmuStubsBMTF_pt.push_back(it->pt());
      _tkmuStubsBMTF_eta.push_back(it->eta());
      _tkmuStubsBMTF_phi.push_back(it->phi());
      _tkmuStubsBMTF_charge.push_back(it->charge());
      _tkmuStubsBMTF_tkiso.push_back(it->getTrkIsol());
      _tkmuStubsBMTF_Vz.push_back(it->getTrkzVtx());
      
      _tkmuStubsBMTF_Nmuons++;

    }

  }
}
void L1MuGlobalNtupleMaker::SetTkMuonStubsEMTF(const edm::Handle<l1t::L1TkMuonParticleCollection> muon,  unsigned int muonDetector)
{
      _tkmuStubsEMTF_pt.clear();
      _tkmuStubsEMTF_eta.clear();
      _tkmuStubsEMTF_phi.clear();
      _tkmuStubsEMTF_charge.clear();
      _tkmuStubsEMTF_tkiso.clear();
      _tkmuStubsEMTF_Vz.clear();
      _tkmuStubsEMTF_Nmuons=0;

  for(l1t::L1TkMuonParticleCollection::const_iterator it=muon->begin(); it!=muon->end() ; it++){

    if (it->pt() > 0 && fabs(it->eta())>=1.2 && fabs(it->eta())<=2.4){
      _tkmuStubsEMTF_pt.push_back(it->pt());
      _tkmuStubsEMTF_eta.push_back(it->eta());
      _tkmuStubsEMTF_phi.push_back(it->phi());
      _tkmuStubsEMTF_charge.push_back(it->charge());
      _tkmuStubsEMTF_tkiso.push_back(it->getTrkIsol());
      _tkmuStubsEMTF_Vz.push_back(it->getTrkzVtx());
      
      _tkmuStubsEMTF_Nmuons++;

    }

  }
}

void L1MuGlobalNtupleMaker::SetTkMuonStubsOMTF(const edm::Handle<l1t::BayesMuCorrTrackBxCollection> muon,  unsigned int muonDetector)
{
      _tkmuStubsOMTF_pt.clear();
      _tkmuStubsOMTF_eta.clear();
      _tkmuStubsOMTF_phi.clear();
      _tkmuStubsOMTF_charge.clear();
      _tkmuStubsOMTF_tkiso.clear();
      _tkmuStubsOMTF_Vz.clear();
      _tkmuStubsOMTF_Nmuons=0;
  for (int ibx = muon->getFirstBX(); ibx <= muon->getLastBX(); ++ibx) {
  for(l1t::BayesMuCorrTrackBxCollection::const_iterator it=muon->begin(); it!=muon->end() ; it++){
    if (it->pt() > 0 && fabs(it->eta())>=0.8 && fabs(it->eta())<1.2){
      _tkmuStubsOMTF_pt.push_back(it->pt());
      _tkmuStubsOMTF_eta.push_back(it->eta());
      _tkmuStubsOMTF_phi.push_back(it->phi());
      _tkmuStubsOMTF_charge.push_back( pow(-1,it->hwSign() ) );
      _tkmuStubsOMTF_tkiso.push_back(0);
      _tkmuStubsOMTF_Vz.push_back(it->getTtTrackPtr()->getPOCA(tk_nFitParams_).z());
      
      _tkmuStubsOMTF_Nmuons++;

    }

  }
 }
}


void L1MuGlobalNtupleMaker::SetTkGlbMuons(const edm::Handle<l1t::L1TkGlbMuonParticleCollection> muon)
{
  _tkglbmu_pt.clear();
  _tkglbmu_eta.clear();
  _tkglbmu_phi.clear();
  _tkglbmu_charge.clear();
  _tkglbmu_tkiso.clear();

  _tkglbmu_Nmuons = 0;

  for (l1t::L1TkGlbMuonParticleCollection::const_iterator it=muon->begin(); it!=muon->end(); it++){

    if (it->pt() > 0){
      _tkglbmu_pt.push_back(it->pt());
      _tkglbmu_eta.push_back(it->eta());
      _tkglbmu_phi.push_back(it->phi());
      _tkglbmu_charge.push_back(it->charge());
      _tkglbmu_tkiso.push_back(it->getTrkIsol());

      _tkglbmu_Nmuons++;

    }
  }

}


void L1MuGlobalNtupleMaker::SetTTTracks(const edm::Handle<TTTracksCollection> l1tks, const edm::Handle< TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > > MCTruthTTTrackHandle)
{
      //const edm::Handle<TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > > TttrackTruth;
      _tttracks_pt.clear();
      _tttracks_eta.clear();
      _tttracks_phi.clear();
      _tttracks_chi2.clear();
      _tttracks_z0.clear();
      _tttracks_bendchi2.clear();
      _tttracks_qual.clear();
      _tttracks_gen_TP_ID_.clear();
      _tttracks_gen_TP_pt_.clear();
      _tttracks_gen_TP_eta_.clear();
      _tttracks_gen_TP_phi_.clear();
      _tttracks_gen_TP_m_.clear();


      //_tttracks_Nmuons = 0;

     int this_l1track = 0;
     const auto &truthmap = MCTruthTTTrackHandle->getTTTrackToTrackingParticleMap();
     for (TTTracksCollection::const_iterator it=l1tks->begin(); it!=l1tks->end()  ; it++){
         edm::Ptr< TTTrack< Ref_Phase2TrackerDigi_ > > l1track_ptr(l1tks, this_l1track);
         this_l1track++;
        if (it->getMomentum().perp() > 0){
          _tttracks_pt.push_back(it->getMomentum(4).perp()); //particle pT
          _tttracks_eta.push_back(it->getMomentum(4).eta());
          _tttracks_phi.push_back(it->getMomentum(4).phi());
          _tttracks_chi2.push_back(it->getChi2());
          _tttracks_bendchi2.push_back(it->getStubPtConsistency());     
          _tttracks_z0.push_back(it->getPOCA(tk_nFitParams_).z());

         int trkgenqual = 0;
         if (MCTruthTTTrackHandle->isGenuine(l1track_ptr))
             trkgenqual |= (1 << 0) ;
         else if (MCTruthTTTrackHandle->isCombinatoric(l1track_ptr))
             trkgenqual |= (1 << 1);
         else if (MCTruthTTTrackHandle->isUnknown(l1track_ptr))
             trkgenqual |=  (1 << 2);

         _tttracks_qual.push_back(trkgenqual);


         bool has_matched_trk = (truthmap.find(l1track_ptr) != truthmap.end());

         int   gen_TP_ID   = -999;
         float gen_TP_pt   = -999.; 
         float gen_TP_eta  = -999.;  
         float gen_TP_phi  = -999.;  
         float gen_TP_m    = -999.; 
            
            if (has_matched_trk)
            {
                const auto matchedTP = truthmap.at(l1track_ptr);
                gen_TP_ID  = matchedTP->pdgId() ;
                gen_TP_pt  = matchedTP->p4().pt() ;
                gen_TP_eta = matchedTP->p4().eta() ;
                gen_TP_phi = matchedTP->p4().phi() ;
                gen_TP_m   = matchedTP->p4().mass() ;
            }

            _tttracks_gen_TP_ID_  . push_back (gen_TP_ID);
            _tttracks_gen_TP_pt_  . push_back (gen_TP_pt);
            _tttracks_gen_TP_eta_ . push_back (gen_TP_eta);
            _tttracks_gen_TP_phi_ . push_back (gen_TP_phi);
            _tttracks_gen_TP_m_   . push_back (gen_TP_m);

    }
  }
}
//}
/*
void L1MuGlobalNtupleMaker::SetTrkG4Parts(const edm::Handle<TrackingParticleCollection> muon)
{
  _trkG4Parts_pt.clear();
  _trkG4Parts_eta.clear();
  _trkG4Parts_phi.clear();
  _trkG4Parts_pdgId.clear();

  _trkG4Parts_Nmuons = 0;

  for (TrackingParticleCollection::const_iterator it=muon->begin(); it!=muon->end() ; it++){

    if (it->pt() > 0){
      _trkG4Parts_pt.push_back(it->pt());
      _trkG4Parts_eta.push_back(it->eta());
      _trkG4Parts_phi.push_back(it->phi());
      _trkG4Parts_pdgId.push_back(it->pdgId());

      _trkG4Parts_Nmuons++;

    }
  }


}
*/
//define this as a plug-in
DEFINE_FWK_MODULE(L1MuGlobalNtupleMaker);
