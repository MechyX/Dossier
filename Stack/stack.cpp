#include "stack.hpp"
using namespace std;

template<typename T>
Stack<T> :: Stack(int capacity){
    this->capacity = capacity;
    top=-1;
    stack = new T[capacity];
}

template<class T>
Stack<T>::~Stack()
{
    delete[] stack;
}

template<typename T>
void Stack<T> :: push(T data){
   if( top == capacity -1)
        cout<<"Stack Overflow"<<endl;

    else
    {
        top++;
        stack[top] = data;
    }
}

template<typename T>
void Stack<T> :: pop(){
   if( top == -1)
        cout<<"Stack Underflow"<<endl;

    else
       stack[top--];     
}


template<typename T>
bool Stack<T> :: empty(){
    if(top == -1)
        return true;
    
    return false;
}

template<typename T>
int Stack<T> :: size(){
    return top+1;
}

template<typename T>
T&  Stack<T> :: Top(){
    try
    {
         if(top != -1)
            return stack[top];
        
        throw "Error : Cannot return reference since there is no element";
    }
    catch(const char *e)
    {
        cout << e;
    }
    
}


int main(){
    Stack<double> stack(5);
    cout << stack.Top() << endl;
    cout << stack.size();
    return 0;
}