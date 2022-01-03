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
   ,today_Year = 1900 + ltm->tm_year;


CoffeeMenu List[20];
int i = 0;

void FindTopSell(){
     for (int r = 0; r < 15; r++)
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
          Today_Top_Sells[type[oS]] = Today_Top_Sells[type[oS]] + arrSize;
          if (type[oS] == 0)
          {
               cout << "Bullet"<< setw(20) ;
          }
          else{
               cout << Menu[type[oS]].Type<< setw(20) ;
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
     today_income = totalPrice + today_income;

}

void dateCheck(){
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
          cout<<"1.Coffee Menu"<<endl;
          cout<<"2.Game"<<endl;
          cout<<"3.Queue"<<endl;
          cout<<"4.Admin"<<endl;
          cout<<"5.Exit"<<endl;
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
               if (List[16].No == 0)
               {
                    goto IDorder;
               }
               cout<<"\t\t----------      Today Specials Coffee       ---------"<<endl;
               cout << "ID" << setw(20) << "Name" << setw(20) << "Small price" << setw(20) << "Medium price" << setw(20) << "Large price" << endl;
               for (int coffleist = 16; coffleist < i; coffleist++)
               {
                    if (List[coffleist].No == 0)
                    {
                         goto IDorder;
                    }
                    else
                    {
                         cout << List[coffleist].No << setw(20) << List[coffleist].Type << setw(20) << List[coffleist].S << setw(20) << List[coffleist].M << setw(20) << List[coffleist].L << endl;
                    }
               }
               
               IDorder:
               cout << "Enter The ID of the Coffee: ";
               cin >> typeofcoffee[n];
               typeofcoffee[n] = typeofcoffee[n] - 1;
               if (List[typeofcoffee[n]].No == 0)
               {
                    goto IDorder;
               }
               
               cout << "Enter The Size of the Coffee: \n 1. Small\n 2. Medium\n 3. Large\n 4. Menu\n> ";
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
                    cout<<"1. Remove a queue\n2. Display queue\n3. Exit\n";
                    cout<<"Enter your choice: ";
                    cin>>select;
                    if(select==1)
                    {
                         string pass;
                         cout << "Password: ";
                         cin >> pass;
                         if (!password(pass))
                         {
                              cout << "Wrong Password\n";
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
                         cout<<"Invalid input\n"<<endl;
                         goto again;
                    }
               }while(select!=4);


          }
          if (choice == 4)
          {
               Wrpass:
               string pass;
               cout << "Password: ";
               cin >> pass;
               if (!password(pass))
               {
                    cout << "Wrong Password\n";
                    goto Wrpass;
               }
               int select;
               int RDay,Rmonth,Ryear;
               
               Ragain:
               cout<<"1. Report Day\n2. Report Month\n3. Report Year\n4. Add Coffee(Today Specials Coffee)\n5. Remove a Coffee(Today Specials Coffee)\n6. Remove ALL Coffee(Today Specials Coffee)\n7. Exit\n"<<"> ";
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
                    if (List[19].No != 0)
                    {
                         cout << "Today Specials Coffee is FUll, Remove a Coffee first.\n"<<i<<endl;
                         goto Ragain;
                    }
                    MakeAgain:
                    string CofName;
                    char yesorno;
                    double Sprice,Mprice,Lprice;
                    cout << "Enter Coffee Name: ";
                    cin >> CofName;
                    cout << "Enter Coffee Small Price: ";
                    cin >> Sprice;
                    cout << "Enter Coffee Medium Price: ";
                    cin >> Mprice;
                    cout << "Enter Coffee Large Price: ";
                    cin >> Lprice;
                    cout << "Name: " <<CofName << " prices S M L "<<Sprice<<" "<<Mprice<<" "<<Lprice<<endl<<"Enter (y) to add ,(n) for no : ";
                    cin >> yesorno;
                    if (yesorno == 'y')
                    {
                         List[i].No = i+1;
                         List[i].Type = CofName;
                         List[i].S = Sprice;
                         List[i].M = Mprice;
                         List[i].L = Lprice;
                         fstream NewMenu;
                         NewMenu.open("CoffeeList.txt",ios::out);
                         for (int NewListMenu = 0; NewListMenu <= i; NewListMenu++)
                         {
                              NewMenu << List[NewListMenu].No <<" " << List[NewListMenu].Type <<" " << List[NewListMenu].S <<" " << List[NewListMenu].M <<" " << List[NewListMenu].L <<endl;
                         }
                         NewMenu.close();
                         i++;
                    }
                    else
                    {
                         goto MakeAgain;
                    }
                    
               }
               else if(select==5){
                    //remove 1
                    if (List[15].No == 0)
                    {
                         cout << "There no Specials Coffee."<<endl;
                         goto Ragain;
                    }
                    cout<<"\t\t----------      Today Specials Coffee       ---------"<<endl;
                    cout << "ID" << setw(20) << "Name" << setw(20) << "Small price" << setw(20) << "Medium price" << setw(20) << "Large price" << endl;
                    for (int coffleist = 15; coffleist < i; coffleist++)
                    {
                         if (List[coffleist].No == 0)
                         {
                              goto deleteCoffee;
                         }
                         else
                         {
                              cout << List[coffleist].No << setw(20) << List[coffleist].Type << setw(20) << List[coffleist].S << setw(20) << List[coffleist].M << setw(20) << List[coffleist].L << endl;
                         }
                    }
                    int delteCoffeeMenu;
                    deleteCoffee:
                    cout << "Enter Coffee ID(Over 15): " ;
                    cin >> delteCoffeeMenu;
                    if (delteCoffeeMenu <= 15 || delteCoffeeMenu <= 0 || delteCoffeeMenu >= 20)
                    {
                         goto deleteCoffee;
                    }
                    delteCoffeeMenu = delteCoffeeMenu - 1;
                    for (int romve = delteCoffeeMenu; romve < i; romve++)
                    {
                         List[romve].No = List[romve+1].No - 1;
                         List[romve].Type =  List[romve+1].Type;
                         List[romve].S = List[romve+1].S;
                         List[romve].M = List[romve+1].M;
                         List[romve].L = List[romve+1].L;
                    }
                    i--;
                    fstream NewMenu;
                    NewMenu.open("CoffeeList.txt",ios::out);
                    for (int NewListMenu = 0; NewListMenu < i; NewListMenu++)
                    {
                         NewMenu << List[NewListMenu].No <<" " << List[NewListMenu].Type <<" " << List[NewListMenu].S <<" " << List[NewListMenu].M <<" " << List[NewListMenu].L <<endl ;
                    }
                    NewMenu.close();
               }
               else if(select==6){
                    int Confom;
                    cout << "Enter (1111) to delete all Today Specials Coffee : ";
                    cin >> Confom;
                    if (Confom != 1111)
                    {
                         cout << "Fail to delete."<<endl;
                         goto Ragain;
                    }
                    
                    //remove all
                    fstream Removeall;
                    Removeall.open("CoffeeList.txt",ios::out);
                    for (int NewListMenu = 0; NewListMenu < 15; NewListMenu++)
                    {
                         Removeall << List[NewListMenu].No <<" " << List[NewListMenu].Type <<" " << List[NewListMenu].S <<" " << List[NewListMenu].M <<" " << List[NewListMenu].L <<endl ;
                    }
                    Removeall.close();

                    goto Ragain;
               }
               else if(select==7){
                    goto Menu;
               }
               else
               {
                    cout<<"Invalid input\n"<<endl;
                    goto Ragain;
               }
          }
          if (choice == 5)
          {
               break;
          }          
     }
         
     FindTopSell();
     //WriteData(today_Date,today_Month,today_Year,today_Scup,today_Mcup,today_Lcup,today_income,ID_Top_Sel,Number_Top_Sell);
     return 0;
};
