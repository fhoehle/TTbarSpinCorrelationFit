
#include <TH1F.h> 
#include <TFile.h> 
#include <TF1.h> 
#include <TLegend.h> 
#include <TMath.h> 
#include <THStack.h> 
#include <TCanvas.h> 
#include <TROOT.h>
#include <TStyle.h>
#include <iostream>
#include "TLegend.h"
#include "TLatex.h"


void ComparePlots(TString channel, TString quantity, TString cut){
  
  
  
  //***********************
  //Get histograms
  //***********************
   
  gStyle->SetPadRightMargin(0.13);
  gStyle->SetPadLeftMargin(0.13); 
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  
  TCanvas *c1 = new TCanvas("c1", "plots",400,400,800,600);
  c1->SetFillColor(10);
  //c1->SetFillStyle(4000);
  c1->SetBorderSize(2); 
  c1->SetLogy(0);

   
  TFile *f_input1 = new TFile("ttbar_mcatnlo_SC_ref.root");
  TFile *f_input2 = new TFile("ttbar_mcatnlo_NoSC_ref.root");
   TH1F * histo1 ;
    TH1F * histo2;
    TString plotname;
  if(channel != "all"){
   plotname = quantity + "_" + channel + "_"  +cut +  "_" + "TTbarSig";
  if(cut == "") plotname = quantity + "_" + channel + "_" + "TTbarSig";
  if(quantity =="Inv")  plotname = quantity  + channel + "MassPair_" + cut +  "_" +"TTbarSig";
  if(quantity =="Inv" && cut == "" )  plotname = quantity  + channel + "MassPair_" +"TTbarSig";
  
  cout << "plotname " << plotname << endl;
  
  f_input1->cd();
  
   histo1 = (TH1F*)gROOT->FindObject(plotname.Data());
  
  f_input2->cd();
  
   histo2 = (TH1F*)gROOT->FindObject(plotname.Data());
  
  }
  
  if(channel == "all"){  
  
  
    //----------------------------------------------------------------------
 
    string thechannel = "emu";
    TString plotname = quantity + "_" + thechannel + "_"  +cut +  "_" + "TTbarSig";
    if(cut == "") plotname = quantity + "_" + thechannel + "_" + "TTbarSig";
    if(quantity =="Inv")  plotname = quantity  + thechannel + "MassPair_" + cut +  "_" +"TTbarSig";
    if(quantity =="Inv" && cut == "" )  plotname = quantity  + thechannel + "MassPair_" +"TTbarSig";
  
    cout << "plotname " << plotname << endl;
  
    f_input1->cd();
  
    TH1F * histo1_emu = (TH1F*)gROOT->FindObject(plotname.Data());
  
    f_input2->cd();
  
    TH1F * histo2_emu = (TH1F*)gROOT->FindObject(plotname.Data());
   //----------------------------------------------------------------------
    thechannel = "ee";
    plotname = quantity + "_" + thechannel + "_"  +cut +  "_" + "TTbarSig";
    if(cut == "") plotname = quantity + "_" + thechannel + "_" + "TTbarSig";
    if(quantity =="Inv")  plotname = quantity  + thechannel + "MassPair_" + cut +  "_" +"TTbarSig";
    if(quantity =="Inv" && cut == "" )  plotname = quantity  + thechannel + "MassPair_" +"TTbarSig";
  
    cout << "plotname " << plotname << endl;
  
    f_input1->cd();
  
    TH1F * histo1_ee = (TH1F*)gROOT->FindObject(plotname.Data());
  
    f_input2->cd();
  
    TH1F * histo2_ee = (TH1F*)gROOT->FindObject(plotname.Data());


   //----------------------------------------------------------------------
 
    channel = "mumu";
     plotname = quantity + "_" + channel + "_"  +cut +  "_" + "TTbarSig";
    if(cut == "") plotname = quantity + "_" + channel + "_" + "TTbarSig";
    if(quantity =="Inv")  plotname = quantity  + channel + "MassPair_" + cut +  "_" +"TTbarSig";
    if(quantity =="Inv" && cut == "" )  plotname = quantity  + channel + "MassPair_" +"TTbarSig";
  
    cout << "plotname " << plotname << endl;
  
    f_input1->cd();
  
    histo1 = (TH1F*)gROOT->FindObject(plotname.Data());
  
    f_input2->cd();
  
    histo2 = (TH1F*)gROOT->FindObject(plotname.Data());

    
    histo1->Add(histo1, histo1_ee, 1, 1);
    histo1->Add(histo1, histo1_emu, 1, 1);
    
    histo2->Add(histo2, histo2_ee, 1, 1);
    histo2->Add(histo2, histo2_emu, 1, 1);
    
    
    
    
    
  }
  
  
  histo1->Sumw2();
  histo2->Sumw2();
  
  TLegend* qw = 0;
  if(quantity == "Njets" || quantity == "NBjets" || quantity == "DeltaPhiLLept" ) qw = new TLegend(.15,.60,.45,.85);
  else qw = new TLegend(.60,.70,.85,.85);
  
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  //qw->AddEntry(histo2,        "ttbar MG5" ,    "ep");
  qw->AddEntry(histo1,        "t#bar{t} with spin correlation","l" );
  qw->AddEntry(histo2,        "t#bar{t} without spin correlation" ,    "l");
  //qw->AddEntry(histo1,        "t#bar{t} MCatNLO fullsim  ","f" );
  //qw->AddEntry(histo2,        "t#bar{t} MCatNLO fastsim " ,    "ep");
 

  histo1->Scale(1/histo1->Integral());
  histo2->Scale(1/histo2->Integral());
  
  histo1->SetMinimum(0.0001);
  histo1->SetMaximum(histo1->GetMaximum()+0.5*histo1->GetMaximum());
  //if(quantity == "DeltaPhiLLept") histo1->GetXaxis()->SetTitle("#Delta #phi (rad)");
  if(quantity == "DeltaPhiLLept") histo1->GetXaxis()->SetTitle("#Delta #phi_{l+l-}");
  if(quantity == "PtMu1") histo1->GetXaxis()->SetTitle("PtMu1");
  if(quantity == "PtMu2") histo1->GetXaxis()->SetTitle("PtMu2");
  if(quantity == "PtEl1") histo1->GetXaxis()->SetTitle("PtEl1");
  if(quantity == "PtEl2") histo1->GetXaxis()->SetTitle("PtEl2");
  if(quantity == "Inv") histo1->GetXaxis()->SetTitle("Mll");
  if(quantity == "Njets") histo1->GetXaxis()->SetTitle("Njets");
  if(quantity == "Met") histo1->GetXaxis()->SetTitle("Met");
  if(quantity == "NBjets") histo1->GetXaxis()->SetTitle("NBjets");
  if(quantity == "PtJet1") histo1->GetXaxis()->SetTitle("PtJet1");
  if(quantity == "PtJet2") histo1->GetXaxis()->SetTitle("PtJet2");
  if(quantity == "CSVDiscriBjets") histo1->GetXaxis()->SetTitle("CSVDiscriBjets");
  
  
  
  //histo1->SetFillColor(5);
  //histo2->SetMarkerSize(1.2);
  //histo2->SetMarkerStyle(20);
  
  histo1->GetYaxis()->SetTitle("arbitrary units");
  histo1->GetYaxis()->SetTitleOffset(1.2);
  histo1->SetTitle("");
  histo1->SetLineColor(4);
  histo1->SetLineStyle(2);
  
  histo1->SetLineWidth(2);
  histo2->SetLineWidth(2);
  
  histo1->Draw("He");
  histo2->Draw("Hesame");
  
  histo1->GetXaxis()->SetTitleOffset(1.2);
  histo1->SetTitle("");
  
  
   TLatex* text1 = new TLatex(0.15,0.92,"CMS Simulation");
    text1->SetNDC();
    text1->SetTextAlign(9);
    //text1->SetX(0.18);
    //text1->SetY(0.92);
    //text1->SetLineWidth(2);
    //text1->SetTextFont(42);
    //text1->SetTextSize(0.0610687);
  text1->SetTextSize(0.04);
    //    text1->SetTextSizePixels(24);// dflt=28
    text1->Draw("same");
  
  qw->Draw("same");
  plotname = "plots/"+plotname+".gif";
  c1->SaveAs(plotname.Data());
  

} 


void ComparePlotsCutFlow(TString channel){
 //***********************
  //Get histograms
  //***********************
   
  gStyle->SetPadRightMargin(0.13);
  gStyle->SetPadLeftMargin(0.13); 
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  
  TCanvas *c1 = new TCanvas("c1", "plots",400,400,800,600);
  c1->SetFillColor(10);
  c1->SetFillStyle(4000);
  c1->SetBorderSize(2); 
  c1->SetLogy(0);

  TFile *f_input1 = new TFile("FinalFiles/ttbar_mcatnlo_NoSC_ref.root");
  TFile *f_input2 = new TFile("FinalFiles/ttbar_mcatnlo_NoSC_ref.root");
   
  TString plotname = "CutFlow_" + channel+ "_TTbarSig";
  
  
  f_input1->cd();
  
  TH1F * histo1 = (TH1F*)gROOT->FindObject(plotname.Data());
  
  f_input2->cd();
  
  TH1F * histo2 = (TH1F*)gROOT->FindObject(plotname.Data());
  
  
  histo1->SetFillColor(5);
  histo2->SetMarkerSize(1.2);
  histo2->SetMarkerStyle(20);
  
  histo1->Sumw2();
  histo2->Sumw2();
  
  
  histo1->Divide(histo1, histo2, 1, 1, "b" );
  
  histo1->Draw();
  plotname = plotname+".gif";
  c1->SaveAs(plotname.Data());

}


void ComparePlots(){


 //ComparePlots("emu", "CSVDiscriBjets", "aftermetcut");
  /*
 ComparePlots("mumu", "PtMu1", "");
 ComparePlots("mumu", "PtMu1", "");
 ComparePlots("mumu", "PtMu2", "");
 ComparePlots("ee", "PtEl1", "");
 ComparePlots("ee", "PtEl2", "");
 ComparePlots("ee", "Inv", "");
 ComparePlots("mumu", "Inv", "");
 ComparePlots("emu", "Inv", "");
 ComparePlots("emu", "Njets", "");
 ComparePlots("ee", "Njets", "");
 ComparePlots("mumu", "Njets", "");
 ComparePlots("emu", "NBjets", "");
 ComparePlots("ee", "NBjets", "");
 ComparePlots("mumu", "NBjets", "");
 ComparePlots("mumu", "Met", "afterjetcut");
 ComparePlots("ee", "Met", "afterjetcut");
 ComparePlots("emu", "Met", "afterjetcut");
 ComparePlots("ee", "PtJet1", "");
 ComparePlots("ee", "PtJet2", "");
 ComparePlots("mumu", "PtJet1", "");
 ComparePlots("mumu", "PtJet2", "");
 ComparePlots("emu", "PtJet2", "");
 ComparePlots("emu", "PtJet1", "");
 */
 
 
 //ComparePlots("all", "Njets", "");
 ComparePlots("all", "DeltaPhiLLept", "afterbtag1");
/* ComparePlots("all", "DeltaPhiLLept", "afterbtag2");
 
 ComparePlots("all", "Njets", "");
 ComparePlots("all", "DeltaPhiLLept", "afterbtag1");
 ComparePlots("all", "DeltaPhiLLept", "afterbtag2");
 
 ComparePlots("ee", "DeltaPhiLLept", "afterbtag1");
 ComparePlots("mumu", "DeltaPhiLLept", "afterbtag1");
 ComparePlots("emu", "DeltaPhiLLept", "afterbtag1");
 
 
 
ComparePlots("emu", "CSVDiscriBjets", "aftermetcut");
ComparePlots("ee", "CSVDiscriBjets", "aftermetcut");
ComparePlots("mumu", "CSVDiscriBjets", "aftermetcut");
ComparePlots("mumu", "CSVDiscri", "aftermetcut");
ComparePlots("ee", "CSVDiscri", "aftermetcut");
ComparePlots("mumu", "CSVDiscri", "aftermetcut");
*/

}



