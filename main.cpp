#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;
//functions necessary for the implementation of stacks with arrays

bool isFull(int &last, int  &size){
    if (last==size-1) return true;
    return false;
    }

bool isEmpty(int &last){
    if (last==-1) return true;
    return false;
    }

void push(int data, int arr[], int &last, int &size ){
    if (isFull(last, size)){
        cout<<"stack overflow"<< endl;
    }
    else{
        last++;
        arr[last]=data;
        cout<< data << " pushed"<<endl;
    }
}

void pop (int arr[], int &last){
    if (isEmpty(last)){
        cout<<"Stack underflow"<<endl;
    }
    else{
        cout<< arr[last]<<" popped"<<endl;
        last--;
    }
}

void stackTop (int arr[], int &last){
    if (isEmpty(last)){
        cout<<"Stack underflow"<<endl;
    }
    else{
        cout<<arr[last]<<endl;
    }
}

void display (int arr[], int &last){
    for (int i=0; i<=last; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}


//implementation of stacks with linked lists

class Node{
public:
    int data;
    Node* next;

    Node (int data){
        this->data=data;
        this->next=nullptr;
    }
};

class Stack{
private:
    Node* head;

    //constructor
public:
    Stack(){
        head=nullptr;
    }

    void push(int data){
        Node* newNode = new Node(data);
        newNode->next=head;
        head=newNode;
        cout<<data<<" pushed"<<endl;
    }

    bool isEmpty(){
        if (head==nullptr) return true;
        return false;
    }

    void pop(){
        if (isEmpty()) cout<<"stack underflow"<<endl;
        else{
            cout << head->data<< " popped"<<endl;
            head= head->next;
        }
    }

    void stackTop(){
        cout << head->data<<endl;
    }

    void display(){
        Node * itr =head;
        while(itr){
            cout<<itr->data<< " ";
            itr=itr->next;
        }
        cout<<endl;
    }



};

int main()
{

    //stacks with arrays
    int size;
    cout<< "Enter the size of the array : "<<endl;
    cin>>size;
    auto startA= high_resolution_clock::now();
    int arr[size];
    int last=-1;

    for (int i=0; i<10; i++){
        int num =rand() % 100;
        push (num, arr, last, size);
    }

    display(arr, last);

    for (int i=0; i<5; i++) pop(arr, last);

    display(arr, last);

    for (int i=0; i<4; i++){
        int num =rand() % 100;
        push (num, arr, last, size);
    }

    display(arr, last);

    auto stopA = high_resolution_clock::now();
    auto durationA = duration_cast <microseconds> (stopA-startA);
    cout << "Time for stack implementation with arrays : " << durationA.count()<< endl;

    //stacks with linkedLists
    auto startL= high_resolution_clock::now();
    Stack s;

    for (int i=0; i<10; i++){
        int num =rand() % 100;
        s.push (num);
    }

    s.display();

    for (int i=0; i<5; i++) s.pop();

    s.display();

    for (int i=0; i<4; i++){
        int num =rand() % 100;
        s.push (num);
    }

    s.display();
    auto stopL = high_resolution_clock::now();
    auto durationL = duration_cast <microseconds> (stopL-startL);
    cout << "Time for stack implementation with linked lists : " << durationL.count()<< endl;

    return 0;
}
