{
gROOT->ProcessLine(".L SpinFit.C+");
j = new SpinFit();
j->fit();
j->printAllValues();

}
