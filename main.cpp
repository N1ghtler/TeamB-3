#include <iostream>
#include "Report.h"
#include "Queue.h"
#include <fstream>
using namespace std;

int today_Date,today_Month,today_Year,Stop=0;

void dateCheck(){
     int Date,Month,year;

     cout << "Input today date"<<endl;
     cout << "Day(number): ";
     cin >> today_Date;
     cout << "Month(Jar,Feb): ";
     cin >> today_Month;
     cout << "Year(number): ";
     cin >> today_Year;

     fstream checkDate;
     checkDate.open("Data.txt",ios::in);

     while(!checkDate.eof()){         
          checkDate>>Date>>Month>>year;
          if (Date == today_Date && Month == today_Month && year == today_Year)
          {
               cout << "The Date is Exist."<<endl;
               checkDate.close();
               dateCheck();
          }
     }
     Stop++;
     if (Stop == 1)
     {
          cout << "The Date is save."<<endl;
          checkDate.close();
     }
     
}

int main(){
     //Start UP
     Queue *Costomer_Queue;
     Costomer_Queue = MakeNewList();
     dateCheck();
     

     
     //Write below here

     return 0;
};
