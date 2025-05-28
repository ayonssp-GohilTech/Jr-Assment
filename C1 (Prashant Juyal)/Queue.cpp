#include<iostream>
using namespace std;

template <typename T>
class Queue
{
    int size;
    T arr[20]; // fix
    T front=0, rear=0; // fix
public:
    Queue(int s)
    {
        size=s;
        cout<<size;
    }

    // Fix (dynamic memory allocation)
    void enqueue(T data)
    {
    
        if(rear==size)
        {
            cout<<"Queue is full";
            return;
        }
        arr[rear]=data;
        rear++;
   }

   void dequeue()
   {
        if(front==rear)
        {
            cout<<"Queue is empty";
            return;
        }
        front++;
    }
    T peek()
    {
        if(front==rear)
        {
            cout<<" Queue is empty";
            return 0;
        }
        return arr[front];

    }
    void display()
    {
        for(int i=front;i<rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    cout << "\nQueue Front: " << q.peek() << endl;

    Queue<char> q2(5);
    q2.enqueue('A');
    q2.enqueue('B');
    q2.enqueue('C');
    q2.display();
    q2.dequeue();
    q2.dequeue();
    q2.display();

    return 0;
}