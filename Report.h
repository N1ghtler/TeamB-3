#include <fstream>
#include <iostream>
using namespace std;

void WriteData(int Date,int Mouth,int year){
     fstream Write;
     Write.open("Data.txt",ios::app);
     Write<<Date<<" "<<Mouth<<" "<<year<<" "<<endl;
     Write.close();
}

void Report_Day(int Day,int Month,int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup,Report_TotalMoney;
     int Check=0;
     fstream Read;
     Read.open("Data.txt",ios::in);
     while (!Read.eof())
     {
          Read>>Report_Date>>Report_Month>>Report_Year;

          if (Report_Date == Day || Report_Month == Month || Report_Year == Year)
          {
               Check++;
               /* code */
          }
          
     }
     Read.close();
     if (Check != 0)
     {
          cout << "Total ...... " << "Total ......  " << "Total ......  " << "Total ......  "<< "Total ......  ";
     }
     else{
          cout <<"Data Not Exist";
     }
     
}