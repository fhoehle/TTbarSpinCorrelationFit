{
gROOT->ProcessLine(".L SpinFit.C+");
RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);
//j = new SpinFit("ttbar_mcatnlo_NoSC_ref.root","ttbar_mcatnlo_SC_ref.root"); FH
j = new SpinFit("proof_backup_outputProof_13-04-18_14-35-35_Mcatnlo6134_TauPolSys_FullSim_completeSample_ReweightingOn.root","proof_backup_outputProof_13-04-18_09-48-55_Mcatnlo5217_TauPolSys_FullSim_completeSample_ReweightingOn.root");

j->do_toys(10000,1.07047);// 0.960356);//0.54) ;
TCanvas * output = new TCanvas("output_pseudoExp","",700,500);
output->Divide(2,2);
output->cd(1);
j->toy_mean->Draw();
output->cd(2);
j->toy_bias->Draw();
output->cd(3);
j->toy_error->Draw();
output->cd(4);
j->toy_pull->Draw();

}
