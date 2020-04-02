#include<iostream>


template<typename T>
class Stack{
    T* stack;
    int capacity;
    int top;
    public:
    Stack(int);
    ~Stack();
    void push(T);
    void pop();
    T& Top();
    int size();
    bool empty();
};
