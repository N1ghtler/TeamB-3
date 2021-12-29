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
     Queue *s;
     s = MakeNewList();
     dateCheck();
     

     
     //Write below here
      int choice;

     while (true)
     {
          Menu:
          cout<<"1.Coffee Menu"<<endl;
          cout<<"2.Queue"<<endl;
          cout<<"3.Report"<<endl;
          cout<<"4.Exit"<<endl;
          cout<<"Please enter your choice:"<<endl;cin>>choice;
          if (choice==1){
               cout <<"Still Under Construction."<<endl;
               goto Menu;
          }
          if(choice==2){
               int select;
          
               do
               {
                    again:
                    cout<<"1. None\n2. Remove a queue\n3. Display queue\n4. Exit\n";
                    cout<<"Enter your choice: ";
                    cin>>select;
                    if(select==1)
                    {
                         cout <<"Still Under Construction."<<endl;
                         goto again;
                    }
                    else if(select==2)
                    {
                         Dequeue(s);
                    }
                    else if(select==3)
                    {
                         Display_Queue_Cos(s);
                         cout<<"--------------------------------\n";
                    }

                    else if(select==4){
                         goto Menu;
                    }else{
                         cout<<"Invalid input\n"<<endl;
                         goto again;
                    }
               }while(select!=4);


          }
          if (choice == 3)
          {
               Ragain:
               int select;
               int RDay,Rmonth,Ryear;
               cout<<"1. Report Day\n2. Report Month\n3. Report Year\n4. Exit\n";
               if(select==1)
                    {
                         cout << "Enter Date:";
                         cin >> RDay;
                         cout << "Enter Month:";
                         cin >> Rmonth;
                         cout << "Enter Year:";
                         cin >> Ryear;
                         Report_Day(RDay,Rmonth,Ryear);
                    }
                    else if(select==2)
                    {
                         cout << "Enter Month:";
                         cin >> Rmonth;
                         cout << "Enter Year:";
                         cin >> Ryear;
                         Report_Month(Rmonth,Ryear);
                    }
                    else if(select==3)
                    {
                         cout << "Enter Year:";
                         cin >> Ryear;
                         Report_Year(Ryear);
                    }

                    else if(select==4){
                         goto Menu;
                    }else{
                         cout<<"Invalid input\n"<<endl;
                         goto Ragain;
                    }
          }
          if (choice == 4)
          {
               break;
          }          
     }
         


     return 0;
};
