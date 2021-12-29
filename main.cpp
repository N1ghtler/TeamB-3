#include <iostream>
#include "Report.h"
#include "Queue.h"
#include <fstream>
using namespace std;

int today_Date,today_Month,today_Year,Stop=0,CosNumber = 0;
int today_Scup,today_Mcup,today_Lcup;

struct CoffeeMenu{
     int No;
     string Type;
     double S;
     double M;
     double L;
};

CoffeeMenu List[20];
int i = 0;

void ReadDataToCoffee(){
     fstream listCoffee;
     listCoffee.open("CoffeeList.txt",ios::in);
     int N,Price;
     double SPrice,MPrice,LPrice;
     string Name;
     while (!listCoffee.eof())
     {
          listCoffee >> N >> Name >> SPrice >> MPrice >> LPrice;
          List[i].No = N;
          List[i].Type = Name;
          List[i].S = SPrice;
          List[i].M = MPrice;
          List[i].L = LPrice;
          i++;
     }
     listCoffee.close();
}

void ReadData(){
    fstream F1;
    float priceS,priceM,priceL;
    string cafe;
    string line;

    F1.open("Menu.txt", ios::in);
    while(!F1.eof()){
    getline(F1,line);
    cout<<line<<endl;
    }
    F1.close();
}

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
     ReadDataToCoffee();

     
     //Write below here
      int choice;

     while (true)
     {
          Menu:
          cout<<"1.Coffee Menu"<<endl;
          cout<<"2.Queue"<<endl;
          cout<<"3.Admin"<<endl;
          cout<<"4.Exit"<<endl;
          cout<<"Please enter your choice:"<<endl;cin>>choice;
          if (choice==1){
               cout<<"\n\n\t\t----------Welcome to  '3 Bullet' !!!---------"<<endl;
               cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
               ReadData();
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
               cout<<"1. Report Day\n2. Report Month\n3. Report Year\n4. Exit\n"<<"> ";
               cin >>select;
               if(select==1)
               {
                    cout << "Enter Date:";
                    cin >> RDay;
                    cout << "Enter Month:";
                    cin >> Rmonth;
                    cout << "Enter Year:";
                    cin >> Ryear;
                    Report_Day(RDay,Rmonth,Ryear);
                    goto Ragain;
               }
               else if(select==2)
               {
                    cout << "Enter Month:";
                    cin >> Rmonth;
                    cout << "Enter Year:";
                    cin >> Ryear;
                    Report_Month(Rmonth,Ryear);
                    goto Ragain;
               }
               else if(select==3)
               {
                    cout << "Enter Year:";
                    cin >> Ryear;
                    Report_Year(Ryear);
                    goto Ragain;
               }

               else if(select==4){
                    goto Menu;
               }
               else
               {
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
