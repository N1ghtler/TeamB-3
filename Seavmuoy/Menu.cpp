#include<iostream>
#include<fstream>
using namespace std;

//Function to read data from file txt (coffee menu)
void ReadData(){
    fstream F1;
    float priceS,priceM,priceL;
    string cafe;
    string line;

    F1.open("TT.txt", ios::in);
    while(!F1.eof()){
    getline(F1,line);
    cout<<line<<endl;
    }
    F1.close();
/*
    fstream F2;
    cout<<"|\t + Coffee  \t\t|\t\t    Size    \t\t|"<<endl;
    cout<<"|\t=============\t\t|\t\t ========== \t\t|"<<endl;
    cout<<"|\t\t\t\t|\tS \t M\t L\t\t\t|"<<endl;
    F2.open("Signature.txt", ios::in);
    while(!F2.eof()){
    F2>>cafe>>priceS>>priceM>>priceL;
    cout<<"|\t  "<<cafe<<" \t\t| \t"<<priceS<<"$ \t"<<priceM<<" $\t"<<priceL<<"$     \t\t|"<<endl;
    }F2.close();  
*/
}
//Survey Form
void Survey(){

}
//Game
void Game(){

}


int main(){
    cout<<"\n\n\t\t----------Welcome to  '3 Bullet' !!!---------"<<endl;
    cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
    ReadData();
    cout<<"\n\n";

    cout<<" Monthly Survey For better performing and service"<<endl;

    cout<<" Game for special occasion"<<endl;
    
}
