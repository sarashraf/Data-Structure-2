#include <iostream>
#include "queue"
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
    thequeue(int arrsize=100)
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
// class stack for creating stack by the my_queue
class stack{
    thequeue <int> my_queue;
    public:
    // to show the top element
        int Top(){
        if(my_queue.isEmpty()){
            return -1;
        }
        else{
            return my_queue.theback();
        }
    }
    // to exit the element from the stack
    void pop(){
        int i=my_queue.theback();
        while (my_queue.thefront()!=i)
        {
            my_queue.enqueue(my_queue.thefront());
            my_queue.dequeue();
        }
        my_queue.dequeue();
    }
    // to insert the element in the stack
    void push(int element){
        my_queue.enqueue(element);
    }
};

int main() {
    stack A;
    A.push(12);
    A.push(55);
    A.push(123);
    A.push(111);
    A.push(765);
    A.push(589);
    A.push(44);
    A.push(50);
    A.push(120);
    A.push(110);
    A.push(760);
    A.push(500);
    cout<< A.Top() << endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;
    A.pop();
    cout << A.Top() <<endl;


    return 0;
}
