
# Stack

Stack is a Linear Data Structure that operate on First-In-Last-Out(FILO) or Last-In-First-Out(LIFO) , where the last element added to the stack is the first to be removed. It allow push,pop,peek to add, remove and read data.



## Implement
Stacks can be implemented using array and linklist . 

Here is a array implementation.

- Initialize an array to represent the stack.
- Use the end of the array to represent the top of the stack.
- Implement push (add to end), pop (remove from the end), and peek (check end) operations.


## Code

Array Implementation

```cpp
#include <iostream>
using namespace std; 

int size=5,top=0,arr[10];

bool isEmpty()  //function check that the stack is empty or not.
{
  if(top==0)
  {
    cout<<"\nStack underflow ";
    return true;
  }
  else
    return false;
}

bool isFull() //functin check that the stack is full or not.
{
  if(top==size)
  {
      cout<< "\nStack overflow ";
      return true;
  }
  else
    return false;
}

void push(int data)  // function to add element in the stack
{
     if(!isFull())
     {
        arr[top]=data;
        cout<<"\n push :"<<arr[top]<<"\n";
        top++;
     }
    
}

void pop()  //function to remove the element
{
  if(isEmpty())
  {
    return;
  }

  int temp= arr[top-1];
  //cout<<"\ntop : "<<top<<"\n";
  cout<<"\npop value : "<<temp<<"\n";

  top--;

  for(int i=0;i<top;i++)
    cout<<arr[i]<<" ";
}

int read()   //function to read the element at top
{
  return arr[top-1];
}



int main()
{ 
  //int data;
  //cout<<"enter data :";
  //cin >> data;
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  push(60);
  pop();
  cout<< "\ndata : "<<read();
  push(70);
  push(80);
  pop();
  pop();
  pop();
  push(90);
  push(100);
  


  return 0; 
}
```



## Code
Linklist Implementation

```cpp
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head=nullptr;

void push(int data) 
{
        Node* new_node = new Node;
        if (!new_node) {
            cout << "\nStack Overflow";
        }
        new_node->data=data;
        new_node->next =head;
        head = new_node;
}

void pop()
{
    if(head==nullptr)
    {
        cout<<"stack underflow";
    }
    else
    {
        Node* temp=head;
        head=head->next;
        cout<<"\npop : "<<temp->data<<"\n";
        delete temp;
    }
    
}

void show()
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data <<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    show();
    pop();
    show();
    pop();
    show();
    push(40);
    show();

    return 0;
}


```


## Rehearsal 
[Question 1](https://www.geeksforgeeks.org/problems/reverse-array-using-stack--143151/1?page=1&category=Stack&sortBy=difficulty)

Solution :

```cpp
#include<iostream>
using namespace std;

int i,arr[10],n,rev[10],top,num;

void push(int data)
{
        rev[num]=data;
        num++;
}

void pop()
{
  int temp= arr[top-1];
  push(temp);
  top--;
}

int main()
{
    cout<<"enter size : ";
    cin>>n;

    cout<<"enter input :";
    for(top=0;top<n;top++)
        cin>>arr[top];

    cout<<"\noriginal array : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    for(int i=0;i<n;i++)
        pop();

    cout<<"\nReverse array : ";

    for(int i=0;i<n;i++)
        cout<<rev[i]<<" ";


    return 0;
}


```







# Queue

Queue is a Linear Data Structure that operate on First-In-First-Out(FIFO) or Last-In-Last-Out(LILO) , where the first element added to the queue is the first to be removed. It allow enqueue,dequeue,peek to add, remove and read data.



## Code

Array Implementation

```cpp
#include <iostream>
using namespace std; 

int size=5,front=0,rear=0,arr[10];

bool isEmpty()  //function check that the queue is empty or not.
{
  if(rear==0)
  {
    cout<<"\n Underflow ";
    return true;
  }
  else
    return false;
}

bool isFull() //functin check that the queue is full or not.
{
  if(rear==size)
  {
      cout<< "\n Overflow ";
      return true;
  }
  else
    return false;
}

void enqueue(int data)  // function to add element in the queue
{
     if(!isFull())
     {
        arr[rear]=data;
        cout<<"\n enqueue :"<<arr[rear]<<"\n";
        rear++;
     }
    
}

void dequeue()  //function to remove the element
{
  if(isEmpty())
  {
    return;
  }

  int temp= arr[front];
  cout<<"\npop value : "<<temp<<"\n";

  front++;

  for(int i=front;i<rear;i++)
    cout<<arr[i]<<" ";
}

int peek()   //function to read the element at rear
{
  return arr[rear];
}



int main()
{ 
  enqueue(10);
  enqueue(20);
  enqueue(30);
  dequeue();
  dequeue();
  


  return 0; 
}
```



## Rehearsal 
[Question 1](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/)

Solution :

```cpp
#include<iostream>
using namespace std;

int main()
{
    int arr[20],n=9,k,res[20];
    cout<<"enter array :";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"enter k :";
    cin>>k;


    for(int i=0;i<=n-k;i++) 
    {
        int max = arr[i];
        for (int j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        res[i]=max;
    }

    for(int i=0;i<=n-k;i++)
        cout<<res[i]<<" ";

    return 0;
}


```
## Rehearsal 
[Question 2](https://www.geeksforgeeks.org/flood-fill-algorithm/)

Solution :
```cpp

#include<iostream>
using namespace std;

int main()
{
    int arr[10][10],res[10][10];
    int r=3,c=4;
    cout<<"enter matrix ; ";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==arr[i][j+1 || arr[i][j]==arr[i+1][j]])
            {
                res[i][j]=2;
            }
            else{
                res[i][j]=arr[i][j];
            }

        }
        //Input: image = [[1, 1, 1, 0], 
        //                [0, 1, 1, 1], 
        //                [1, 0, 1, 1]]
        //, sr = 1, sc = 2, newColor = 2
// Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2,2]]
        //Input: image = [[0, 1, 0],
//                        [0, 1, 0]], sr = 0, sc = 1, newColor = 0
//Output: [[0, 0, 0], [0, 0, 0]]
    }


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<res[i][j] <<" ";
        }
    }



    return 0;
}




//Input: image = [[0, 1, 0],
//                [0, 1, 0]], sr = 0, sc = 1, newColor = 0
//Output: [[0, 0, 0], [0, 0, 0]]


```