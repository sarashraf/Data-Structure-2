#include <iostream>
using namespace std;
template <class T>
class thequeue
{

public:
    //the default constructor of the class which takes the size of the array as a parameter
    T*arr;
    int thesize;
    int current_size;
    int f,r;
    thequeue()
    {
    }
    thequeue(int arrsize)
    {
        thesize=arrsize;
        arr=new T [thesize];
        f=r=-1;
        current_size=0;
    }
//function enqueue that add values at the end of the queue
    void enqueue (T value)
    {
        r=r+1%thesize;
        arr[r]=value;
        if(f==-1)
        {
            f=r;
        }
        current_size++;
    }
//function dequeue that removes a value from the beginning of the queue
    int dequeue()
    {
        int val=arr[f];
        f=(f+1)%thesize;
        current_size--;
        return val;
    }

    //function that checks if the queue is empty or not
    bool isEmpty()
    {
        if(f==-1 && r ==-1)
            return true;
        else
            return false;
    }

    T* getarr()
    {
        return arr;
    }
//function that returns the first value in the queue
    int thefront()
    {
        if (f==-1)
            cout<<"the queue is empty."<<endl;
        else
            return arr[f];
    }

    int theback()
    {
        if (r==-1)
            cout<<"the queue is empty."<<endl;
        else
            return arr[r];
    }
//function that returns the size of the queue
    int getsize ()
    {
        return current_size;
    }

    /* void display ()
     {
         for(int i=f;i<thesize;i++)
         {
             cout<<arr[i]<<endl;
         }
     }
 */

    ~thequeue()
    {
        delete [] arr;
    }
};

//function that returns the time taken by the person(k) to buy all the tickets he needs
template<class t>
int getTime(thequeue <t> *q, int k)
{
    int time=0;
    while(q->arr[k]!=0)
    {
        if(q->arr[q->f]==0)
        {
            q->dequeue();
            continue;
        }
        q->arr[q->f]=q->arr[q->f]-1;
        time++;
        q->f=(q->f+1)%q->thesize;
       // q->r=(q->r+1)%q.thesize;
    }
    return time;
}
int main()
{
    thequeue <int>q1 (3);
    q1.enqueue(4);
    q1.enqueue(2);
    q1.enqueue(1);

    cout<<"the time taken for the first queue is : "<<getTime(&q1,2)<<endl;

    cout<<"------------------------------------------"<<endl;
    thequeue <int>q2(4);
    q2.enqueue(5);
    q2.enqueue(1);
    q2.enqueue(1);
    q2.enqueue(1);

    cout<< "the time taken  for the second queue is : "<<getTime(&q2,0)<<endl;

    return 0;
}
