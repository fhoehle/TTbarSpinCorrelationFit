#include <fstream>
#include <iostream>
#include "TApplication.h"

void finalizeFile(){  
   
   string ofilenametex = "systList.tex";
   ofstream ofile(ofilenametex.c_str(), ios::app);

   ofile << "\\end{tabular}" << endl;
   ofile << "\\end{table}" << endl;
   gApplication->Terminate();
}
