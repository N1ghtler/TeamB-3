#include <iostream>
#include <fstream>
#include <iomanip>
#include "Report.h"
#include "Queue.h"
using namespace std;

int today_Date,today_Month,today_Year,Stop=0,CosNumber = 0;
int today_Scup,today_Mcup,today_Lcup;
int cos_Scup=0,cos_Mcup=0,cos_Lcup=0;
double Cos_Total=0,today_income = 0;
int Today_Top_Sells[20],ID_Top_Sel,Number_Top_Sell;

struct CoffeeMenu{
     int No;
     string Type;
     double S;
     double M;
     double L;
};

CoffeeMenu List[20];
int i = 0;

void FindTopSell(){
     for (int r = 0; r < 20; r++)
     {
          if (Today_Top_Sells[r] < Today_Top_Sells[r+1])
          {
               ID_Top_Sel = r;
               Number_Top_Sell = Today_Top_Sells[r+1];
          }
     }
}

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

void priceCar(CoffeeMenu Menu[],int type[],int Size[],int number[],int arrSize){
     Cos_Total=0;
     double totalPrice = 0,afCal;
     for (int oS = 0; oS < arrSize; oS++)
     {
          Today_Top_Sel[type[oS]] = Today_Top_Sel[type[oS]] + arrSize;
          cout << Menu[type[oS]].Type<< setw(20) ;
          if (Size[oS] == 1)
          {
               afCal = Menu[type[oS]].S * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].S << setw(20) << totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
          else if (Size[oS] == 2)
          {
               afCal = Menu[type[oS]].M * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].M << setw(20) << totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
          else if (Size[oS] == 3)
          {
               afCal = Menu[type[oS]].L * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].L << setw(20) << totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
     }
     cout<< "\nThe total cost is "<<Cos_Total<<"$";
     today_income = totalPrice + today_income;

}

void dateCheck(){
     int Date,Month,year,t,s,m,l;
     double p;

     cout << "Input today date"<<endl;
     cout << "Day(number): ";
     cin >> today_Date;
     cout << "Month(1,2): ";
     cin >> today_Month;
     cout << "Year(number): ";
     cin >> today_Year;

     fstream checkDate;
     checkDate.open("Data.txt",ios::in);

     while(!checkDate.eof()){         
          checkDate>>Date>>Month>>year>>s>>m>>l>>p;
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
          cout<<"\n\n\t\t----------Welcome to  '3 Bullet' !!!---------"<<endl;
          cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
          cout<<"1.Coffee Menu"<<endl;
          cout<<"2.Queue"<<endl;
          cout<<"3.Admin"<<endl;
          cout<<"4.Exit"<<endl;
          cout<<"Please enter your choice:"<<endl;cin>>choice;
          if (choice==1){
               char more;
               int n = 0;
               int typeofcoffee[10];
               int typeofcup[10];
               int numberofcup[10];
               Order:
               cout<<"\n\n\t\t----------Welcome to  '3 Bullet' !!!---------"<<endl;
               cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
               ReadData();
               IDorder:
               cout << "Enter The ID of the Coffee: ";
               cin >> typeofcoffee[n];
               if (typeofcoffee[n] > 15)
               {
                    goto IDorder;
               }
               
               cout << "Enter The Size of the Coffee: \n 1. Small\n 2. Medmin\n 3. Large\n 4. Menu\n> ";
               cin >> typeofcup[n];
               if (typeofcup[n] == 4)
               {
                    goto IDorder;
               }
               AmountCoff:
               cout << "Enter The number of the Coffee \n(-1 for Menu):";
               cin >> numberofcup[n];
               if (numberofcup[n] == -1)
               {
                    goto IDorder;
               }
               else if (numberofcup[n] < 0)
               {
                    cout <<"ONLY BIGGER THEN 0";
                    goto AmountCoff;
               }
               
               wantmore:
               cout << "Do You want to get more ?(y)Yes,(n)No";
               cin >> more;
               
               if (more == 'y')
               {
                    n++;
                    goto Order;
               }
               else if (more == 'n')
               {
                    ++CosNumber;
                    n++;
                    for (int p = 0; p < n; p++)
                    {
                         if (typeofcup[p] == 1)
                         {
                              today_Scup++;
                              cos_Scup++;
                         }
                         else if (typeofcup[p] == 2)
                         {
                              today_Mcup++;
                              cos_Mcup++;
                         }
                         else if (typeofcup[p] == 3)
                         {
                              today_Lcup++;
                              cos_Lcup++;
                         }
                    }
                    enqueue(s,typeofcoffee,typeofcup,numberofcup,n);
               }
               else
               {
                    goto wantmore;
               }
               cout << "Coffee\t Price per Coffee\t Total\n";
               priceCar(List,typeofcoffee,typeofcup,numberofcup,n);
               
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
                    Report_month(Rmonth,Ryear);
                    goto Ragain;
               }
               else if(select==3)
               {
                    cout << "Enter Year:";
                    cin >> Ryear;
                    Report_year(Ryear);
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
