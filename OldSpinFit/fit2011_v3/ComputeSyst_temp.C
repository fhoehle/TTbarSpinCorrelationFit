


void ComputeSyst(){ 
 
 //double theRefValue= ;
 double theRefValue= 0.74207 ;

 gROOT->ProcessLine(".L SpinFitSyst.C+");
 gROOT->ProcessLine(".L SpinFit.C+");
 

 TString systtype = "initsyst";
 
 if(systtype == ""){
 
  SpinFit * ref = new SpinFit();
  ref->do_toys(5000,theRefValue);
  ref->toy_mean->Draw();
  ref->toy_mean->Fit("gaus");
  theRefValue = ref->toy_mean->GetFunction("gaus")->GetParameter(1);
 }else{
 
   TString FastSimNoSpinCorr; 
   TString FastSimSpinCorr ;  
 
   //if(systtype == "JesDown"){
    //FastSimNoSpinCorr = "P0_2011/templates/proof_FastSimNoSpinCorr_JESdown.root";
    //FastSimSpinCorr   = "P0_2011/templates/proof_SpinCorr_JETdown.root";
    
    FastSimNoSpinCorr = "initFastSimNoSpinCorr";
    FastSimSpinCorr   = "initFastSimSpinCorr";
    
   //}
 
   string ofilenametex = "systList.tex";
   ofstream ofile(ofilenametex.c_str(), ios::app);
   ofile.precision(3);
   ofile.setf(ios::fixed);

   //ofile << "file 1 " <<  FastSimNoSpinCorr.Data() << "   file 2 " << FastSimSpinCorr.Data() << endl;
   
   
   SpinFitSyst * theSys = new SpinFitSyst(FastSimNoSpinCorr.Data(),FastSimSpinCorr.Data());
   theSys->do_toys(3000,theRefValue); 

   theSys->toy_mean->Draw();
   theSys->toy_mean->Fit("gaus");
   
   
   
   double  theSysValue= theSys->toy_mean->GetFunction("gaus")->GetParameter(1);
   //ofile << " the ref value " << theRefValue  << "   the sys value " << theSysValue << endl;
   theSysValue= theSysValue ;
   theRefValue = theRefValue ;
   //ofile << " the ref value after " << theRefValue  << "   the sys value after " << theSysValue<< endl;
 
   double  theSysUnc  = (theSysValue-theRefValue);
   double  theSysUncRel  = 100*(theSysValue-theRefValue)/theRefValue;
 
  
   if(systtype == "JesDown")  ofile << "Jes Down &" ;
   if(systtype == "JesUp")    ofile << "Jes Up &" ;
   if(systtype == "Jer")      ofile << "Jer &" ;
   if(systtype == "LeptSF")   ofile << " LeptSF&" ;
   if(systtype == "elecup")   ofile << " elecup&" ;
   if(systtype == "elecDown") ofile << " elecDown&" ;
   if(systtype == "elecResol") ofile << " elecDown&" ;
   if(systtype == "PUUP")   ofile << " PUUP&" ;
   if(systtype == "PUDown") ofile << " PUDown &" ;
   if(systtype == "btagup") ofile << " btag up &" ;
   if(systtype == "btagdow") ofile << " btag dow &" ;
   if(systtype == "mass170") ofile << "  mass170&" ;
   if(systtype == "mass1775") ofile << " mass1775 &" ;
   if(systtype == "hadrshower") ofile << " hadrs, hower &" ;
   if(systtype == "genlevel") ofile << " generator &" ;
   if(systtype == "genlevel") ofile << " generator &" ;
   
   ofile << theSysUnc << " &" << theSysUncRel << "\\% \\\\" << endl;
   ofile  << "\\hline " << endl;
  }
  gApplication->Terminate();
}
