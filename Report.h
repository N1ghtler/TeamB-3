#include <fstream>
#include <iostream>
using namespace std;

void WriteData(int Date,int Mouth,int year,int SCup,int MCup,int LCup,double Income){
     fstream Write;
     Write.open("Data.txt",ios::app);
     Write<<Date<<" "<<Mouth<<" "<<year<<" "<<SCup<<" "<<MCup<<" "<<LCup<<" "<<Income<<endl;
     Write.close();
}

void Report_Day(int Day,int Month,int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup,Report_TotalMoney,total_SCup,total_SCup,total_SCup;
     double TotalIncome;
     int Check=0;
     fstream Read;
     Read.open("Data.txt",ios::in);
     while (!Read.eof())
     {
          double tmpincmone;
          int tmpSCup,tmpMCup,tmpLCup;
          Read>>Report_Date>>Report_Month>>Report_Year>>tmpSCup>>tmpMCup>>tmpLCup>>tmpincmone;

          if (Report_Date == Day && Report_Month == Month && Report_Year == Year)
          {
               Check++;
               /* code */
          }
          
     }
     Read.close();
     if (Check != 0)
     {
          cout << "Total ...... " << "Total ......  " << "Total ......  " << "Total ......  "<< "Total ......  "<<endl;
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}

void Report_Month(int Month,int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup,Report_TotalMoney,total_SCup,total_SCup,total_SCup;
     double TotalIncome;
     int Check=0;
     fstream Read;
     Read.open("Data.txt",ios::in);
     while (!Read.eof())
     {
          double tmpincmone;
          int tmpSCup,tmpMCup,tmpLCup;
          Read>>Report_Date>>Report_Month>>Report_Year>>tmpSCup>>tmpMCup>>tmpLCup>>tmpincmone;

          if (Report_Month == Month && Report_Year == Year)
          {
               Check++;
               /* code */
          }
          
     }
     Read.close();
     if (Check != 0)
     {
          cout << "Total ...... " << "Total ......  " << "Total ......  " << "Total ......  "<< "Total ......  "<<endl;
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}

void Report_Year(int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup,Report_TotalMoney,total_SCup,total_SCup,total_SCup;
     double TotalIncome;
     int Check=0;
     fstream Read;
     Read.open("Data.txt",ios::in);
     while (!Read.eof())
     {
          double tmpincmone;
          int tmpSCup,tmpMCup,tmpLCup;
          Read>>Report_Date>>Report_Month>>Report_Year>>tmpSCup>>tmpMCup>>tmpLCup>>tmpincmone;

          if (Report_Year == Year)
          {
               Check++;
               /* code */
          }
          
     }
     Read.close();
     if (Check != 0)
     {
          cout << "Total ...... " << "Total ......  " << "Total ......  " << "Total ......  "<< "Total ......  "<<endl;
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}