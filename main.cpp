#include <iostream>
#include <Report.h>
#include <Queue.h>
using namespace std;



int main(){
     //Start UP
     Queue *Costomer_Queue;
     Costomer_Queue = MakeNewList();

     //Write below here
     
     //Write to txt
     fstream Write;
     Write.open("Data.txt",ios::app);
     Write<<endl;
     Write.close();
     //

     return 0;
}
