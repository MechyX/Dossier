#include<iostream>

template<typename T>
class Queue{
    int front;
    int rear;
    int capacity;
    T * queue;
    public:
    Queue(int);
    ~Queue();
    void enqueue(T);
    void dequeue();
    int size();
    T& Front();
    T& Rear();
};