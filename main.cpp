#include <iostream>
#include <fstream>
#include <iomanip>
#include "Report.h"
#include "Queue.h"
#include "Game.h"
using namespace std;

int Stop=0,CosNumber = 0;
int today_Scup,today_Mcup,today_Lcup;
int cos_Scup=0,cos_Mcup=0,cos_Lcup=0;
double Cos_Total=0,today_income = 0;
int Today_Top_Sells[20],ID_Top_Sel,Number_Top_Sell;

time_t now = time(0);
tm *ltm = localtime(&now);

int today_Date = ltm->tm_mday
   ,today_Month = 1 + ltm->tm_mon
   ,today_Year = 1900 + ltm->tm_year
;

CoffeeMenu List[20];
int i = 0;

void FindTopSell(){
     for (int r = 0; r < 15; r++)
     {
          if (Today_Top_Sells[r] < Today_Top_Sells[r+1])
          {
               ID_Top_Sel = r+1;
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

bool password(string password)
{
  if(password == "pass12345")
  {
    return true;
  }
  else
  {
    return false;
  }
}

void priceCar(CoffeeMenu Menu[],int type[],int Size[],int number[],int arrSize){
     Cos_Total=0;
     double totalPrice = 0,afCal;
     for (int oS = 0; oS < arrSize; oS++)
     {   
          totalPrice = 0; 
          Today_Top_Sells[type[oS]] = Today_Top_Sells[type[oS]] + arrSize;
          if (type[oS] == 0)
          {
               cout << "Bullet"<< setw(15) ;
          }
          else{
               cout << Menu[type[oS]].Type<< setw(18) ;
          }
          if (Size[oS] == 1)
          {
               afCal = Menu[type[oS]].S * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].S << setw(18) << totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
          else if (Size[oS] == 2)
          {
               afCal = Menu[type[oS]].M * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].M << setw(18) << totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
          else if (Size[oS] == 3)
          {
               afCal = Menu[type[oS]].L * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].L << setw(18) << totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
     }
     cout<< "\nThe total cost is "<<Cos_Total<<"$";
     today_income = Cos_Total + today_income;

}

void DateCheck(){
     cout << "Year:" << 1900 + ltm->tm_year<<endl;
     cout << "Month: "<< 1 + ltm->tm_mon<< endl;
     cout << "Day: "<< ltm->tm_mday << endl;
     cout << "The Date is save."<<endl;
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
          cout<<" 1. Coffee Menu"<<endl;
          cout<<" 2. Game"<<endl;
          cout<<" 3. Queue"<<endl;
          cout<<" 4. Admin"<<endl;
          cout<<" 5. Exit"<<endl;
          cout<<" => Please enter your choice : ";cin>>choice;
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
               cout << " - Enter The ID of the Coffee: ";
               cin >> typeofcoffee[n];
               typeofcoffee[n] = typeofcoffee[n] - 1;
               if (List[typeofcoffee[n]].No == 0)
               {
                    goto IDorder;
               }
               
               cout << " Enter The Size of the Coffee: \n 1. Small\n 2. Medium\n 3. Large\n 4. Menu\n> ";
               cout <<" => ";
               cin >> typeofcup[n];
               if (typeofcup[n] == 4)
               {
                    goto IDorder;
               }
               AmountCoff:
               cout << " Enter The number of the Coffee \n(-1 for Menu) : ";
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
               cout<<" => ";
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
                    enqueue(s,typeofcoffee,typeofcup,numberofcup,n,List);
               }
               else
               {
                    goto wantmore;
               }
               cout << "Coffee\t Price per Coffee\t Total\n";
               priceCar(List,typeofcoffee,typeofcup,numberofcup,n);
               
          }
          if (choice == 2)
          {
               system("cls");
               char an;
               cout<<" ++ We have 3 games and our system will randomly chose it for you ++\n"<<endl;
               cout<<" ----->>   Game   <<-----"<<endl;
               cout<<" | 1. Tic Tac Toe       |"<<endl;
               cout<<" | 2. Rock Paper Scissor|"<<endl;
               cout<<" | 3. Special Word      |"<<endl;
               cout<<" ------------------------"<<endl;

               cout<<" \n\n- Our system will randomly chose a game for you"<<endl;

               while (an<'1' || an>'2'){
               cout<<" - Are you Ready to Start The Game ?\n  1. Yes , 2. N0 \n => ";
               cin >> an;
               system("cls");
               if(an=='1'){
                    cout<<" \t<< Game Start !! >>\n"<<endl;
                    char GameChoice;
                    srand(time(NULL));
                    GameChoice = (rand() % 3) + 1;

                    if(GameChoice==1){
                         Game1();}
                    else if(GameChoice==2){
                         Game2();}
                    else{
                         Game3();}
                    }
               else if(an== '2'){
                    cout<<" <<Exit Game!!>>"<<endl;
                    break;}
               else{
                         cout<<" << Invalid Input! ";
                         cout<<"Please choose again >>"<<endl;
                    }
               }
          }  
          if (choice == 3){
               int select;
          
               do
               {
                    again:
                    cout<<"  1. Remove a queue\n  2. Display queue\n  3. Exit\n";
                    cout<<" Enter your choice : ";
                    cin>>select;
                    if(select==1)
                    {
                         string pass;
                         cout << " ++ Password : ";
                         cin >> pass;
                         if (!password(pass))
                         {
                              cout << " << Wrong Password >>\n";
                              goto Wrpass;
                         }
                         Dequeue(s);
                    }
                    else if(select==2)
                    {
                         Display_Queue_Cos(s);
                         cout<<"--------------------------------\n";
                    }
                    else if(select==3)
                    {
                         goto Menu;
                    }
                    else{
                         cout<<" << Invalid input >> \n"<<endl;
                         goto again;
                    }
               }while(select!=4);


          }
          if (choice == 4)
          {
               Wrpass:
               string pass;
               cout << " ** Password : ";
               cin >> pass;
               if (!password(pass))
               {
                    cout << " << Wrong Password >>\n";
                    goto Wrpass;
               }
               int select;
               int RDay,Rmonth,Ryear;
               
               Ragain:
               cout<<" 1. Report Day\n 2. Report Month\n 3. Report Year\n 4.Save Report\n 5. Exit\n"<<" => ";
               cin >>select; 
               if(select==1)
               {
                    cout << " - Enter Date :";
                    cin >> RDay;
                    cout << " - Enter Month :";
                    cin >> Rmonth;
                    cout << " - Enter Year : ";
                    cin >> Ryear;
                    Report_Day(RDay,Rmonth,Ryear);
                    goto Ragain;
               }
               else if(select==2)
               {
                    cout << " - Enter Month : ";
                    cin >> Rmonth;
                    cout << " - Enter Year : ";
                    cin >> Ryear;
                    Report_month(Rmonth,Ryear);
                    goto Ragain;
               }
               else if(select==3)
               {
                    cout << " - Enter Year : ";
                    cin >> Ryear;
                    Report_year(Ryear);
                    goto Ragain;
               }
               else if(select==4){
                    FindTopSell();
                    WriteData(today_Date,today_Month,today_Year,today_Scup,today_Mcup,today_Lcup,today_income,ID_Top_Sel,Number_Top_Sell);
                    today_Scup = 0;
                    today_Mcup = 0;
                    today_Lcup = 0;
                    today_income = 0;
                    ID_Top_Sel = 0;
                    Number_Top_Sell = 0;
                    for (int r = 0; r < 15; r++)
                    {
                         Today_Top_Sells[r] = 0;
                    }
                    cout << " <<Data Saved>>"<<endl;
                    goto Ragain;
               }
               else if(select==5){
                    goto Menu;
               }
               else
               {
                    cout<<"  << Invalid input  >>\n"<<endl;
                    goto Ragain;
               }
          }
          if (choice == 5)
          {
               break;
          }          
     }
         
     FindTopSell();
     WriteData(today_Date,today_Month,today_Year,today_Scup,today_Mcup,today_Lcup,today_income,ID_Top_Sel,Number_Top_Sell);
     return 0;
};
