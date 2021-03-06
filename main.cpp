#include <iostream>
#include <fstream>
#include <iomanip>
#include "Report.h"
#include "Queue.h"
#include "Game.h"
#include "Survey.h"
using namespace std;

int Stop=0;
int today_Scup=0,today_Mcup=0,today_Lcup=0;
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
     for (int r = 0; r < 15; r++)
     {
          if (Today_Top_Sells[ID_Top_Sel] < Today_Top_Sells[r])
          {
               ID_Top_Sel = r;
               Number_Top_Sell = Today_Top_Sells[r];     
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
  if(password == "CADTauto2021")
  {
    return true;
  }
  else
  {
    return false;
  }
}

double discount(double Price){

    double discount,AfterDiscount;

    if(Price<0){
     cout<<"Invalid input!! Please try again\n\n"<<endl;
    }
    else if(Price>0 && Price<10){
     AfterDiscount=Price;
    }
    else if(Price>=10 && Price<20){
     discount=Price*5/100;
     cout << "\n Discount 5%" <<endl;
    }
    else if(Price>50){
     discount=Price*20/100;
     cout << "\n Discount 20%" <<endl;
    }
    else if(Price>=20 && Price<50){
    discount=Price*10/100;
     cout << "\n Discount 10%" <<endl;
    }
    AfterDiscount=Price-discount;
    cout <<"\n After discount is " << AfterDiscount<<"$"<<endl;
    return AfterDiscount;
}

void priceCar(CoffeeMenu Menu[],int type[],int Size[],int number[],int arrSize){
     Cos_Total=0;
     double totalPrice = 0,afCal;
     system("color 01");
     for (int oS = 0; oS < arrSize; oS++)
     {   
          totalPrice = 0; 
          Today_Top_Sells[type[oS]] = Today_Top_Sells[type[oS]] + number[oS];
          if (type[oS] == 0)
          {
               cout << "Bullet"<<"\t\t" ;
          }
          else{
               if (type[oS] == 1 || type[oS] == 4 || type[oS] == 5)
               {
                    cout << Menu[type[oS]].Type<<"\t\t";
               }
               else
               {
                    cout << Menu[type[oS]].Type<<"\t";
               }
               
          }
          if (Size[oS] == 1)
          {
               today_Scup = today_Scup + number[oS];
               afCal = Menu[type[oS]].S * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].S <<"\t\t" << number[oS] <<"\t"<< totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
          else if (Size[oS] == 2)
          {
               today_Mcup = today_Mcup + number[oS];
               afCal = Menu[type[oS]].M * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].M <<"\t\t" << number[oS] <<"\t"<< totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
          else if (Size[oS] == 3)
          {
               today_Lcup = today_Lcup + number[oS];
               afCal = Menu[type[oS]].L * number[oS];
               totalPrice = totalPrice + afCal;
               cout << Menu[type[oS]].L <<"\t\t" << number[oS] <<"\t"<< totalPrice<<"$"<<endl;
               Cos_Total = Cos_Total + totalPrice;
          }
     }
     cout<< "\nThe total cost is "<<Cos_Total<<"$" ;
     Cos_Total = discount(Cos_Total);
     today_income = Cos_Total + today_income;
}

void DateCheck(){
     
     cout << " - Year :" << 1900 + ltm->tm_year<<endl;
     cout << " - Month : "<< 1 + ltm->tm_mon<< endl;
     cout << " - Day : "<< ltm->tm_mday << endl;
     cout << " - Date saved."<<endl;
}

int main(){
     system("cls");
     //Start UP
     Queue *s;
     s = MakeNewList();
     DateCheck();
     ReadDataToCoffee();

     //Write below here
      int choice;
     while (true)
     {
          Menu:
          system("color 05");
          cout<<"\n\n\t\t----------Welcome to  '3 Bullet' !!!---------"<<endl;
          cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
          cout<<" 1. Coffee Menu"<<endl;
          cout<<" 2. Game"<<endl;
          cout<<" 3. Queue"<<endl;
          cout<<" 4. Survey"<<endl;
          cout<<" 5. Admin"<<endl;
          cout<<" 6. Exit"<<endl;
          cout<<" \n=> Please enter your choice : ";cin>>choice;
          if (choice==1){
               cout<<"\n  ++ Coffee Menu ::"<<endl;
               char more;
               int n = 0;
               int typeofcoffee[10];
               int typeofcup[10];
               int numberofcup[10];
               Order:
               system("color 0A");
               cout<<"\n\n\t\t----------Welcome to  '3 Bullet' !!!---------"<<endl;
               cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
               ReadData();
               IDorder:
               cout << " - Enter The ID of the Coffee : ";
               cin >> typeofcoffee[n];
               typeofcoffee[n] = typeofcoffee[n] - 1;
               if (List[typeofcoffee[n]].No == 0 || typeofcoffee[n] > 20)
               {
                    goto IDorder;
               }
               cout << " - Enter The Size of the Coffee: \n 1. Small\n 2. Medium\n 3. Large\n 4. Menu\n";
               cout <<" => ";
               cin >> typeofcup[n];
               if (typeofcup[n] == 4 || typeofcup[n] > 4)
               {
                    goto IDorder;
               }
               AmountCoff:
               cout << " - Enter The number of the Coffee \n(-1 Back to Menu) => : ";
               cin >> numberofcup[n];
               if (numberofcup[n] == -1)
               {
                    goto IDorder;
               }
               else if (numberofcup[n] < 0)
               {
                    cout <<" !!<< ONLY BIGGER THEN 0 >>";
                    goto AmountCoff;
               }
       
               wantmore:
               cout << " - Do You want to get more ?\n ( 1. Yes , 2. No ) ";
               cout<<" => ";
               cin >> more;
               
               if (more == '1')
               {
                    n++;
                    goto Order;
               }
               else if (more == '2')
               {
                    n++;
                    cout<<" \n >> Here is your Reciept : \n";
                    enqueue(s,typeofcoffee,typeofcup,numberofcup,n,List);
               }
               else
               {
                    goto wantmore;
               }
               system("color 01");
               cout << "Coffee \t Price per Cup \t Total cup \t Total: \n";
               priceCar(List,typeofcoffee,typeofcup,numberofcup,n);
               
          }
          if (choice == 2)
          {
               cout<<"\n ++ Game For Cutomer (Waiting for Serve)::"<<endl;
               
               system("cls");
               char an;
               cout<<" ++ We have 3 games and our system will randomly chose it for you ++\n"<<endl;
               cout<<" ----->>   Game   <<-----"<<endl;
               cout<<" | 1. Tic Tac Toe       |"<<endl;
               cout<<" | 2. Rock Paper Scissor|"<<endl;
               cout<<" | 3. Special Word      |"<<endl;
               cout<<" ------------------------"<<endl;

               cout<<" \n\n- Our system will randomly chose a game for you"<<endl;

               while (true){
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
               cout<<"\n ++ Customer Order ::"<<endl;
               int select;
               do
               {
                    again:
                    cout<<"  1. Remove a Order (It has been served)\n  2. Display Order\n  3. Back\n";
                    cout<<" \nEnter your choice : ";
                    cin>>select;
                    if(select==1)
                    {
                         string pass;
                         cout << "(e)For exit"<<endl;
                         cout << " ++ Password : ";
                         cin >> pass;
                         if (!password(pass))
                         {
                              cout << " << Wrong Password >>\n";
                              goto again;
                         }
                         else if (pass == "e")
                         {
                              goto again;
                         }
                         system("cls");
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
          if (choice == 5)
          {
               system("color 04");
               cout<<"\n ++ Admin ::"<<endl;
               Wrpass:
               string pass;
               cout << "(e)For exit"<<endl;
               cout << " ** Password : ";
               cin >> pass;
               if (pass == "e")
               {
                    goto Menu;
               }
               else if (!password(pass))
               {
                    cout << " << Wrong Password >>\n";
                    goto Wrpass;
               }
               system("cls");
               int select;
               int RDay,Rmonth,Ryear;
               
               Ragain:
               cout<<" 1. Report Day\n 2. Report Month\n 3. Report Year\n 4. Save Report\n 5. Survey Report\n 6. Exit\n"<<" => ";
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
               else if (select==5)
               {
                    ReadSurvey();
                    goto Menu;
               }
               
               else if(select==6){
                    goto Menu;
               }
               else
               {
                    cout<<"  << Invalid input  >>\n"<<endl;
                    goto Ragain;
               }
          }
          if (choice == 4)
          {
               system("cls");
               cout<<"\n ++ Customer Survey ::"<<endl;
               int k=1;
               char answer1;string answer2;
               char anSurvey;
               while(true){
                    Strate:
                    cout<<" \nWould you like to Do the Survey with BUllet ?"<<endl;
                    cout<<" 1. Yes , 2. No"<<endl;
                    cout<<" => ";
                    cin>>anSurvey;
               if(anSurvey == '1'){
                    cout<<" Please read Question Carefully !!"<<endl;
                    ReadSurveyQ();
                    
                    for(k=1;k<=3;k++){
                         cout<<" Q : "<<k;
                         cout<<". (1. Good , 2. Normal, 3. Bad)"<<endl;
                         cout<<" => Answer : ";cin>>answer1;
                         while(answer1>'3' ){
                              cout<<" << Invalid Input! ";
                              cout<<"Please Input agian>>"<<endl;
                              cout<<"  Q : "<<k;
                              cout<<". (1. Good , 2. Normal, 3. Bad)"<<endl;
                              cout<<" => Answer : ";cin>>answer1;}
                              WriteSurvey1(k,answer1);
                         }
                         for(k=4;k<=5;k++){
                              if(k==4){
                                   cout<<" Q : "<<k;
                                   cout<<". (1. Yes, 2. No)"<<endl;
                                   cout<<" => Answer : ";cin>>answer1;
                                   while(answer1>'2' ){
                                   cout<<" << Invalid Input! ";
                                   cout<<"Please Input agian>>"<<endl;
                                   cout<<"  Q : "<<k;
                                   cout<<". (1. Yesc, 2. No)"<<endl;
                                   cout<<" => Answer : ";cin>>answer1;}
                                   WriteSurvey1(k,answer1);
                              }
                              else{
                                   cout<<" Q : "<<k;
                                   cout<<" => Feedbaack Or Suggestion : ";
                                   fflush(stdin);getline(cin,answer2);
                                   WriteSurvey2(k,answer2);
                                   cout<<"\n";
                              }
                         }
               }
               else if(anSurvey=='2'){
                    cout<<" <<Exit Survey>>"<<endl;
                    cout<<" xxx- Thanks You for Visiting Us -xxx"<<endl;
                    goto Menu;
               }
               else{
               cout<<" << Invalid Input! ";
               cout<<"Please choose again >>"<<endl;
               goto Strate;
               }
               goto Menu;

               }
          }
          if (choice == 6)
          {
               cout<<"\n + Close Shop ::"<<endl;
               break;
          }          
     }
         
     FindTopSell();
     WriteData(today_Date,today_Month,today_Year,today_Scup,today_Mcup,today_Lcup,today_income,ID_Top_Sel,Number_Top_Sell);
     return 0;
};
