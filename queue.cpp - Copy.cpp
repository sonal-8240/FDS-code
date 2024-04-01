#include <iostream>
#define MAX 10 /* `MAX` is a macro that sets the maximum number of elements the queue can hold to 10.*/
using namespace std;
struct queue	/*A `queue` structure is defined with an integer array `data` that can hold up to `MAX` elements, and two integer indicators: `front` and `rear` which are used to keep track of the front and rear positions within the queue.*/
{       int data[MAX];
	int front,rear;
};
class Queue		/*A `Queue` class is declared and defined, encapsulating the queue operations. It includes the following methods:
  			 - `Queue()` - constructor that initializes the front and rear markers of the queue to -1, signifying an empty queue.
  			 - `isempty()` - returns 1 (true) if the queue is empty, 0 (false) otherwise.
			- `isfull()` - returns 1 (true) if the queue is full (i.e., rear is at the last position of the array), 0 (false) otherwise.
			 - `enqueue(int)` - inserts an element at the rear of the queue if it is not full.
   			- `delqueue()` - removes and returns an element from the front of the queue if it is not empty.
   			- `display()` - prints all the elements of the queue from the front to the rear.*/
{    struct queue q;
   public:
      Queue(){q.front=q.rear=-1;}
      int isempty();
      int isfull();
      void enqueue(int);
      int delqueue();
      void display();
};
int Queue::isempty()
{
	return(q.front==q.rear)?1:0;
}
int Queue::isfull()
{    return(q.rear==MAX-1)?1:0;}/*
- `q`: This appears to be an instance of a `queue` data structure.
- `q.rear`: This accesses the `rear` attribute of the queue instance, which tracks the index of the last element in the queue.
- `MAX`: A constant that defines the maximum size of the queue.
- `MAX-1`: Since array indices in most programming languages start at 0, the last valid index in an array of size `MAX` is `MAX-1`.
- `?1:0`: This is a ternary conditional operator that works as a compact form of an if-else statement. The expression before the `?` gets evaluated, and if it's true, the value after the `?` is returned; otherwise, the value after the `:` is returned.

Putting it all together, the code is essentially asking, "Is the rear index of the queue equal to the last valid index in the array?" If the answer is yes (true), it returns `1`, which typically signifies a "true" condition in C-style languages. If the answer is no (false), it returns `0`, which signifies a "false" condition.*/
void Queue::enqueue(int x)
{q.data[++q.rear]=x;}
int Queue::delqueue()
{return q.data[++q.front];}
void Queue::display()
{   int i;
    cout<<"\n";
    for(i=q.front+1;i<=q.rear;i++)
	     cout<<q.data[i]<<" ";
}
int main()
{      Queue obj;
	int ch,x;
	do{    cout<<"\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
	       cin>>ch;
	switch(ch)
	{  case 1: if (!obj.isfull())
		   {   cout<<"\n Enter data : \n";
			cin>>x;
			obj.enqueue(x);
			cout<<endl;
		   }
	          else
		      cout<< "Queue is overflow!!!\n\n";
	           break;
	   case 2: if(!obj.isempty())
			    cout<<"\n Deleted Element = "<<obj.delqueue()<<endl;
		    else
			{   cout<<"\n Queue is underflow!!!\n\n";  }
		    cout<<"\nRemaining Jobs : \n";
		    obj.display();
	           break;
	  case 3: if (!obj.isempty())
	        {  cout<<"\n Queue contains : \n";
		       obj.display();
	        }
	        else
		         cout<<"\n Queue is empty!!!\n\n";
	       break;
	  case 4: cout<<"\n Exiting Program.....";
        }
      }while(ch!=4);
return 0;
}
