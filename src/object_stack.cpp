//
// Created by ogi on 15.12.2021.
//
#include "object_stack.h"
#include "student.h"
template <class T>
object_stack<T>::object_stack(){
    top=-1, kontenjan=0;
}
template <class T>
void object_stack<T>::SetSize(int size) {
    kontenjan=size;
}
template <class T>
int object_stack<T>::StackEmpty() const
{
    return top==-1;
}
template <class T>
int object_stack<T>::StackFull() const
{
    return top==(kontenjan-1);
}
template <class T>
void object_stack<T>::Push(const T& item)
{
    if (StackFull())
    {
        cerr<<"Stack overflow"<<endl;
        exit(1);
    }
    top++;
    stacklist[top]=item;
}
template <class T>
T object_stack<T>::Pop()
{
    T temp;
    if (StackEmpty())
    {
        cerr<<"Stack empty"<<endl;
        exit(1);
    }
    temp=stacklist[top];
    top--;
    return temp;
}
template <class T>
T object_stack<T>::Peek() const
{
    T temp;
    if (StackEmpty())
    {
        cerr<<"Stack empty"<<endl;
        exit(1);
    }
    temp=stacklist[top];
    return temp;
}
template <class T>
void object_stack<T>::ClearStack() {
    top=-1;
}
template class object_stack<student>;

