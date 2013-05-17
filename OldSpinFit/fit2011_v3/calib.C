#include <iostream>
#include <iomanip>

#include <vector>
#include <TH1F.h>
#include <TFile.h>
#include <TString.h>
#include <TLegend.h>
#include <TVectorD.h>
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TLatex.h"
#include "TTree.h"
#include <TROOT.h>

using namespace std;

static const float massPoints[9] = {161.5, 163.5, 166.5, 169.5, 172.5, 175.5, 178.5, 181.5, 184.5};
float fitMass = 172.777;//;173.231;
float fitUnc = 0.4278;//0.596;

bool reduced = false;

void cmsprelim()
{
    TLatex* text1 = new TLatex(3.570061,25,"CMS Preliminary, 5.0 fb^{-1} at #sqrt{s} = 7 TeV");
    text1->SetNDC();
    text1->SetTextAlign(13);
    text1->SetX(0.167);
    text1->SetY(0.987);
    text1->SetTextFont(42);
    text1->SetTextSizePixels(24);
    text1->Draw();
   }

void cmssim()
{
    TLatex* text1 = new TLatex(3.570061,23.08044,"CMS Simulation");
    text1->SetNDC();
    text1->SetTextAlign(13);
    text1->SetX(0.167);
    text1->SetY(0.985);
    text1->SetTextFont(42);
    text1->SetTextSizePixels(24);
    //text1->Draw();
   
}

void calib(char fn[100],char tag[20]){
  //gROOT->ProcessLine("setTDRStyle()");
  
//   gStyle->SetPadRightMargin(0.15);
//   gStyle->SetPadLeftMargin(0.15);
//   gStyle->SetPadBottomMargin(0.15);
//   gStyle->SetOptTitle(0);
//   gStyle->SetOptStat(0);
//   gStyle->SetErrorX(0);
//   
//   gStyle->SetOptDate(0);
//   gStyle->SetStatColor(0);
//   gStyle->SetTitleColor(1);
  //gStyle->SetTitleW(0.4);
  //gStyle->SetTitleH(0.07);
  //gStyle->SetOptStat(stati);
  // gStyle->SetFrameFillColor(18);
  //gStyle->SetPalette(51,0);

  TCanvas* c_min = new TCanvas("c_min","", 600, 600);
//   c_min->SetFillColor(10);
//   c_min->SetFillStyle(4000);
//   c_min->SetBorderSize(2);
//   
//   //c1.Divide(2,2);
//   c_min->SetFillColor(0);
//   c_min->SetBorderMode(0);
//   c_min->SetFrameFillColor(10);
  
  char name[200], hname[50];

  TFile* theFile = new TFile (fn) ;
  TTree* tree;
  theFile->GetObject("PE",tree);
  Int_t           i;
  Float_t         ratioCorrGen;
  TBranch        *b_i;   //!
  TBranch        *b_ratioCorrGen;   //!
  tree->SetBranchAddress("i", &i, &b_i);
  tree->SetBranchAddress("ratioCorrGen", &ratioCorrGen, &b_ratioCorrGen);

  Long64_t nentries = tree->GetEntriesFast();

  TVectorD massV(nentries), meanV(nentries), biasV(nentries), pullV(nentries), pullWV(nentries);
  TVectorD massErrV(nentries), meanErrV(nentries), biasErrV(nentries), pullErrV(nentries), pullWErrV(nentries);
  float minTMass = -100, maxTMass = 0;


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    nb = tree->GetEntry(jentry);   nbytes += nb;

    if (minTMass==-100.) {minTMass = ratioCorrGen;}
    maxTMass = ratioCorrGen;

    sprintf(hname,"meanMass_%i", i);
    TH1F* toy_mean  = (TH1F*) gDirectory->Get(hname);
    sprintf(hname,"biasMass_%i", i);
    TH1F* toy_bias= (TH1F*) gDirectory->Get(hname) ;
    sprintf(hname,"errMass_%i", i);
    TH1F* toy_error= (TH1F*) gDirectory->Get(hname) ;
    sprintf(hname,"pullMass_%i", i);
    TH1F* toy_pull= (TH1F*) gDirectory->Get(hname) ;

    toy_mean->Fit("gaus","Q");
    toy_bias->Fit("gaus","Q");
    toy_pull->Fit("gaus","Q");

    massV(jentry)=ratioCorrGen;
    meanV(jentry)=toy_mean->GetFunction("gaus")->GetParameter(1);
    biasV(jentry)=toy_bias->GetFunction("gaus")->GetParameter(1);
    pullV(jentry)=toy_pull->GetFunction("gaus")->GetParameter(1);
    pullWV(jentry)=toy_pull->GetFunction("gaus")->GetParameter(2);
    massErrV(jentry)=0.;
    meanErrV(jentry)=toy_bias->GetFunction("gaus")->GetParameter(2)/sqrt(1);
    biasErrV(jentry)=toy_bias->GetFunction("gaus")->GetParameter(2)/sqrt(1);
    pullErrV(jentry)=toy_pull->GetFunction("gaus")->GetParError(1)/sqrt(1);
    pullWErrV(jentry)=toy_pull->GetFunction("gaus")->GetParError(2)/sqrt(1);

    cout << "Ratio Gen "<< ratioCorrGen<< " - Fit: " << meanV[jentry] <<" +/- "<<meanErrV[jentry];
    cout << "\t  Unc: " << toy_error->GetMean();
    cout << "\t  Pull: " << pullV[jentry] <<" / "<<pullWV[jentry]<<endl;

  }

// Mass plot & fit

   gStyle->SetOptStat(0); 
   gStyle->SetOptFit(0); 
  TGraphErrors *massGraph = new TGraphErrors(massV, meanV, massErrV, meanErrV);
  massGraph->SetName("massGraph");
  TF1* meanFit = new TF1("meanFit","pol1",minTMass-1, maxTMass+1);
  massGraph->Fit("meanFit");
  TF1* f2 = new TF1("f2","pol1",minTMass-1, maxTMass+1);
  f2->SetParameter(0,0.);
  f2->SetParameter(1,1.);
  f2->SetLineColor(4);
//   massGraph->SetMinimum(160);
//   massGraph->SetMaximum(190);
  massGraph->GetXaxis()->SetNdivisions(50205);
  massGraph->GetXaxis()->SetTitle("generated f^{SM}");
  massGraph->GetYaxis()->SetTitleOffset(1.22);
  massGraph->GetYaxis()->SetTitle("estimated f^{SM}");
//     massGraph->SetMarkerStyle(20);
  massGraph->Draw("apz");
  f2->Draw("same");
  cmssim();
  sprintf(hname,"cal_mass_%s.pdf", tag);
  c_min->Print(hname);
  sprintf(hname,"cal_mass_%s.png", tag);
  c_min->Print(hname);


// Pull plot & fit

// 
   gStyle->SetOptStat(0); 
   gStyle->SetOptFit(0); 
  TGraphErrors *pullGraph = new TGraphErrors(massV, pullV, massErrV, pullErrV);
  pullGraph->SetName("pullGraph");
  TF1* pullFit = new TF1("pullFit","pol0",minTMass-1, maxTMass+1);
  pullGraph->Fit("pullFit");
  TF1* f3 = new TF1("f3","pol1",minTMass-1, maxTMass+1);
  f3->SetParameter(0,0.);
  f3->SetParameter(1,0.);
  f3->SetLineColor(4);
  pullGraph->SetMinimum(-2);
  pullGraph->SetMaximum(+2);
  pullGraph->GetXaxis()->SetNdivisions(50205);
  pullGraph->GetXaxis()->SetTitle("generated f^{SM}");
  pullGraph->GetYaxis()->SetTitleOffset(1.22);
  pullGraph->GetYaxis()->SetTitle("pull mean");
  pullGraph->Draw("apz");
  f3->Draw("same");
  cmssim();
  sprintf(hname,"cal_pull_%s.pdf", tag);
  c_min->Print(hname);
  sprintf(hname,"cal_pull_%s.png", tag);
  c_min->Print(hname);

  TGraphErrors *pullWGraph = new TGraphErrors(massV, pullWV, massErrV, pullWErrV);
  pullWGraph->SetName("pullWGraph");
  TF1* f4 = new TF1("f3","pol1",minTMass-1, maxTMass+1);
  f4->SetParameter(0,1.);
  f4->SetParameter(1,0.);
  f4->SetLineColor(4);
  TF1* pullWFit = new TF1("pullWFit","pol0",minTMass-1, maxTMass+1);
  pullWGraph->Fit("pullWFit");
  pullWGraph->GetXaxis()->SetNdivisions(50205);
  pullWGraph->GetXaxis()->SetTitle("generated f^{SM}");
  pullWGraph->GetYaxis()->SetTitleOffset(1.22);
  pullWGraph->GetYaxis()->SetTitle("pull width");
//   pullWGraph->SetMinimum(0.8);
//   pullWGraph->SetMaximum(1.2);
  pullWGraph->Draw("apz");
  f4->Draw("same");
  cmssim();
  sprintf(hname,"cal_pullW_%s.pdf", tag);
  c_min->Print(hname);
  sprintf(hname,"cal_pullW_%s.png", tag);
  c_min->Print(hname);

// bias plot & fit

  TGraphErrors *biasGraph = new TGraphErrors(massV, biasV, massErrV, biasErrV);
  biasGraph->SetName("biasGraph");
  TF1* biasFit = new TF1("biasFit","pol1",minTMass-1, maxTMass+1);
  biasGraph->Fit("biasFit");
//   biasGraph->SetMinimum(160);
//   biasGraph->SetMaximum(190);
  biasGraph->GetXaxis()->SetNdivisions(50205);
  biasGraph->GetXaxis()->SetTitle("generated f^{SM}");
  biasGraph->GetYaxis()->SetTitleOffset(1.22);
  biasGraph->GetYaxis()->SetTitle("Bias");
  biasGraph->SetMinimum(-1);
  biasGraph->SetMaximum(+1);
  biasGraph->Draw("apz");
  f3->Draw("same");
  cmssim();
  sprintf(hname,"cal_bias_%s.pdf", tag);
  c_min->Print(hname);
  sprintf(hname,"cal_bias_%s.png", tag);
  c_min->Print(hname);

   gStyle->SetOptStat(0); 
   gStyle->SetOptFit(kTRUE); 

cout << "Properties at 172.5:\n";
  TH1F*   toy_err  = (TH1F*) gDirectory->Get("errMass_5") ;
  toy_err->GetXaxis()->SetTitle("Uncertainty");
  toy_err->GetYaxis()->SetTitleOffset(1.4);
  toy_err->Draw();
  cmssim();
  sprintf(hname,"errMass_5_%s.pdf", tag);
  c_min->Print(hname);
  sprintf(hname,"errMass_5_%s.png", tag);
  c_min->Print(hname);
  cout << "Mean uncertainty "<<toy_err->GetMean()<<endl;

  gStyle->SetOptFit(1111);
  TH1F*   toy_mean  = (TH1F*) gDirectory->Get("meanMass_5") ;
  toy_mean->Fit("gaus","Q");
  toy_mean->GetXaxis()->SetTitle("f^{SM}");
  toy_mean->GetYaxis()->SetTitleOffset(1.4);
  toy_mean->Draw();
  cmssim();
  sprintf(hname,"meanMass_5_%s.pdf", tag);
  c_min->Print(hname);
  sprintf(hname,"meanMass_5_%s.png", tag);
  c_min->Print(hname);

  gStyle->SetOptFit(1111);
  TH1F*   toy_pull  = (TH1F*) gDirectory->Get("pullMass_5") ;
  toy_pull->Fit("gaus","Q");
  toy_pull->GetXaxis()->SetTitle("Pull");
  toy_pull->GetYaxis()->SetTitleOffset(1.4);
  toy_pull->Draw();
  cmssim();
  sprintf(hname,"pullMass_5_%s.pdf", tag);
  c_min->Print(hname);
  sprintf(hname,"pullMass_5_%s.png", tag);
  c_min->Print(hname);



cout << "Inversion\n";
float a = meanFit->GetParameter(1);
float b = meanFit->GetParameter(0);
float ae = meanFit->GetParError(1);
float be = meanFit->GetParError(0);
    cout << "Template spin "<< fitMass<< " - Fit: " << a <<" / "<<b<<endl;
    cout << "calib spin: " << (fitMass-b)/a<<endl;
    float err = sqrt(ae*ae*((fitMass-b)/(a*a))*((fitMass-b)/(a*a)) + be*be/(a*a));
    cout << "calib err: " << err<<endl;
    
    cout << "Pull at 5: "<< pullWFit->Eval(5)<<endl;
    cout << "calbrated stat unc: "<< pullWFit->Eval(172.5)*fitUnc<<endl;

  theFile->Close();
}
