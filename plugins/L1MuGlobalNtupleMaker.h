
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
  void SetL1Muons(const edm::Handle<l1t::MuonBxCollection> muon, int maxL1Upgrade);
  void SetBMTFMuons(const edm::Handle<l1t::RegionalMuonCandBxCollection> muon, int maxBMTFUpgrade);
  void SetOMTFMuons(const edm::Handle<l1t::RegionalMuonCandBxCollection> muon, int maxOMTFUpgrade);
  void SetEMTFMuons(const edm::Handle<l1t::RegionalMuonCandBxCollection> muon, int maxEMTFUpgrade);
  void SetKBMTFMuons(const edm::Handle<l1t::RegionalMuonCandBxCollection> muon, int maxKBMTFUpgrade);
  void SetBMTFPhiInputs(const edm::Handle<L1MuDTChambPhContainer > L1MuDTChambPhContainer, int maxDTPrimitives);
  void SetBMTFThetaInputs(const edm::Handle<L1MuDTChambThContainer > L1MuDTChambThContainer, int maxDTPrimitives);
  void SetTkMuons(const edm::Handle<l1t::L1TkMuonParticleCollection> muon, int maxTkMuons);
  void SetTkGlbMuons(const edm::Handle<l1t::L1TkGlbMuonParticleCollection> muon, int maxTkGlbMuons);
  void SetTkMuonStubsBMTF (const  edm::Handle<l1t::L1TkMuonParticleCollection> muon, int maxTkMuonStubsBMTF,unsigned int muonDetector);
  void SetTkMuonStubsEMTF (const  edm::Handle<l1t::L1TkMuonParticleCollection> muon, int maxTkMuonStubsEMTF,unsigned int muonDetector);
  void SetTkMuonStubsOMTF (const  edm::Handle<l1t::BayesMuCorrTrackBxCollection> muon, int maxTkMuonStubsOMTF,unsigned int muonDetector);
  void SetTTTracks(const edm::Handle<TTTracksCollection> muon, int maxTTTracks, const edm::Handle<TTTrackAssociationMap< Ref_Phase2TrackerDigi_ > > muonTruth);
  void SetTrkG4Parts(const edm::Handle<TrackingParticleCollection> muon, int maxTrkG4Parts);

  bool _RunningOnData;
  int _PU_scenario;
  const edm::InputTag _PileupSrc;

  int _maxGenMuons;
  int _maxL1Muons;
  int _maxBMTFMuons;
  int _maxOMTFMuons;
  int _maxEMTFMuons;
  int _maxKBMTFMuons;
  int _maxDTPrimitives;
  int _maxTkMuons;
  int _maxTkMuonStubsBMTF;
  int _maxTkMuonStubsEMTF;
  int _maxTkMuonStubsOMTF;
  int _maxTkGlbMuons;
  int _maxTTTracks;
  int _maxTrkG4Parts;

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
  std::vector<float> _genmu_pt;
  std::vector<float> _genmu_eta;
  std::vector<float> _genmu_phi;
  std::vector<short int> _genmu_id;
  std::vector<short int> _genmu_parent;
  std::vector<short int> _genmu_charge;
  std::vector<float> _genmu_dxy;
  std::vector<float> _genmu_Vz;
  short int _genmu_Nmuons;

  //L1 muon
  std::vector<float> _l1mu_et;
  std::vector<float> _l1mu_eta;
  std::vector<float> _l1mu_phi;
  std::vector<float> _l1mu_etaAtVtx;
  std::vector<float> _l1mu_phiAtVtx;
  std::vector<short int> _l1mu_hwet;
  std::vector<short int> _l1mu_hweta;
  std::vector<short int> _l1mu_hwphi;
  std::vector<short int> _l1mu_charge;
  std::vector<unsigned short int> _l1mu_hwIso;
  std::vector<unsigned short int> _l1mu_hwQual;
  std::vector<short int> _l1mu_bx;

  short int _l1mu_Nmuons;

  //BMTF muon
  std::vector<short int> _bmtfmu_hwpt;
  std::vector<short int> _bmtfmu_hweta;
  std::vector<short int> _bmtfmu_hwphi;
  std::vector<short int> _bmtfmu_glbphi;
  std::vector<short int> _bmtfmu_hwsign;
  std::vector<short int> _bmtfmu_hwqual;
  std::vector<short int> _bmtfmu_link;
  std::vector<short int> _bmtfmu_processor;
  std::vector<short int> _bmtfmu_bx;
  std::vector<short int> _bmtfmu_wheel;

  short int _bmtfmu_Nmuons;

  //BMTF input
  std::vector<short int> _Inputbmtf_phiBX;
  std::vector<short int> _Inputbmtf_phiWheel;
  std::vector<short int> _Inputbmtf_phiSector;
  std::vector<short int> _Inputbmtf_phiStation;
  std::vector<short int> _Inputbmtf_phiAngle;
  std::vector<short int> _Inputbmtf_phiBandAngle;

  short int _Inputbmtf_phiNprimitives;

  std::vector<short int> _Inputbmtf_thetaBX;
  std::vector<short int> _Inputbmtf_thetaWheel;
  std::vector<short int> _Inputbmtf_thetaSector;
  std::vector<short int> _Inputbmtf_thetaStation;
  std::vector<short int> _Inputbmtf_thetaAngle;

  short int _Inputbmtf_thetaNprimitives;

  //OMTF muon
  std::vector<short int> _omtfmu_hwpt;
  std::vector<short int> _omtfmu_hweta;
  std::vector<short int> _omtfmu_hwphi;
  std::vector<short int> _omtfmu_glbphi;
  std::vector<short int> _omtfmu_hwsign;
  std::vector<short int> _omtfmu_hwqual;
  std::vector<short int> _omtfmu_link;
  std::vector<short int> _omtfmu_processor;
  std::vector<short int> _omtfmu_bx;
  std::vector<short int> _omtfmu_wheel;

  short int _omtfmu_Nmuons;

  //EMTF muon
  std::vector<short int> _emtfmu_hwpt;
  std::vector<short int> _emtfmu_hweta;
  std::vector<short int> _emtfmu_hwphi;
  std::vector<short int> _emtfmu_glbphi;
  std::vector<short int> _emtfmu_hwsign;
  std::vector<short int> _emtfmu_hwqual;
  std::vector<short int> _emtfmu_link;
  std::vector<short int> _emtfmu_processor;
  std::vector<short int> _emtfmu_bx;
  std::vector<short int> _emtfmu_wheel;

  short int _emtfmu_Nmuons;

  //KBMTF muon
  std::vector<short int> _Kbmtfmu_hwpt;
  std::vector<short int> _Kbmtfmu_hweta;
  std::vector<short int> _Kbmtfmu_hwphi;
  std::vector<short int> _Kbmtfmu_glbphi;
  std::vector<short int> _Kbmtfmu_hwsign;
  std::vector<short int> _Kbmtfmu_hwqual;
  std::vector<short int> _Kbmtfmu_link;
  std::vector<short int> _Kbmtfmu_processor;
  std::vector<short int> _Kbmtfmu_bx;
  std::vector<short int> _Kbmtfmu_wheel;

  short int _Kbmtfmu_Nmuons;

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
  std::vector<int>   _tttracks_gen_qual;
  std::vector<int>   _tttracks_gen_TP_ID;
  std::vector<float> _tttracks_gen_TP_pt;
  std::vector<float> _tttracks_gen_TP_eta;
  std::vector<float> _tttracks_gen_TP_phi;
  std::vector<float> _tttracks_gen_TP_m;;

  short int _tttracks_Nmuons;

  //TrkG4Parts
  std::vector<float> _trkG4Parts_pt;
  std::vector<float> _trkG4Parts_eta;
  std::vector<float> _trkG4Parts_phi;
  std::vector<int>   _trkG4Parts_pdgId;

  short int _trkG4Parts_Nmuons;


  //Tokens
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> > _pileupSummaryToken;
  edm::EDGetTokenT<reco::GenParticleCollection> _genParticleToken;
  edm::EDGetTokenT<l1t::MuonBxCollection> _L1MuonToken;
  edm::EDGetTokenT<l1t::RegionalMuonCandBxCollection> _bmtfMuonToken;
  edm::EDGetTokenT<l1t::RegionalMuonCandBxCollection> _omtfMuonToken;
  edm::EDGetTokenT<l1t::RegionalMuonCandBxCollection> _emtfMuonToken;
  edm::EDGetTokenT<l1t::RegionalMuonCandBxCollection> _KbmtfMuonToken;
  edm::EDGetTokenT<L1MuDTChambPhContainer> _bmtfPhInputToken;
  edm::EDGetTokenT<L1MuDTChambThContainer> _bmtfThInputToken;
  edm::EDGetTokenT<l1t::L1TkMuonParticleCollection> _TkMuonToken;
  edm::EDGetTokenT<l1t::L1TkMuonParticleCollection> _TkMuonStubsToken;
  edm::EDGetTokenT<l1t::L1TkMuonParticleCollection> _TkMuonStubsBMTFToken;
  edm::EDGetTokenT<l1t::L1TkMuonParticleCollection> _TkMuonStubsEMTFToken;
  edm::EDGetTokenT<l1t::BayesMuCorrTrackBxCollection> _TkMuonStubsOMTFToken;
  edm::EDGetTokenT<l1t::L1TkGlbMuonParticleCollection> _TkGlbMuonToken;
  edm::EDGetTokenT<TTTracksCollection> _TTTracksToken;
  edm::EDGetTokenT<TTTrackAssociationMap< Ref_Phase2TrackerDigi_> > _TTTracksTruthToken;
  edm::EDGetTokenT<TrackingParticleCollection> _TrkG4PartsToken;

};
