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

               char ask;
               int number,n;
               int total=0;
               int price[5]={4000,5000,7000,10000,12000};

               retry:
               cout<<"----------------------"<<endl;
               cout<<"Coffee List"<<endl;
               cout<<"----------------------"<<endl;
               cout<<"Item Name        \t|Price"<<endl;
               cout<<"1.Cappuccino     \t|4000"<<endl;
               cout<<"2.Exspresso     \t|5000"<<endl;
               cout<<"3.Mochachino     \t|7000 "<<endl;
               cout<<"4.Latte          \t|10000 "<<endl;
               cout<<"5.Americano     \t|12000 "<<endl;

               cout<<"Enter the number that you want to buy: "<<endl;
               cin>>number;

               switch(number){
               case 1:
                    cout<<"How many item you want to buy: "<<endl;
                    cin>>n;
                    total+=price[0]*n;
                    cout<<"Are there anything else you want to buy? (yes(y) or no(n))"<<endl;
                    cin>>ask;
                    if (ask=='y'){
                         system("cls");
                         goto retry;
                    }else{
                         goto end;
                    }
               case 2:
                    cout<<"How many item you want to buy: "<<endl;
                    cin>>n;
                    total+=price[1]*n;
                    cout<<"Are there anything else you want to buy? (yes(y) or no(n))"<<endl;
                    cin>>ask;
                    if (ask=='y'){
                         system("cls");
                         goto retry;
                    }else{
                         goto end;
                    }

               case 3:
                    cout<<"How many item you want to buy: "<<endl;
                    cin>>n;
                    total+=price[2]*n;
                    cout<<"Are there anything else you want to buy? (yes(y) or no(n))"<<endl;
                    cin>>ask;
                    if (ask=='y'){
                    system("cls");
                    goto retry;
                    }else{
                         goto end;
                    }
                    case 4:
                    cout<<"How many item you want to buy: "<<endl;
                    cin>>n;
                    total+=price[3]*n;
                    cout<<"Are there anything else you want to buy? (yes(y) or no(n))"<<endl;
                    cin>>ask;
                    if (ask=='y'){
                         system("cls");
                         goto retry;
                    }else{
                         goto end;
                    }
                    case 5:
                    cout<<"How many item you want to buy: "<<endl;
                    cin>>n;
                    total+=price[4]*n;
                    cout<<"Are there anything else you want to buy? (yes(y) or no(n))"<<endl;
                    cin>>ask;
                    if (ask=='y'){
                         system("cls");
                         goto retry;
                    }else{
                         goto end;
                    }
                    default:
                    cout<<"\n invalid choice!! Please enter your number again\n";
                    goto retry;
               }

               end:
                    cout<<"The total money you mmust pay is:"<<total <<endl;
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
