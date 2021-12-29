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
     int Report_TotalCup=0,total_SCup=0,total_MCup=0,total_LCup=0;
     double TotalIncome=0;
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
               total_SCup = total_SCup + tmpSCup;
               total_MCup = total_MCup + tmpMCup;
               total_LCup = total_LCup + tmpLCup;
               TotalIncome = TotalIncome + tmpincmone;
          }
          
     }
     Report_TotalCup = total_SCup + total_MCup + total_LCup;
     Read.close();
     if (Check != 0)
     {
          cout << "Total Cup: "<<Report_TotalCup << "Total s Cup: "<< total_SCup << "Total M Cup: "<<total_MCup<< "Total L Cup: "<<total_LCup<< "Total income: "<<TotalIncome<<endl;
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}

void Report_month(int Month,int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup=0,total_SCup=0,total_MCup=0,total_LCup=0;
     double TotalIncome=0;
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
               total_SCup = total_SCup + tmpSCup;
               total_MCup = total_MCup + tmpMCup;
               total_LCup = total_LCup + tmpLCup;
               TotalIncome = TotalIncome + tmpincmone;
          }
          
     }
     Report_TotalCup = total_SCup + total_MCup + total_LCup;
     Read.close();
     if (Check != 0)
     {
          cout << "Total Cup: "<<Report_TotalCup << "Total s Cup: "<< total_SCup << "Total M Cup: "<<total_MCup<< "Total L Cup: "<<total_LCup<< "Total income: "<<TotalIncome<<endl;
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}

void Report_year(int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup=0,total_SCup=0,total_MCup=0,total_LCup=0;
     double TotalIncome=0;
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
               total_SCup = total_SCup + tmpSCup;
               total_MCup = total_MCup + tmpMCup;
               total_LCup = total_LCup + tmpLCup;
               TotalIncome = TotalIncome + tmpincmone;
          }
          
     }
     Report_TotalCup = total_SCup + total_MCup + total_LCup;
     Read.close();
     if (Check != 0)
     {
          cout << "Total Cup: "<<Report_TotalCup << "Total s Cup: "<< total_SCup << "Total M Cup: "<<total_MCup<< "Total L Cup: "<<total_LCup<< "Total income: "<<TotalIncome<<endl;
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}