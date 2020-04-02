#include "queue.hpp"
using namespace std;

template<typename T>
Queue<T>::Queue(int capacity)
{
    this->capacity = capacity;
    queue = new T[capacity];
    front = -1;
    rear = -1;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] queue;
}

template <class T>
int Queue<T>::size()
{
    return rear - front;
}

template<typename T>
void Queue<T>:: enqueue(T data){
    if(rear == capacity-1)
        cout<<"Queue Full"<<cout;

    else
        queue[++rear] = data;
}

template<typename T>
void Queue<T>:: dequeue(){
    if(front == rear)
        cout<<"Queue Empty"<<cout;

    else
        front++;
}

template<typename T>
T& Queue<T>:: Rear(){
    try
    {
        if(front != rear)
            return queue[rear];
        else
        throw "Error : Cannot return reference since there is no element";
    }
    catch(const char* e)
    {
        cout<<e;
    }
}

template<typename T>
T& Queue<T>:: Front(){
    try
    {
        if(front != rear)
            return queue[front+1];

        throw "Error : Cannot return reference since there is no element";
    }
    catch(const char* e)
    {
        cout<<e;
    }
}

int main(){
    Queue<int> queue(2);
    queue.enqueue(10);
    queue.enqueue(20);
    int& a = queue.Front();
    int& b = queue.Rear();
    cout<< a << " " << b <<endl;
    cout<< queue.size() <<endl;
    queue.dequeue();
    int &c = queue.Front();
    cout << c <<endl;
    return 0;
}