import FWCore.ParameterSet.Config as cms

L1MuGlobalNtupleMaker = cms.EDAnalyzer('L1MuGlobalNtupleMaker',
                                  RunningOnData      = cms.bool(False),
                                  PileUpScenario     = cms.int32(200),
                                  genParticle        = cms.InputTag("genParticles"),
                                  PileupSrc          = cms.InputTag("addPileupInfo"),
                                  triggerbits        = cms.InputTag("TriggerResults","","HLT"),
                                  L1muon             = cms.InputTag("simGmtStage2Digis",""),
                                  bmtfMuon           = cms.InputTag("simBmtfDigis","BMTF"),
                                  omtfMuon           = cms.InputTag("simOmtfDigis","OMTF"),
                                  emtfMuon           = cms.InputTag("simEmtfDigis","EMTF"),
                                  KbmtfMuon          = cms.InputTag("simKBmtfDigis","BMTF"),
                                  bmtfInputPhMuon    = cms.InputTag("simDtTriggerPrimitiveDigis",""),
                                  bmtfInputThMuon    = cms.InputTag("simDtTriggerPrimitiveDigis",""),
                                  tkMuon             = cms.InputTag("L1TkMuons",""),                          #filled only if doPhase2Emul=true
                                  #tkMuonStubsBMTF        = cms.InputTag("L1TkMuons",""),                      #filled only if doPhase2Emul=true
                                  tkMuonStubsBMTF = cms.InputTag("l1StubMatchedMuons",""),  # by Vlad...                                                              
                                  tkMuonStubsEMTF = cms.InputTag("l1TkMuonStubEndCapS12",""),
                                  tkMuonStubsOMTF = cms.InputTag("l1TkMuonStubOverlap","MuonTracks"),
                                  tkGlbMuon          = cms.InputTag("L1TkGlbMuons",""),                       #filled only if doPhase2Emul=true
                                  tttracks           = cms.InputTag("TTTracksFromTracklet","Level1TTTracks"), #filled only if doPhase2Emul=true 
                                  #tttracksTruth            = cms.InputTag("TTTrackAssociatorFromPixelDigis", "Level1TTTracks"),
                                  #L1TrackInputTag    = cms.InputTag("TTTracksFromTrackletEmulation", "Level1TTTracks"),
                                  trkG4Parts         = cms.InputTag("mix","MergedTrackTruth","HLT"),          #G4 tracking particles
                                  maxGenMuons        = cms.int32(1124),
                                  maxL1Muons         = cms.int32(1124),
                                  maxBMTFMuons       = cms.int32(1124),
                                  maxOMTFMuons       = cms.int32(1124),
                                  maxEMTFMuons       = cms.int32(1124),
                                  maxKBMTFMuons      = cms.int32(1124),
                                  maxDTPrimitives    = cms.int32(1124),
                                  maxTkMuons         = cms.int32(1124),
                                  maxTkMuonStubs     = cms.int32(1124),
                                  maxTkGlbMuons      = cms.int32(1124),
                                  maxTTTracks        = cms.int32(1124),
                                  maxTrkG4Parts      = cms.int32(8),
                                 )
