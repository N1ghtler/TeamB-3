#include<iostream>
#include<ctime>
#include<string>
using namespace std;

//Game1 Tic Tac Toe
char Sign[10] = {'o','1','2','3','4','5','6','7','8','9'};
//Chek winner for Game 1
int Check_Winner()
{
    if (Sign[1]==Sign[2] && Sign[2]==Sign[3])
        return 1;

    else if (Sign[1]==Sign[4] && Sign[4]==Sign[7])
        return 1;
    
    else if (Sign[1]==Sign[5] && Sign[5]==Sign[9])
        return 1;
    
    else if (Sign[2]==Sign[5] && Sign[5]==Sign[8])
        return 1;

    else if (Sign[3]==Sign[6] && Sign[6]==Sign[9])
        return 1;

    else if (Sign[3]==Sign[5] && Sign[5]==Sign[7])
        return 1;

    else if (Sign[4]==Sign[5] && Sign[5]==Sign[6])
        return 1;

    else if (Sign[7]==Sign[8] && Sign[8]==Sign[9])
        return 1;

    else if (Sign[1] != '1' && Sign[2] != '2' && Sign[3] != '3' 
             && Sign[4] != '4' && Sign[5] != '5' && Sign[6] != '6' 
             && Sign[7] != '7' && Sign[8] != '8' && Sign[9] != '9')
        return 0;
    else
        return -1;
}
// Show board of TicTacToe Game1
void ShowBoard()
{system("cls");
    cout<< "\n\tTic Tac Toe\n";

    cout<< "  Player 1 Sign : Customer => (X)"<<endl;
    cout<< "  Player 2 Sign : Staff    => (O)" << endl;

    cout << "._______________________. "<<endl;
    cout << "|       |       |       |" << endl;
    cout << "|   "<< Sign[1] <<  "   |   "  << Sign[2] <<  "   |   " << Sign[3]  << "   |" <<endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   " <<Sign[4] <<  "   |   " << Sign[5] << "   |   " << Sign[6]<< "   |"<<endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   "<< Sign[7] <<  "   |   " << Sign[8] <<  "   |   " << Sign[9] << "   |"<<endl;
    cout << "|_______|_______|_______|" << endl << endl;
}
void Game1(){

    system("cls");
    cout<<" ** Random on Game 1: 'Tic Tac Toe'\n"<<endl;

	int player = 1;
    int i;
    char choice;
    char PlayerSign;

    do{
        ShowBoard();
        player=(player%2)?1:2;

        cout << "Player " << player << ", Enter Your Choice : ";
        cin >> choice;

        PlayerSign = (player == 1) ? 'X':'O';

        if (choice == '1' && Sign[1] == '1')
            Sign[1] = PlayerSign;

        else if (choice=='2' && Sign[2]=='2')
            Sign[2] = PlayerSign;

        else if (choice=='3' && Sign[3]=='3')
            Sign[3] = PlayerSign;

        else if (choice=='4' && Sign[4]=='4')
            Sign[4] = PlayerSign;

        else if (choice=='5' && Sign[5]=='5')
            Sign[5] = PlayerSign;

        else if (choice =='6' && Sign[6] == '6')
            Sign[6] = PlayerSign;

        else if (choice=='7' && Sign[7]=='7')
            Sign[7] = PlayerSign;

        else if (choice=='8' && Sign[8]=='8')
            Sign[8] = PlayerSign;

        else if (choice=='9' && Sign[9]=='9')
            Sign[9] = PlayerSign;
        else
        {
            cout<<" << Invalid Input! ";
            cout<<"Please choose again >>"<<endl;
        }
    // i increase 1 for winning time
        i=Check_Winner(); player++;

    }while((i==-1) || ( choice<'1' || choice>'9'));

    ShowBoard();
    if(i==1){
        cout<<"==>\aPlayer "<<--player<<" win "<<endl;
        if(player==1){
            cout<<" Congratulation !! You got discount 2$"<<endl;
        }
        else{
            cout<<" Our staff win you didn't get any discount . Try next time!!"<<endl;
        }
    }
    else {
     cout<<"---x--- \aGame draw  ---X---";
    }
}
void Game2(){
    int i;
    char choice1;
    int choice2;
    string player;
    system("cls");
    cout<<" ** Random on Game 2: 'Rock Paper Scissor'\n"<<endl;
    cout<<" Below is our introduction please read it carefully"<<endl;

//Introduction
    cout<<"\t.__________________."<<endl;
    cout<<"\t|      Menu        |"<<endl;
    cout<<"\t|   1. Rock        |"<<endl;
    cout<<"\t|   2. Paper       |"<<endl;
    cout<<"\t|   3. Scissor     |"<<endl;
    cout<<"\t|__________________|"<<endl;
    cout<<"  + Rock crack scissor mean Rock win over Scissor"<<endl;
    cout<<"  + Paper wrap rock mean Paper win over Rock"<<endl;
    cout<<"  + Scissor cut paper mean Scissor win over Paper"<<endl;

    cout<<" \nYou are player 1 :"<<endl;
    cout<<"  Please enter your name : ";fflush(stdin);getline(cin,player);
 
//customer turn
while(choice1<'1' || choice1>'3'){
        cout <<" + "<< player << ", Enter Your Choice :  ";
        cin >> choice1;
        system("cls");
        if(choice1=='1'){
            cout<<" => "<<player<<" chose :1 . Rock"<<endl;
            }
        else if(choice1=='2'){
            cout<<" => "<<player<<" chose :2 . Paper"<<endl;
             }
        else if(choice1== '3'){
            cout<<" => "<<player<<" chose :3 . Scissor"<<endl;
            }
    else{
            cout<<" << Invalid Input! ";
            cout<<"Please choose again >>"<<endl;
    }
}
//Staff turn
        srand(time(NULL));
        choice2 = (rand() % 3) + 1;

    if(choice2==1){
        cout<<" => Staff chose :1 . Rock"<<endl;
    }
    else if(choice2==2){
        cout<<" => Staff chose :2 . Paper"<<endl;
    }
    else{
        cout<<" => Staff chose :3 . Scissor"<<endl;}
//Result 
    cout<<"\n\n => Result : ";
    if(choice1=='1'){
        if(choice2==1){
            cout<<"---x--- \aGame draw  ---X---"<<endl;
        }
        else if(choice2==2){
            cout<<" Our staff win you didn't get any discount . Try next time!!"<<endl;
        }
        else{
            cout<<" Congratulation !! You got coupon discount 2$"<<endl;
        }
    }
    else if(choice1=='2'){
        if(choice2==1){
            cout<<" Congratulation !! You got coupon discount 1$"<<endl;
        }
        else if(choice2==2){
            cout<<"---x--- \aGame draw  ---X---"<<endl;
        }
        else{
            cout<<" Our staff win you didn't get any discount . Try next time!!"<<endl;
        }}
    else{
        if(choice2=='1'){
               cout<<" Our staff win you didn't get any discount . Try next time!!"<<endl;
        }
        else if(choice2==2){
            cout<<" Congratulation !! You got discount 2$"<<endl;
        }
        else {
            cout<<"---x--- \aGame draw  ---X---"<<endl;
        }
    }
}
// Game 3 Convert Input word from Customer to Ascii
int ConvertAscii(string word){
    int i,sum=0,j=0,k;

    for(i=0;i<word[i]!='\0';i++){
        j++;
    }for(i=0;i<j;i++){
        k=word[i];
        sum=sum+k;
    }
    return sum;
}
const int SIZE=4;
int GenerateWord(string a){
    int i;
    i= ConvertAscii(a);
    return i%SIZE;
}
//Game 3
void Game3(){
    system("cls");
    string word;

    cout<<" ** Random on Game 3: 'Special Word'\n"<<endl;
    cout<<" Below is our introduction please read it carefully"<<endl;
    cout<<" - You will be asked to give any Word in which more than 4 letters "<<endl;
    cout<<" - IF the combination of those letters fit with our lucky table you will get a price \n"<<endl;
    
    int len;
    while(len<5){
        cout<<" Please Enter Your Word : ";
        fflush(stdin);getline(cin,word);len=word.length();
    // cout<<GenerateWord(word);
    len = word.length();
    
        if(len>= 5){
            if(GenerateWord(word)==0){
                cout<<" => Congratulation !! You got Discount 1$"<<endl;}
            else if(GenerateWord(word)==1){
                cout<<" => Congratulation !! Free 1 Bullet Cafe "<<endl;}
            else if(GenerateWord(word)==2){
                cout<<" => You Didn't get any price !! Try next time "<<endl;}
            else if(GenerateWord(word)==3){
                cout<<" => You Didn't get any price !! Try next time "<<endl;}
            break;}
        else {
            cout<<" <<Lack letter plase input again>>"<<endl;
        }
    }
}