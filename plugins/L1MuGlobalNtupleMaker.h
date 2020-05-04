
//---------- class declaration----------

class L1MuGlobalNtupleMaker : public edm::EDAnalyzer {
public:
  explicit L1MuGlobalNtupleMaker(const edm::ParameterSet&);
  ~L1MuGlobalNtupleMaker();

private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() override;

  void SetGenMuons(const edm::Handle<reco::GenParticleCollection>  genParticles, int maxGenMu);
  void SetTkMuons(const edm::Handle<l1t::L1TkMuonParticleCollection> muon);
  void SetTkGlbMuons(const edm::Handle<l1t::L1TkGlbMuonParticleCollection> muon);
  void SetTkMuonStubsBMTF (const  edm::Handle<l1t::L1TkMuonParticleCollection> muon, unsigned int muonDetector);
  void SetTkMuonStubsEMTF (const  edm::Handle<l1t::L1TkMuonParticleCollection> muon, unsigned int muonDetector);
  void SetTkMuonStubsOMTF (const  edm::Handle<l1t::BayesMuCorrTrackBxCollection> muon,unsigned int muonDetector);
  void SetTTTracks(const edm::Handle<TTTracksCollection> muon, const edm::Handle< TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > > truthtrack);


  bool _RunningOnData;
  int _PU_scenario;
  const edm::InputTag _PileupSrc;

  int _maxGenMuons;
  edm::Service<TFileService> fs;

  void create_trees();

  // ----------member data ---------------------------
  TH1F* _h_Global_Info;

  //Counters
  int _Nevents_processed;

  //#########################################
  //TTree and TTree variables
  //#########################################
  TTree *_mytree;

  int _run_number;
  int tk_nFitParams_=4 ;
  //MC truth
  float _NTruePU;
  std::vector<float> _genpart_pt;
  std::vector<float> _genpart_eta;
  std::vector<float> _genpart_phi;
  std::vector<short int> _genpart_id;
  std::vector<short int> _genpart_parent;
  std::vector<short int> _genpart_charge;
  std::vector<float> _genpart_dxy;
  std::vector<float> _genpart_Vz;
  std::vector<short int> _genpart_status;
  std::vector<bool> _genpart_status_isLast;

  short int _genpart_Npart;


   //Tk Muons
   short int _tkmu_Nmuons;
   std::vector<double>   _tkmu_pt;
   std::vector<double>   _tkmu_eta;
   std::vector<double>   _tkmu_phi;
   std::vector<int>      _tkmu_charge;
   std::vector<double> _tkmu_tkiso;

  //TkMuon Stubs
  short int _tkmuStubsBMTF_Nmuons;
  std::vector<double>   _tkmuStubsBMTF_pt;
  std::vector<double>   _tkmuStubsBMTF_eta;
  std::vector<double>   _tkmuStubsBMTF_phi;
  std::vector<int>      _tkmuStubsBMTF_charge;
  std::vector<double>   _tkmuStubsBMTF_tkiso;
  std::vector<double>   _tkmuStubsBMTF_Vz;

  short int _tkmuStubsEMTF_Nmuons;
  std::vector<double>   _tkmuStubsEMTF_pt;
  std::vector<double>   _tkmuStubsEMTF_eta;
  std::vector<double>   _tkmuStubsEMTF_phi;
  std::vector<int>      _tkmuStubsEMTF_charge;
  std::vector<double>   _tkmuStubsEMTF_tkiso;
  std::vector<double>   _tkmuStubsEMTF_Vz;


  short int _tkmuStubsOMTF_Nmuons;
  std::vector<double>   _tkmuStubsOMTF_pt;
  std::vector<double>   _tkmuStubsOMTF_eta;
  std::vector<double>   _tkmuStubsOMTF_phi;
  std::vector<int>      _tkmuStubsOMTF_charge;
  std::vector<double>   _tkmuStubsOMTF_tkiso;
  std::vector<double>   _tkmuStubsOMTF_Vz;

  //Tk Glb muon
  std::vector<float> _tkglbmu_pt;
  std::vector<float> _tkglbmu_eta;
  std::vector<float> _tkglbmu_phi;
  std::vector<float> _tkglbmu_charge;
  std::vector<float> _tkglbmu_tkiso;

  short int _tkglbmu_Nmuons;

  //TTTracks 
  std::vector<float> _tttracks_pt;
  std::vector<float> _tttracks_eta;
  std::vector<float> _tttracks_phi;
  std::vector<float> _tttracks_chi2;  
  std::vector<float> _tttracks_z0; 
  std::vector<float> _tttracks_bendchi2;
  std::vector<int> _tttracks_qual;
  std::vector<int>   _tttracks_gen_TP_ID_;
  std::vector<float> _tttracks_gen_TP_pt_;
  std::vector<float> _tttracks_gen_TP_eta_;
  std::vector<float> _tttracks_gen_TP_phi_;
  std::vector<float> _tttracks_gen_TP_m_;

  short int this_l1track;

/*
  //TrkG4Parts
  std::vector<float> _trkG4Parts_pt;
  std::vector<float> _trkG4Parts_eta;
  std::vector<float> _trkG4Parts_phi;
  std::vector<int>   _trkG4Parts_pdgId;

  short int _trkG4Parts_Nmuons;
*/

  //Tokens
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> > _pileupSummaryToken;
  edm::EDGetTokenT<reco::GenParticleCollection> _genParticleToken;
  edm::EDGetTokenT<l1t::L1TkMuonParticleCollection> _TkMuonToken;
  edm::EDGetTokenT<l1t::L1TkMuonParticleCollection> _TkMuonStubsBMTFToken;
  edm::EDGetTokenT<l1t::L1TkMuonParticleCollection> _TkMuonStubsEMTFToken;
  edm::EDGetTokenT<l1t::BayesMuCorrTrackBxCollection> _TkMuonStubsOMTFToken;
  edm::EDGetTokenT<l1t::L1TkGlbMuonParticleCollection> _TkGlbMuonToken;
  edm::EDGetTokenT<TTTracksCollection> _TTTracksToken;
  edm::EDGetTokenT< TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > > _TTTracksTruthToken;
  //edm::EDGetTokenT<TrackingParticleCollection> _TrkG4PartsToken;

};
