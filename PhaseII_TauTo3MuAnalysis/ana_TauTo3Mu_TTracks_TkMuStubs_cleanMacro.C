#include "ana_TauTo3Mu.h"
//include "histos_defs.h"

{TFile* histf = new TFile("Performance_TauTo3Mu_PU0.root" ,"recreate");

  TH1F *h_gMuPt       = new TH1F("h_genMuPt"    , "GEN Mu Pt",         250, 0 , 250);
  TH1F *h_gMuPt_sort  = new TH1F("h_genPt_sort", "GEN Pt sort",        250, 0 , 250);
  TH1F *h_gMuId       = new TH1F("h_genId"     ,   "GEN Id",               100, 0 , 100);
  TH1F *h_gMuEta      = new TH1F("h_genEta"    ,  "GEN Eta",                200, -5,   5);
  TH1F *h_gMuPhi      = new TH1F("h_genPhi"    ,  "GEN Phi",                32,  -3.20,3.20);
  TH1F *h_nGMuons     = new TH1F("h_nGMuons",    "nummber of Gen Muons",      15, 0, 15);
  TH1F *h_gMuPartParent  = new TH1F("h_gMuPartParent",      "GEN Mu Parent Muon Id",  50, 0, 50);
  TH1F *h_gMuPt_Bar   = new TH1F("h_gMuPt_Bar",  "GEN Muon Pt bar",           100, 0, 100);
  TH1F *h_gMuPt_Over   = new TH1F("h_gMuPt_Over","GEN Muon Pt over",          100, 0, 100);
  TH1F *h_gMuPt_End   = new TH1F("h_gMuPt_End",  "GEN Muon Pt end",           100, 0, 100);
  TH1F *h_genmu1Pt    = new TH1F("h_genmu1Pt", "Gen Mu leading Pt from tau",           120,0,60);
  TH1F *h_genmu2Pt    = new TH1F("h_genmu2Pt", "Gen Mu sub-leading Pt from tau",       120,0,60);
  TH1F *h_genmu3Pt    = new TH1F("h_genmu3Pt", "Gen Mu trailing Pt from tau",          120,0,60);
  TH1F *h_genMu1_barrel = new TH1F("h_genMu1_barrel", "Gen mu 1 pt barrel", 100,0,100);
  TH1F *h_genMu2_barrel = new TH1F("h_genMu2_barrel", "Gen mu 2 pt barrel", 100,0,100);
  TH1F *h_genMu3_barrel = new TH1F("h_genMu3_barrel", "Gen mu 3 pt barrel", 100,0,100);
  TH1F *h_genMu1_overlap = new TH1F("h_genMu1_overlap", "Gen mu 1 pt overlap", 100,0,100);
  TH1F *h_genMu2_overlap = new TH1F("h_genMu2_overlap", "Gen mu 2 pt overlap", 100,0,100);
  TH1F *h_genMu3_overlap = new TH1F("h_genMu3_overlap", "Gen mu 3 pt overlap", 100,0,100);
  TH1F *h_genMu1_endcap = new TH1F("h_genMu1_endcap", "Gen mu 1 pt endcap", 100,0,100);
  TH1F *h_genMu2_endcap = new TH1F("h_genMu2_endcap", "Gen mu 2 pt endcap", 100,0,100);
  TH1F *h_genMu3_endcap = new TH1F("h_genMu3_endcap", "Gen mu 3 pt endcap", 100,0,100);

  TH1F *h_gTriMuMass  = new TH1F("h_gTriMuMass", "h_gTriMuMass",              40, 0, 20);
  TH1F *h_gTripleMuPt   = new TH1F("h_gTripleMuPt",  "h_gTripleMuPt",         100, 0, 50);
  TH1F *h_genTau_pt    = new TH1F("h_genTau_pt" ,  "genTau pt",           100, 0, 100);
  TH1F *h_genTau_pt_Bar    = new TH1F("h_genTau_pt_Bar" ,  "genTau pt barrel",       100, 0, 100);
  TH1F *h_genTau_pt_Over    = new TH1F("h_genTau_pt_Over" ,  "genTau pt over",        100, 0, 100);
  TH1F *h_genTau_pt_End    = new TH1F("h_genTau_pt_End" ,  "genTau pt end",           100, 0, 100);
  TH1F *h_genTau_eta   = new TH1F("h_genTau_eta",  "genTau Eta",   100,-4, 4);
  TH1F *h_genTau_phi   = new TH1F("h_genTau_phi",  "genTau Phi",   32,-3.20, 3.20);
  TH1F *h_genLeadMuTau_pt = new TH1F("h_genLeadMuTau_pt", "h_genLeadMuTau_pt", 120, 0, 60);
  TH1F *h_genSubleadMuTau_pt = new TH1F("h_genSubleadMuTau_pt", "h_genSubleadMuTau_pt", 120, 0, 60);
  TH1F *h_genThirdMuTau_pt = new TH1F("h_genThirdMuTau_pt", "h_genThirdMuTau_pt", 120, 0, 60);
  TH1F *h_gTauMudR_mu12       = new TH1F("h_gTauMudR_mu12",      "GenTau-mu12 dR",         50, 0, 1);
  TH1F *h_gTauMudR_mu13       = new TH1F("h_gTauMudR_mu13",      "GenTau-mu13 dR",         50, 0, 1);
  TH1F *h_gTauMudR_mu23       = new TH1F("h_gTauMudR_mu23",      "GenTau-mu23 dR",         50, 0, 1);

  TH1F *h_TTTracks_N_qual1         = new TH1F("h_TTTracks_N_qual1",    "h_TTTracks_N only genuine", 50, 50,250);
  TH1F *h_TTTracks_N_allqual        = new TH1F("h_TTTracks_N_allqual",    "h_TTTracks_N all qual", 50, 0,400);
  TH1F *h_TTTracks_pt_beforequal     = new TH1F("h_TTTracks_pt_beforequal",    "h_TTTracks_pt before qual cut", 120, 0, 60);
  TH1F *h_TTTracks_eta_beforequal    = new TH1F("h_TTTracks_eta_beforequal",   "h_TTTracks_eta before qual cut", 100,-4,4);
  TH1F *h_TTTracks_phi_beforequal    = new TH1F("h_TTTracks_phi_beforequal",   "h_TTTracks_phi before qual cut", 100, -4,4);
  TH1F *h_TTTracks_chi2_beforequal   = new TH1F("h_TTTracks_chi2_beforequal",   "h_TTTracks_chi2 before qual cut", 200,0,200);
  TH1F *h_TTTracks_chi2Bend_beforequal = new TH1F("h_TTTracks_chi2Bend_beforequal", "h_TTTracks_chi2Bend befre qual cut", 100,0,100);
  TH1F *h_TTTracks_z0_beforequal     = new TH1F("h_TTTracks_z0_beforequal",   "h_TTTracks_z0 before qual cut", 40,-20,20);
  TH1F * h_TTTracks_qual_beforequal  = new TH1F("h_TTTracks_qual_beforequal", "h_TTTracks_qual before qual", 5,0,5);
  TH1F * h_TTTracks_gen_TP_ID_beforequal  = new TH1F("h_TTTracks_gen_TP_ID_beforequal", "h_TTTracks_gen_TP_ID before qual", 700,-350,350);
  TH1F *h_TTTracks_pt        = new TH1F("h_TTTracks_pt",          "h_TTTracks_pt", 120, 0, 60);
  TH1F *h_TTTracks_eta       = new TH1F("h_TTTracks_eta",         "h_TTTracks_eta", 100,-4,4);
  TH1F *h_TTTracks_phi       = new TH1F("h_TTTracks_phi",         "h_TTTracks_phi", 100, -4,4);
  TH1F *h_TTTracks_chi2      = new TH1F("h_TTTracks_chi2",        "h_TTTracks_chi2", 200,0,200);
  TH1F *h_TTTracks_chi2Bend      = new TH1F("h_TTTracks_chi2Bend",        "h_TTTracks_chi2Bend", 100,0,100);
  TH1F *h_TTTracks_z0      = new TH1F("h_TTTracks_z0",        "h_TTTracks_z0", 40,-20,20);
  TH1F * h_TTTracks_qual  = new TH1F("h_TTTracks_qual", "h_TTTracks_qual", 5,0,5);
  TH1F * h_TTTracks_gen_TP_ID  = new TH1F("h_TTTracks_gen_TP_ID", "h_TTTracks_gen_TP_ID", 700,-350,350);
  //TH1F *h_TTTrackgdR_mu11  = new TH1F("h_TTTrackgdR_mu11", "TTTrack-gendR 11 for eff", 50,0,5);
  //TH1F *h_TTTrackgdR_mu22  = new TH1F("h_TTTrackgdR_mu22", "TTTrack-gendR 22 for eff", 50,0,5);
  //TH1F *h_TTTrackgdR_mu33  = new TH1F("h_TTTrackgdR_mu33", "TTTrack-gendR 33 for eff", 50,0,5);

  TH1F *h_dR_TTTRack_Gen1_beforeCut = new TH1F("h_dR_TTTRack_Gen1_beforeCut", "TTTrack-Gen1 dR before cut", 100,0,5);
  TH1F *h_dR_TTTRack_Gen2_beforeCut = new TH1F("h_dR_TTTRack_Gen2_beforeCut", "TTTrack-Gen2 dR before cut", 100,0,5);
  TH1F *h_dR_TTTRack_Gen3_beforeCut = new TH1F("h_dR_TTTRack_Gen3_beforeCut", "TTTrack-Gen3 dR before cut", 100,0,5);
  TH1F *h_dEta_TTTrack_GenMu1 = new TH1F("h_dEta_TTTrack_GenMu1", "dEta TTTrack-Gen1 ", 50,0,5);
  TH1F *h_dEta_TTTrack_GenMu2 = new TH1F("h_dEta_TTTrack_GenMu2", "dEta TTTrack-Gen2 ", 50,0,5);
  TH1F *h_dEta_TTTrack_GenMu3 = new TH1F("h_dEta_TTTrack_GenMu3", "dEta TTTrack-Gen1 ", 50,0,5);
  TH1F *h_dPt_TTTrack_GenMu1 = new TH1F ("h_dPt_TTTrack_GenMu1", "dPt Gen1 and Tracks", 200, 0,20);
  TH1F *h_dPt_TTTrack_GenMu2 = new TH1F ("h_dPt_TTTrack_GenMu2", "dPt Gen2 and Tracks", 200, 0,20);
  TH1F *h_dPt_TTTrack_GenMu3 = new TH1F ("h_dPt_TTTrack_GenMu3", "dPt Gen3 and Tracks", 200, 0,20);
  TH1F *h_dPt_TTTrack_GenMu1_afterAlgo =new TH1F("h_dPt_TTTrack_GenMu1_afterAlgo", "min dPt gen1-TTTrack after algo", 100,0,10);
  TH1F *h_dPt_TTTrack_GenMu2_afterAlgo =new TH1F("h_dPt_TTTrack_GenMu2_afterAlgo", "min dPt gen2-TTTrack after algo", 100,0,10);
  TH1F *h_dPt_TTTrack_GenMu3_afterAlgo =new TH1F("h_dPt_TTTrack_GenMu3_afterAlgo", "min dPt gen3-TTTrack after algo", 100,0,10);
  TH1F *h_ratio_Pt_TTTrack_GenMu1 = new TH1F ("h_ratio_Pt_TTTrack_GenMu1", "ratio Pt Gen1 and Track with mindPt", 80, 0,0.2);
  TH1F *h_ratio_Pt_TTTrack_GenMu2 = new TH1F ("h_ratio_Pt_TTTrack_GenMu2", "ratio Pt Gen2 and Track with mindPt", 80, 0,0.2);
  TH1F *h_ratio_Pt_TTTrack_GenMu3 = new TH1F ("h_ratio_Pt_TTTrack_GenMu3", "ratio Pt Gen3 and Track with mindPt", 80, 0,0.2);
  TH1F *h_TTTrackdR_mu12_beforeMassCut = new TH1F("h_TTTrackdR_m12_beforeMassCut", "dR TTTrack 1-2 before mass and dZmax cut", 50,0,0.5);
  TH1F *h_TTTrackdR_mu13_beforeMassCut = new TH1F("h_TTTrackdR_m13_beforeMassCut", "dR TTTrack 1-3 before mass and dZmax cut", 50,0,0.5);
  TH1F *h_TTTrackdR_mu23_beforeMassCut = new TH1F("h_TTTrackdR_m23_beforeMassCut", "dR TTTrack 2-3 before mass and dZmax cut", 50,0,0.5);
  TH1F *h_TTTrackdzVtx_12 = new TH1F("h_TTTrackdzVtx_12", "dxVtx Mu1-Mu2 TTTracks", 100, 0, 5);
  TH1F *h_TTTrackdzVtx_13 = new TH1F("h_TTTrackdzVtx_13", "dxVtx Mu1-Mu3 TTTracks", 100, 0, 5);
  TH1F *h_TTTrackdzVtx_23 = new TH1F("h_TTTrackdzVtx_23", "dxVtx Mu2-Mu3 TTTRacks", 100, 0, 5);
  TH1F *h_TTTrackdzVtx_max = new TH1F("h_TTTrackdzVtx_max", "dxVtx TTTracks max", 100, 0, 5);
  TH1F *h_TTTrack_TripleMu_Mass = new TH1F("h_TTTrack_TripleMu_Mass", "h_TTTrack_TripleMu_Mass", 200,0,20);
  TH1F *h_TTTrackdR_mu12_afterMassCut = new TH1F("h_TTTrackdR_m12", "dR TTTrack 1-2 after mass and dz cut ", 50,0,0.5);
  TH1F *h_TTTrackdR_mu13_afterMassCut = new TH1F("h_TTTrackdR_m13", "dR TTTrack 1-3 after mass and dz cut", 50,0,0.5);
  TH1F *h_TTTrackdR_mu23_afterMassCut = new TH1F("h_TTTrackdR_m23", "dR TTTrack 2-3 after mass and dz cut", 50,0,0.5);

  TH1F *h_TTTrackTau_pt    = new TH1F("h_TTTrackTau_pt" ,  "TTTrack Tau pt",                   100, 0, 100);
  TH1F *h_TTTrackTau_pt_Bar = new TH1F("h_TTTrackTau_pt_Bar" ,  "TTTrack Tau pt Bar",             100, 0, 100);
  TH1F *h_TTTrackTau_pt_Over = new TH1F("h_TTTrackTau_pt_Over" ,  "TTTrack Tau pt Over",           100, 0, 100);
  TH1F *h_TTTrackTau_pt_End = new TH1F("h_TTTrackTau_pt_End" ,  "TTTrack Tau pt End",             100, 0, 100);
  TH1F *h_TTTrackTau_eta   = new TH1F("h_TTTrackTau_eta",  "TTTrack Tau Eta",                   24, -3,  3);
  TH1F *h_TTTrackTau_phi   = new TH1F("h_TTTrackTau_phi",  "TTTrack Tau Phi",          32,-3.20, 3.20);
  TH1F *h_TTTrackTau_mass  = new TH1F("h_TTTrackTau_mass", "TTTrack tau mass", 100,0,3);
  TH1F *h_TTTrackLeadMuTau_pt    = new TH1F("h_TTTrackLeadLepTau_pt", "Pt of leading TTTrack in tau cand", 120, 0, 60);
  TH1F *h_TTTrackSubleadMuTau_pt = new TH1F("h_TTTrackSubleadLepTau_pt", "Pt of subleading TTTrack in tau cand", 120, 0, 60);
  TH1F *h_TTTrackThirdMuTau_pt   = new TH1F("h_TTTrackThirdLepTau_pt", "Pt of training TTTrack in tau cand", 120, 0, 60);

  TH1F *h_dR_TkMuStubTTTrack1 = new TH1F("h_dR_TkMuStubTTTrack1", "dR Track1 -TkMuSTub", 100,0,10);
  TH1F *h_dR_TkMuStubTTTrack2 = new TH1F("h_dR_TkMuStubTTTrack2", "dR Track2 -TkMuSTub", 100,0,10);

  TH1F *h_min_dPt_TTTrack1_TkMuStubs = new TH1F("h_min_dPt_TTTrack1_TkMuStubs", "min dPt TTTrack1-TkMuStub",200,0,10);
  TH1F *h_min_dPt_TTTrack2_TkMuStubs = new TH1F("h_min_dPt_TTTrack2_TkMuStubs", "min dPt TTTrack2-TkMuStub",200,0,10);

  TH1F *h_dPt_TkMuStub1_TTTrack3 = new TH1F("h_dPt_TkMuStub1_TTTrack3", "dPt of TTTrack 3 and TkMuStub matched to TTTrack 1", 100,0,5);
  TH1F *h_dPt_TkMuStub2_TTTrack3 = new TH1F("h_dPt_TkMuStub2_TTTrack3", "dPt of TTTrack 3 and TkMuStub matched to TTTrack 2", 100,0,5);
  TH1F *h_dPt_TkMuStub1_TTTrack2 = new TH1F("h_dPt_TkMuStub1_TTTrack2", "dPt of TTTrack 1 and TkMuStub matched to TTTrack 2", 100,0,5);

  TH1F *h_TkMuSTubTTTrack_LeadPt = new TH1F("h_TkMuSTubTTTrack_LeadPt", "Pt of leading TkMuStubs from 2TkMUStub matched to TTTrack1", 60, 0,60);
  TH1F *h_TkMuSTubTTTrack_SubLeadPt = new TH1F("h_TkMuSTubTTTrack_SubLeadPt", "Pt of sub-leading TkMuStubs from 2TkMUStub matched to TTTrack2", 60, 0,60);
  TH1F *h_TkMuSTubTTTrack_TrailPt = new TH1F("h_TkMuSTubTTTrack_TrailPt", "Pt of trail TTTrack 2TkMUStub matched to gen3", 60, 0,60);
  TH1F *h_TkMuStubsTTTrackkdzVtx_12 = new TH1F("h_TkMuStubsTTTrackkdzVtx_12", "dZ0 TkMuStub matched to TTTrack 1 and TkMuStub matched to TTTrack 2",100,0,5);
  TH1F *h_TkMuStubsTTTrackkdzVtx_13 = new TH1F("h_TkMuStubsTTTrackkdzVtx_13", "dZ0 TkMuStub matched to TTTrack 1 and TTTrack 3",100,0,5);
  TH1F *h_TkMuStubsTTTrackkdzVtx_23 = new TH1F("h_TkMuStubsTTTrackkdzVtx_23", "dZ0 TkMuStub matched to TTTrack 1 and TTTrack 2",100,0,5);
  TH1F *h_TkMuStubsTTTrackdzVtx_max= new TH1F("h_TkMuStubsTTTrackdzVtx_max", "max dZ between TkMuStubs and TTTrack3",100,0,5);
  TH1F *h_TkMuStubTTTrack_TripleMu_Mass = new TH1F("h_TkMuStubTTTrack_TripleMu_Mass", "Triple Mu Mass 2TkMuStubs&TTTrack", 100,0,10);
  TH1F *h_TkMuStubsTTTrackdR_mu12 = new TH1F("h_TkMuStubsTTTrackdR_mu12", "dR TkMuStub matched to TTTrack 1 & TkMuStub matched to TTTrack 2 after mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubsTTTrackdR_mu13 = new TH1F("h_TkMuStubsTTTrackdR_mu13", "dR TkMuStub matched to TTTrack 1 &  TTTrack 3 after mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubsTTTrackdR_mu23 = new TH1F("h_TkMuStubsTTTrackdR_mu23", "dR TkMuStub matched to TTTrack 2 & TTTrack 3 after mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubsTTTrackdR_mu12_BeforeMassCut = new TH1F("h_TkMuStubsTTTrackdR_mu12 before Mass cut", "dR TkMuStub matched to TTTrack 1 & TkMuStub matched to TTTrack 2 before mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubsTTTrackdR_mu13_BeforeMassCut = new TH1F("h_TkMuStubsTTTrackdR_mu13 before Mass cut", "dR TkMuStub matched to TTTrack 1 &  TTTrack 3 before mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubsTTTrackdR_mu23_BeforeMassCut = new TH1F("h_TkMuStubsTTTrackdR_mu23 before Mass cut", "dR TkMuStub matched to TTTrack 2 & TTTrack 3 before mass and dz cut", 100,0,1);

  TH1F *h_TkMuStubsTTTrackTau_pt = new TH1F("h_TkMuStubsTTTrackTau_pt", "pt of 2TkMuStub&TTTrack reconstr. tau", 100, 0,100);
  TH1F *h_TkMuStubsTTTrackTau_phi = new TH1F("h_TkMuStubsTTTrackTau_phi", "phi of 2TkMuStub&TTTrack reconstr. tau",  32,-3.20, 3.20);
  TH1F *h_TkMuStubsTTTrackTau_eta = new TH1F("h_TkMuStubsTTTrackTau_eta", "eta of 2TkMuStub&TTTrack reconstr. tau",  24, -3,  3);
  TH1F *h_TkMuStubsTTTrackTau_mass = new TH1F("h_TkMuStubsTTTrackTau_mass", "2TkMuStub+TTTrack Inv Mass of Tau", 100,0,3);
  TH1F *h_TkMuStubsTTTrackTau_pt_Bar = new TH1F("h_TkMuStubsTTTrackTau_pt_Bar", "pt of 2TkMuStub&TTTrack reconstr. tau barrel", 100,0,100);
  TH1F *h_TkMuStubsTTTrackTau_pt_Over = new TH1F("h_TkMuStubsTTTrackTau_pt_Over", "pt of 2TkMuStub&TTTrack reconstr. tau overlap", 100,0,100);
  TH1F *h_TkMuStubsTTTrackTau_pt_End = new TH1F("h_TkMuStubsTTTrackTau_pt_End", "pt of 2TkMuStub&TTTrack reconstr. tau endcap", 100,0,100);
  TH1F *h_TkMuStubsTTTrackLeadMuTau_pt = new TH1F("h_TkMuStubsTTTrackLeadMuTau_pt", "pt of Leading muon in 2TkMuStub&TTTrack reconstr. tau", 100,0,100);
  TH1F *h_TkMuStubsTTTrackSubleadMuTau_pt = new TH1F("h_TkMuStubsTTTrackSubleadMuTau_pt", "pt of Subeading muon in 2TkMuStub&TTTrack reconstr. tau", 100,0,100);
  TH1F *h_TkMuStubsTTTrackThirdMuTau_pt = new TH1F("h_TkMuStubsTTTrackThirdMuTau_pt", "pt of trailing muon in 2TkMuStub&TTTrack reconstr. tau", 100,0,100);

  TH1F *h_TkMuStubTTTracskdzVtx_max= new TH1F("h_TkMuStubTTTracskdzVtx_max", "max dZ between TkMuStub and TTTrack2 TTTrack3",100,0,5);
  TH1F *h_TkMuStubTTTracksdR_mu12_beforeMassCut= new TH1F("h_TkMuStubTTTracksdR_mu12_beforeMassCut", "dR between TkMuSTub matched to TTTrack 1 &  TTTrack 2",100,0,1);
  TH1F *h_TkMuStubTTTracksdR_mu13_beforeMassCut= new TH1F("h_TkMuStubTTTracksdR_mu13_beforeMassCut", "dR between TkMuSTub matched to TTTrack 1  &  TTTrack 3", 100,0,1);
  TH1F *h_TkMuStubTTTracksdR_mu23_beforeMassCut= new TH1F("h_TkMuStubTTTracksdR_mu23_beforeMassCut", "dR between TTTrack 2 &  TTTrack 3", 100,0,1);
  TH1F *h_TkMuStubTTTracksdR_mu12 = new TH1F("h_TkMuStubTTTracksdR_mu12", "dR TkMuStub matched to TTTrack 1 &  TTTrack 2 after mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubTTTracksdR_mu13 = new TH1F("h_TkMuStubTTTracksdR_mu13", "dR TkMuStub matched to TTTrack 1 &  TTTrack 3 after mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubTTTracksdR_mu23 = new TH1F("h_TkMuStubTTTracksdR_mu23", "dR  TTTrack 2 & TTTrack 3 after mass and dz cut", 100,0,1);
  TH1F *h_TkMuStubTTTracksTau_pt = new TH1F("h_TkMuStubTTTracksTau_pt", "pt of 1TkMuStub&2TTTrack reconstr. tau", 100, 0,100);
  TH1F *h_TkMuStubTTTracksTau_phi = new TH1F("h_TkMuStubTTTracksTau_phi", "phi of 1TkMuStub&2TTTrack reconstr. tau",  32,-3.20, 3.20);
  TH1F *h_TkMuStubTTTracksTau_eta = new TH1F("h_TkMuStubTTTracksTau_eta", "eta of 1TkMuStub&2TTTrack reconstr. tau",  24, -3,  3);
  TH1F *h_TkMuStubTTTracks_TripleMu_Mass = new TH1F("h_TkMuStubTTTracks_TripleMu_Mass", "1TkMuStub+2TTTrack Inv Mass of Tau", 100,0,10);
  TH1F *h_TkMuStubTTTracksTau_mass = new TH1F("h_TkMuStubTTTracksTau_mass", "Triple Mu mass after mass cut", 100, 0,3);

  TH1F *h_TkMuStubTTTracksLeadMuTau_pt = new TH1F("h_TkMuStubTTTracksLeadMuTau_pt", "pt of Leading muon in 1TkMuStub&2TTTrack reconstr. tau", 100,0,100);
  TH1F *h_TkMuStubTTTracksSubleadMuTau_pt = new TH1F("h_TkMuStubTTTracksSubleadMuTau_pt", "pt of Subeading muon in 1TkMuStub&2TTTrack reconstr. tau", 100,0,100);
  TH1F *h_TkMuStubTTTracksThirdMuTau_pt = new TH1F("h_TkMuStubTTTracksThirdMuTau_pt", "pt of trailing muon in 1TkMuStub&2TTTrack reconstr. tau", 100,0,100);



  TH1F *h_nL1Muons    = new TH1F("h_nL1Muons",   "nummber of L1 TPS Muons",    10, 0, 20);
  TH1F *h_L1MuPt      = new TH1F("h_L1MuPt",     "TkMUStub Muon Pt",                120, 0, 60);
  TH1F *h_L1MuEta     = new TH1F("h_L1MuEta",    "TkMuStub Muon Eta",                100,-5,  5);
  TH1F *h_L1MuPhi     = new TH1F("h_L1MuPhi",    "TkMuStub Muon Phi",                32,-3.20, 3.20);
  TH1F *h_L1MuCh      = new TH1F("h_L1MuCh",     "TkMuStub Muon Charge",             10,-2,  2);
  TH1F *h_L1MuzVtx   = new TH1F("h_L1MuzVtx", "L1 muon z Vtx", 30, -30, 30);
  //TH1F *h_L1gdR_mu11 = new TH1F("h_L1gdR_mu11", "L1gdR mu11 for efficiency not tau", 150,0,7);
  //TH1F *h_L1gdR_mu22 = new TH1F("h_L1gdR_mu22", "L1gdR mu22 for efficiency not tau", 150,0,7);
  //TH1F *h_L1gdR_mu33 = new TH1F("h_L1gdR_mu33", "L1gdR mu33 for efficiency not tau", 150,0,7);

  TH1F *h_mindPt_TkMuStub0_Gen = new TH1F("h_mindPt_TkMuStub0_Gen", "dPt Gen Mu0 and TkMuStubs", 100,0,10);
  TH1F *h_mindPt_TkMuStub1_Gen = new TH1F("h_mindPt_TkMuStub1_Gen", "dPt Gen Mu1 and TkMuStubs", 100,0,10);
  TH1F *h_mindPt_TkMuStub2_Gen = new TH1F("h_mindPt_TkMuStub2_Gen", "dPt Gen Mu2 and TkMuStubs", 100,0,10);
  TH1F *h_dR_TkMuStub0_Gen = new TH1F("h_dR_TkMuStub0_Gen", "dR Gen Mu0 and TkMuStubs", 100,0,5);
  TH1F *h_dR_TkMuStub1_Gen = new TH1F("h_dR_TkMuStub1_Gen", "dR Gen Mu1 and TkMuStubs", 100,0,5);
  TH1F *h_dR_TkMuStub2_Gen = new TH1F("h_dR_TkMuStub2_Gen", "dR Gen Mu2 and TkMuStubs", 100,0,5);


  TH1F *h_L1TriMuMass  = new TH1F("h_L1TriMuMass", "TriMuMass of TkMUStubs",        200, 0, 10);
  TH1F *h_L1dzVtx_12 = new TH1F("h_L1dzVtx_12", "dxVtx Mu1-Mu2 L1", 100, 0, 5);
  TH1F *h_L1dzVtx_13 = new TH1F("h_L1dzVtx_13", "dxVtx Mu1-Mu3 L1", 100, 0, 5);
  TH1F *h_L1dzVtx_23 = new TH1F("h_L1dzVtx_23", "dxVtx Mu2-Mu3 L1", 100, 0, 5);
  TH1F *h_L1dzVtx_max = new TH1F("h_L1dzVtx_max", "dxVtx L1 max", 100, 0, 5);
  TH1F *h_L1dzVtx_min = new TH1F("h_L1dzVtx_min", "dxVtx L1 min", 100, 0, 5);
  TH1F *h_L1dR_mu12_AfterMassCut  = new TH1F("h_L1dR_mu12",      "dR TkMuStub mu12 in tau cand",         50, 0, 1);
  TH1F *h_L1dR_mu13_AfterMassCut  = new TH1F("h_L1dR_mu13",      "dR TkMuStub mu13 in tau cand",         50, 0, 1);
  TH1F *h_L1dR_mu23_AfterMassCut  = new TH1F("h_L1dR_mu23",      "dR TkMuStub mu23 in tau cand",         50, 0, 1);
  TH1F *h_TkMuStub_dR12_beforeCut = new TH1F("h_TkMuStub_dR12_beforeCut", "dR TkMuStub mu12 before cut", 50,0,1);
  TH1F *h_TkMuStub_dR13_beforeCut = new TH1F("h_TkMuStub_dR13_beforeCut", "dR TkMuStub mu13 before cut", 50,0,1);
  TH1F *h_TkMuStub_dR23_beforeCut = new TH1F("h_TkMuStub_dR23_beforeCut", "dR TkMuStub mu23 before cut", 50,0,1);
  TH1F *h_ratio_TkMuStub0dPtOvPt = new TH1F("h_ratio_TkMuStub0dPtOvPt", "ratio mindPt TkMuStub 1 ov Pt GenMu1", 80,0,0.2);
  TH1F *h_ratio_TkMuStub1dPtOvPt = new TH1F("h_ratio_TkMuStub1dPtOvPt", "ratio mindPt TkMuStub 2 ov Pt GenMu2", 80,0,0.2);
  TH1F *h_ratio_TkMuStub2dPtOvPt = new TH1F("h_ratio_TkMuStub2dPtOvPt", "ratio mindPt TkMuStub 3 ov Pt GenMu3", 80,0,0.2);

  TH1F *h_TkMuStub1pt_barrel  = new TH1F("h_TkMuStub1pt_barrel", "TkMuStub 1 pt barrel", 100,0,100);
  TH1F *h_TkMuStub2pt_barrel  = new TH1F("h_TkMuStub2pt_barrel", "TkMuStub 2 pt barrel", 100,0,100);
  TH1F *h_TkMuStub3pt_barrel  = new TH1F("h_TkMuStub3pt_barrel", "TkMuStub 3 pt barrel", 100,0,100);
  TH1F *h_TkMuStub1pt_overlap  = new TH1F("h_TkMuStub1pt_overlap", "TkMuStub 1 pt overlap", 100,0,100);
  TH1F *h_TkMuStub2pt_overlap  = new TH1F("h_TkMuStub2pt_overlap", "TkMuStub 2 pt overlap", 100,0,100);
  TH1F *h_TkMuStub3pt_overlap  = new TH1F("h_TkMuStub3pt_overlap", "TkMuStub 3 pt overlap", 100,0,100);
  TH1F *h_TkMuStub1pt_endcap  = new TH1F("h_TkMuStub1pt_endcap", "TkMuStub 1 pt endcap", 100,0,100);
  TH1F *h_TkMuStub2pt_endcap  = new TH1F("h_TkMuStub2pt_endcap", "TkMuStub 2 pt endcap", 100,0,100);
  TH1F *h_TkMuStub3pt_endcap  = new TH1F("h_TkMuStub3pt_endcap", "TkMuStub 3 pt endcap", 100,0,100);


  TH1F *h_L1Tau_pt    = new TH1F("h_L1Tau_pt" ,  "L1Tau pt",                   100, 0, 100);
  TH1F *h_L1Tau_pt_Bar = new TH1F("h_L1Tau_pt_Bar" ,  "L1Tau pt Bar",             100, 0, 100);
  TH1F *h_L1Tau_pt_Over = new TH1F("h_L1Tau_pt_Over" ,  "L1Tau pt Over",           100, 0, 100);
  TH1F *h_L1Tau_pt_End = new TH1F("h_L1Tau_pt_End" ,  "L1Tau pt End",             100, 0, 100);
  TH1F *h_L1Tau_eta   = new TH1F("h_L1Tau_eta",  "L1Tau Eta",                   24, -3,  3);
  TH1F *h_L1Tau_phi   = new TH1F("h_L1Tau_phi",  "L1Tau Phi",          32,-3.20, 3.20);
  TH1F *h_L1Tau_mass  = new TH1F("h_L1Tau_mass", "L1 Tau mass",     100,1,3);
  TH1F *h_TkMuStubLeadPt = new TH1F("h_TkMuStubLeadPt", "TkMuSTub Tau Lead mu pt", 100,0,100);
  TH1F *h_TkMuStubSubLeadPt = new TH1F("h_TkMuStubSubLeadPt", "TkMuSTub Tau SubLead mu pt", 100,0,100);
  TH1F *h_TkMuStubThirdPt = new TH1F("h_TkMuStubThirdPt", "TkMuSTub Tau Third mu pt", 100,0,100);

  TH1F *h_L1LeadMuTau_pt    = new TH1F("h_L1LeadLepTau_pt", "h_L1LeadLepTau_pt", 120, 0, 60);
  TH1F *h_L1SubleadMuTau_pt = new TH1F("h_L1SubleadLepTau_pt", "h_L1SubleadLepTau_pt", 120, 0, 60);
  TH1F *h_L1ThirdMuTau_pt   = new TH1F("h_L1ThirdLepTau_pt", "h_L1ThirdLepTau_pt", 120, 0, 60);

  TH1F *h_TTTrackgdR       = new TH1F("h_TTTrackgdR",    "TTTrack-gen tau dR",         50, 0, 0.1);

  TH1F *h_nGTaus     = new TH1F("h_nGTaus",    "nummber of Gen Taus",      10, 0, 10);
  TH1F *h_nTTTrackTaus     = new TH1F("h_nTTTrackTaus",    "nummber of TTTrack Taus",      10, 0, 10);
  TH1F *h_nL1Taus     = new TH1F("h_nL1Taus",    "nummber of TkMuStub Taus",      10, 0, 10);

  Double_t mumass=0.10566,  genMatchCut=0.05,massCutLow=1.5,massCutHigh=2.2,maxdZ=1, dRcone_preMatch=0.2, mindPt=0.035, dRpairCut=0.3;

  bool  gPassedLead, gPassedSubLead, gPassedTrail, gMuSort_status_isLast,gPassedTTTrackLead, gPassedTTTrackSubLead, gPassedTTTrackTrail;
  Int_t   gMu1, gMu2, gMu3,igSort,iL1Sort,iTTTSort, minIdx_mu0_dPt, minIdx_mu1_dPt, minIdx_mu2_dPt, minIdx_gen1TTTrack, minIdx_gen2TTTrack, minIdx_gen3TTTrack, minIdxdPt_TTTrack1_TkMuStubs, minIdxdPt_TTTrack2_TkMuStubs, minIdxdPt_TTTrack3_TkMuStubs, nL1TPS_BMTFMuons, nL1TPS_OMTFMuons, nL1TPS_EMTFMuons,L1Ch_BMTF,L1Ch_OMTF, L1Ch_EMTF, mu3_PartParent, mu2_PartParent, mu1_PartParent, mu1_status, mu2_status, mu3_status, nTTTracks ;
  Short_t nGMuons, nGPart, gMuSort_Id, gPartId, gMuPartParent,gMuSort_PartParent, gMuSort_ch, gMuSort_status;
  Float_t  gen_tripleMuMass, gMuSort_pt, gMuSort_eta, gMuSort_phi, gMuSort_Vz, TTTrack_tripleMuMass, TTTracks_pt, TTTracks_pt_sort, TTTracks_eta, TTTrack_eta_sort, TTTracks_phi, TTTracks_phi_sort, TTTracks_chi2, TTTracks_chi2_sort, TTTracks_chi2bend, TTTracks_chi2bend_sort, TTTracks_z0, TTTracks_z0_sort, TTTrack_pt_sort, TTTrack_phi_sort, TTTrack_z0_sort, TTTrack_chi2_sort, TTTrack_chi2bend_sort, dPt_TTTrack1_TkMuStubs, dPt_TTTrack2_TkMuStubs, dPt_TTTrack3_TkMuStubs;
  Double_t TTTrackdzVtx_12, TTTrackdzVtx_23, TTTrackdzVtx_13, TkMuStubsTTTrackdzVtx_12, TkMuStubsTTTrackdzVtx_13, TkMuStubsTTTrackdzVtx_23, dPt_TTTrack_GenMu1, dPt_TTTrack_GenMu2, dPt_TTTrack_GenMu3, genTau_phi, genTau_eta, genTau_pt, genTau_mass, L1gdPhi_mu11, L1gdR_mu11 , L1gdPhi_mu22, L1gdR_mu22,  L1gdPhi_mu33, L1gdR_mu33,dPt_L1_GenMu0,dPt_L1_GenMu1,dPt_L1_GenMu2 , L1Pt_BMTF,L1Pt_OMTF, L1Pt_EMTF, L1Eta_BMTF, L1Eta_OMTF, L1Eta_EMTF, L1Phi_BMTF, L1Phi_OMTF, L1Phi_EMTF,L1zVtx_BMTF,L1zVtx_OMTF, L1zVtx_EMTF, L1_tripleMuMass, L1Tau_phi, L1Tau_eta, L1Tau_pt, L1Tau_mass, L1MuSort_eta, L1MuSort_phi, L1MuSort_ch, L1MuSort_zVtx, L1dzVtx_12, L1dzVtx_23, L1dzVtx_13, GendR_mu12, GendR_mu23, GendR_mu13, TTTrackTau_pt, TTTrackTau_eta, TTTrackTau_phi, TTTrackTau_mass, dR_TTTrack1_TkMuStubs, dR_TTTrack2_TkMuStubs, dPt_TkMuStub1_TTTrack3, dPt_TkMuStub2_TTTrack3,dPt_TkMuStub1_TTTrack2, TkMuStubsTTTrackTau_phi, TkMuStubsTTTrackTau_eta, TkMuStubsTTTrackTau_pt,TTTrackgdR_mu11,TTTrackgdR_mu22,TTTrackgdR_mu33, TkMuStubdR_mu12, TkMuStubdR_mu13, TkMuStubdR_mu23, TkMuStubTTTracksdzVtx_12, TkMuStubTTTracksdzVtx_13, TkMuStubTTTracksdzVtx_23, TkMuStubTTTracksdR_mu12_beforeMassCut, TkMuStubTTTracksdR_mu13_beforeMassCut, TkMuStubTTTracksdR_mu23_beforeMassCut, dR_L1Mu_GenMu0, dR_L1Mu_GenMu1, dR_L1Mu_GenMu2,  dR_TTTrack_GenMu1, dR_TTTrack_GenMu2, dR_TTTrack_GenMu3, TTTrackdR_mu12_beforeMassCut, TTTrackdR_mu13_beforeMassCut, TTTrackdR_mu23_beforeMassCut,  TTTrackdR_mu12, TTTrackdR_mu13, TTTrackdR_mu23, TkMuStubsTTTrackdR_mu12_beforeMassCut, TkMuStubsTTTrackdR_mu13_beforeMassCut, TkMuStubsTTTrackdR_mu23_beforeMassCut, TkMuStubsTTTrack_tripleMuMass, TkMuStubTTTracksTau_phi,TkMuStubTTTracksTau_eta, TkMuStubTTTracksTau_pt, TkMuStubTTTracks_tripleMuMass ;

  vector<bool> gPassed, gPassedEta, gPassedBarrel, gPassedOver, gPassedEnd, gPassed_TTTrack, vec_gMuStatus_isLast, vec_gMuStatus_isLast_sorted, gPassed_TkMuStubsTTTrack, gPassed_OR, gPassed_ORTkMuStubsTracks,gPassed_ORTkMuStubsTrack_Tracks,gPassed_TkMuStubTTTracks,gPassedeta_3TkMuStubs_10,gPassedeta_3Tracks_10,gPassedeta_2TkMuStubsTrack_10,gPassedeta_1TkMuStub2Tracks_10, gPassedeta_3TkMuStubs_15,gPassedeta_3Tracks_15,gPassedeta_2TkMuStubsTrack_15,gPassedeta_1TkMuStub2Tracks_15, gPassedeta_3TkMuStubs_20,gPassedeta_3Tracks_20,gPassedeta_2TkMuStubsTrack_20,gPassedeta_1TkMuStub2Tracks_20;
  vector<bool>  gPassed_3TkMuStubs_10, gPassed_3TkMuStubs_15, gPassed_3TkMuStubs_20, gPassed_3TkMuStubs_25,gPassed_3TkMuStubs_30,gPassed_3TkMuStubs_35,gPassed_3TkMuStubs_40;
  vector<bool>  gPassed_TTTrack_10, gPassed_TTTrack_12, gPassed_TTTrack_14, gPassed_TTTrack_16,gPassed_TTTrack_18,gPassed_TTTrack_20,gPassed_TTTrack_22,gPassed_TTTrack_24;
  vector<bool>  gPassed_TkMuStubsTTTrack_10, gPassed_TkMuStubsTTTrack_15, gPassed_TkMuStubsTTTrack_20, gPassed_TkMuStubsTTTrack_25,gPassed_TkMuStubsTTTrack_30,gPassed_TkMuStubsTTTrack_35,gPassed_TkMuStubsTTTrack_40;
  vector<bool>  gPassed_TkMuStubTTTracks_10, gPassed_TkMuStubTTTracks_12, gPassed_TkMuStubTTTracks_14, gPassed_TkMuStubTTTracks_16,gPassed_TkMuStubTTTracks_18,gPassed_TkMuStubTTTracks_20,gPassed_TkMuStubTTTracks_22,gPassed_TkMuStubTTTracks_24, gPassed_TkMuStubTTTracks_26,gPassed_TkMuStubTTTracks_28,gPassed_TkMuStubTTTracks_30,gPassed_TkMuStubTTTracks_32,gPassed_TkMuStubTTTracks_34,gPassed_TkMuStubTTTracks_36,gPassed_TkMuStubTTTracks_38,gPassed_TkMuStubTTTracks_40,gPassed_TkMuStubTTTracks_45;

  vector<int> g_Mu_ch, vec_TTTracks_qual, vec_TTTracks_gen_TP_ID, vec_genuineTrack_gen_TP_ID,vec_Idx_GenMu_Track1_dR0p2, vec_Idx_GenMu_Track2_dR0p2, vec_Idx_GenMu_Track3_dR0p2,vec_Idx_TkMuStub_TTTrack2_dR0p2,vec_Idx_TkMuStub_TTTrack1_dR0p2, vec_Idx_GenMu_TkMuStub0_dR0p2, vec_Idx_GenMu_TkMuStub1_dR0p2, vec_Idx_GenMu_TkMuStub2_dR0p2;
  vector<short> vec_gMuCh, vec_gMuCh_sorted, vec_gMuId, vec_gMuId_sorted, vec_gMuPartParent, vec_gMuPartParent_sorted, vec_gMuStatus, vec_gMuStatus_sorted, vec_L1MuCh, vec_L1MuCh_sorted, vec_sortgList, vec_sortTTTList, vec_sortL1List;
  vector<float> vec_gMuPt, vec_gMuPt_sorted, vec_gMuEta, vec_gMuEta_sorted,  vec_gMuPhi, vec_gMuPhi_sorted, vec_gMuVz, vec_gMuVz_sorted, vec_TTTracks_pt, vec_TTTracks_pt_sort, vec_genuineTrack_pt, vec_TTTracks_eta, vec_TTTracks_eta_sort,vec_genuineTrack_eta ,vec_TTTracks_phi,vec_genuineTrack_phi, vec_TTTracks_chi2, vec_genuineTrack_chi2,vec_TTTracks_chi2bend,vec_genuineTrack_chi2bend ,vec_TTTracks_z0, vec_genuineTrack_z0,  vec_TTTrackTauPt, vec_TTTrackTauM;
  vector<double> vec_gTauPt, vec_gTauEta, vec_gTauPhi, vec_gTauM,vec_dPt_TTTrack1_TkMuStubs, vec_dPt_TTTrack2_TkMuStubs, vec_dPt_TTTrack3_TkMuStubs, vec_L1MuPt, vec_L1MuPt_sorted, vec_L1MuEta, vec_L1MuEta_sorted,  vec_L1MuPhi, vec_L1MuPhi_sorted, vec_L1MuzVtx, vec_L1MuzVtx_sorted, vec_dPt_L1_GenMu0, vec_dPt_L1_GenMu1, vec_dPt_L1_GenMu2, vec_dz_TTTrack,vec_dz_TkMuStubsTTTrack, vec_dPt_TTTrack_GenMu2, vec_dPt_TTTrack_GenMu3,vec_dPt_TTTrack_GenMu1, vec_dz_TkMuStubTTTracks, vec_L1TauPt, vec_L1TauEta, vec_L1TauPhi, vec_L1TauM, vec_TkMuStubsTTTrackTauPt, vec_TkMuStubsTTTrackTauEta, vec_TkMuStubsTTTrackTauPhi, dR, vec_dR_L1MuGenMu0FromTau, vec_L1MuGenMu1FromTau, vec_L1MuGenMu2FromTau, vec_TTTracksGenMu3FromTau, vec_dz_L1,   vec_dR_TTTrack1_TkMuStubs, vec_dR_TTTrack2_TkMuStubs, vec_dR_TTTrack3_TkMuStubs , vec_TTTrackTauEta, vec_TTTrackTauPhi, vec_TkMuStubTTTracksTauPt;

  vector<TLorentzVector>  gen_Taus,   TkMuStubsTTTrack_Taus;

  TLorentzVector gen_mu1,gen_mu2,gen_mu3, L1_mu1,L1_mu1TT, L1_mu2TT, TTTrack_mu3, L1_mu2, L1_mu3, gentau_mu1, gentau_mu2, gentau_mu3, L1tau_mu1, L1tau_mu2, L1tau_mu3, vec_genTau, vec_L1Tau, gentau_mu1_m, gentau_mu2_m, gentau_mu3_m, L1tau_mu1_m, L1tau_mu2_m, L1tau_mu3_m, TTTrack_mu1, TTTrack_mu2, TkMuStubMatchTTTrack_mu1, TkMuStubMatchTTTrack_mu2,TTTrackComb_mu3, vec_TkMuStubsTTTrackTau, TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks, TTTrackComb_mu2_1TkMuStub2Tracks,TTTrackComb_mu3_1TkMuStub2Tracks;
  vector<vector<int>> gen_Tau_MuCh, L1_Tau_MuCh;

  TEfficiency *L1TauEff = new TEfficiency("L1TauEff",";P_{T}^{gen} (GeV);Efficiency",1,0,80);
  TEfficiency *L1TauEff_10 = new TEfficiency("L1TauEff_10",";P_{T}^{gen} (GeV);Efficiency L1 pt>10",1,0,80);
  TEfficiency *L1TauEff_15 = new TEfficiency("L1TauEff_15",";P_{T}^{gen} (GeV);Efficiency L1 pt>15",1,0,80);
  TEfficiency *L1TauEff_20 = new TEfficiency("L1TauEff_20",";P_{T}^{gen} (GeV);Efficiency L1 pt>20",1,0,80);
  TEfficiency *L1TauEff_25 = new TEfficiency("L1TauEff_25",";P_{T}^{gen} (GeV);Efficiency L1 pt>25",1,0,80);
  TEfficiency *L1TauEff_30 = new TEfficiency("L1TauEff_30",";P_{T}^{gen} (GeV);Efficiency L1 pt>30",1,0,80);
  TEfficiency *L1TauEff_35 = new TEfficiency("L1TauEff_35",";P_{T}^{gen} (GeV);Efficiency L1 pt>35",1,0,80);
  TEfficiency *L1TauEff_40 = new TEfficiency("L1TauEff_40",";P_{T}^{gen} (GeV);Efficiency L1 pt>40",1,0,80);
  TEfficiency *L1TauEff_HighPt = new TEfficiency("L1TauEff_HighPt",";P_{T}^{gen} (GeV);Efficiency",20,0,80);

  TEfficiency *TTTrackTauEff = new TEfficiency("TTTrackTauEff", ";P_{T}^{gen} (GeV);Efficiency",1,0,80);
  TEfficiency *TTTrackTauEff_10 = new TEfficiency("TTTrackTauEff_10",";P_{T}^{gen} (GeV);Efficiency L1 pt>10",1,0,80);
  TEfficiency *TTTrackTauEff_12 = new TEfficiency("TTTrackTauEff_12",";P_{T}^{gen} (GeV);Efficiency L1 pt>12",1,0,80);
  TEfficiency *TTTrackTauEff_14 = new TEfficiency("TTTrackTauEff_14",";P_{T}^{gen} (GeV);Efficiency L1 pt>14",1,0,80);
  TEfficiency *TTTrackTauEff_16 = new TEfficiency("TTTrackTauEff_16",";P_{T}^{gen} (GeV);Efficiency L1 pt>16",1,0,80);
  TEfficiency *TTTrackTauEff_18 = new TEfficiency("TTTrackTauEff_18",";P_{T}^{gen} (GeV);Efficiency L1 pt>18",1,0,80);
  TEfficiency *TTTrackTauEff_20 = new TEfficiency("TTTrackTauEff_20",";P_{T}^{gen} (GeV);Efficiency L1 pt>20",1,0,80);
  TEfficiency *TTTrackTauEff_22 = new TEfficiency("TTTrackTauEff_22",";P_{T}^{gen} (GeV);Efficiency L1 pt>22",1,0,80);
  TEfficiency *TTTrackTauEff_24 = new TEfficiency("TTTrackTauEff_24",";P_{T}^{gen} (GeV);Efficiency L1 pt>24",1,0,80);
  TEfficiency *TTTrackTauEff_HighPt = new TEfficiency("TTTrackTauEff_HighPt", ";P_{T}^{gen} (GeV);Efficiency",20,0,80);

  TEfficiency *TkMuStubsTTTrackTauEff = new TEfficiency("TkMuStubsTTTrackTauEff", ";P_{T}^{gen} (GeV);Efficiency",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_10 = new TEfficiency("TkMuStubsTTTrackTauEff_10",";P_{T}^{gen} (GeV);Efficiency L1 pt>10",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_15 = new TEfficiency("TkMuStubsTTTrackTauEff_15",";P_{T}^{gen} (GeV);Efficiency L1 pt>15",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_20 = new TEfficiency("TkMuStubsTTTrackTauEff_20",";P_{T}^{gen} (GeV);Efficiency L1 pt>20",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_25 = new TEfficiency("TkMuStubsTTTrackTauEff_25",";P_{T}^{gen} (GeV);Efficiency L1 pt>25",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_30 = new TEfficiency("TkMuStubsTTTrackTauEff_30",";P_{T}^{gen} (GeV);Efficiency L1 pt>30",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_35 = new TEfficiency("TkMuStubsTTTrackTauEff_35",";P_{T}^{gen} (GeV);Efficiency L1 pt>35",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_40 = new TEfficiency("TkMuStubsTTTrackTauEff_40",";P_{T}^{gen} (GeV);Efficiency L1 pt>40",1,0,80);
  TEfficiency *TkMuStubsTTTrackTauEff_HighPt = new TEfficiency("TkMuStubsTTTrackTauEff_HighPt", ";P_{T}^{gen} (GeV);Efficiency",20,0,80);

  TEfficiency *TkMu1Stub2TTTrackTauEff = new TEfficiency("1TkMuStub2TTTrackTauEff", ";P_{T}^{gen} (GeV);Efficiency",1,0,100);
  TEfficiency *TkMu1Stub2TTTrackTauEff_10 = new TEfficiency("1TkMuStubs2TTTrackTauEff_10",";P_{T}^{gen} (GeV);Efficiency L1 pt>10",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_12 = new TEfficiency("1TkMuStubs2TTTrackTauEff_12",";P_{T}^{gen} (GeV);Efficiency L1 pt>12",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_14 = new TEfficiency("1TkMuStubs2TTTrackTauEff_14",";P_{T}^{gen} (GeV);Efficiency L1 pt>14",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_16 = new TEfficiency("1TkMuStubs2TTTrackTauEff_16",";P_{T}^{gen} (GeV);Efficiency L1 pt>16",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_18 = new TEfficiency("1TkMuStubs2TTTrackTauEff_18",";P_{T}^{gen} (GeV);Efficiency L1 pt>18",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_20 = new TEfficiency("1TkMuStubs2TTTrackTauEff_20",";P_{T}^{gen} (GeV);Efficiency L1 pt>20",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_22 = new TEfficiency("1TkMuStubs2TTTrackTauEff_22",";P_{T}^{gen} (GeV);Efficiency L1 pt>22",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_24 = new TEfficiency("1TkMuStubs2TTTrackTauEff_24",";P_{T}^{gen} (GeV);Efficiency L1 pt>24",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_26 = new TEfficiency("1TkMuStubs2TTTrackTauEff_26",";P_{T}^{gen} (GeV);Efficiency L1 pt>26",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_28 = new TEfficiency("1TkMuStubs2TTTrackTauEff_28",";P_{T}^{gen} (GeV);Efficiency L1 pt>28",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_30 = new TEfficiency("1TkMuStubs2TTTrackTauEff_30",";P_{T}^{gen} (GeV);Efficiency L1 pt>30",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_32 = new TEfficiency("1TkMuStubs2TTTrackTauEff_32",";P_{T}^{gen} (GeV);Efficiency L1 pt>32",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_34 = new TEfficiency("1TkMuStubs2TTTrackTauEff_34",";P_{T}^{gen} (GeV);Efficiency L1 pt>34",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_36 = new TEfficiency("1TkMuStubs2TTTrackTauEff_36",";P_{T}^{gen} (GeV);Efficiency L1 pt>36",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_38 = new TEfficiency("1TkMuStubs2TTTrackTauEff_38",";P_{T}^{gen} (GeV);Efficiency L1 pt>38",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_40 = new TEfficiency("1TkMuStubs2TTTrackTauEff_40",";P_{T}^{gen} (GeV);Efficiency L1 pt>40",80,0,80);
  TEfficiency *TkMu1Stub2TTTrackTauEff_45 = new TEfficiency("1TkMuStubs2TTTrackTauEff_45",";P_{T}^{gen} (GeV);Efficiency L1 pt>45",80,0,80);

  TEfficiency *TkMu1Stub2TTTrackTauEff_HighPt = new TEfficiency("1TkMuStub2TTTrackTauEff_HighPt", ";P_{T}^{gen} (GeV);Efficiency",20,0,80);

  TEfficiency *TkMuStubsOR2TkMuStubsTrack_High = new TEfficiency("TkMuStubsOR2TkMuStubsTrack_High", "P_{T}^{gen} (GeV);Efficiency",20,0,80);
  TEfficiency *TkMuStubsOR2TkMuStubsTrack = new TEfficiency("TkMuStubsOR2TkMuStubsTrack", "P_{T}^{gen} (GeV);Efficiency",1,0,80);


  TEfficiency *L13TkMuStubs_eta_10 = new TEfficiency("L13TkMuStubs_eta_10",";#eta^{gen} ;Efficiency",20,-2.5,2.5);
  TEfficiency *L13Tracks_eta_10 = new TEfficiency("L13Tracks_eta_10", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);
  TEfficiency *L12TkMuStubsTrack_eta_10 = new TEfficiency("L12TkMuStubTrack_eta_10", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);
  TEfficiency *L11TkMuStub2Tracks_eta_10 = new TEfficiency("L11TkMuStub2Tracks_eta_10", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);

  TEfficiency *L13TkMuStubs_eta_15 = new TEfficiency("L13TkMuStubs_eta_15",";#eta^{gen} ;Efficiency",20,-2.5,2.5);
  TEfficiency *L13Tracks_eta_15 = new TEfficiency("L13Tracks_eta_15", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);
  TEfficiency *L12TkMuStubsTrack_eta_15 = new TEfficiency("L12TkMuStubTrack_eta_15", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);
  TEfficiency *L11TkMuStub2Tracks_eta_15 = new TEfficiency("L11TkMuStub2Tracks_eta_15", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);

  TEfficiency *L13TkMuStubs_eta_20 = new TEfficiency("L13TkMuStubs_eta_20",";#eta^{gen} ;Efficiency",20,-2.5,2.5);
  TEfficiency *L13Tracks_eta_20 = new TEfficiency("L13Tracks_eta_20", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);
  TEfficiency *L12TkMuStubsTrack_eta_20 = new TEfficiency("L12TkMuStubTrack_eta_20", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);
  TEfficiency *L11TkMuStub2Tracks_eta_20 = new TEfficiency("L11TkMuStub2Tracks_eta_20", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);

  TEfficiency *L13TkMuStubs_eta_25 = new TEfficiency("L13TkMuStubs_eta_25",";#eta^{gen} ;Efficiency",20,-2.5,2.5);
  TEfficiency *L12TkMuStubsTrack_eta_25 = new TEfficiency("L12TkMuStubTrack_eta_25", ";#eta^{gen}; Efficiency", 20, -2.5,2.5);

  TEfficiency *L13TkMuStubs_eta_30 = new TEfficiency("L13TkMuStubs_eta_30",";#eta^{gen} ;Efficiency",20,-2.5,2.5);
  TEfficiency *L12TkMuStubsTrack_eta_30 = new TEfficiency("L12TkMuStubs_eta_30",";#eta^{gen} ;Efficiency",20,-2.5,2.5);

  TEfficiency *L1LeadEff = new TEfficiency("L1LeadEff", ";P_{T}^{gen};Efficiency",30,0,60);
  TEfficiency *L1SubLeadEff = new TEfficiency("L1SubLeadEff", ";P_{T}^{gen};Efficiency",30,0,60);
  TEfficiency *L1TrailEff = new TEfficiency("L1TrailEff", ";P_{T}^{gen};Efficiency",30,0,60);

  TEfficiency *TTTrackLeadEff = new TEfficiency("TTTrackLeadEff", ";P_{T}^{gen};Efficiency",30,0,60);
  TEfficiency *TTTrackSubLeadEff = new TEfficiency("TTTrackSubLeadEff", ";P_{T}^{gen};Efficiency",30,0,60);
  TEfficiency *TTTrackTrailEff = new TEfficiency("TTTrackTrailEff", ";P_{T}^{gen};Efficiency",30,0,60);
  TEfficiency *TkMuStubsOR3Tracks = new TEfficiency("TkMuStubsOR3Tracks", "P_{T}^{gen} (GeV);Efficiency",1,0,100);
  TEfficiency *TkMuStubsOR3Tracks_High = new TEfficiency("TkMuStubsOR3Tracks_High", "P_{T}^{gen} (GeV);Efficiency",25,0,100);
  TEfficiency *TkMuStubTrackOR3Tracks = new TEfficiency("TkMuStubTrackOR3Tracks", "P_{T}^{gen} (GeV);Efficiency",1,0,100);
  TEfficiency *TkMuStubTrackOR3Tracks_High = new TEfficiency("TkMuStubTrackOR3Tracks_High", "P_{T}^{gen} (GeV);Efficiency",25,0,100);


  TH1F *h_Rate = new TH1F("h_Rate","Rate",   25,0,50);

  L1TauEff->SetStatisticOption(TEfficiency::kFCP);
  L1TauEff_10->SetStatisticOption(TEfficiency::kFCP);
  L1TauEff_15->SetStatisticOption(TEfficiency::kFCP);
  L1TauEff_20->SetStatisticOption(TEfficiency::kFCP);
  L1TauEff_25->SetStatisticOption(TEfficiency::kFCP);
  L1TauEff_30->SetStatisticOption(TEfficiency::kFCP);
  L1TauEff_35->SetStatisticOption(TEfficiency::kFCP);
  L1TauEff_40->SetStatisticOption(TEfficiency::kFCP);

  TTTrackTauEff->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_10->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_12->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_14->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_16->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_18->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_20->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_22->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_24->SetStatisticOption(TEfficiency::kFCP);

  TkMuStubsTTTrackTauEff->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_10->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_15->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_20->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_25->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_30->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_35->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_40->SetStatisticOption(TEfficiency::kFCP);

  TkMu1Stub2TTTrackTauEff->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_10->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_12->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_14->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_16->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_18->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_20->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_22->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_24->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_26->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_28->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_30->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_32->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_34->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_36->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_38->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_40->SetStatisticOption(TEfficiency::kFCP);
  TkMu1Stub2TTTrackTauEff_45->SetStatisticOption(TEfficiency::kFCP);

  L1TauEff_HighPt->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTauEff_HighPt->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsTTTrackTauEff_HighPt->SetStatisticOption(TEfficiency::kFCP);

  L1LeadEff->SetStatisticOption(TEfficiency::kFCP);
  L1SubLeadEff->SetStatisticOption(TEfficiency::kFCP);
  L1TrailEff->SetStatisticOption(TEfficiency::kFCP);
  TTTrackLeadEff->SetStatisticOption(TEfficiency::kFCP);
  TTTrackSubLeadEff->SetStatisticOption(TEfficiency::kFCP);
  TTTrackTrailEff->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsOR2TkMuStubsTrack_High ->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsOR2TkMuStubsTrack->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsOR3Tracks->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubsOR3Tracks_High->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubTrackOR3Tracks->SetStatisticOption(TEfficiency::kFCP);
  TkMuStubTrackOR3Tracks_High->SetStatisticOption(TEfficiency::kFCP);

  TkMu1Stub2TTTrackTauEff_HighPt->SetStatisticOption(TEfficiency::kFCP);
  L13TkMuStubs_eta_10->SetStatisticOption(TEfficiency::kFCP);
  L13Tracks_eta_10->SetStatisticOption(TEfficiency::kFCP);
  L12TkMuStubsTrack_eta_10 ->SetStatisticOption(TEfficiency::kFCP);
  L11TkMuStub2Tracks_eta_10->SetStatisticOption(TEfficiency::kFCP);
  L13TkMuStubs_eta_15->SetStatisticOption(TEfficiency::kFCP);
  L13Tracks_eta_15->SetStatisticOption(TEfficiency::kFCP);
  L12TkMuStubsTrack_eta_15 ->SetStatisticOption(TEfficiency::kFCP);
  L11TkMuStub2Tracks_eta_15->SetStatisticOption(TEfficiency::kFCP);
  L13TkMuStubs_eta_20->SetStatisticOption(TEfficiency::kFCP);
  L13Tracks_eta_20->SetStatisticOption(TEfficiency::kFCP);
  L12TkMuStubsTrack_eta_20 ->SetStatisticOption(TEfficiency::kFCP);
  L11TkMuStub2Tracks_eta_20->SetStatisticOption(TEfficiency::kFCP);
  L13TkMuStubs_eta_25->SetStatisticOption(TEfficiency::kFCP);
  L13TkMuStubs_eta_30->SetStatisticOption(TEfficiency::kFCP);
  L12TkMuStubsTrack_eta_25 ->SetStatisticOption(TEfficiency::kFCP);
  L12TkMuStubsTrack_eta_30 ->SetStatisticOption(TEfficiency::kFCP);
  }

 float dPhi(float_t phi1, float_t phi2){
   float_t dphi =  phi1-phi2;
   if (dphi < -TMath::Pi()) dphi += TMath::TwoPi();
   if (dphi >  TMath::Pi()) dphi -= TMath::TwoPi();
   return dphi;
 }

float dR_calc (float_t eta1,float_t phi1,float_t eta2,float_t phi2)
     {
      float_t dphi = dPhi(phi1, phi2);
      float_t deta = eta1-eta2;
      float_t dr = TMath::Sqrt(deta*deta+dphi*dphi);
      return dr;
}

float dEta_calc (float_t eta1, float_t eta2)
       {
        float_t deta = eta1-eta2;
        return deta;
       }


int Find_Idx(vector<int> vec1, Int_t minIdx1, vector<int> vec2, Int_t minIdx2){
                if (std::find(vec1.begin(), vec1.end(), vec2.at(minIdx2))!= vec1.end()){
                    std::vector<int>::iterator it =  std::find(vec1.begin(), vec1.end(), vec2.at(minIdx2));
                    return (std::distance(std::begin(vec1), it));
                   }
                 else {
                   return minIdx1;}
}

void anaTau(float_t L1_LeadPtCut,float_t L1_SubLeadPtCut,float_t L1_TrailPtCut,  float_t Gen_LeadPtCut, float_t Gen_SubLeadPtCut, float_t Gen_TrailPtCut,  float_t L1MuonEta_Min, float_t L1MuonEta_Max, float_t GenMuonEta_Min, float_t GenMuonEta_Max, float_t dRCut){

    for (Int_t i=0; i<nevents; i++)
    {
      mytree -> GetEntry(i);
      unordered_set <int>  doup_gen1, doup_gen2, doup_gen3, doup_genTot;

      gPassedLead=0;
      gPassedSubLead=0;
      gPassedTrail=0;
      gPassedTTTrackLead=0;
      gPassedTTTrackSubLead=0;
      gPassedTTTrackTrail=0;
      Int_t countL1TkMuStubMuons=0;


      nGMuons = 0;
      nGPart = genpart_Npart;
      vec_gMuPt.clear();
      vec_gMuPt_sorted.clear();
      vec_gMuId.clear();
      vec_gMuId_sorted.clear();
      vec_gMuPartParent.clear();
      vec_gMuPartParent_sorted.clear();
      vec_gMuEta.clear();
      vec_gMuEta_sorted.clear();
      vec_gMuPhi.clear();
      vec_gMuPhi_sorted.clear();
      vec_gMuCh.clear();
      vec_gMuCh_sorted.clear();
      vec_gMuVz.clear();
      vec_gMuVz_sorted.clear();
      vec_gMuStatus.clear();
      vec_gMuStatus_sorted.clear();
      vec_gMuStatus_isLast.clear();
      vec_gMuStatus_isLast_sorted.clear();
      vec_sortgList.clear();

      for(Int_t j=0; j<nGPart; j++){
          gPartId = genpart_id->at(j);
          if (abs(gPartId) == 13 ){
             vec_gMuPt.push_back(genpart_pt->at(j));
             vec_gMuPt_sorted.push_back(genpart_pt->at(j));
             vec_gMuEta.push_back(genprt_eta->at(j));
             vec_gMuId.push_back(genpart_id->at(j));
             vec_gMuPhi.push_back(genpart_phi->at(j));
             vec_gMuVz.push_back(genpart_Vz->at(j));
             vec_gMuPartParent.push_back(genpart_parent->at(j));
             vec_gMuCh.push_back(genpart_charge->at(j));
             vec_gMuStatus.push_back(genpart_status->at(j));
             vec_gMuStatus_isLast.push_back(genpart_status_isLast->at(j));

             h_gMuPt->Fill(genpart_pt->at(j));
             h_gMuId->Fill(fabs(genpart_id->at(j)));
             h_gMuEta->Fill(genprt_eta->at(j));
             h_gMuPhi->Fill(genpart_phi->at(j));
             h_gMuPartParent->Fill(fabs(genpart_parent->at(j)));
             nGMuons ++;
          }}

          h_nGMuons->Fill(nGMuons);

          std::sort(vec_gMuPt_sorted.begin(),vec_gMuPt_sorted.end());
          std::reverse(vec_gMuPt_sorted.begin(),vec_gMuPt_sorted.end());
          vec_sortgList.clear();

          for(Int_t j=0; j<vec_gMuPt_sorted.size(); j++)
            {
              for(Int_t k=0; k<vec_gMuPt_sorted.size(); k++)
               {
                 if(vec_gMuPt.at(k)==vec_gMuPt_sorted.at(j)) vec_sortgList.push_back(k);
               }
            }

          for (Int_t j=0; j<vec_gMuPt_sorted.size(); j++){
                igSort = vec_sortgList.at(j);
                gMuSort_pt  = vec_gMuPt_sorted.at(j);
                gMuSort_eta = vec_gMuEta.at(igSort);
                gMuSort_phi = vec_gMuPhi.at(igSort);
                gMuSort_Vz  = vec_gMuVz.at(igSort);
                gMuSort_Id  = vec_gMuId.at(igSort);
                gMuSort_PartParent = vec_gMuPartParent.at(igSort);
                gMuSort_ch = vec_gMuCh.at(igSort);
                gMuSort_status = vec_gMuStatus.at(igSort);
                gMuSort_status_isLast = vec_gMuStatus_isLast.at(igSort);
    
                vec_gMuEta_sorted.push_back(gMuSort_eta);
                vec_gMuPhi_sorted.push_back(gMuSort_phi);
                vec_gMuVz_sorted.push_back(gMuSort_Vz);
                vec_gMuId_sorted.push_back(gMuSort_Id);
                vec_gMuPartParent_sorted.push_back(gMuSort_PartParent);
                vec_gMuCh_sorted.push_back(gMuSort_ch );
                vec_gMuStatus_sorted.push_back(gMuSort_status);
                vec_gMuStatus_isLast_sorted.push_back(gMuSort_status_isLast);
     
                if(abs(gMuSort_eta)<=2.4)h_gMuPt_sort->Fill(vec_gMuPt_sorted.at(j));
                if(abs(gMuSort_eta)<0.8 && abs(gMuSort_eta)>=0) h_gMuPt_Bar->Fill(vec_gMuPt_sorted.at(j));
                if(abs(gMuSort_eta)<1.2 && abs(gMuSort_eta)>=0.8) h_gMuPt_Over->Fill(vec_gMuPt_sorted.at(j));
                if(abs(gMuSort_eta)<=2.4 && abs(gMuSort_eta)>=1.24) h_gMuPt_End->Fill(vec_gMuPt_sorted.at(j));
             }

          //Choose gen muons coming from taus
           gMu1=0;
           gMu2=0;
           gMu3=0;
           gen_Taus.clear();
           gen_Tau_MuCh.clear();
           if (nGMuons>=3){
              for (Int_t j=0; j<nGMuons; j++){
                 gen_mu1.SetPtEtaPhiM(vec_gMuPt_sorted.at(j),vec_gMuEta_sorted.at(j),vec_gMuPhi_sorted.at(j),mumass);
                 mu1_PartParent = vec_gMuPartParent_sorted.at(j);
                 mu1_status = vec_gMuStatus_sorted.at(j);
                 for(Int_t k=j+1; k<nGMuons; k++){
                   gen_mu2.SetPtEtaPhiM(vec_gMuPt_sorted.at(k),vec_gMuEta_sorted.at(k),vec_gMuPhi_sorted.at(k),mumass);
                   mu2_PartParent = vec_gMuPartParent_sorted.at(k);
                   mu2_status = vec_gMuStatus_sorted.at(k);
                   for (Int_t l=k+1; l<nGMuons; l++){
                     gen_mu3.SetPtEtaPhiM(vec_gMuPt_sorted.at(l),vec_gMuEta_sorted.at(l),vec_gMuPhi_sorted.at(l),mumass);
                     mu3_PartParent = vec_gMuPartParent_sorted.at(l);
                     mu3_status = vec_gMuStatus_sorted.at(l);
                     gen_tripleMuMass = (gen_mu1+gen_mu2+gen_mu3).M();                     
                     h_gTriMuMass->Fill(gen_tripleMuMass);
                     h_gTripleMuPt->Fill((gen_mu1+gen_mu2+gen_mu3).Pt());
                     if (mu1_status==1 && mu2_status==1 && mu3_status==1){
                       if(fabs(gen_mu1.Eta())<2.4 && fabs(gen_mu2.Eta())<2.4 && fabs(gen_mu3.Eta())<2.4){
                           if ((abs(mu1_PartParent) == 15 || abs(mu1_PartParent) == 13) && (abs(mu2_PartParent)==15 || abs(mu2_PartParent) == 13) && (abs(mu3_PartParent)==15 || abs(mu3_PartParent) == 13)){
                          h_genmu1Pt->Fill(gen_mu1.Pt());
                          h_genmu2Pt->Fill(gen_mu2.Pt());
                          h_genmu3Pt->Fill(gen_mu3.Pt());
                          if (fabs(gen_mu1.Eta())>0 && fabs(gen_mu1.Eta())<0.8)h_genMu1_barrel->Fill(gen_mu1.Pt());
                          if (fabs(gen_mu2.Eta())>0 && fabs(gen_mu2.Eta())<0.8)h_genMu2_barrel->Fill(gen_mu2.Pt());
                          if (fabs(gen_mu3.Eta())>0 && fabs(gen_mu3.Eta())<0.8)h_genMu3_barrel->Fill(gen_mu3.Pt());
                          if (fabs(gen_mu1.Eta())>0.8 && fabs(gen_mu1.Eta())<1.2)h_genMu1_overlap->Fill(gen_mu1.Pt());
                          if (fabs(gen_mu2.Eta())>0.8 && fabs(gen_mu2.Eta())<1.2)h_genMu2_overlap->Fill(gen_mu2.Pt());
                          if (fabs(gen_mu3.Eta())>0.8 && fabs(gen_mu3.Eta())<1.2)h_genMu3_overlap->Fill(gen_mu3.Pt());
                          if (fabs(gen_mu1.Eta())>1.2 && fabs(gen_mu1.Eta())<2.4)h_genMu1_endcap->Fill(gen_mu1.Pt());
                          if (fabs(gen_mu2.Eta())>1.2 && fabs(gen_mu2.Eta())<2.4)h_genMu2_endcap->Fill(gen_mu2.Pt());
                          if (fabs(gen_mu3.Eta())>1.2 && fabs(gen_mu3.Eta())<2.4)h_genMu3_endcap->Fill(gen_mu3.Pt());

                         if ((gen_mu1.Pt()>Gen_LeadPtCut && gen_mu2.Pt()>Gen_SubLeadPtCut && gen_mu3.Pt()>Gen_TrailPtCut)){ 
                              g_Mu_ch.clear();
                              gMu1=j;
                              gMu2=k;
                              gMu3=l;
                              //Make a TVector3 with the muon indicies
                              vec_genTau.SetVect(TVector3(j,k,l));
                              //Do not save taus containing the same muons
                             if (doup_gen1.find(j) == doup_gen1.end() && doup_gen2.find(k) == doup_gen2.end() && doup_gen3.find(l) == doup_gen3.end() && doup_genTot.find(j) == doup_genTot.end() && doup_genTot.find(k) == doup_genTot.end() && doup_genTot.find(l) == doup_genTot.end()) {
                              gen_Taus.push_back(vec_genTau);
                              g_Mu_ch.push_back(vec_gMuCh_sorted.at(j));
                              g_Mu_ch.push_back(vec_gMuCh_sorted.at(k));
                              g_Mu_ch.push_back(vec_gMuCh_sorted.at(l));
                              doup_gen1.insert(j);
                              doup_gen2.insert(k);
                              doup_gen3.insert(l);
                              doup_genTot.insert(j);
                              doup_genTot.insert(k);
                              doup_genTot.insert(l);
                              goto ExitLoops;
                              }}}}}}}}}

           ExitLoops: 
           h_nGTaus->Fill(gen_Taus.size());

           vec_gTauPt.clear();
           vec_gTauEta.clear();
           vec_gTauPhi.clear();
           vec_gTauM.clear();
           
           // For all the gen taus in the event, make 4vectors
           if (gen_Taus.size()==1) {
                gentau_mu1.SetPtEtaPhiM(vec_gMuPt_sorted.at(gen_Taus.at(0)(0)),vec_gMuEta_sorted.at(gen_Taus.at(0)(0)),vec_gMuPhi_sorted.at(gen_Taus.at(0)(0)),mumass);
                gentau_mu2.SetPtEtaPhiM(vec_gMuPt_sorted.at(gen_Taus.at(0)(1)),vec_gMuEta_sorted.at(gen_Taus.at(0)(1)),vec_gMuPhi_sorted.at(gen_Taus.at(0)(1)),mumass);
                gentau_mu3.SetPtEtaPhiM(vec_gMuPt_sorted.at(gen_Taus.at(0)(2)),vec_gMuEta_sorted.at(gen_Taus.at(0)(2)),vec_gMuPhi_sorted.at(gen_Taus.at(0)(2)),mumass);
     
                h_genLeadMuTau_pt->Fill(gentau_mu1.Pt());
                h_genSubleadMuTau_pt->Fill(gentau_mu2.Pt());
                h_genThirdMuTau_pt->Fill(gentau_mu3.Pt());
     
                GendR_mu12 = dR_calc(gentau_mu1.Eta(), gentau_mu1.Phi(), gentau_mu2.Eta(), gentau_mu2.Phi());
                GendR_mu13 = dR_calc(gentau_mu1.Eta(), gentau_mu1.Phi(), gentau_mu3.Eta(), gentau_mu3.Phi());
                GendR_mu23 = dR_calc(gentau_mu2.Eta(), gentau_mu2.Phi(), gentau_mu3.Eta(), gentau_mu3.Phi());
      
                h_gTauMudR_mu12->Fill(GendR_mu12);
                h_gTauMudR_mu13->Fill(GendR_mu13);
                h_gTauMudR_mu23->Fill(GendR_mu23);
     
                //// Calculate gen tau properties
                genTau_phi  = (gentau_mu1+gentau_mu2+gentau_mu3).Phi();
                genTau_eta  = (gentau_mu1+gentau_mu2+gentau_mu3).Eta();
                genTau_pt   = (gentau_mu1+gentau_mu2+gentau_mu3).Pt();
                genTau_mass = (gentau_mu1+gentau_mu2+gentau_mu3).M();
     
                vec_gTauPt.push_back(genTau_pt);
                vec_gTauEta.push_back(genTau_eta);
                vec_gTauPhi.push_back(genTau_phi);
                vec_gTauM.push_back(genTau_mass);
     
                h_genTau_phi->Fill(genTau_phi);
                h_genTau_eta->Fill(genTau_eta);
                h_genTau_pt->Fill(genTau_pt);     
                if (abs(genTau_eta)<0.8 && abs(genTau_eta)>=0) h_genTau_pt_Bar->Fill(genTau_pt);
                if (abs(genTau_eta)<1.2 && abs(genTau_eta)>=0.8) h_genTau_pt_Over->Fill(genTau_pt);
                if (abs(genTau_eta)<=2.4 && abs(genTau_eta)>=1.2) h_genTau_pt_End->Fill(genTau_pt);
                }

           nL1TPS_BMTFMuons = tkmuStubsBMTF_Nmuons;
           nL1TPS_OMTFMuons = tkmuStubsOMTF_Nmuons;
           nL1TPS_EMTFMuons = tkmuStubsEMTF_Nmuons;
           vec_L1MuPt.clear();
           vec_L1MuPt_sorted.clear();
           vec_L1MuEta.clear();
           vec_L1MuEta_sorted.clear();
           vec_L1MuPhi.clear();
           vec_L1MuPhi_sorted.clear();
           vec_L1MuCh.clear();
           vec_L1MuCh_sorted.clear();
           vec_L1MuzVtx.clear();
           vec_L1MuzVtx_sorted.clear();
  
          for (Int_t j=0; j<nL1TPS_BMTFMuons; j++){
              L1Pt_BMTF=tkmuStubsBMTF_pt->at(j);
              L1Eta_BMTF=tkmuStubsBMTF_eta->at(j);
              L1Phi_BMTF=tkmuStubsBMTF_phi->at(j);
              L1Ch_BMTF=tkmuStubsBMTF_charge->at(j);
              L1zVtx_BMTF=tkmuStubsBMTF_Vz->at(j);
              vec_L1MuPt.push_back(L1Pt_BMTF);
              vec_L1MuPt_sorted.push_back(L1Pt_BMTF);
              vec_L1MuEta.push_back(L1Eta_BMTF);
              vec_L1MuPhi.push_back(L1Phi_BMTF);
              vec_L1MuCh.push_back(L1Ch_BMTF);
              vec_L1MuzVtx.push_back(L1zVtx_BMTF);
              countL1TkMuStubMuons++;
              }

          for (Int_t j=0; j<nL1TPS_OMTFMuons; j++){
              L1Pt_OMTF=tkmuStubsOMTF_pt->at(j);
              L1Eta_OMTF=tkmuStubsOMTF_eta->at(j);
              L1Phi_OMTF=tkmuStubsOMTF_phi->at(j);
              L1Ch_OMTF=tkmuStubsOMTF_charge->at(j);
              L1zVtx_OMTF=tkmuStubsOMTF_Vz->at(j);
              vec_L1MuPt.push_back(L1Pt_OMTF);
              vec_L1MuPt_sorted.push_back(L1Pt_OMTF);
              vec_L1MuEta.push_back(L1Eta_OMTF);
              vec_L1MuPhi.push_back(L1Phi_OMTF);
              vec_L1MuCh.push_back(L1Ch_OMTF);
              vec_L1MuzVtx.push_back(L1zVtx_OMTF);
              countL1TkMuStubMuons++;
              }
          for (Int_t j=0; j<nL1TPS_EMTFMuons; j++){
              L1Pt_EMTF=tkmuStubsEMTF_pt->at(j);
              L1Eta_EMTF=tkmuStubsEMTF_eta->at(j);
              L1Phi_EMTF=tkmuStubsEMTF_phi->at(j);
              L1Ch_EMTF=tkmuStubsEMTF_charge->at(j);
              L1zVtx_EMTF=tkmuStubsEMTF_Vz->at(j);
              vec_L1MuPt.push_back(L1Pt_EMTF);
              vec_L1MuPt_sorted.push_back(L1Pt_EMTF);
              vec_L1MuEta.push_back(L1Eta_EMTF);
              vec_L1MuPhi.push_back(L1Phi_EMTF);
              vec_L1MuCh.push_back(L1Ch_EMTF);
              vec_L1MuzVtx.push_back(L1zVtx_EMTF);
              countL1TkMuStubMuons++;
              }
          h_nL1Muons->Fill(countL1TkMuStubMuons);

          std::sort(vec_L1MuPt_sorted.begin(),vec_L1MuPt_sorted.end());
          std::reverse(vec_L1MuPt_sorted.begin(),vec_L1MuPt_sorted.end());
 
          vec_sortL1List.clear();
 
          for(Int_t j=0; j<vec_L1MuPt_sorted.size(); j++){
             for(Int_t k=0; k<vec_L1MuPt_sorted.size(); k++){
                if(vec_L1MuPt.at(k)==vec_L1MuPt_sorted.at(j)) vec_sortL1List.push_back(k);
                }}
          for (Int_t j=0; j<vec_L1MuPt_sorted.size(); j++){
              iL1Sort = vec_sortL1List.at(j);                  
              L1MuSort_eta = vec_L1MuEta.at(iL1Sort);
              L1MuSort_phi = vec_L1MuPhi.at(iL1Sort);
              L1MuSort_ch  = vec_L1MuCh.at(iL1Sort);
              L1MuSort_zVtx = vec_L1MuzVtx.at(iL1Sort);
              vec_L1MuEta_sorted.push_back(L1MuSort_eta);
              vec_L1MuPhi_sorted.push_back(L1MuSort_phi);
              vec_L1MuCh_sorted.push_back(L1MuSort_ch);
              vec_L1MuzVtx_sorted.push_back(L1MuSort_zVtx);

              if (abs(L1MuSort_eta)<=2.4)h_L1MuPt->Fill(vec_L1MuPt_sorted.at(j));
              h_L1MuEta->Fill(L1MuSort_eta);
              h_L1MuPhi->Fill(L1MuSort_phi);
              h_L1MuzVtx->Fill(L1MuSort_zVtx);
              h_L1MuCh->Fill(L1MuSort_ch);
              }


/*
      if (vec_L1MuPhi_sorted.size()>0 && vec_gMuPhi_sorted.size()>0  && vec_L1MuPt_sorted[0]>L1_LeadPtCut && vec_gMuPt_sorted[0] >Gen_LeadPtCut && fabs(vec_L1MuEta_sorted[0])>=L1MuonEta_Min && fabs(vec_L1MuEta_sorted[0])<L1MuonEta_Max && fabs(vec_gMuEta_sorted[0])>=GenMuonEta_Min && fabs(vec_gMuEta_sorted[0])<GenMuonEta_Max)
       {
        L1gdPhi_mu11 = dPhi(vec_L1MuPhi_sorted[0],vec_gMuPhi_sorted[0]);
        L1gdR_mu11 = TMath::Sqrt(((vec_L1MuEta_sorted[0]-vec_gMuEta_sorted[0])*(vec_L1MuEta_sorted[0]-vec_gMuEta_sorted[0])) + L1gdPhi_mu11*L1gdPhi_mu11);
        h_L1gdR_mu11->Fill(L1gdR_mu11);
        if (L1gdR_mu11<0.6) gPassedLead=1;
        L1LeadEff ->Fill(gPassedLead, vec_gMuPt_sorted[0]);
       }
     if (vec_L1MuPhi_sorted.size()>1 && vec_gMuPhi_sorted.size()>1 && fabs(vec_L1MuEta_sorted[1])>=L1MuonEta_Min && fabs(vec_L1MuEta_sorted[1])<L1MuonEta_Max && vec_L1MuPt_sorted[1]>L1_SubLeadPtCut && vec_gMuPt_sorted[1]>Gen_SubLeadPtCut  && fabs(vec_gMuEta_sorted[1])>=GenMuonEta_Min && fabs(vec_gMuEta_sorted[1])<GenMuonEta_Max)
       {
       L1gdPhi_mu22 = dPhi(vec_L1MuPhi_sorted[1],vec_gMuPhi_sorted[1]);
        L1gdR_mu22 = TMath::Sqrt(((vec_L1MuEta_sorted[1]-vec_gMuEta_sorted[1])*(vec_L1MuEta_sorted[1]-vec_gMuEta_sorted[1])) + L1gdPhi_mu22*L1gdPhi_mu22);
        h_L1gdR_mu22->Fill(L1gdR_mu22);
        if (L1gdR_mu22<0.8) gPassedSubLead=1;
        L1SubLeadEff ->Fill(gPassedSubLead, vec_gMuPt_sorted[1]);
       }

      if (vec_L1MuPhi_sorted.size()>2 && vec_gMuPhi_sorted.size()>2 &&  fabs(vec_L1MuEta_sorted[2])>=L1MuonEta_Min && fabs(vec_L1MuEta_sorted[2])<L1MuonEta_Max && vec_L1MuPt_sorted[2]>L1_TrailPtCut &&  vec_gMuPt_sorted[2]>Gen_TrailPtCut  && fabs(vec_gMuEta_sorted[2])>=GenMuonEta_Min && fabs(vec_gMuEta_sorted[2])<=GenMuonEta_Max)
       {
        L1gdPhi_mu33 = dPhi(vec_L1MuPhi_sorted[2],vec_gMuPhi_sorted[2]);
        L1gdR_mu33 = TMath::Sqrt(((vec_L1MuEta_sorted[2]-vec_gMuEta_sorted[2])*(vec_L1MuEta_sorted[2]-vec_gMuEta_sorted[2])) + L1gdPhi_mu33*L1gdPhi_mu33);
        h_L1gdR_mu33->Fill(L1gdR_mu33);
        if (L1gdR_mu33<1.5) gPassedTrail=1;
        L1TrailEff ->Fill(gPassedTrail, vec_gMuPt_sorted[2]);
       }
*/

    nTTTracks=tttracks_pt->size();

    vec_TTTracks_pt.clear();
    vec_TTTracks_pt_sort.clear();
    vec_TTTracks_eta.clear();
    vec_TTTracks_phi.clear();
    vec_TTTracks_chi2.clear();
    vec_TTTracks_chi2bend.clear();
    vec_TTTracks_z0.clear();
    vec_TTTracks_qual.clear();
    vec_TTTracks_gen_TP_ID.clear();
    vec_genuineTrack_pt.clear();
    vec_genuineTrack_eta.clear();
    vec_genuineTrack_phi.clear();
    vec_genuineTrack_chi2.clear();
    vec_genuineTrack_chi2bend.clear();
    vec_genuineTrack_z0.clear();
    vec_genuineTrack_gen_TP_ID.clear();

    for(Int_t j=0; j<nTTTracks; j++) {
       TTTracks_pt = tttracks_pt->at(j);
       TTTracks_eta = tttracks_eta->at(j);
       TTTracks_phi = tttracks_phi->at(j);
       TTTracks_chi2 = tttracks_chi2->at(j);
       TTTracks_chi2bend = tttracks_bendchi2->at(j);
       TTTracks_z0 = tttracks_z0->at(j);
  
       vec_TTTracks_pt.push_back(TTTracks_pt);
       vec_TTTracks_pt_sort.push_back(TTTracks_pt);
       vec_TTTracks_eta.push_back(TTTracks_eta);
       vec_TTTracks_phi.push_back(TTTracks_phi);
       vec_TTTracks_chi2.push_back(TTTracks_chi2);
       vec_TTTracks_chi2bend.push_back(TTTracks_chi2bend);
       vec_TTTracks_z0.push_back(TTTracks_z0);
       vec_TTTracks_qual.push_back(tttracks_qual->at(j));
       vec_TTTracks_gen_TP_ID.push_back(tttracks_gen_TP_ID->at(j));  
      }
 


  std::sort(vec_TTTracks_pt_sort.begin(),vec_TTTracks_pt_sort.end());
  std::reverse(vec_TTTracks_pt_sort.begin(),vec_TTTracks_pt_sort.end());
  vec_sortTTTList.clear();

  for(Int_t j=0; j<vec_TTTracks_pt_sort.size(); j++) {
      for(Int_t k=0; k<vec_TTTracks_pt_sort.size(); k++){
          if(vec_TTTracks_pt.at(k)==vec_TTTracks_pt_sort.at(j)) vec_sortTTTList.push_back(k);
          }}
      for (Int_t j=0; j<vec_TTTracks_pt_sort.size(); j++){
          iTTTSort = vec_sortTTTList.at(j);
          TTTrack_pt_sort  = vec_TTTracks_pt_sort.at(j);
          TTTrack_eta_sort = vec_TTTracks_eta.at(iTTTSort);
          TTTrack_phi_sort = vec_TTTracks_phi.at(iTTTSort);
          TTTrack_z0_sort  = vec_TTTracks_z0.at(iTTTSort);
          TTTrack_chi2_sort  = vec_TTTracks_chi2.at(iTTTSort);
          TTTrack_chi2bend_sort  = vec_TTTracks_chi2bend.at(iTTTSort);
          h_TTTracks_pt_beforequal->Fill(TTTrack_pt_sort);
          h_TTTracks_eta_beforequal->Fill(TTTrack_eta_sort);
          h_TTTracks_phi_beforequal->Fill(TTTrack_phi_sort);
          h_TTTracks_chi2_beforequal->Fill(TTTrack_chi2_sort);
          h_TTTracks_chi2Bend_beforequal->Fill(TTTrack_chi2bend_sort);
          h_TTTracks_z0_beforequal->Fill(TTTrack_z0_sort);
          h_TTTracks_qual_beforequal->Fill(vec_TTTracks_qual.at(iTTTSort));
          h_TTTracks_gen_TP_ID_beforequal->Fill(vec_TTTracks_gen_TP_ID.at(iTTTSort));
          if (vec_TTTracks_qual.at(iTTTSort)==1 && vec_TTTracks_chi2.at(iTTTSort)<100 && vec_TTTracks_chi2bend.at(iTTTSort)<5 && fabs(vec_TTTracks_eta.at(iTTTSort))<L1MuonEta_Max) {
              vec_genuineTrack_pt.push_back(TTTrack_pt_sort);
              vec_genuineTrack_eta.push_back(TTTrack_eta_sort);
              vec_genuineTrack_phi.push_back(TTTrack_phi_sort);
              vec_genuineTrack_chi2.push_back(TTTrack_chi2_sort);
              vec_genuineTrack_chi2bend.push_back(TTTrack_chi2bend_sort);
              vec_genuineTrack_z0.push_back(TTTrack_z0_sort);
              vec_genuineTrack_gen_TP_ID.push_back(vec_TTTracks_gen_TP_ID.at(iTTTSort));
              h_TTTracks_pt->Fill(TTTrack_pt_sort);
              h_TTTracks_eta->Fill(TTTrack_eta_sort);
              h_TTTracks_phi->Fill(TTTrack_phi_sort);
              h_TTTracks_chi2->Fill(TTTrack_chi2_sort);
              h_TTTracks_chi2Bend->Fill(TTTrack_chi2bend_sort);
              h_TTTracks_z0->Fill(TTTrack_z0_sort);
              h_TTTracks_qual->Fill(vec_TTTracks_qual.at(iTTTSort));
              h_TTTracks_gen_TP_ID->Fill(vec_TTTracks_gen_TP_ID.at(iTTTSort));
              }}

      h_TTTracks_N_qual1->Fill(vec_genuineTrack_pt.size());
      h_TTTracks_N_allqual->Fill(vec_TTTracks_pt_sort.size());
/*      if ( vec_gMuPhi_sorted.size()>0 && vec_genuineTrack_phi.size()>0 && vec_gMuPt_sorted[0] >Gen_LeadPtCut && fabs(vec_genuineTrack_eta[0])>=L1MuonEta_Min && fabs(vec_genuineTrack_eta[0])<L1MuonEta_Max && fabs(vec_gMuEta_sorted[0])>=GenMuonEta_Min && fabs(vec_gMuEta_sorted[0])<GenMuonEta_Max)
       {

        TTTrackgdR_mu11 = dR_calc(vec_genuineTrack_eta[0], vec_genuineTrack_phi[0],vec_gMuEta_sorted[0], vec_gMuPhi_sorted[0] ) ;
        h_TTTrackgdR_mu11->Fill(TTTrackgdR_mu11);
        if (TTTrackgdR_mu11<0.5) gPassedTTTrackLead=1;
        TTTrackLeadEff ->Fill(gPassedTTTrackLead, vec_gMuPt_sorted[0]);
       }
     if (vec_genuineTrack_phi.size()>1 && vec_gMuPhi_sorted.size()>1 && fabs(vec_genuineTrack_eta[1])>=L1MuonEta_Min && fabs(vec_genuineTrack_eta[1])<L1MuonEta_Max && vec_gMuPt_sorted[1]>Gen_SubLeadPtCut  && fabs(vec_gMuEta_sorted[1])>=GenMuonEta_Min && fabs(vec_gMuEta_sorted[1])<GenMuonEta_Max)
       {

        TTTrackgdR_mu22 = dR_calc(vec_genuineTrack_eta[1], vec_genuineTrack_phi[1],vec_gMuEta_sorted[1], vec_gMuPhi_sorted[1] );  
        h_TTTrackgdR_mu22->Fill(TTTrackgdR_mu22);
        if (TTTrackgdR_mu22<0.5) gPassedTTTrackSubLead=1;
        TTTrackSubLeadEff ->Fill(gPassedTTTrackSubLead, vec_gMuPt_sorted[1]);
       }

      if (vec_genuineTrack_phi.size()>2 && vec_gMuPhi_sorted.size()>2 && fabs(vec_genuineTrack_eta[2])>=L1MuonEta_Min && fabs(vec_genuineTrack_eta[2])<L1MuonEta_Max && vec_gMuPt_sorted[2]>Gen_SubLeadPtCut  && fabs(vec_gMuEta_sorted[2])>=GenMuonEta_Min && fabs(vec_gMuEta_sorted[2])<GenMuonEta_Max)
       {
        TTTrackgdR_mu33 = dR_calc(vec_genuineTrack_eta[2], vec_genuineTrack_phi[2],vec_gMuEta_sorted[2], vec_gMuPhi_sorted[2]);  

        h_TTTrackgdR_mu33->Fill(TTTrackgdR_mu33);
        if (TTTrackgdR_mu33<1.5) gPassedTTTrackTrail=1;
        TTTrackTrailEff ->Fill(gPassedTTTrackTrail, vec_gMuPt_sorted[2]);
       }
*/

       vec_dPt_TTTrack_GenMu1.clear();
       vec_dPt_TTTrack_GenMu2.clear();
       vec_dPt_TTTrack_GenMu3.clear();

       vector<double>::iterator min_dRgenMu1_TTTrack, min_dRgenMu2_TTTrack, min_dRgenMu3_TTTrack;
       vector<double>::iterator min_dPt_TTTrack_GenMu1,min_dPt_TTTrack_GenMu2,min_dPt_TTTrack_GenMu3;
       vec_Idx_GenMu_Track3_dR0p2.clear();
       vec_Idx_GenMu_Track2_dR0p2.clear();
       vec_Idx_GenMu_Track1_dR0p2.clear();
       if (gen_Taus.size()==1){
           for (Int_t TTTrack=0; TTTrack<vec_genuineTrack_pt.size(); TTTrack++){
              dR_TTTrack_GenMu1 = dR_calc(vec_genuineTrack_eta.at(TTTrack), vec_genuineTrack_phi.at(TTTrack),gentau_mu1.Eta(), gentau_mu1.Phi());
              dPt_TTTrack_GenMu1 = fabs(vec_genuineTrack_pt.at(TTTrack)-gentau_mu1.Pt());
              h_dR_TTTRack_Gen1_beforeCut->Fill(dR_TTTrack_GenMu1);
              h_dEta_TTTrack_GenMu1->Fill(fabs(dEta_calc(vec_genuineTrack_eta.at(TTTrack), gentau_mu1.Eta())));
              h_dPt_TTTrack_GenMu1->Fill(dPt_TTTrack_GenMu1);
              if (dR_TTTrack_GenMu1<dRcone_preMatch){
                  vec_dPt_TTTrack_GenMu1.push_back(dPt_TTTrack_GenMu1);
                  vec_Idx_GenMu_Track1_dR0p2.push_back(TTTrack);
                  }
              dR_TTTrack_GenMu2 = dR_calc(vec_genuineTrack_eta.at(TTTrack), vec_genuineTrack_phi.at(TTTrack), gentau_mu2.Eta(), gentau_mu2.Phi());
              dPt_TTTrack_GenMu2 = fabs(vec_genuineTrack_pt.at(TTTrack)-gentau_mu2.Pt());
              h_dR_TTTRack_Gen2_beforeCut->Fill(dR_TTTrack_GenMu2);
              h_dEta_TTTrack_GenMu2->Fill(fabs(dEta_calc(vec_genuineTrack_eta.at(TTTrack), gentau_mu2.Eta())));
              h_dPt_TTTrack_GenMu2->Fill(dPt_TTTrack_GenMu2);
              if (dR_TTTrack_GenMu2<dRcone_preMatch){
                  vec_dPt_TTTrack_GenMu2.push_back(dPt_TTTrack_GenMu2);
                  vec_Idx_GenMu_Track2_dR0p2.push_back(TTTrack);
                  }
              dR_TTTrack_GenMu3 = dR_calc(vec_genuineTrack_eta.at(TTTrack), vec_genuineTrack_phi.at(TTTrack), gentau_mu3.Eta(), gentau_mu3.Phi());
              dPt_TTTrack_GenMu3 = fabs(vec_genuineTrack_pt.at(TTTrack)-gentau_mu3.Pt());
              h_dR_TTTRack_Gen3_beforeCut->Fill(dR_TTTrack_GenMu3);
              h_dEta_TTTrack_GenMu3->Fill(fabs(dEta_calc(vec_genuineTrack_eta.at(TTTrack), gentau_mu3.Eta())));
              h_dPt_TTTrack_GenMu3->Fill(dPt_TTTrack_GenMu3);
              if(dR_TTTrack_GenMu3<dRcone_preMatch){
                  vec_dPt_TTTrack_GenMu3.push_back(dPt_TTTrack_GenMu3);
                  vec_Idx_GenMu_Track3_dR0p2.push_back(TTTrack);
                  }
              }
         if (vec_dPt_TTTrack_GenMu1.size()>0 && vec_dPt_TTTrack_GenMu2.size()>0 && vec_dPt_TTTrack_GenMu3.size()>0){
                min_dPt_TTTrack_GenMu1 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu1), std::end(vec_dPt_TTTrack_GenMu1));
                min_dPt_TTTrack_GenMu2 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu2), std::end(vec_dPt_TTTrack_GenMu2));
                min_dPt_TTTrack_GenMu3 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu3), std::end(vec_dPt_TTTrack_GenMu3));
                minIdx_gen1TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu1), min_dPt_TTTrack_GenMu1);
                minIdx_gen2TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu2), min_dPt_TTTrack_GenMu2);
                minIdx_gen3TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu3), min_dPt_TTTrack_GenMu3);                
             }

        if (vec_genuineTrack_pt.size()>=3 && vec_dPt_TTTrack_GenMu1.size()>0 && vec_dPt_TTTrack_GenMu2.size()>0 && vec_dPt_TTTrack_GenMu3.size()>0){
            if (vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)==vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack) || vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)==vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack) || vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)==vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)) {
                if (vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack)<vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack) && vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack)<vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)){
                      if (vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)==vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)) {    
                          vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)=1000;
                          min_dPt_TTTrack_GenMu2 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu2), std::end(vec_dPt_TTTrack_GenMu2));
                          minIdx_gen2TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu2), min_dPt_TTTrack_GenMu2); 
                      }
                     if (vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)==vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)){
                         vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)=1000;
                         min_dPt_TTTrack_GenMu3 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu3), std::end(vec_dPt_TTTrack_GenMu3));
                         minIdx_gen3TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu3), min_dPt_TTTrack_GenMu3);
                      }
                    if (vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)==vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack) && vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)!=vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)){
                        if (vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)<vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)){
                        vec_dPt_TTTrack_GenMu3.at(Find_Idx(vec_Idx_GenMu_Track3_dR0p2,minIdx_gen3TTTrack, vec_Idx_GenMu_Track1_dR0p2, minIdx_gen1TTTrack)) = 1000;
                        vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)=1000;
                        min_dPt_TTTrack_GenMu3 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu3), std::end(vec_dPt_TTTrack_GenMu3));
                        minIdx_gen3TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu3), min_dPt_TTTrack_GenMu3);
                         }
                        else if (vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)>vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)){
                            vec_dPt_TTTrack_GenMu2.at(Find_Idx(vec_Idx_GenMu_Track2_dR0p2,minIdx_gen2TTTrack, vec_Idx_GenMu_Track1_dR0p2, minIdx_gen1TTTrack)) = 1000;                
                           vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack) = 1000;
                           min_dPt_TTTrack_GenMu2 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu2), std::end(vec_dPt_TTTrack_GenMu2));
                           minIdx_gen2TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu2), min_dPt_TTTrack_GenMu2);
                        }
                     }
                  }
                  if (vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)<vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack) && vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)<vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)){
                      if (vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)==vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)){                        
                         vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack) = 1000;
                         min_dPt_TTTrack_GenMu1 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu1), std::end(vec_dPt_TTTrack_GenMu1));
                         minIdx_gen1TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu1), min_dPt_TTTrack_GenMu1);
                       }
                      if (vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)==vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)){
                          vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack) = 1000;
                          min_dPt_TTTrack_GenMu3 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu3), std::end(vec_dPt_TTTrack_GenMu3));
                          minIdx_gen3TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu3), min_dPt_TTTrack_GenMu3);
                        }
                      if (vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)==vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack) && vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)!=vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)){
                          if (vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack)<vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)){
                              vec_dPt_TTTrack_GenMu3.at(Find_Idx(vec_Idx_GenMu_Track3_dR0p2,minIdx_gen3TTTrack, vec_Idx_GenMu_Track2_dR0p2, minIdx_gen2TTTrack)) = 1000;
                              vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack) = 1000;
                              min_dPt_TTTrack_GenMu3 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu3), std::end(vec_dPt_TTTrack_GenMu3));
                              minIdx_gen3TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu3), min_dPt_TTTrack_GenMu3);
                            }
                          else if (vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack)>vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)){
                              vec_dPt_TTTrack_GenMu1.at(Find_Idx(vec_Idx_GenMu_Track1_dR0p2,minIdx_gen1TTTrack, vec_Idx_GenMu_Track2_dR0p2, minIdx_gen2TTTrack)) = 1000;

                              vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack) = 1000;
                              min_dPt_TTTrack_GenMu1 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu1), std::end(vec_dPt_TTTrack_GenMu1));
                              minIdx_gen1TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu1), min_dPt_TTTrack_GenMu1);
                            }
                       }
                    }

                  if (vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack)>vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack) && vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)>vec_dPt_TTTrack_GenMu3.at(minIdx_gen3TTTrack)){
                      if (vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)==vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)){
                          vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack) = 1000;
                          min_dPt_TTTrack_GenMu2 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu2), std::end(vec_dPt_TTTrack_GenMu2));
                          minIdx_gen2TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu2), min_dPt_TTTrack_GenMu2);
                       }   
                     if (vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)==vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)){
                         vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack) = 1000;
                         min_dPt_TTTrack_GenMu1 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu1), std::end(vec_dPt_TTTrack_GenMu1));
                         minIdx_gen1TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu1), min_dPt_TTTrack_GenMu1);
                      }
 
                    if (vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)==vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack) && vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)!=vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)){
                        if (vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack)<vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)){
                            vec_dPt_TTTrack_GenMu2.at(Find_Idx(vec_Idx_GenMu_Track2_dR0p2,minIdx_gen2TTTrack, vec_Idx_GenMu_Track3_dR0p2, minIdx_gen3TTTrack)) = 1000;
                            vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack) = 1000;
                            min_dPt_TTTrack_GenMu2 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu2), std::end(vec_dPt_TTTrack_GenMu2));
                            minIdx_gen2TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu2), min_dPt_TTTrack_GenMu2);
                          }
                        else if (vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack)>vec_dPt_TTTrack_GenMu2.at(minIdx_gen2TTTrack)){
                            vec_dPt_TTTrack_GenMu1.at(Find_Idx(vec_Idx_GenMu_Track1_dR0p2,minIdx_gen1TTTrack, vec_Idx_GenMu_Track3_dR0p2, minIdx_gen3TTTrack)) = 1000;

                            vec_dPt_TTTrack_GenMu1.at(minIdx_gen1TTTrack) = 1000;
                            min_dPt_TTTrack_GenMu1 = std::min_element(std::begin(vec_dPt_TTTrack_GenMu1), std::end(vec_dPt_TTTrack_GenMu1));
                           minIdx_gen1TTTrack = std::distance(std::begin(vec_dPt_TTTrack_GenMu1), min_dPt_TTTrack_GenMu1);
                       }
                     }
              }}}}

          vec_TTTrackTauPt.clear();
          vec_TTTrackTauEta.clear();
          vec_TTTrackTauPhi.clear();
          vec_TTTrackTauM.clear();
          vec_dz_TTTrack.clear();
          vector<double>::iterator dz_min_TTTrack, dz_max_TTTrack;

          if (vec_dPt_TTTrack_GenMu1.size()>0 && vec_dPt_TTTrack_GenMu2.size()>0 && vec_dPt_TTTrack_GenMu3.size()>0){
              if( vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)!=vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack) && vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)!=vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack) && vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)!=vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack) && *min_dPt_TTTrack_GenMu1!=1000 && *min_dPt_TTTrack_GenMu2!=1000 && *min_dPt_TTTrack_GenMu3!=1000){
                  h_dPt_TTTrack_GenMu1_afterAlgo->Fill(*min_dPt_TTTrack_GenMu1);
                  h_dPt_TTTrack_GenMu2_afterAlgo->Fill(*min_dPt_TTTrack_GenMu2);
                  h_dPt_TTTrack_GenMu3_afterAlgo->Fill(*min_dPt_TTTrack_GenMu3);
                  h_ratio_Pt_TTTrack_GenMu1 -> Fill((*min_dPt_TTTrack_GenMu1/gentau_mu1.Pt()));
                  h_ratio_Pt_TTTrack_GenMu2 -> Fill((*min_dPt_TTTrack_GenMu2/gentau_mu2.Pt()));
                  h_ratio_Pt_TTTrack_GenMu3 -> Fill((*min_dPt_TTTrack_GenMu3/gentau_mu3.Pt()));
                  if ((*min_dPt_TTTrack_GenMu1/gentau_mu1.Pt())<mindPt && (*min_dPt_TTTrack_GenMu2/gentau_mu2.Pt())<mindPt && (*min_dPt_TTTrack_GenMu3/gentau_mu3.Pt())<mindPt){
                      TTTrack_mu1.SetPtEtaPhiM(vec_genuineTrack_pt.at(vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)),vec_genuineTrack_eta.at(vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)),vec_genuineTrack_phi.at(vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack)),mumass);
                      TTTrack_mu2.SetPtEtaPhiM(vec_genuineTrack_pt.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)),vec_genuineTrack_eta.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)),vec_genuineTrack_phi.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)),mumass);
                      TTTrack_mu3.SetPtEtaPhiM(vec_genuineTrack_pt.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),vec_genuineTrack_eta.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),vec_genuineTrack_phi.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),mumass);

                      TTTrackdzVtx_12= (vec_genuineTrack_z0.at(vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack))) - (vec_genuineTrack_z0.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)));
                      TTTrackdzVtx_13= (vec_genuineTrack_z0.at(vec_Idx_GenMu_Track1_dR0p2.at(minIdx_gen1TTTrack))) - (vec_genuineTrack_z0.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)));
                      TTTrackdzVtx_23= (vec_genuineTrack_z0.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack))) - (vec_genuineTrack_z0.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)));

                      vec_dz_TTTrack.push_back(TTTrackdzVtx_12);
                      vec_dz_TTTrack.push_back(TTTrackdzVtx_13);
                      vec_dz_TTTrack.push_back(TTTrackdzVtx_23);
                      dz_max_TTTrack = std::max_element(std::begin(vec_dz_TTTrack), std::end(vec_dz_TTTrack));
                      TTTrackdR_mu12_beforeMassCut = dR_calc(TTTrack_mu1.Eta(), TTTrack_mu1.Phi(), TTTrack_mu2.Eta(), TTTrack_mu2.Phi());
                      TTTrackdR_mu13_beforeMassCut = dR_calc(TTTrack_mu1.Eta(), TTTrack_mu1.Phi(), TTTrack_mu3.Eta(), TTTrack_mu3.Phi());
                      TTTrackdR_mu23_beforeMassCut = dR_calc(TTTrack_mu2.Eta(), TTTrack_mu2.Phi(), TTTrack_mu3.Eta(), TTTrack_mu3.Phi());
                      TTTrack_tripleMuMass = (TTTrack_mu1+TTTrack_mu2+TTTrack_mu3).M();
     
                      h_TTTrackdzVtx_12->Fill(abs(TTTrackdzVtx_12));
                      h_TTTrackdzVtx_23->Fill(abs(TTTrackdzVtx_23));
                      h_TTTrackdzVtx_13->Fill(abs(TTTrackdzVtx_13));
                      h_TTTrackdzVtx_max->Fill(fabs(*dz_max_TTTrack));
                      h_TTTrackdR_mu12_beforeMassCut->Fill(TTTrackdR_mu12_beforeMassCut);
                      h_TTTrackdR_mu13_beforeMassCut->Fill(TTTrackdR_mu13_beforeMassCut);
                      h_TTTrackdR_mu23_beforeMassCut->Fill(TTTrackdR_mu23_beforeMassCut);
                      h_TTTrack_TripleMu_Mass->Fill(TTTrack_tripleMuMass);
                 if (TTTrack_tripleMuMass>massCutLow && TTTrack_tripleMuMass<massCutHigh && fabs(*dz_max_TTTrack)<maxdZ && TTTrackdR_mu12_beforeMassCut<dRpairCut && TTTrackdR_mu13_beforeMassCut<dRpairCut && TTTrackdR_mu23_beforeMassCut<dRpairCut){
                    TTTrackdR_mu12 = dR_calc(TTTrack_mu1.Eta(), TTTrack_mu1.Phi(), TTTrack_mu2.Eta(), TTTrack_mu2.Phi());
                    TTTrackdR_mu13 = dR_calc(TTTrack_mu1.Eta(), TTTrack_mu1.Phi(), TTTrack_mu3.Eta(), TTTrack_mu3.Phi());
                    TTTrackdR_mu23 = dR_calc(TTTrack_mu2.Eta(), TTTrack_mu2.Phi(), TTTrack_mu3.Eta(), TTTrack_mu3.Phi());
                    h_TTTrackdR_mu12_afterMassCut->Fill(TTTrackdR_mu12);
                    h_TTTrackdR_mu13_afterMassCut->Fill(TTTrackdR_mu13);
                    h_TTTrackdR_mu23_afterMassCut->Fill(TTTrackdR_mu23);

                    TTTrackTau_phi  = (TTTrack_mu1+TTTrack_mu2+TTTrack_mu3).Phi();
                    TTTrackTau_eta  = (TTTrack_mu1+TTTrack_mu2+TTTrack_mu3).Eta();
                    TTTrackTau_pt   = (TTTrack_mu1+TTTrack_mu2+TTTrack_mu3).Pt();
                    TTTrackTau_mass = (TTTrack_mu1+TTTrack_mu2+TTTrack_mu3).M();
                    vec_TTTrackTauPt.push_back(TTTrackTau_pt);
                    vec_TTTrackTauEta.push_back(TTTrackTau_eta);
                    vec_TTTrackTauPhi.push_back(TTTrackTau_phi);
                    vec_TTTrackTauM.push_back(TTTrackTau_mass);
                    if (abs(TTTrackTau_eta)<=2.4){
                        h_TTTrackTau_pt->Fill(TTTrackTau_pt);
                        h_TTTrackTau_phi->Fill(TTTrackTau_phi);
                        h_TTTrackTau_eta->Fill(TTTrackTau_eta);
                        h_TTTrackTau_mass->Fill(TTTrackTau_mass);
                        }
                    if (abs(TTTrackTau_eta)<0.8 && abs(TTTrackTau_eta)>=0) h_TTTrackTau_pt_Bar->Fill(TTTrackTau_pt);
                    if (abs(TTTrackTau_eta)<1.2 && abs(TTTrackTau_eta)>=0.8) h_TTTrackTau_pt_Over->Fill(TTTrackTau_pt);
                    if (abs(TTTrackTau_eta)<=2.4 && abs(TTTrackTau_eta)>=1.2) h_TTTrackTau_pt_End->Fill(TTTrackTau_pt);                 
                    h_TTTrackLeadMuTau_pt->Fill(TTTrack_mu1.Pt());
                    h_TTTrackSubleadMuTau_pt->Fill(TTTrack_mu2.Pt());
                    h_TTTrackThirdMuTau_pt->Fill(TTTrack_mu3.Pt());
                    goto ExitTrackLoop;
                    }}}}
          ExitTrackLoop:

          vec_dR_TTTrack1_TkMuStubs.clear();
          vec_dR_TTTrack2_TkMuStubs.clear();
          vec_dPt_TTTrack1_TkMuStubs.clear();
          vec_dPt_TTTrack2_TkMuStubs.clear();
          vec_Idx_TkMuStub_TTTrack2_dR0p2.clear();
          vec_Idx_TkMuStub_TTTrack1_dR0p2.clear();
          vector<double>::iterator min_dR_TTTrack1_TkMuStubs,min_dR_TTTrack2_TkMuStubs,  min_dPt_TTTrack1_TkMuStubs,min_dPt_TTTrack2_TkMuStubs;
   
          if (gen_Taus.size()==1)
        {
         //Find 2 TkMuStubs Match to leading and subleading TTTracks
         for (Int_t L1Mu=0; L1Mu<vec_L1MuPt_sorted.size(); L1Mu++)
            {
             if (abs(vec_L1MuEta_sorted.at(L1Mu))<=L1MuonEta_Max)
              {
               dR_TTTrack1_TkMuStubs = dR_calc(vec_L1MuEta_sorted.at(L1Mu),vec_L1MuPhi_sorted.at(L1Mu),TTTrack_mu1.Eta(), TTTrack_mu1.Phi());
               vec_dR_TTTrack1_TkMuStubs.push_back(dR_TTTrack1_TkMuStubs);        
               h_dR_TkMuStubTTTrack1->Fill(dR_TTTrack1_TkMuStubs);
               if(dR_TTTrack1_TkMuStubs<dRcone_preMatch){
                   dPt_TTTrack1_TkMuStubs = fabs(vec_L1MuPt_sorted.at(L1Mu) - TTTrack_mu1.Pt());
                   vec_dPt_TTTrack1_TkMuStubs.push_back(dPt_TTTrack1_TkMuStubs);
                   vec_Idx_TkMuStub_TTTrack1_dR0p2.push_back(L1Mu);
                }

               dR_TTTrack2_TkMuStubs = dR_calc(vec_L1MuEta_sorted.at(L1Mu), vec_L1MuPhi_sorted.at(L1Mu), TTTrack_mu2.Eta(), TTTrack_mu2.Phi());
               vec_dR_TTTrack2_TkMuStubs.push_back(dR_TTTrack2_TkMuStubs);
               h_dR_TkMuStubTTTrack2->Fill(dR_TTTrack2_TkMuStubs);
               if(dR_TTTrack2_TkMuStubs<dRcone_preMatch){
                   dPt_TTTrack2_TkMuStubs= fabs(vec_L1MuPt_sorted.at(L1Mu) - TTTrack_mu2.Pt());
                   vec_dPt_TTTrack2_TkMuStubs.push_back(dPt_TTTrack2_TkMuStubs);
                   vec_Idx_TkMuStub_TTTrack2_dR0p2.push_back(L1Mu);
                }

               }
             }

           if (vec_dPt_TTTrack1_TkMuStubs.size()>0)
              {
                min_dPt_TTTrack1_TkMuStubs = std::min_element(std::begin(vec_dPt_TTTrack1_TkMuStubs), std::end(vec_dPt_TTTrack1_TkMuStubs));
                minIdxdPt_TTTrack1_TkMuStubs = std::distance(std::begin(vec_dPt_TTTrack1_TkMuStubs), min_dPt_TTTrack1_TkMuStubs); 
             }
           if (vec_dPt_TTTrack2_TkMuStubs.size()>0)
              {
                min_dPt_TTTrack2_TkMuStubs = std::min_element(std::begin(vec_dPt_TTTrack2_TkMuStubs), std::end(vec_dPt_TTTrack2_TkMuStubs));
                minIdxdPt_TTTrack2_TkMuStubs = std::distance(std::begin(vec_dPt_TTTrack2_TkMuStubs), min_dPt_TTTrack2_TkMuStubs);
              }
           }

          if (vec_genuineTrack_pt.size()>=3 && vec_dPt_TTTrack1_TkMuStubs.size()>0 && vec_dPt_TTTrack2_TkMuStubs.size()>0 )
            {

             if (vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)==vec_Idx_TkMuStub_TTTrack2_dR0p2.at(minIdxdPt_TTTrack2_TkMuStubs))
              {
               if (vec_dPt_TTTrack1_TkMuStubs.at(minIdxdPt_TTTrack1_TkMuStubs) < vec_dPt_TTTrack2_TkMuStubs.at(minIdxdPt_TTTrack2_TkMuStubs))
                {
                  vec_dPt_TTTrack2_TkMuStubs.at(minIdxdPt_TTTrack2_TkMuStubs) = 1000;
                  min_dPt_TTTrack2_TkMuStubs = std::min_element(std::begin(vec_dPt_TTTrack2_TkMuStubs), std::end(vec_dPt_TTTrack2_TkMuStubs));
                  minIdxdPt_TTTrack2_TkMuStubs = std::distance(std::begin(vec_dPt_TTTrack2_TkMuStubs), min_dPt_TTTrack2_TkMuStubs);
                 }
               else if (vec_dPt_TTTrack1_TkMuStubs.at(minIdxdPt_TTTrack1_TkMuStubs) > vec_dPt_TTTrack2_TkMuStubs.at(minIdxdPt_TTTrack2_TkMuStubs))
                 {
                  vec_dPt_TTTrack1_TkMuStubs.at(minIdxdPt_TTTrack1_TkMuStubs) = 1000;
                  min_dPt_TTTrack1_TkMuStubs = std::min_element(std::begin(vec_dPt_TTTrack1_TkMuStubs), std::end(vec_dPt_TTTrack1_TkMuStubs));
                  minIdxdPt_TTTrack1_TkMuStubs = std::distance(std::begin(vec_dPt_TTTrack1_TkMuStubs), min_dPt_TTTrack1_TkMuStubs);
                  }
               }

             h_min_dPt_TTTrack1_TkMuStubs->Fill(*min_dPt_TTTrack1_TkMuStubs);
             h_min_dPt_TTTrack2_TkMuStubs->Fill(*min_dPt_TTTrack2_TkMuStubs);
           }

       if (vec_dPt_TTTrack1_TkMuStubs.size()>0 && vec_dPt_TTTrack2_TkMuStubs.size()>0 && vec_dPt_TTTrack_GenMu3.size()>0 && *min_dPt_TTTrack1_TkMuStubs<0.02 && *min_dPt_TTTrack2_TkMuStubs<0.02 && (*min_dPt_TTTrack_GenMu3/gentau_mu3.Pt())<mindPt)
       {
         dPt_TkMuStub1_TTTrack3 = fabs(vec_L1MuPt_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)) -  TTTrack_mu3.Pt());
         h_dPt_TkMuStub1_TTTrack3->Fill(dPt_TkMuStub1_TTTrack3);
         dPt_TkMuStub2_TTTrack3 = fabs(vec_L1MuPt_sorted.at(vec_Idx_TkMuStub_TTTrack2_dR0p2.at(minIdxdPt_TTTrack2_TkMuStubs)) -  TTTrack_mu3.Pt());
         h_dPt_TkMuStub2_TTTrack3->Fill(dPt_TkMuStub2_TTTrack3);
         dPt_TkMuStub1_TTTrack2 = fabs(vec_L1MuPt_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)) - TTTrack_mu2.Pt());
         h_dPt_TkMuStub1_TTTrack2->Fill(dPt_TkMuStub1_TTTrack2);

        }

        vec_dz_TkMuStubsTTTrack.clear();
        vec_TkMuStubsTTTrackTauPt.clear();
        vec_TkMuStubsTTTrackTauPhi.clear();
        vec_TkMuStubsTTTrackTauEta.clear();
        vector<double>::iterator dz_max_TkMuStubsTTTrack;
        TkMuStubsTTTrack_Taus.clear();

       if (vec_dPt_TTTrack1_TkMuStubs.size()>0 && vec_dPt_TTTrack2_TkMuStubs.size()>0 && vec_dPt_TTTrack_GenMu3.size()>0)
              {
              if (*min_dPt_TTTrack1_TkMuStubs<0.02 && *min_dPt_TTTrack2_TkMuStubs<0.02 && (*min_dPt_TTTrack_GenMu3/gentau_mu3.Pt())<mindPt && dPt_TkMuStub1_TTTrack3>0.02 && dPt_TkMuStub2_TTTrack3>0.02)
               {
                TkMuStubMatchTTTrack_mu1.SetPtEtaPhiM(vec_L1MuPt_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)),vec_L1MuEta_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)), vec_L1MuPhi_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)),mumass);
                TkMuStubMatchTTTrack_mu2.SetPtEtaPhiM(vec_L1MuPt_sorted.at(vec_Idx_TkMuStub_TTTrack2_dR0p2.at(minIdxdPt_TTTrack2_TkMuStubs)),vec_L1MuEta_sorted.at(vec_Idx_TkMuStub_TTTrack2_dR0p2.at(minIdxdPt_TTTrack2_TkMuStubs)), vec_L1MuPhi_sorted.at(vec_Idx_TkMuStub_TTTrack2_dR0p2.at(minIdxdPt_TTTrack2_TkMuStubs)),mumass);
                TTTrackComb_mu3.SetPtEtaPhiM(vec_genuineTrack_pt.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),vec_genuineTrack_eta.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),vec_genuineTrack_phi.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),mumass);

                TkMuStubsTTTrackdzVtx_12= vec_L1MuzVtx_sorted.at(vec_Idx_TkMuStub_TTTrack2_dR0p2.at(minIdxdPt_TTTrack2_TkMuStubs)) - vec_L1MuzVtx_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs));
                TkMuStubsTTTrackdzVtx_13= vec_genuineTrack_z0.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)) - vec_L1MuzVtx_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs));
                TkMuStubsTTTrackdzVtx_23= vec_genuineTrack_z0.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)) - vec_L1MuzVtx_sorted.at(vec_Idx_TkMuStub_TTTrack2_dR0p2.at(minIdxdPt_TTTrack2_TkMuStubs));
                if ((fabs(TkMuStubMatchTTTrack_mu1.Eta())<=L1MuonEta_Max && fabs(TkMuStubMatchTTTrack_mu2.Eta())<=L1MuonEta_Max && fabs(TTTrackComb_mu3.Eta())<=L1MuonEta_Max && TkMuStubMatchTTTrack_mu1.Pt()>L1_LeadPtCut && TkMuStubMatchTTTrack_mu2.Pt()>L1_SubLeadPtCut))
                  {
                   vec_dz_TkMuStubsTTTrack.push_back(TkMuStubsTTTrackdzVtx_23);
                   vec_dz_TkMuStubsTTTrack.push_back(TkMuStubsTTTrackdzVtx_12);
                   vec_dz_TkMuStubsTTTrack.push_back(TkMuStubsTTTrackdzVtx_13);
                   dz_max_TkMuStubsTTTrack = std::max_element(std::begin(vec_dz_TkMuStubsTTTrack), std::end(vec_dz_TkMuStubsTTTrack));
                   TkMuStubsTTTrackdR_mu12_beforeMassCut = dR_calc(TkMuStubMatchTTTrack_mu1.Eta(), TkMuStubMatchTTTrack_mu1.Phi(), TkMuStubMatchTTTrack_mu2.Eta(), TkMuStubMatchTTTrack_mu2.Phi());
                   TkMuStubsTTTrackdR_mu13_beforeMassCut = dR_calc(TkMuStubMatchTTTrack_mu1.Eta(), TkMuStubMatchTTTrack_mu1.Phi(),TTTrackComb_mu3.Eta(), TTTrackComb_mu3.Phi());
                   TkMuStubsTTTrackdR_mu23_beforeMassCut = dR_calc(TkMuStubMatchTTTrack_mu2.Eta(), TkMuStubMatchTTTrack_mu2.Phi(), TTTrackComb_mu3.Eta(), TTTrackComb_mu3.Phi());
                   TkMuStubsTTTrack_tripleMuMass = (TkMuStubMatchTTTrack_mu1+TkMuStubMatchTTTrack_mu2+TTTrackComb_mu3).M();

                   h_TkMuStubsTTTrackdzVtx_max->Fill(fabs(*dz_max_TkMuStubsTTTrack));
                   h_TkMuStubTTTrack_TripleMu_Mass->Fill(TkMuStubsTTTrack_tripleMuMass);
                   h_TkMuSTubTTTrack_LeadPt->Fill(TkMuStubMatchTTTrack_mu1.Pt());
                   h_TkMuSTubTTTrack_SubLeadPt->Fill(TkMuStubMatchTTTrack_mu2.Pt());
                   h_TkMuSTubTTTrack_TrailPt->Fill(TTTrackComb_mu3.Pt());
                   h_TkMuStubsTTTrackkdzVtx_12->Fill(abs(TkMuStubsTTTrackdzVtx_12));
                   h_TkMuStubsTTTrackkdzVtx_23->Fill(abs(TkMuStubsTTTrackdzVtx_23));
                   h_TkMuStubsTTTrackkdzVtx_13->Fill(abs(TkMuStubsTTTrackdzVtx_13));
                   h_TkMuStubsTTTrackdR_mu12_BeforeMassCut->Fill(TkMuStubsTTTrackdR_mu12_beforeMassCut);
                   h_TkMuStubsTTTrackdR_mu13_BeforeMassCut->Fill(TkMuStubsTTTrackdR_mu13_beforeMassCut);
                   h_TkMuStubsTTTrackdR_mu23_BeforeMassCut->Fill(TkMuStubsTTTrackdR_mu23_beforeMassCut);


                   if (TkMuStubsTTTrack_tripleMuMass>massCutLow && TkMuStubsTTTrack_tripleMuMass<massCutHigh && fabs(*dz_max_TkMuStubsTTTrack)<maxdZ && TkMuStubsTTTrackdR_mu12_beforeMassCut<dRpairCut && TkMuStubsTTTrackdR_mu13_beforeMassCut<dRpairCut && TkMuStubsTTTrackdR_mu23_beforeMassCut<dRpairCut)
                    {

                     h_TkMuStubsTTTrackdR_mu12->Fill(TkMuStubsTTTrackdR_mu12_beforeMassCut);
                     h_TkMuStubsTTTrackdR_mu13->Fill(TkMuStubsTTTrackdR_mu13_beforeMassCut);
                     h_TkMuStubsTTTrackdR_mu23->Fill(TkMuStubsTTTrackdR_mu23_beforeMassCut);

                     // Calculate 2TkMuStubs&TTTrack tau candidate properties
                     TkMuStubsTTTrackTau_phi  = (TkMuStubMatchTTTrack_mu1+TkMuStubMatchTTTrack_mu2+TTTrackComb_mu3).Phi();
                     TkMuStubsTTTrackTau_eta  = (TkMuStubMatchTTTrack_mu1+TkMuStubMatchTTTrack_mu2+TTTrackComb_mu3).Eta();
                     TkMuStubsTTTrackTau_pt   = (TkMuStubMatchTTTrack_mu1+TkMuStubMatchTTTrack_mu2+TTTrackComb_mu3).Pt();

                     vec_TkMuStubsTTTrackTauPt.push_back(TkMuStubsTTTrackTau_pt);
                     vec_TkMuStubsTTTrackTauEta.push_back(TkMuStubsTTTrackTau_eta);
                     vec_TkMuStubsTTTrackTauPhi.push_back(TkMuStubsTTTrackTau_phi);
                     if (abs(TkMuStubsTTTrackTau_eta)<=2.4)
                      {
                        h_TkMuStubsTTTrackTau_pt->Fill(TkMuStubsTTTrackTau_pt);
                        h_TkMuStubsTTTrackTau_phi->Fill(TkMuStubsTTTrackTau_phi);
                        h_TkMuStubsTTTrackTau_eta->Fill(TkMuStubsTTTrackTau_eta);
                        h_TkMuStubsTTTrackTau_mass->Fill( (TkMuStubMatchTTTrack_mu1+TkMuStubMatchTTTrack_mu2+TTTrackComb_mu3).M());
                      }                                                                                                                                                                                          
                     h_TkMuStubsTTTrackLeadMuTau_pt->Fill(TkMuStubMatchTTTrack_mu1.Pt());
                     h_TkMuStubsTTTrackSubleadMuTau_pt->Fill(TkMuStubMatchTTTrack_mu2.Pt());
                     h_TkMuStubsTTTrackThirdMuTau_pt->Fill(TTTrackComb_mu3.Pt());
                     goto ExitTrackTkMustubLoop;
                 }
                }
              }
             }

       ExitTrackTkMustubLoop:


        vec_dz_TkMuStubTTTracks.clear();
        vec_TkMuStubTTTracksTauPt.clear();
        vector<double>::iterator dz_max_TkMuStubTTTracks;


       if (vec_dPt_TTTrack1_TkMuStubs.size()>0 && vec_dPt_TTTrack_GenMu2.size()>0 && vec_dPt_TTTrack_GenMu3.size()>0)
              {
              if (*min_dPt_TTTrack1_TkMuStubs<0.02 && (*min_dPt_TTTrack_GenMu2/gentau_mu2.Pt())<mindPt && (*min_dPt_TTTrack_GenMu3/gentau_mu3.Pt())<mindPt && dPt_TkMuStub1_TTTrack3>0.02 && dPt_TkMuStub1_TTTrack2>0.02)
               {
                TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.SetPtEtaPhiM(vec_L1MuPt_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)),vec_L1MuEta_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)), vec_L1MuPhi_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs)),mumass);

                TTTrackComb_mu2_1TkMuStub2Tracks.SetPtEtaPhiM(vec_genuineTrack_pt.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)),vec_genuineTrack_eta.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)),vec_genuineTrack_phi.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)),mumass);

                TTTrackComb_mu3_1TkMuStub2Tracks.SetPtEtaPhiM(vec_genuineTrack_pt.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),vec_genuineTrack_eta.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),vec_genuineTrack_phi.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)),mumass);

                TkMuStubTTTracksdzVtx_12= vec_genuineTrack_z0.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack)) - vec_L1MuzVtx_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs));
                TkMuStubTTTracksdzVtx_13= vec_genuineTrack_z0.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)) - vec_L1MuzVtx_sorted.at(vec_Idx_TkMuStub_TTTrack1_dR0p2.at(minIdxdPt_TTTrack1_TkMuStubs));
                TkMuStubTTTracksdzVtx_23= vec_genuineTrack_z0.at(vec_Idx_GenMu_Track3_dR0p2.at(minIdx_gen3TTTrack)) - vec_genuineTrack_z0.at(vec_Idx_GenMu_Track2_dR0p2.at(minIdx_gen2TTTrack));
                if ( fabs(TTTrackComb_mu2_1TkMuStub2Tracks.Eta())<=L1MuonEta_Max && fabs(TTTrackComb_mu3_1TkMuStub2Tracks.Eta())<=L1MuonEta_Max && TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Pt()>L1_LeadPtCut )
                  {
                   vec_dz_TkMuStubTTTracks.push_back(TkMuStubTTTracksdzVtx_23);
                   vec_dz_TkMuStubTTTracks.push_back(TkMuStubTTTracksdzVtx_12);
                   vec_dz_TkMuStubTTTracks.push_back(TkMuStubTTTracksdzVtx_13);
                   dz_max_TkMuStubTTTracks = std::max_element(std::begin(vec_dz_TkMuStubTTTracks), std::end(vec_dz_TkMuStubTTTracks));
                   h_TkMuStubTTTracskdzVtx_max->Fill(fabs(*dz_max_TkMuStubTTTracks));

                   TkMuStubTTTracksdR_mu12_beforeMassCut = dR_calc(TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Eta(),TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Phi(),TTTrackComb_mu2_1TkMuStub2Tracks.Eta(),TTTrackComb_mu2_1TkMuStub2Tracks.Phi());
                   TkMuStubTTTracksdR_mu13_beforeMassCut = dR_calc(TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Eta(),TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Phi(),TTTrackComb_mu3_1TkMuStub2Tracks.Eta(),TTTrackComb_mu3_1TkMuStub2Tracks.Phi());
                   TkMuStubTTTracksdR_mu23_beforeMassCut = dR_calc(TTTrackComb_mu2_1TkMuStub2Tracks.Eta(),TTTrackComb_mu2_1TkMuStub2Tracks.Phi(),TTTrackComb_mu3_1TkMuStub2Tracks.Eta(),TTTrackComb_mu3_1TkMuStub2Tracks.Phi());

                   h_TkMuStubTTTracksdR_mu12_beforeMassCut->Fill(dR_calc(TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Eta(),TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Phi(),TTTrackComb_mu2_1TkMuStub2Tracks.Eta(),TTTrackComb_mu2_1TkMuStub2Tracks.Phi()));
                   TkMuStubTTTracks_tripleMuMass = (TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks+TTTrackComb_mu2_1TkMuStub2Tracks+TTTrackComb_mu3_1TkMuStub2Tracks).M();
                   h_TkMuStubTTTracks_TripleMu_Mass->Fill(TkMuStubTTTracks_tripleMuMass);

                 if (TkMuStubTTTracks_tripleMuMass>massCutLow && TkMuStubTTTracks_tripleMuMass<massCutHigh && fabs(*dz_max_TkMuStubTTTracks)<maxdZ && TkMuStubTTTracksdR_mu12_beforeMassCut<dRpairCut && TkMuStubTTTracksdR_mu13_beforeMassCut<dRpairCut && TkMuStubTTTracksdR_mu23_beforeMassCut<dRpairCut)
                  {
                     h_TkMuStubTTTracksdR_mu12->Fill(TkMuStubTTTracksdR_mu12_beforeMassCut);
                     h_TkMuStubTTTracksdR_mu13->Fill(TkMuStubTTTracksdR_mu13_beforeMassCut);
                     h_TkMuStubTTTracksdR_mu23->Fill(TkMuStubTTTracksdR_mu23_beforeMassCut);

                     // Calculate 2TkMuStubs&TTTrack tau candidate properties
                     TkMuStubTTTracksTau_phi  = (TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks+TTTrackComb_mu2_1TkMuStub2Tracks+TTTrackComb_mu3_1TkMuStub2Tracks).Phi();
                     TkMuStubTTTracksTau_eta  = (TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks+TTTrackComb_mu2_1TkMuStub2Tracks+TTTrackComb_mu3_1TkMuStub2Tracks).Eta();
                     TkMuStubTTTracksTau_pt   = (TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks+TTTrackComb_mu2_1TkMuStub2Tracks+TTTrackComb_mu3_1TkMuStub2Tracks).Pt();

                     vec_TkMuStubTTTracksTauPt.push_back(TkMuStubTTTracksTau_pt);
                     if (abs(TkMuStubsTTTrackTau_eta)<=2.4)
                      {
                        h_TkMuStubTTTracksTau_pt->Fill(TkMuStubTTTracksTau_pt);
                        h_TkMuStubTTTracksTau_phi->Fill(TkMuStubTTTracksTau_phi);
                        h_TkMuStubTTTracksTau_eta->Fill(TkMuStubTTTracksTau_eta);
                        h_TkMuStubTTTracksTau_mass->Fill(TkMuStubTTTracks_tripleMuMass);
                      }                                                                                                                                                                                          
                     h_TkMuStubTTTracksLeadMuTau_pt->Fill(TkMuStubMatchTTTracks_mu1_1TkMuStub2Tracks.Pt());
                     h_TkMuStubTTTracksSubleadMuTau_pt->Fill(TTTrackComb_mu2_1TkMuStub2Tracks.Pt());
                     h_TkMuStubTTTracksThirdMuTau_pt->Fill(TTTrackComb_mu3_1TkMuStub2Tracks.Pt());
                     goto ExitTkMustubTTTrackLoop;
                 }}}}
       ExitTkMustubTTTrackLoop:
       vec_dR_L1MuGenMu0FromTau.clear();
       vec_L1MuGenMu1FromTau.clear();
       vec_L1MuGenMu2FromTau.clear();
       vec_dPt_L1_GenMu0.clear();
       vec_dPt_L1_GenMu1.clear();
       vec_dPt_L1_GenMu2.clear();
       vector<double>::iterator min_genMu0, min_genMu1, min_genMu2;
       vector<double>::iterator min_genMu3_TTTracks, min_genMu0_dPt, min_genMu1_dPt, min_genMu2_dPt;
       vec_TTTracksGenMu3FromTau.clear();

       vec_Idx_GenMu_TkMuStub2_dR0p2.clear();
       vec_Idx_GenMu_TkMuStub1_dR0p2.clear();
       vec_Idx_GenMu_TkMuStub0_dR0p2.clear();
       if (gen_Taus.size()==1){
          for (Int_t L1Mu=0; L1Mu<vec_sortL1List.size(); L1Mu++){
             if (( abs(vec_L1MuEta_sorted.at(L1Mu))<=L1MuonEta_Max)){
                dR_L1Mu_GenMu0 = dR_calc(vec_L1MuEta_sorted.at(L1Mu), vec_L1MuPhi_sorted.at(L1Mu),  gentau_mu1.Eta(),  gentau_mu1.Phi());
                dPt_L1_GenMu0 = fabs(vec_L1MuPt_sorted.at(L1Mu) - gentau_mu1.Pt());
                vec_dR_L1MuGenMu0FromTau.push_back(dR_L1Mu_GenMu0);
                h_dR_TkMuStub0_Gen->Fill(dR_L1Mu_GenMu0);
                if(dR_L1Mu_GenMu0<dRcone_preMatch){
                    vec_dPt_L1_GenMu0.push_back(dPt_L1_GenMu0);
                    vec_Idx_GenMu_TkMuStub0_dR0p2.push_back(L1Mu);
                   }

                dR_L1Mu_GenMu1 = dR_calc(vec_L1MuEta_sorted.at(L1Mu), vec_L1MuPhi_sorted.at(L1Mu),  gentau_mu2.Eta(),  gentau_mu2.Phi());
                dPt_L1_GenMu1 = fabs(vec_L1MuPt_sorted.at(L1Mu) - gentau_mu2.Pt());
                vec_L1MuGenMu1FromTau.push_back(dR_L1Mu_GenMu1);
                if(dR_L1Mu_GenMu1<dRcone_preMatch){
                    vec_dPt_L1_GenMu1.push_back(dPt_L1_GenMu1);
                    vec_Idx_GenMu_TkMuStub1_dR0p2.push_back(L1Mu);
                   }
                h_dR_TkMuStub1_Gen->Fill(dR_L1Mu_GenMu1);


                dR_L1Mu_GenMu2 = dR_calc(vec_L1MuEta_sorted.at(L1Mu), vec_L1MuPhi_sorted.at(L1Mu), gentau_mu3.Eta(), gentau_mu3.Phi());
                dPt_L1_GenMu2=fabs(vec_L1MuPt_sorted.at(L1Mu) - gentau_mu3.Pt());
                vec_L1MuGenMu2FromTau.push_back(dR_L1Mu_GenMu2);
                if(dR_L1Mu_GenMu2<dRcone_preMatch){
                    vec_dPt_L1_GenMu2.push_back(dPt_L1_GenMu2);
                    vec_Idx_GenMu_TkMuStub2_dR0p2.push_back(L1Mu);
                   }
                h_dR_TkMuStub2_Gen->Fill(dR_L1Mu_GenMu2);
             }}

          if (vec_dPt_L1_GenMu2.size()>0 && vec_dPt_L1_GenMu1.size()>0 && vec_dPt_L1_GenMu0.size()>0){
               min_genMu0_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu0), std::end(vec_dPt_L1_GenMu0));
               min_genMu1_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu1), std::end(vec_dPt_L1_GenMu1));
               min_genMu2_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu2), std::end(vec_dPt_L1_GenMu2));

               minIdx_mu0_dPt = std::distance(std::begin(vec_dPt_L1_GenMu0), min_genMu0_dPt);
               minIdx_mu1_dPt = std::distance(std::begin(vec_dPt_L1_GenMu1), min_genMu1_dPt);
               minIdx_mu2_dPt = std::distance(std::begin(vec_dPt_L1_GenMu2), min_genMu2_dPt);

            }


         if (vec_sortL1List.size()>=3 && vec_dPt_L1_GenMu0.size()>0 && vec_dPt_L1_GenMu1.size()>0 && vec_dPt_L1_GenMu2.size()>0){

             if (vec_L1MuEta_sorted.size()>3 && vec_dPt_L1_GenMu0.size()>0 && vec_dPt_L1_GenMu1.size()>0 && vec_dPt_L1_GenMu2.size()>0 && (vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)==vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt) || vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)==vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt) || vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)==vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt))){
               if ( vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) < vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt) && vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) < vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt)){
                 if (vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)==vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)){
                    vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt) = 1000;
                    min_genMu1_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu1), std::end(vec_dPt_L1_GenMu1));
                    minIdx_mu1_dPt = std::distance(std::begin(vec_dPt_L1_GenMu1), min_genMu1_dPt);
                 }
                 if (vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)==vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)){
                   vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt) = 1000;
                   min_genMu2_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu2), std::end(vec_dPt_L1_GenMu2));
                   minIdx_mu2_dPt = std::distance(std::begin(vec_dPt_L1_GenMu2), min_genMu2_dPt);
                  }
                 if (vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)==vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt) && vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)!=vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)){
                  if (vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt)<vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt)){
                      vec_dPt_L1_GenMu2.at(Find_Idx(vec_Idx_GenMu_TkMuStub2_dR0p2,minIdx_mu2_dPt, vec_Idx_GenMu_TkMuStub0_dR0p2,minIdx_mu0_dPt)) = 1000;
                      vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt) = 1000;
                      min_genMu2_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu2), std::end(vec_dPt_L1_GenMu2));
                      minIdx_mu2_dPt = std::distance(std::begin(vec_dPt_L1_GenMu2), min_genMu2_dPt);
                  }

               else if (vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt)>vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt)){
                  vec_dPt_L1_GenMu1.at(Find_Idx(vec_Idx_GenMu_TkMuStub1_dR0p2,minIdx_mu1_dPt, vec_Idx_GenMu_TkMuStub0_dR0p2,minIdx_mu0_dPt)) = 1000;
                  vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt) = 1000;
                  min_genMu1_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu1), std::end(vec_dPt_L1_GenMu1));
                  minIdx_mu1_dPt = std::distance(std::begin(vec_dPt_L1_GenMu1), min_genMu1_dPt);
                 }
                }}

           if (vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt) < vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) &&  vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt)<vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt)){
              if (vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)==vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)){
                    vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) = 1000;
                    min_genMu0_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu0), std::end(vec_dPt_L1_GenMu0));
                    minIdx_mu0_dPt = std::distance(std::begin(vec_dPt_L1_GenMu0), min_genMu0_dPt);
                 }
              if (vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)==vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)){
                  vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt) = 1000;
                  min_genMu2_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu2), std::end(vec_dPt_L1_GenMu2));
                  minIdx_mu2_dPt = std::distance(std::begin(vec_dPt_L1_GenMu2), min_genMu2_dPt);
                }
             if (vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)==vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt) && vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)!=vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)){
                 if (vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt)<vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt)){
                  vec_dPt_L1_GenMu2.at(Find_Idx(vec_Idx_GenMu_TkMuStub2_dR0p2,minIdx_mu2_dPt, vec_Idx_GenMu_TkMuStub1_dR0p2,minIdx_mu1_dPt)) = 1000;
                  vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt) = 1000;
                  min_genMu2_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu2), std::end(vec_dPt_L1_GenMu2));
                  minIdx_mu2_dPt = std::distance(std::begin(vec_dPt_L1_GenMu2), min_genMu2_dPt);
                  }
                else if (vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt)>vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt)){
                  vec_dPt_L1_GenMu0.at(Find_Idx(vec_Idx_GenMu_TkMuStub0_dR0p2,minIdx_mu0_dPt, vec_Idx_GenMu_TkMuStub1_dR0p2,minIdx_mu1_dPt)) = 1000;
                  vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) = 1000;
                  min_genMu0_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu0), std::end(vec_dPt_L1_GenMu0));
                  minIdx_mu0_dPt = std::distance(std::begin(vec_dPt_L1_GenMu0), min_genMu0_dPt);
                 }
                }}
           if (vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt)< vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) && vec_dPt_L1_GenMu2.at(minIdx_mu2_dPt) < vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt)){
               if (vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)==vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)){
                   vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) = 1000;
                   min_genMu0_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu0), std::end(vec_dPt_L1_GenMu0));
                   minIdx_mu0_dPt = std::distance(std::begin(vec_dPt_L1_GenMu0), min_genMu0_dPt);
                 }
              if (vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)==vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)){
                  vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt) = 1000;
                  min_genMu1_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu1), std::end(vec_dPt_L1_GenMu1));
                  minIdx_mu1_dPt = std::distance(std::begin(vec_dPt_L1_GenMu1), min_genMu1_dPt);
                  //vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt) = minIdx_mu1_dPt;
                }
             if (vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)==vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt) && vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)!=vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)){
                 if (vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt)<vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt)){
                     vec_dPt_L1_GenMu1.at(Find_Idx(vec_Idx_GenMu_TkMuStub1_dR0p2,minIdx_mu1_dPt, vec_Idx_GenMu_TkMuStub2_dR0p2,minIdx_mu2_dPt)) = 1000;
                     vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt) = 1000;
                     min_genMu1_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu1), std::end(vec_dPt_L1_GenMu1));
                     minIdx_mu1_dPt = std::distance(std::begin(vec_dPt_L1_GenMu1), min_genMu1_dPt);
                   }
                 else if (vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt)>vec_dPt_L1_GenMu1.at(minIdx_mu1_dPt)){
                     vec_dPt_L1_GenMu0.at(Find_Idx(vec_Idx_GenMu_TkMuStub0_dR0p2,minIdx_mu0_dPt, vec_Idx_GenMu_TkMuStub2_dR0p2,minIdx_mu2_dPt)) = 1000;
                     vec_dPt_L1_GenMu0.at(minIdx_mu0_dPt) = 1000;
                     min_genMu0_dPt = std::min_element(std::begin(vec_dPt_L1_GenMu0), std::end(vec_dPt_L1_GenMu0));
                     minIdx_mu0_dPt = std::distance(std::begin(vec_dPt_L1_GenMu0), min_genMu0_dPt);
                 }
                }}}}}




          vec_L1TauPt.clear();
          vec_L1TauEta.clear();
          vec_L1TauPhi.clear();
          vec_L1TauM.clear();

          vec_dz_L1.clear();

          vector<double>::iterator dz_min, dz_max;

          if (vec_dPt_L1_GenMu0.size()>0 && vec_dPt_L1_GenMu1.size()>0 && vec_dPt_L1_GenMu2.size()>0){
             if (vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)!=vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt) && vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)!=vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt) && vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)!=vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt) && *min_genMu0_dPt!=1000 && *min_genMu1_dPt!=1000 && *min_genMu2_dPt!=1000){
               h_mindPt_TkMuStub0_Gen->Fill(*min_genMu0_dPt);
               h_mindPt_TkMuStub1_Gen->Fill(*min_genMu1_dPt);
               h_mindPt_TkMuStub2_Gen->Fill(*min_genMu2_dPt); 

               h_ratio_TkMuStub0dPtOvPt -> Fill((*min_genMu0_dPt)/gentau_mu1.Pt());             
               h_ratio_TkMuStub1dPtOvPt -> Fill((*min_genMu1_dPt)/gentau_mu2.Pt());
               h_ratio_TkMuStub2dPtOvPt -> Fill((*min_genMu2_dPt)/gentau_mu3.Pt());

                 if ((*min_genMu0_dPt/gentau_mu1.Pt())<mindPt && (*min_genMu1_dPt/gentau_mu2.Pt())<mindPt && (*min_genMu2_dPt/gentau_mu3.Pt())<mindPt){

                     L1_mu1.SetPtEtaPhiM(vec_L1MuPt_sorted.at(vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)),vec_L1MuEta_sorted.at(vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)),vec_L1MuPhi_sorted.at(vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt)),mumass);
                     L1_mu2.SetPtEtaPhiM(vec_L1MuPt_sorted.at(vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)),vec_L1MuEta_sorted.at(vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)),vec_L1MuPhi_sorted.at(vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)),mumass);
                     L1_mu3.SetPtEtaPhiM(vec_L1MuPt_sorted.at(vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)),vec_L1MuEta_sorted.at(vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)),vec_L1MuPhi_sorted.at(vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)),mumass);

                    L1dzVtx_12= (vec_L1MuzVtx_sorted.at(vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt))) - (vec_L1MuzVtx_sorted.at(vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt)));
                    L1dzVtx_13= (vec_L1MuzVtx_sorted.at(vec_Idx_GenMu_TkMuStub0_dR0p2.at(minIdx_mu0_dPt))) - (vec_L1MuzVtx_sorted.at(vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)));
                    L1dzVtx_23= (vec_L1MuzVtx_sorted.at(vec_Idx_GenMu_TkMuStub1_dR0p2.at(minIdx_mu1_dPt))) - (vec_L1MuzVtx_sorted.at(vec_Idx_GenMu_TkMuStub2_dR0p2.at(minIdx_mu2_dPt)));

                    h_TkMuStubLeadPt->Fill(L1_mu1.Pt());
                    h_TkMuStubSubLeadPt->Fill(L1_mu2.Pt());
                    h_TkMuStubThirdPt->Fill(L1_mu3.Pt());

                   if ((fabs(L1_mu1.Eta())<=L1MuonEta_Max && fabs(L1_mu2.Eta())<=L1MuonEta_Max && fabs(L1_mu3.Eta())<=L1MuonEta_Max) && L1_mu1.Pt()>L1_LeadPtCut &&  L1_mu2.Pt()>L1_SubLeadPtCut && L1_mu3.Pt()> L1_TrailPtCut ){
                       h_L1dzVtx_12->Fill(abs(L1dzVtx_12));
                       h_L1dzVtx_23->Fill(abs(L1dzVtx_23));
                       h_L1dzVtx_13->Fill(abs(L1dzVtx_13));
                       vec_dz_L1.push_back(L1dzVtx_12);
                       vec_dz_L1.push_back(L1dzVtx_13);
                       vec_dz_L1.push_back(L1dzVtx_23);
                       dz_min = std::min_element(std::begin(vec_dz_L1), std::end(vec_dz_L1));
                       dz_max = std::max_element(std::begin(vec_dz_L1), std::end(vec_dz_L1));
                       h_L1dzVtx_min->Fill(fabs(*dz_min));
                       h_L1dzVtx_max->Fill(fabs(*dz_max));
  
                       TkMuStubdR_mu12 = dR_calc(L1_mu1.Eta(), L1_mu1.Phi(), L1_mu2.Eta(), L1_mu2.Phi());
                       TkMuStubdR_mu13 = dR_calc(L1_mu1.Eta(), L1_mu1.Phi(), L1_mu3.Eta(), L1_mu3.Phi());
                       TkMuStubdR_mu23 = dR_calc(L1_mu2.Eta(), L1_mu2.Phi(), L1_mu3.Eta(), L1_mu3.Phi());
                    
                       L1_tripleMuMass = (L1_mu1+L1_mu2+L1_mu3).M();
                       h_L1TriMuMass->Fill(L1_tripleMuMass);
                       h_TkMuStub_dR12_beforeCut->Fill(TkMuStubdR_mu12);
                       h_TkMuStub_dR13_beforeCut->Fill(TkMuStubdR_mu13);
                       h_TkMuStub_dR23_beforeCut->Fill(TkMuStubdR_mu23);
                       if (L1_tripleMuMass>massCutLow && L1_tripleMuMass<massCutHigh && fabs(*dz_max)<maxdZ && TkMuStubdR_mu12<dRpairCut && TkMuStubdR_mu13<dRpairCut && TkMuStubdR_mu23<dRpairCut )
                           {
                             h_L1dR_mu12_AfterMassCut->Fill(TkMuStubdR_mu12);
                             h_L1dR_mu13_AfterMassCut->Fill(TkMuStubdR_mu13);
                             h_L1dR_mu23_AfterMassCut->Fill(TkMuStubdR_mu23);          
                             // Calculate L1 tau properties
                             L1Tau_phi  = (L1_mu1+L1_mu2+L1_mu3).Phi();
                             L1Tau_eta  = (L1_mu1+L1_mu2+L1_mu3).Eta();
                             L1Tau_pt   = (L1_mu1+L1_mu2+L1_mu3).Pt();
                             L1Tau_mass = (L1_mu1+L1_mu2+L1_mu3).M();
                             vec_L1TauPt.push_back(L1Tau_pt);
                             vec_L1TauEta.push_back(L1Tau_eta);
                             vec_L1TauPhi.push_back(L1Tau_phi);
                             vec_L1TauM.push_back(L1Tau_mass);          
                             if (abs(L1Tau_eta)<=2.4)
                             {
                              h_L1Tau_pt->Fill(L1Tau_pt);
                              h_L1Tau_phi->Fill(L1Tau_phi);
                              h_L1Tau_eta->Fill(L1Tau_eta);
                              h_L1Tau_mass->Fill(L1Tau_mass);
                             }

                             if (abs(L1Tau_eta)<0.8 && abs(L1Tau_eta)>=0) h_L1Tau_pt_Bar->Fill(L1Tau_pt);
                             if (abs(L1Tau_eta)<1.2 && abs(L1Tau_eta)>=0.8) h_L1Tau_pt_Over->Fill(L1Tau_pt);
                             if (abs(L1Tau_eta)<=2.4 && abs(L1Tau_eta)>=1.2) h_L1Tau_pt_End->Fill(L1Tau_pt);
                             if (abs(L1_mu1.Eta())<0.8 && abs(L1_mu1.Eta())>=0)   h_TkMuStub1pt_barrel->Fill(L1_mu1.Pt());
                             if (abs(L1_mu1.Eta())<1.2 && abs(L1_mu1.Eta())>=0.8) h_TkMuStub1pt_overlap->Fill(L1_mu1.Pt());
                             if (abs(L1_mu1.Eta())<2.4 && abs(L1_mu1.Eta())>=1.2) h_TkMuStub1pt_endcap->Fill(L1_mu1.Pt());
                             if (abs(L1_mu2.Eta())<0.8 && abs(L1_mu2.Eta())>=0)   h_TkMuStub2pt_barrel->Fill(L1_mu2.Pt());
                             if (abs(L1_mu2.Eta())<1.2 && abs(L1_mu2.Eta())>=0.8) h_TkMuStub2pt_overlap->Fill(L1_mu2.Pt());
                             if (abs(L1_mu2.Eta())<2.4 && abs(L1_mu2.Eta())>=1.2) h_TkMuStub2pt_endcap->Fill(L1_mu2.Pt());
                             if (abs(L1_mu3.Eta())<0.8 && abs(L1_mu3.Eta())>=0)   h_TkMuStub3pt_barrel->Fill(L1_mu3.Pt());
                             if (abs(L1_mu3.Eta())<1.2 && abs(L1_mu3.Eta())>=0.8) h_TkMuStub3pt_overlap->Fill(L1_mu3.Pt());
                             if (abs(L1_mu3.Eta())<2.4 && abs(L1_mu3.Eta())>=1.2) h_TkMuStub3pt_endcap->Fill(L1_mu3.Pt());
                             h_L1LeadMuTau_pt->Fill(L1_mu1.Pt());
                             h_L1SubleadMuTau_pt->Fill(L1_mu2.Pt());
                             h_L1ThirdMuTau_pt->Fill(L1_mu3.Pt());
                             goto TkMuStubLoop;
            }
          }}}}

        TkMuStubLoop:

        h_nL1Taus->Fill(vec_L1TauPt.size());



        gPassed.assign(1, false);
        gPassed_3TkMuStubs_10.assign(1,false);
        gPassed_3TkMuStubs_15.assign(1,false);
        gPassed_3TkMuStubs_20.assign(1,false);
        gPassed_3TkMuStubs_25.assign(1,false);
        gPassed_3TkMuStubs_30.assign(1,false);
        gPassed_3TkMuStubs_35.assign(1,false);
        gPassed_3TkMuStubs_40.assign(1,false);

        gPassed_TTTrack.assign(1, false);
        gPassed_TTTrack_10.assign(1,false);
        gPassed_TTTrack_12.assign(1,false);
        gPassed_TTTrack_14.assign(1,false);
        gPassed_TTTrack_16.assign(1,false);
        gPassed_TTTrack_18.assign(1,false);
        gPassed_TTTrack_20.assign(1,false);
        gPassed_TTTrack_22.assign(1,false);
        gPassed_TTTrack_24.assign(1,false);

        gPassed_TkMuStubsTTTrack.assign(1,false);
        gPassed_TkMuStubsTTTrack_10.assign(1,false);
        gPassed_TkMuStubsTTTrack_15.assign(1,false);
        gPassed_TkMuStubsTTTrack_20.assign(1,false);
        gPassed_TkMuStubsTTTrack_25.assign(1,false);
        gPassed_TkMuStubsTTTrack_30.assign(1,false);
        gPassed_TkMuStubsTTTrack_35.assign(1,false);
        gPassed_TkMuStubsTTTrack_40.assign(1,false);

        gPassed_TkMuStubTTTracks.assign(1,false);
        gPassed_TkMuStubTTTracks_10.assign(1,false);
        gPassed_TkMuStubTTTracks_12.assign(1,false);
        gPassed_TkMuStubTTTracks_14.assign(1,false);
        gPassed_TkMuStubTTTracks_16.assign(1,false);
        gPassed_TkMuStubTTTracks_18.assign(1,false);
        gPassed_TkMuStubTTTracks_20.assign(1,false);
        gPassed_TkMuStubTTTracks_22.assign(1,false);
        gPassed_TkMuStubTTTracks_24.assign(1,false);
        gPassed_TkMuStubTTTracks_26.assign(1,false);
        gPassed_TkMuStubTTTracks_28.assign(1,false);
        gPassed_TkMuStubTTTracks_30.assign(1,false);
        gPassed_TkMuStubTTTracks_32.assign(1,false);
        gPassed_TkMuStubTTTracks_34.assign(1,false);
        gPassed_TkMuStubTTTracks_36.assign(1,false);
        gPassed_TkMuStubTTTracks_38.assign(1,false);
        gPassed_TkMuStubTTTracks_40.assign(1,false);
        gPassed_TkMuStubTTTracks_45.assign(1,false);

        gPassed_OR.assign(1,false);
        gPassed_ORTkMuStubsTracks.assign(1,false);
        gPassed_ORTkMuStubsTrack_Tracks.assign(1,false);

        gPassedeta_3TkMuStubs_10.assign(1,false);
        gPassedeta_3Tracks_10.assign(1,false);
        gPassedeta_2TkMuStubsTrack_10.assign(1,false);
        gPassedeta_1TkMuStub2Tracks_10.assign(1,false);

        gPassedeta_3TkMuStubs_15.assign(1,false);
        gPassedeta_3Tracks_15.assign(1,false);
        gPassedeta_2TkMuStubsTrack_15.assign(1,false);
        gPassedeta_1TkMuStub2Tracks_15.assign(1,false);

        gPassedeta_3TkMuStubs_20.assign(1,false);
        gPassedeta_3Tracks_20.assign(1,false);
        gPassedeta_2TkMuStubsTrack_20.assign(1,false);
        gPassedeta_1TkMuStub2Tracks_20.assign(1,false);

      if (gen_Taus.size()==1)
      {
       if (vec_L1TauPt.size()>0)
         {
          gPassed[0] = 1;
          if(L1Tau_pt>10 ) {
              gPassedeta_3TkMuStubs_10[0]=1;
              gPassed_3TkMuStubs_10[0] =1;
              }
          if(L1Tau_pt>15 ) { 
              gPassedeta_3TkMuStubs_15[0]=1;
              gPassed_3TkMuStubs_15[0]=1;
              }
          if(L1Tau_pt>20 ){
              gPassedeta_3TkMuStubs_20[0]=1;
              }
         if(L1Tau_pt>20 ){
              gPassed_3TkMuStubs_20[0]=1;
              }
         if(L1Tau_pt>25 ) gPassed_3TkMuStubs_25[0]=1; 
         if(L1Tau_pt>30 ) gPassed_3TkMuStubs_30[0]=1; 
         if(L1Tau_pt>35 ) gPassed_3TkMuStubs_35[0]=1; 
         if(L1Tau_pt>40 ) gPassed_3TkMuStubs_40[0]=1; 
        }

       if ( vec_TTTrackTauPt.size()>0 )
        {
         gPassed_TTTrack[0]= 1;
         if(TTTrackTau_pt>10 ) {
             gPassedeta_3Tracks_10[0]=1;         
             gPassed_TTTrack_10[0] =1;
             }
         if(TTTrackTau_pt>15 ) {
             gPassedeta_3Tracks_15[0]=1;         
             }
         if(TTTrackTau_pt>20 ){
             gPassedeta_3Tracks_20[0]=1;         
             }

         if(TTTrackTau_pt>12 ) gPassed_TTTrack_12[0]=1;
         if(TTTrackTau_pt>14 ) gPassed_TTTrack_14[0]=1;
         if(TTTrackTau_pt>16 ) gPassed_TTTrack_16[0]=1;
         if(TTTrackTau_pt>18 ) gPassed_TTTrack_18[0]=1;
         if(TTTrackTau_pt>20 ) gPassed_TTTrack_20[0]=1;
         if(TTTrackTau_pt>22 ) gPassed_TTTrack_22[0]=1;
         if(TTTrackTau_pt>24 ) gPassed_TTTrack_24[0]=1;
         }

       if (vec_TkMuStubsTTTrackTauPt.size()>0)
        {
         gPassed_TkMuStubsTTTrack[0]= 1;
         if(TkMuStubsTTTrackTau_pt>10 ) {
             gPassedeta_2TkMuStubsTrack_10[0]=1;
             gPassed_TkMuStubsTTTrack_10[0]=1;
             }
         if(TkMuStubsTTTrackTau_pt>15 ) {
             gPassedeta_2TkMuStubsTrack_15[0]=1;
             gPassed_TkMuStubsTTTrack_15[0]=1;
             }
         if(TkMuStubsTTTrackTau_pt>20 ) {
             gPassedeta_2TkMuStubsTrack_20[0]=1;
             }
          if(TkMuStubsTTTrackTau_pt>20 ) {
             gPassed_TkMuStubsTTTrack_20[0]=1;
             }
         if(TkMuStubsTTTrackTau_pt>25 ) gPassed_TkMuStubsTTTrack_25[0]=1;
         if(TkMuStubsTTTrackTau_pt>30 ) gPassed_TkMuStubsTTTrack_30[0]=1;
         if(TkMuStubsTTTrackTau_pt>35 ) gPassed_TkMuStubsTTTrack_35[0]=1;
         if(TkMuStubsTTTrackTau_pt>40 ) gPassed_TkMuStubsTTTrack_40[0]=1;
         }
       if (vec_TkMuStubTTTracksTauPt.size()>0)
        {
          gPassed_TkMuStubTTTracks[0]=1;
          if (TkMuStubTTTracksTau_pt>10) {
              gPassedeta_1TkMuStub2Tracks_10[0]=1;
              gPassed_TkMuStubTTTracks_10[0]=1;
              }
          if (TkMuStubTTTracksTau_pt>15 ) {
             gPassedeta_1TkMuStub2Tracks_15[0]=1;
             }
          if (TkMuStubTTTracksTau_pt>20 ) {
             gPassedeta_1TkMuStub2Tracks_20[0]=1;
             }
         if(TkMuStubTTTracksTau_pt>12 ) gPassed_TkMuStubTTTracks_12[0]=1;
         if(TkMuStubTTTracksTau_pt>14 ) gPassed_TkMuStubTTTracks_14[0]=1;
         if(TkMuStubTTTracksTau_pt>16 ) gPassed_TkMuStubTTTracks_16[0]=1;
         if(TkMuStubTTTracksTau_pt>18 ) gPassed_TkMuStubTTTracks_18[0]=1;
         if(TkMuStubTTTracksTau_pt>20 ) gPassed_TkMuStubTTTracks_20[0]=1;
         if(TkMuStubTTTracksTau_pt>22 ) gPassed_TkMuStubTTTracks_22[0]=1;
         if(TkMuStubTTTracksTau_pt>24 ) gPassed_TkMuStubTTTracks_24[0]=1;
         if(TkMuStubTTTracksTau_pt>26 ) gPassed_TkMuStubTTTracks_26[0]=1;
         if(TkMuStubTTTracksTau_pt>28 ) gPassed_TkMuStubTTTracks_28[0]=1;
         if(TkMuStubTTTracksTau_pt>30 ) gPassed_TkMuStubTTTracks_30[0]=1;
         if(TkMuStubTTTracksTau_pt>32 ) gPassed_TkMuStubTTTracks_32[0]=1;
         if(TkMuStubTTTracksTau_pt>34 ) gPassed_TkMuStubTTTracks_34[0]=1;
         if(TkMuStubTTTracksTau_pt>36 ) gPassed_TkMuStubTTTracks_36[0]=1;
         if(TkMuStubTTTracksTau_pt>38 ) gPassed_TkMuStubTTTracks_38[0]=1;
         if(TkMuStubTTTracksTau_pt>40 ) gPassed_TkMuStubTTTracks_40[0]=1;
         if(TkMuStubTTTracksTau_pt>45 ) gPassed_TkMuStubTTTracks_45[0]=1;
        }
       if (vec_L1TauPt.size()>0 or (vec_L1TauPt.size()==0 &&  vec_TkMuStubsTTTrackTauPt.size()>0))
         {
          gPassed_OR[0] = 1;
         }

      if(vec_L1TauPt.size()>0 or (vec_TTTrackTauPt.size()>0 && vec_L1TauPt.size()==0))
       {
          gPassed_ORTkMuStubsTracks[0]=1;
         }
      if(vec_TkMuStubsTTTrackTauPt.size()>0 or (vec_TTTrackTauPt.size()>0 && vec_TkMuStubsTTTrackTauPt.size()==0))
         {
          gPassed_ORTkMuStubsTrack_Tracks[0]=1;
         }

      

        L1TauEff_HighPt->Fill(gPassed[0], vec_gTauPt.at(0));
        L1TauEff->Fill(gPassed[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>12)L1TauEff_10->Fill(gPassed_3TkMuStubs_10[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>17)L1TauEff_15->Fill(gPassed_3TkMuStubs_15[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>22)L1TauEff_20->Fill(gPassed_3TkMuStubs_20[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>27)L1TauEff_25->Fill(gPassed_3TkMuStubs_25[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>32)L1TauEff_30->Fill(gPassed_3TkMuStubs_30[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>37)L1TauEff_35->Fill(gPassed_3TkMuStubs_35[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>42)L1TauEff_40->Fill(gPassed_3TkMuStubs_40[0], vec_gTauPt.at(0));

        TTTrackTauEff_HighPt->Fill(gPassed_TTTrack[0],vec_gTauPt.at(0));
        TTTrackTauEff->Fill(gPassed_TTTrack[0],vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>12)TTTrackTauEff_10->Fill(gPassed_TTTrack_10[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>14)TTTrackTauEff_12->Fill(gPassed_TTTrack_12[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>16)TTTrackTauEff_14->Fill(gPassed_TTTrack_14[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>18)TTTrackTauEff_16->Fill(gPassed_TTTrack_16[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>22)TTTrackTauEff_18->Fill(gPassed_TTTrack_18[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>24)TTTrackTauEff_20->Fill(gPassed_TTTrack_20[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>26)TTTrackTauEff_22->Fill(gPassed_TTTrack_22[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>20)TTTrackTauEff_18->Fill(gPassed_TTTrack_18[0], vec_gTauPt.at(0));


        TkMuStubsTTTrackTauEff_HighPt->Fill(gPassed_TkMuStubsTTTrack[0],vec_gTauPt.at(0));
        TkMuStubsTTTrackTauEff->Fill(gPassed_TkMuStubsTTTrack[0],vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>12)TkMuStubsTTTrackTauEff_10->Fill(gPassed_TkMuStubsTTTrack_10[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>17)TkMuStubsTTTrackTauEff_15->Fill(gPassed_TkMuStubsTTTrack_15[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>22)TkMuStubsTTTrackTauEff_20->Fill(gPassed_TkMuStubsTTTrack_20[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>27)TkMuStubsTTTrackTauEff_25->Fill(gPassed_TkMuStubsTTTrack_25[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>32)TkMuStubsTTTrackTauEff_30->Fill(gPassed_TkMuStubsTTTrack_30[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>34)TkMuStubsTTTrackTauEff_35->Fill(gPassed_TkMuStubsTTTrack_35[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>42)TkMuStubsTTTrackTauEff_40->Fill(gPassed_TkMuStubsTTTrack_40[0], vec_gTauPt.at(0));

        TkMu1Stub2TTTrackTauEff->Fill(gPassed_TkMuStubTTTracks[0], vec_gTauPt.at(0));
        TkMu1Stub2TTTrackTauEff_HighPt->Fill(gPassed_TkMuStubTTTracks[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>10)TkMu1Stub2TTTrackTauEff_10->Fill(gPassed_TkMuStubTTTracks_10[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>12)TkMu1Stub2TTTrackTauEff_12->Fill(gPassed_TkMuStubTTTracks_12[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>14)TkMu1Stub2TTTrackTauEff_14->Fill(gPassed_TkMuStubTTTracks_14[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>16)TkMu1Stub2TTTrackTauEff_16->Fill(gPassed_TkMuStubTTTracks_16[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>18)TkMu1Stub2TTTrackTauEff_18->Fill(gPassed_TkMuStubTTTracks_18[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>20)TkMu1Stub2TTTrackTauEff_20->Fill(gPassed_TkMuStubTTTracks_20[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>22)TkMu1Stub2TTTrackTauEff_22->Fill(gPassed_TkMuStubTTTracks_22[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>24)TkMu1Stub2TTTrackTauEff_24->Fill(gPassed_TkMuStubTTTracks_24[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>26)TkMu1Stub2TTTrackTauEff_26->Fill(gPassed_TkMuStubTTTracks_26[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>28)TkMu1Stub2TTTrackTauEff_28->Fill(gPassed_TkMuStubTTTracks_28[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>30)TkMu1Stub2TTTrackTauEff_30->Fill(gPassed_TkMuStubTTTracks_30[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>32)TkMu1Stub2TTTrackTauEff_32->Fill(gPassed_TkMuStubTTTracks_32[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>34)TkMu1Stub2TTTrackTauEff_34->Fill(gPassed_TkMuStubTTTracks_34[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>36)TkMu1Stub2TTTrackTauEff_36->Fill(gPassed_TkMuStubTTTracks_36[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>38)TkMu1Stub2TTTrackTauEff_38->Fill(gPassed_TkMuStubTTTracks_38[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>40)TkMu1Stub2TTTrackTauEff_40->Fill(gPassed_TkMuStubTTTracks_40[0], vec_gTauPt.at(0));
        if (vec_gTauPt.at(0)>45)TkMu1Stub2TTTrackTauEff_45->Fill(gPassed_TkMuStubTTTracks_45[0], vec_gTauPt.at(0));


        TkMuStubsOR2TkMuStubsTrack->Fill(gPassed_OR[0], vec_gTauPt.at(0));
        TkMuStubsOR2TkMuStubsTrack_High->Fill(gPassed_OR[0], vec_gTauPt.at(0));
        TkMuStubsOR3Tracks->Fill(gPassed_ORTkMuStubsTracks[0], vec_gTauPt.at(0));
        TkMuStubsOR3Tracks_High->Fill(gPassed_ORTkMuStubsTracks[0], vec_gTauPt.at(0));
        TkMuStubTrackOR3Tracks->Fill(gPassed_ORTkMuStubsTrack_Tracks[0], vec_gTauPt.at(0));
        TkMuStubTrackOR3Tracks_High->Fill(gPassed_ORTkMuStubsTrack_Tracks[0], vec_gTauPt.at(0));

        if (vec_gTauPt.at(0)>15)L13TkMuStubs_eta_10->Fill(gPassedeta_3TkMuStubs_10[0], vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>15)L13Tracks_eta_10->Fill(gPassedeta_3Tracks_10[0], vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>15)L12TkMuStubsTrack_eta_10->Fill(gPassedeta_2TkMuStubsTrack_10[0],vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>15)L11TkMuStub2Tracks_eta_10->Fill(gPassedeta_1TkMuStub2Tracks_10[0],vec_gTauEta.at(0));

        if (vec_gTauPt.at(0)>20)L13TkMuStubs_eta_15->Fill(gPassedeta_3TkMuStubs_15[0], vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>20)L13Tracks_eta_15->Fill(gPassedeta_3Tracks_15[0], vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>20)L12TkMuStubsTrack_eta_15->Fill(gPassedeta_2TkMuStubsTrack_15[0],vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>20)L11TkMuStub2Tracks_eta_15->Fill(gPassedeta_1TkMuStub2Tracks_15[0],vec_gTauEta.at(0));


        if (vec_gTauPt.at(0)>25)L13TkMuStubs_eta_20->Fill(gPassedeta_3TkMuStubs_20[0], vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>25)L13Tracks_eta_20->Fill(gPassedeta_3Tracks_20[0], vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>25)L12TkMuStubsTrack_eta_20->Fill(gPassedeta_2TkMuStubsTrack_20[0],vec_gTauEta.at(0));
        if (vec_gTauPt.at(0)>25)L11TkMuStub2Tracks_eta_20->Fill(gPassedeta_1TkMuStub2Tracks_20[0],vec_gTauEta.at(0));

    }
  if(i%100==0) cout<<" Events processed: "<<i<<"/"<<nevents<<endl;
}


for (Int_t bins10=0; bins10<=80; bins10++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_10->GetEfficiency(bins10);
    if (binCont>=0.6) {
    cout << "For L1 threshold 10 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins10 <<  endl;
    break;}
}
for (Int_t bins12=0; bins12<=80; bins12++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_12->GetEfficiency(bins12);
    if (binCont>=0.6) {
    cout << "For L1 threshold 12 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins12 <<  endl;
    break;}
}
for (Int_t bins14=0; bins14<=80; bins14++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_14->GetEfficiency(bins14);
    if (binCont>=0.6) {
    cout << "For L1 threshold 14 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins14 <<  endl;
    break;}
}
for (Int_t bins16=0; bins16<=80; bins16++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_16->GetEfficiency(bins16);
    if (binCont>=0.6) {
    cout << "For L1 threshold 16 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins16 <<  endl;
    break;}
}

for (Int_t bins18=0; bins18<=80; bins18++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_18->GetEfficiency(bins18);
    if (binCont>=0.6) {
    cout << "For L1 threshold 18 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins18 <<  endl;
    break;}
}
for (Int_t bins20=0; bins20<=80; bins20++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_20->GetEfficiency(bins20);
    if (binCont>=0.6) {
    cout << "For L1 threshold 20 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins20 <<  endl;
    break;}
}
for (Int_t bins22=0; bins22<=80; bins22++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_22->GetEfficiency(bins22);
    if (binCont>=0.6) {
    cout << "For L1 threshold 22 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins22 <<  endl;
    break;}
}
for (Int_t bins24=0; bins24<=80; bins24++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_24->GetEfficiency(bins24);
    if (binCont>=0.6) {
    cout << "For L1 threshold 24 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins24 <<  endl;
    break;}
}
for (Int_t bins26=0; bins26<=80; bins26++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_26->GetEfficiency(bins26);
    if (binCont>=0.6) {
    cout << "For L1 threshold 26 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins26 <<  endl;
    break;}
}
for (Int_t bins28=0; bins28<=80; bins28++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_28->GetEfficiency(bins28);
    if (binCont>=0.6) {
    cout << "For L1 threshold 28 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins28 <<  endl;
    break;}
}
for (Int_t bins30=0; bins30<=80; bins30++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_30->GetEfficiency(bins30);
    if (binCont>=0.6) {
    cout << "For L1 threshold 30 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins30 <<  endl;
    break;}
}
for (Int_t bins32=0; bins32<=80; bins32++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_32->GetEfficiency(bins32);
    if (binCont>=0.6) {
    cout << "For L1 threshold 32 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins32 <<  endl;
    break;}
}
for (Int_t bins34=0; bins34<=80; bins34++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_34->GetEfficiency(bins34);
    if (binCont>=0.6) {
    cout << "For L1 threshold 34 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins34 <<  endl;
    break;}
}
for (Int_t bins36=0; bins36<=80; bins36++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_36->GetEfficiency(bins36);
    if (binCont>=0.6) {
    cout << "For L1 threshold 36 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins36 <<  endl;
    break;}
}
for (Int_t bins38=0; bins38<=80; bins38++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_38->GetEfficiency(bins38);
    if (binCont>=0.6) {
    cout << "For L1 threshold 38 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins38 <<  endl;
    break;}
}
for (Int_t bins40=0; bins40<=80; bins40++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_40->GetEfficiency(bins40);
    if (binCont>=0.6) {
    cout << "For L1 threshold 40 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins40 <<  endl;
    break;}
}
for (Int_t bins45=0; bins45<=80; bins45++){
    Double_t binCont = TkMu1Stub2TTTrackTauEff_45->GetEfficiency(bins45);
    if (binCont>=0.6) {
    cout << "For L1 threshold 45 GeV "<< binCont << " the Gen pt at which the eff is>=60% is " << bins45 <<  endl;
    break;}
}

    histf->cd();
    histf->Write();
    histf->Close();
}
