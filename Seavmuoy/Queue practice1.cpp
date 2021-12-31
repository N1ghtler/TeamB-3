#include<iostream>
using namespace std;

struct Element
{
	string name[50];
    string size[50];
	int number[50];
	Element *next;
};

struct Queue
{
	int n;
	Element *front;
	Element *tail;
};

Queue *MakeNewList()
{
	Queue *qs = new Queue();
	qs->front = NULL;
	qs->tail = NULL;
	qs->n = 0;
	return qs;
}

void enqueue(Queue *qs, int name[], int size[], int number[], int arrSize)
{
	Element *e = new Element();
	for(int i=0;i<arrSize;i++)
	{
		e->number[i] = number[i];
	    if(name[i] == 1)
	    {
		    e->name[i] = "Bullet";
		    if(size[i] == 1)
		    {
			    e->size[i] = "small";
		    }
		    else if(size[i] == 2)
		    {
			    e->size[i] = "medium";
		    }
		    else if(size[i] == 3)
		    {
			    e->size[i] = "large";
		    }
		    else
		    {
			    e->size[i] = "Invalid";
		    }
	    }
	    else if(name[i] == 2)
	    {
		    e->name[i] = "Crown";
		    if(size[i] == 1)
		    {
			    e->size[i] = "small";
		    }
		    else if(size[i] == 2)
		    {
			    e->size[i] = "medium";
		    }
		    else if(size[i] == 3)
		    {
			    e->size[i] = "large";
		    }
		    else
		    {
			    e->size[i] = "Invalid";
		    }
	    }
	    else if(name[i] == 3)
	    {
		    e->name[i] = "Hot_Latte";
		    if(size[i] == 1)
		    {
			    e->size[i] = "small";
		    }
		    else if(size[i] == 2)
		    {
			    e->size[i] = "medium";
		    }
		    else if(size[i] == 3)
		    {
			    e->size[i] = "large";
		    }
		    else
		    {
			    e->size[i] = "Invalid";
		    }
	    }
	    else if(name[i] == 4)
	    {
		    e->name[i] = "Cappucino";
		    if(size[i] == 1)
		    {
			    e->size[i] = "small";
		    }
		    else if(size[i] == 2)
		    {
			    e->size[i] = "medium";
		    }
		    else if(size[i] == 3)
		    {
			    e->size[i] = "large";
		    }
		    else
		    {
			    e->size[i] = "Invalid";
		    }
	    }
	    else if(name[i] == 5)
	    {
		    e->name[i] = "Mocha";
		    if(size[i] == 1)
		    {
			    e->size[i] = "small";
		    }
		    else if(size[i] == 2)
		    {
			    e->size[i] = "medium";
		    }
		    else if(size[i] == 3)
		    {
			    e->size[i] = "large";
		    }
		    else
		    {
			    e->size[i] = "Invalid";
		    }
	    }
	    else if(name[i] == 6)
	    {
	    	e->name[i] = "Cacoa";
	    	if(size[i] == 1)
		    {
			    e->size[i] = "small";
	    	}
	    	else if(size[i] == 2)
		    {
			    e->size[i] = "medium";
	     	}
	     	else if(size[i] == 3)
	    	{
		    	e->size[i] = "large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
    	}
    	else if(name[i] == 7)
    	{
		    e->name[i] = "Vannila_Frape";
	        if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
	    	else if(size[i] == 2)
	    	{
			    e->size[i] = "medium";
	    	}
     		else if(size[i] == 3)
	    	{
		    	e->size[i] = "large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
    	}
    	else if(name[i] == 8)
	    {
	    	e->name[i] = "Caramel_Frape";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "medium";
	    	}
	    	else if(size[i] == 3)
		    {
			    e->size[i] = "large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
    	}
    	else if(name[i] == 9)
     	{
	    	e->name[i] = "Salted_Caramel";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
	 	    else if(size[i] == 2)
	    	{
		    	e->size[i] = "medium";
	       	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "large";
		    }
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
    	}
	    else if(name[i] == 10)
    	{
	    	e->name[i] = "Ice_Latte";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
	    	else if(size[i] == 2)
	    	{
	    		e->size[i] = "medium";
	    	}
	    	else if(size[i] == 3)
		   {
			   e->size[i] = "large";
	    	}
	    	else
	    	{
	    		e->size[i] = "Invalid";
	    	}
    	}
    	else if(name[i] == 11)
    	{
	    	e->name[i] = "Cappucino";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
	     	else if(size[i] == 2)
		    {
		    	e->size[i] = "medium";
	     	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "large";
	    	}
		    else
	    	{
		    	e->size[i] = "Invalid";
	    	}
    	}
    	else if(name[i] == 12)
    	{
    		e->name[i] = "Espresso";
	    	if(size[i] == 1)
    		{
		    	e->size[i] = "small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "medium";
	    	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
    	}
	    else if(name[i] == 13)
	    {
	    	e->name[i] = "Americano";
	     	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
		    else if(size[i] == 2)
	     	{
		     	e->size[i] = "medium";
	    	}
		    else if(size[i] == 3)
		    {
		    	e->size[i] = "large";
	    	}
	        else
		    {
		    	e->size[i] = "Invalid";
		    }
    	}
	    else if(name[i] == 14)
	    {
		   e->name[i] = "Machhiato";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "medium";
	    	}
		    else if(size[i] == 3)
		    {
			    e->size[i] = "large";
		    }
	    	else
	    	{
		    	e->size[i] = "Invalid";
		    }
    	}
    	else if(name[i] == 15)
    	{
	    	e->name[i] = "Marochhino";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "medium";
	    	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
    	}
	   else
    	{
	    	e->name[i] = "Invalid";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "small";
	    	}
		    else if(size[i] == 2)
	     	{
		    	e->size[i] = "medium";
	    	}
	    	else if(size[i] == 3)
	    	{
	 	    	e->size[i] = "large";
	    	}
	    	else
	    	{
		     	e->size[i] = "Invalid";
	    	}
    	}
	}

	e->next = NULL;
	if(qs->n == 0)
	{
		qs->front = e;
		qs->tail = e;
	}
	else
	{
		qs->tail->next = e;
		qs->tail = e;
	}
	qs->n = qs->n + 1;
}

void Dequeue(Queue *qs)
{
	Element *tmp;
	tmp = qs->front;
	if(qs->n == 0)
	{
		cout<<"Cannot delete because there is no element in the queue";
	}
	else
	{
		qs->front = qs->front->next;
		delete tmp;
		qs->n = qs->n - 1;
	}
}

void Display_Queue_Cos(Queue *qs, int arrSize)
{
	Element *tmp;
	tmp = qs->front;
	if(qs->n == 0)
	{
		cout<<"Cannot display because there is no element in the queue";
	}
	else
	{
		for(int i=0;i<arrSize;i++)
		{
			cout<<"Name/Size/Number : ";
			cout<<tmp->name[i]<<"/"<<tmp->size[i]<<"/"<<tmp->number[i];
			cout<<endl;
		}
	}
}

int main()
{
	int arrSize;
	cout<<"How many drink do you want to buy? ";
	cin>>arrSize;
	int name[arrSize],size[arrSize],number[arrSize];
	for(int i=0;i<arrSize;i++)
	{
		cout<<"Enter name: ";
		cin>>name[i];
		cout<<"Enter size: ";
		cin>>size[i];
		cout<<"Enter number: ";
		cin>>number[i];
	}
	Queue *qs = createEmptyQueue();
	enqueue(qs, name, size, number, arrSize);
	display(qs,arrSize);
}