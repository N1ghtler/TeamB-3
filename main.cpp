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
          cout<<"2.Admin"<<endl;
          cout<<"3.Exit"<<endl;
          cout<<"Please enter your choice:"<<endl;cin>>choice;
          if (choice==1){

               

          }
          if(choice==2){
               string a, b, c;
               int select;
          
               do
               {
                    again:
                    cout<<"1. Add a item to the menu\n2. Remove a queue\n3. Display queue\n4. Exit\n";
                    cout<<"Enter your choice: ";
                    cin>>select;
                    if(select==1)
                    {
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
               break;
          }
               
          }
         


     return 0;
};
