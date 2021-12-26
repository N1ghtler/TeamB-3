#include <fstream>
#include <iostream>
using namespace std;



void WriteData(int data){
     fstream Write;
     Write.open("Data.txt",ios::app);
     Write<<endl;
     Write.close();
}