#include <iostream>
using namespace std;

struct Node
{
     int data;
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

void enqueue(Queue *q, int Queue_data){
  Node *e;
  e = new Node;
  e->data = Queue_data;
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
}

void Display(Queue *ds){
  Node *dy;
  dy = ds->Front;

  while (dy!= NULL)
  {
    cout<<dy->data<<" ";
    dy = dy->next;
  }
  cout<<endl;
}