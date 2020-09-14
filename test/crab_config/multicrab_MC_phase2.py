import CRABClient
from WMCore.Configuration import Configuration
#from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = Configuration()

config.section_('General')
config.General.transferOutputs = True
config.General.workArea = 'crab_projects/L1MuPhase2Ntuples_WToTauTo3Mu_PU0_GenMax1124_8_TruthMapTTTrack/l1t-phase2-v2p37p1/PU200'

config.section_('JobType')
config.JobType.psetName = '../run_L1MuNtuple.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['WToTauTo3Mu_PU0.root']
config.JobType.pyCfgParams = ['doPhase2Emul=True']

config.section_('Data')
config.Data.splitting = 'Automatic'
config.Data.outLFNDirBase = '/store/user/ipapaver/L1MuPhase2Ntuples_WToTauTo3Mu_PU0_GenMax1124_8_TruthMapTTTrack/Tag_l1t-phase2-v2p37p1/PU200'
config.Data.publication = False

config.section_('Site')
#config.Site.storageSite = 'T2_IT_Legnaro'
config.Site.storageSite = 'T2_CH_CERN'

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException
    from multiprocessing import Process

    def submit(config):
        try:
            crabCommand('submit', config = config)
        except HTTPException as hte:
            print "Failed submitting task: %s" % (hte.headers)
        except ClientException as cle:
            print "Failed submitting task: %s" % (cle)

    #############################################################################################
    ## From now on that's what users should modify: this is the a-la-CRAB2 configuration part. ##
    #############################################################################################
    
    config.General.requestName = 'L1MuPhase2Ntuples_WToTauTo3Mu_PU0_GenMax1124_8_TruthMapTTTrack'
    #config.Data.unitsPerJob = 300
    config.Data.inputDataset = '/WToTauTo3Mu_TuneCP5_14TeV-pythia8/PhaseIITDRSpring19DR-NoPU_106X_upgrade2023_realistic_v3-v1/GEN-SIM-DIGI-RAW'
    #'/Nu_E10-pythia8-gun/PhaseIITDRSpring19DR-PU200_106X_upgrade2023_realistic_v3-v3/GEN-SIM-DIGI-RAW'
    #'/WToTauTo3Mu_TuneCP5_14TeV-pythia8/PhaseIITDRSpring19DR-PU200_106X_upgrade2023_realistic_v3-v1/GEN-SIM-DIGI-RAW'
    #'/Nu_E10-pythia8-gun/PhaseIITDRSpring19DR-PU200_106X_upgrade2023_realistic_v3-v3/GEN-SIM-DIGI-RAW'
    #'/WToTauTo3Mu_TuneCP5_14TeV-pythia8/PhaseIITDRSpring19DR-PU200_106X_upgrade2023_realistic_v3-v1/GEN-SIM-DIGI-RAW'

    p = Process(target=submit, args=(config,))
    p.start()
    p.join()

    #config.General.requestName = 'L1MuPhase2Ntuples_SingleMuPt2to100_PU140'
    #config.Data.unitsPerJob = 3
    #config.Data.inputDataset = '/SingleMu_FlatPt-2to100/PhaseIIFall17D-L1TPU140_93X_upgrade2023_realistic_v5-v1/GEN-SIM-DIGI-RAW'
    #p = Process(target=submit, args=(config,))
    #p.start()
    #p.join()

    #config.General.requestName = 'L1MuPhase2Ntuples_SingleMuPt2to100_PU200'
    #config.Data.unitsPerJob = 3
    #config.Data.inputDataset = '/SingleMu_FlatPt-2to100/PhaseIIFall17D-L1TPU200_93X_upgrade2023_realistic_v5-v1/GEN-SIM-DIGI-RAW'
    #p = Process(target=submit, args=(config,))
    #p.start()
    #p.join()
