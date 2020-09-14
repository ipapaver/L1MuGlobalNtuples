    //TFile *f=TFile::Open("/eos/cms/store/user/ipapaver/WToTauTo3Mu_V10_3_ntuple/NUGun.root");
    //TFile *f=TFile::Open("/eos/cms/store/user/ipapaver/WToTauTo3Mu_V10_3_ntuple/L1NtuplePhaseII_MTD_2467188.root");
    //TFile *f=TFile::Open("L1PhaseII_MuNtuple_WToTauPU200.root");
    //TFile *f=TFile::Open("WToTauTo3Mu_PU0_V10_6.root");

    //TFile *f=TFile::Open("Rate/L1PhaseII_MuNtuple_NuGun.root");
    TFile *f=TFile::Open("WToTauTo3Mu_PU0_L1MUGlobalNtuple.root");
    //TTree *treeL1=(TTree*)f->Get("l1PhaseIITree/L1PhaseIITree");
    //Tree *treeGen=(TTree*)f->Get("genTree/L1GenTree");

    TTree *mytree=(TTree*)f->Get("L1MuGlobalNtupleMaker/mytree");

    Int_t                tkmuStubsBMTF_Nmuons=0;
    vector<double>       *tkmuStubsBMTF_pt=0;
    vector<double>       *tkmuStubsBMTF_eta=0;
    vector<double>       *tkmuStubsBMTF_phi=0;
    vector<int>          *tkmuStubsBMTF_charge=0;
    vector<double>       *tkmuStubsBMTF_tkiso=0;
    vector<double>          *tkmuStubsBMTF_Vz=0;

    Int_t                tkmuStubsOMTF_Nmuons=0;
    vector<double>       *tkmuStubsOMTF_pt=0;
    vector<double>       *tkmuStubsOMTF_eta=0;
    vector<double>       *tkmuStubsOMTF_phi=0;
    vector<int>          *tkmuStubsOMTF_charge=0;
    vector<double>       *tkmuStubsOMTF_tkiso=0;
    vector<double>          *tkmuStubsOMTF_Vz=0;

    Int_t                tkmuStubsEMTF_Nmuons=0;
    vector<double>       *tkmuStubsEMTF_pt=0;
    vector<double>       *tkmuStubsEMTF_eta=0;
    vector<double>       *tkmuStubsEMTF_phi=0;
    vector<int>          *tkmuStubsEMTF_charge=0;
    vector<double>       *tkmuStubsEMTF_tkiso=0;
    vector<double>          *tkmuStubsEMTF_Vz=0;

    short int               tttracks_Nmuons=0;
    vector<float>       *tttracks_pt=0;
    vector<float>       *tttracks_eta=0;
    vector<float>       *tttracks_phi=0;
    vector<float>       *tttracks_chi2=0;
    vector<float>       *tttracks_bendchi2=0;
    vector<float>       *tttracks_z0=0;
    vector<int>         *tttracks_qual=0;
    vector<int>         *tttracks_gen_TP_ID;

    mytree->SetMakeClass(1);
    mytree->SetBranchAddress("tkmuStubsBMTF_Nmuons", &tkmuStubsBMTF_Nmuons );
    mytree->SetBranchAddress("tkmuStubsBMTF_pt",     &tkmuStubsBMTF_pt     );
    mytree->SetBranchAddress("tkmuStubsBMTF_eta",    &tkmuStubsBMTF_eta    );
    mytree->SetBranchAddress("tkmuStubsBMTF_phi",    &tkmuStubsBMTF_phi    );
    mytree->SetBranchAddress("tkmuStubsBMTF_charge", &tkmuStubsBMTF_charge );
    mytree->SetBranchAddress("tkmuStubsBMTF_tkiso",  &tkmuStubsBMTF_tkiso  );
    mytree->SetBranchAddress("tkmuStubsBMTF_Vz",     &tkmuStubsBMTF_Vz     );
 
    mytree->SetBranchAddress("tkmuStubsEMTF_Nmuons", &tkmuStubsEMTF_Nmuons );
    mytree->SetBranchAddress("tkmuStubsEMTF_pt",     &tkmuStubsEMTF_pt     );
    mytree->SetBranchAddress("tkmuStubsEMTF_eta",    &tkmuStubsEMTF_eta    );
    mytree->SetBranchAddress("tkmuStubsEMTF_phi",    &tkmuStubsEMTF_phi    );
    mytree->SetBranchAddress("tkmuStubsEMTF_charge", &tkmuStubsEMTF_charge );
    mytree->SetBranchAddress("tkmuStubsEMTF_tkiso",  &tkmuStubsEMTF_tkiso  );
    mytree->SetBranchAddress("tkmuStubsEMTF_Vz",     &tkmuStubsEMTF_Vz     );

    mytree->SetBranchAddress("tkmuStubsOMTF_Nmuons", &tkmuStubsOMTF_Nmuons );
    mytree->SetBranchAddress("tkmuStubsOMTF_pt",     &tkmuStubsOMTF_pt     );
    mytree->SetBranchAddress("tkmuStubsOMTF_eta",    &tkmuStubsOMTF_eta    );
    mytree->SetBranchAddress("tkmuStubsOMTF_phi",    &tkmuStubsOMTF_phi    );
    mytree->SetBranchAddress("tkmuStubsOMTF_charge", &tkmuStubsOMTF_charge );
    mytree->SetBranchAddress("tkmuStubsOMTF_tkiso",  &tkmuStubsOMTF_tkiso  );
    mytree->SetBranchAddress("tkmuStubsOMTF_Vz",     &tkmuStubsOMTF_Vz     );

    mytree->SetBranchAddress("tttracks_Nmuons", &tttracks_Nmuons    );
    mytree->SetBranchAddress("tttracks_pt",     &tttracks_pt        );
    mytree->SetBranchAddress("tttracks_eta",    &tttracks_eta       );
    mytree->SetBranchAddress("tttracks_phi",    &tttracks_phi       );
    mytree->SetBranchAddress("tttracks_chi2",   &tttracks_chi2      );
    mytree->SetBranchAddress("tttracks_bendchi2",&tttracks_bendchi2 );
    mytree->SetBranchAddress("tttracks_z0",   &tttracks_z0          );
    mytree->SetBranchAddress("tttracks_qual", &tttracks_qual);
    mytree->SetBranchAddress("tttracks_gen_TP_ID", &tttracks_gen_TP_ID);

    short int       genpart_Npart =0;
    vector<short>   *genpart_id=0;
    vector<short>   *genpart_parent=0;
    vector<float>   *genpart_pt =0;
    vector<float>   *genprt_eta=0;
    vector<float>   *genpart_phi=0;
    vector<short>   *genpart_charge=0;
    vector<float>   *genpart_dxy=0;
    vector<float>   *genpart_Vz=0;
    vector<short>   *genpart_status=0;
    vector<bool>    *genpart_status_isLast=0;

    mytree->SetBranchAddress("genpart_Npart",   &genpart_Npart);
    mytree->SetBranchAddress("genpart_id",     &genpart_id);
    mytree->SetBranchAddress("genpart_parent", &genpart_parent);
    mytree->SetBranchAddress("genpart_pt",     &genpart_pt);
    mytree->SetBranchAddress("genprt_eta",    &genprt_eta);
    mytree->SetBranchAddress("genpart_phi",    &genpart_phi);
    mytree->SetBranchAddress("genpart_charge", &genpart_charge);
    mytree->SetBranchAddress("genpart_dxy",    &genpart_dxy);
    mytree->SetBranchAddress("genpart_Vz",     &genpart_Vz);
    mytree->SetBranchAddress("genpart_status", &genpart_status);
    mytree->SetBranchAddress("genpart_status_isLast", &genpart_status_isLast);


    Int_t nevents=mytree->GetEntries();

