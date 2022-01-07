#include<iostream>
#include<fstream>
using namespace std;


void ReadSurveyQ(){
    fstream Survey1;
    string line1;

    Survey1.open("SurveyFile.txt", ios::in);
    while(!Survey1.eof()){
    getline(Survey1,line1);
    cout<<line1<<endl;
    }
    Survey1.close();
}

void WriteSurvey1(int q_no, char answer1){
     fstream Write1;
          cout<<"\n";
     Write1.open("QuestionInReport.txt",ios::app);
     Write1<<" Question"<<q_no<<" : "<<answer1<<" ,";
     Write1.close();
}
void WriteSurvey2(int q_no, string answer2){
     fstream Write2;
     Write2.open("QuestionInReport.txt",ios::app);
     
     Write2<<" "<<q_no<<" Feedback : "<<answer2<<endl;
     Write2.close();
}
//Display in In Admin part one of the option in Admin
void ReadSurvey(){
    fstream Survey2;
    string line2;

    Survey2.open("QuestionInReport.txt", ios::in);
    while(!Survey2.eof()){
    getline(Survey2,line2);
    cout<<line2<<endl;
    }
    Survey2.close();
}
