import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras
import FWCore.ParameterSet.VarParsing as VarParsing
import sys

options = VarParsing.VarParsing()

options.register('globalTag',
                 '103X_upgrade2023_realistic_v2', #default value 
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.string,
                 "Global Tag")


process = cms.Process('REPR',eras.Phase2C8_trigger)


# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.Geometry.GeometryExtended2023D41Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2023D41_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)


# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('root://cms-xrd-global.cern.ch//store/mc/PhaseIITDRSpring19DR/WToTauTo3Mu_TuneCP5_14TeV-pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3-v1/240000/F8F18CA1-4F51-2046-9A37-9BAD13CD84CF.root'),
    secondaryFileNames = cms.untracked.vstring()
)


# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('repr nevts:2'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

process.TFileService = cms.Service('TFileService',
    fileName = cms.string('Test_NewConfig_GeomD41.root')
)


#L1 tracking
process.load("L1Trigger.TrackFindingTracklet.L1TrackletTracks_cff")
process.TTTracks=cms.Path(process.L1TrackletTracks) #run only the tracking (no MC truth associators)
process.TTTracksWithTruth=cms.Path(process.L1TrackletTracksWithAssociators) #run the tracking AND MC truth associators)
process.VertexProducer.l1TracksInputTag = cms.InputTag("TTTracksFromTracklet", "Level1TTTracks")
process.VertexProducer.l1TracksInputTagTruth = cms.InputTag("TTTrackAssociatorFromPixelDigis", "Level1TTTracks")

print "Using GlobalTag", options.globalTag
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, options.globalTag, '')

process.load('SimCalorimetry.HcalTrigPrimProducers.hcaltpdigi_cff')
process.load('CalibCalorimetry.CaloTPG.CaloTPGTranscoder_cfi')

# Path and EndPath definitions
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.endjob_step = cms.EndPath(process.endOfProcess)

#Import the ntuplizer
process.load("L1Trigger.L1MuGlobalNtuples.L1MuGlobalNtupleMaker_cfi")
process.ntuplizer = cms.Path(process.L1MuGlobalNtupleMaker)

# Schedule definition
process.schedule = cms.Schedule(process.TTTracksWithTruth, process.L1simulation_step, process.ntuplizer, process.endjob_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

from L1Trigger.L1TMuonEndCap.customise_Phase2 import customise as customise_Phase2
process = customise_Phase2(process)


process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True),
)

