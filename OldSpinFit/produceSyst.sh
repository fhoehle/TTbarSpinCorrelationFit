 root -l initiateFile.C
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C

 echo "compute syst uncertainty for JES down"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/JesDown/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_JesDown.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_JesDow.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C





 echo "compute syst uncertainty for JES up"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/JesUp/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_JesUp.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_JesUp.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C






 echo "compute syst uncertainty for JER"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/Jer/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_Jer.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_Jer.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C






 echo "compute syst uncertainty for LeptSF"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/LeptSF/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_LeptSF.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_LeptSF.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C





 echo "compute syst uncertainty for elecScaleUp"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/elecup/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_ElecScaleUp.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_ElecScaleUp.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C




 echo "compute syst uncertainty for elecScaleDown"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/elecDown/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_ElecScaleDown.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_ElecScaleDown.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C




 echo "compute syst uncertainty for elecResol"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/elecDown/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_ElecResolUp.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_ElecResolUp.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C





 echo "compute syst uncertainty for PU up"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/PUUP/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_PUpu.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_PUpu.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C





 echo "compute syst uncertainty for PU Down"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/PUDown/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_PUdown.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_PUdown.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C






# echo "compute syst uncertainty for "
# cp ComputeSyst_temp.C ComputeSyst_0.C
# sed 's/initsyst/mass170/g' ComputeSyst_0.C > ComputeSyst_new.C
# sed 's/initFastSimNoSpinCorr//g' ComputeSyst_new.C > ComputeSyst_new2.C
# sed 's/initFastSimSpinCorr//g' ComputeSyst_new2.C > ComputeSyst_new3.C
# mv ComputeSyst_new3.C ComputeSyst.C #

# root -l ComputeSyst.C 
# rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C




#echo "compute syst uncertainty for "
#cp ComputeSyst_temp.C ComputeSyst_0.C
#sed 's/initsyst/mass1775/g' ComputeSyst_0.C > ComputeSyst_new.C
#sed 's/initFastSimNoSpinCorr//g' ComputeSyst_new.C > ComputeSyst_new2.C
#sed 's/initFastSimSpinCorr//g' ComputeSyst_new2.C > ComputeSyst_new3.C
#mv ComputeSyst_new3.C ComputeSyst.C 

#root -l ComputeSyst.C 
#rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C





#echo "compute syst uncertainty for "
#cp ComputeSyst_temp.C ComputeSyst_0.C
#sed 's/initsyst/genlevel/g' ComputeSyst_0.C > ComputeSyst_new.C
#sed 's/initFastSimNoSpinCorr//g' ComputeSyst_new.C > ComputeSyst_new2.C
#sed 's/initFastSimSpinCorr//g' ComputeSyst_new2.C > ComputeSyst_new3.C
#mv ComputeSyst_new3.C ComputeSyst.C  

#root -l ComputeSyst.C 
#rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C


 echo "compute syst uncertainty for btagup"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/btagup/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_btagup.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_btagup.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C




 echo "compute syst uncertainty for btagdow"
 cp ComputeSyst_temp.C ComputeSyst_0.C
 sed 's/initsyst/btagdow/g' ComputeSyst_0.C > ComputeSyst_new.C
 sed 's/initFastSimNoSpinCorr/ttbar_mcatnlo_NoSC_btagdown.root/g' ComputeSyst_new.C > ComputeSyst_new2.C
 sed 's/initFastSimSpinCorr/ttbar_mcatnlo_SC_btagdown.root/g' ComputeSyst_new2.C > ComputeSyst_new3.C
 mv ComputeSyst_new3.C ComputeSyst.C 

 root -l ComputeSyst.C 
 rm -rf ComputeSyst.C  ComputeSyst_0.C ComputeSyst_new.C ComputeSyst_new2.C ComputeSyst_new3.C

 root -l finalizeFile.C
