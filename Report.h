#include <fstream>
#include <iostream>
using namespace std;

void WriteData(int Date,int Mouth,int year){
     fstream Write;
     Write.open("Data.txt",ios::app);
     Write<<Date<<" "<<Mouth<<" "<<year<<" "<<endl;
     Write.close();
}
