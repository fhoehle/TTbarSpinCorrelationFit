#include <fstream>
#include <iostream>
#include "TApplication.h"

void initiateFile(){

   string ofilenametex = "systList.tex";
   ofstream ofile(ofilenametex.c_str());
   ofile << "\\begin{table} " << endl;
   ofile << "\\begin{tabular}{|l|c|c|} " << endl;
   ofile << "systematics & absolute & relative " << endl;
   ofile << "\\hline " << endl;

   gApplication->Terminate();

}
