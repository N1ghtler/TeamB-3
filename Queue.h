#include <iostream>
using namespace std;

struct Node
{
  int Name;
  int Size=0;
  int Mize=0;
  int Lize=0;
  Node *next;
};

struct Queue
{
  int size;
  Node *Front;
  Node *Rear;
};

Queue *MakeNewList(){
     Queue *ls;
     ls = new Queue;

     ls->size =0;
     ls->Front = NULL;
     ls->Rear = NULL;
     return ls;
}

void enqueue(Queue *q,int Name,int Size,int Mize,int Lize){
  Node *e;
  e = new Node;
  e->Name = Name;
  e->Size = Size;
  e->Mize = Mize;
  e->Lize = Lize;
  if(q->size == 0){
    q->Front = e;
    q->Rear = e;
  }
  else{
    q->Rear->next = e;
    q->Rear = e;
  }
  q->size = q->size + 1;
}

void Dequeue(Queue *q) {
  Node *e;
  if(q->size == 0){
    cout << "There are NO DATA in Queue" << '\n';
  }
  else{
    e = q->Front;
    q->Front = q->Front->next;
    delete e;
    q->size = q->size - 1;
  }
  cout <<"Done"<<endl;
}

void Display_Queue_Cos(Queue *ds){
  Node *dy;
  dy = ds->Front;

  while (dy!= NULL)
  {
    cout<<dy->Name<<" "<< "S Cup ;" << dy->Size<< " M Cup ;" << dy->Mize<< " L Cup ;" << dy->Lize;
    dy = dy->next;
  }
  cout<<endl;
}
