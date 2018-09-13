#include <iostream>
#include "myCode/foo.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>
#include <fstream>
//#include "cuts.h"

using namespace std;

int main(int argc, char **argv){

    if (argc<9 || argc>14) {
        cout << argc << endl;
        cout<<"Usage: "<<argv[0]
            <<" <Sample> <XML GRL> <Trigger> <Njets> <pTLeading> <pTLast> <MET> <BOOST> <Nleptons> <ISO> <[OS or SS]> <Flav1> <Flav2> <Trigger2>"<<endl;
        exit(0);
    }

    cout << "argc=" << argc<< endl;
    string fname  = argv[1];
    string gRname  = argv[2];
    string trigname  = argv[3];
    cout << endl << fname << "   GRL:" << gRname;
    cout <<  "   Trigger:" << trigname<< endl;

    Int_t Njets = atoi(argv[4]);
    Int_t pTLeading = atoi(argv[5]);
    Int_t pTLast = atoi(argv[6]);
    Int_t MET = atoi(argv[7]);
    Int_t BOOST = atoi(argv[8]);
    Int_t Nleptons = atoi(argv[9]);
    // LOG:
    cout<< Njets<<" jets ("<<pTLeading<<"-"<<pTLast<<")   MET:"<<MET<<"   BOOST:"<<BOOST<<"  "<<Nleptons<<" lepton " <<endl<<endl;

    TString Iso  = argv[10];
/*
    if(Iso != "LooseIso" && Iso != "MediumIso" && Iso != "TightIso" 
        && Iso != "CustomOLD" && Iso != "Custom" && Iso != "None"
        && Iso != "eLmL" 
        && Iso != "eMmL" 
        && Iso != "eTmL" 
        && Iso != "eVTmL" 
        && Iso != "eVVTmL" 
        && Iso != "eLmT" 
        && Iso != "eMmT" 
        && Iso != "eTmT" 
        && Iso != "eVTmT" 
        && Iso != "eVVTmT" 
        && Iso != "eLmVT" 
        && Iso != "eMmVT" 
        && Iso != "eTmVT" 
        && Iso != "eVTmVT" 
        && Iso != "eVVTmVT" 
        && Iso != "VeryLooseTO" 
        && Iso != "VeryLoose" 
        && Iso != "Loose" 
        && Iso != "Tight" 
        && Iso != "Grad" 
        && Iso != "GradLoose" 
        && Iso != "GradCustom" 
        ){
        cout<<"Invalid iso: \""<<argv[10] << endl;
        exit(0);
    }
*/
    cout << "Iso: " << Iso << endl;

    TString Sign  = argv[11];
    if(Sign != "OS" && Sign != "SS" && Sign != "" && Sign != "SSp"
        && Sign != "OSee" && Sign != "OSmm" && Sign != "OSem" 
        && Sign != "emm" && Sign != "eem"
        && Sign != "lep"
        ){
        cout<<"Invalid sign: \""<<argv[9]
        <<"\". Valid values: OS, SS (blank for 0-1 leptons)."<<endl;
        exit(0);
    }
    if(Nleptons==2 && Sign != "OS" && Sign != "SS" && Sign != "OSee" && Sign != "OSmm"&& Sign != "OSem"){
        cout<<"Need to specify OS or SS for 2-lepton analysis!!"<<endl;
        exit(0);
    }
    cout << "Sign: " << Sign << endl;

    Int_t proc = -1;
    if(argc>=13){
        proc = atoi(argv[12]);
    }

    cout << "Proc: " << proc << endl;

    Int_t Flav1 = 0;
    Int_t Flav2 = 0;
    //   if(argc>=13){
    //     Flav1 = atoi(argv[12]);
    //     Flav2 = atoi(argv[13]);
    //   }
    string trigname2  = "";
    if(argc>=15)
        trigname2 = argv[14];


    // LOG:
    cout<< Njets<<" jets ("<<pTLeading<<"-"<<pTLast<<")   MET:"<<MET<<"   BOOST:"<<BOOST<<"  "<<Nleptons<<" lepton "<<Sign;
    cout << " (" << Flav1 << " & " << Flav2 << ")   trig2=" << trigname2;
    cout <<endl<<endl;

    gROOT->SetBatch(1);

    // CHECK
    TString strTemp = fname;
    if(strTemp.Contains("Eg_v20") && Sign=="OSmm"){
        cout << "==== Skipping mm channel in Egamma stream =====" << endl;
        return(0);
    }
    if(strTemp.Contains("Mu_v20") && Sign=="OSee"){
        cout << "==== Skipping ee channel in Muon stream =====" << endl;
        return(0);
    }


    //  TChain* chain=new TChain("t3333");
    TChain* chain;
    chain=new TChain("AnaNtup");

    string fileName;

    cout << " --> Load Chain from file: " << fileName << endl;

    string list="../FileLists/"+fname+".list";
    ifstream fList(list.c_str());
    if (!fList)
    {
        cout << "!!! Can't open file " << list //fNameList 
             << endl;
    }

    char lineFromFile[400];
    float SumW = 0;
    float SumW2 = 0;
    while(fList.getline(lineFromFile, 450))
    {
        if(chain->Add((const char*) lineFromFile))
            cout << "File '" << lineFromFile<< "' has been loaded" << endl;
        else
            cout << "--> Can't load file '" << lineFromFile << "'" << endl;

        TFile *f = new TFile((const char*) lineFromFile);
        TH1F* h_w = (TH1F*)f->Get("DerivationStat_Weights");
        SumW += h_w->GetBinContent(1);
        TH1F* h_w2 = (TH1F*)f->Get("DerivationStat_Weights_Squared");
        SumW2 += h_w2->GetBinContent(1);

    }

    cout << "Total number of entries: " << chain->GetEntries() <<endl;
    cout << "Total sum of weights: " << SumW << "   weights2: "  << SumW2 <<endl;
    fList.close();

    foo* bar = new foo(chain);
    //   Cuts* cut=new Cuts(0,bar);
    //  cout<<"foo created.."<<endl;
    //bar->Loop(fname,Nleptons,CType,Njets,Sign,Energy,Inverted);
    bool UseXSec=true;
    TH1F *htemp = new TH1F("temp","temp",400,0,4000);
    Float_t NevtsMeff[10]={0.};
    bool Rew=false;
    float nevts = bar->Loop(fname,SumW,SumW2,gRname,trigname,Njets,pTLeading,pTLast,MET,BOOST,Nleptons,Rew,Sign,UseXSec,htemp, proc, Flav2, trigname2,NevtsMeff,Iso);

    cout << " End of loop Ana " << nevts << " " << __LINE__ << endl;
    exit;
    return 0;

}

