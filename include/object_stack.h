//
// Created by ogi on 25.12.2021.
//

#ifndef HOMEWORK_2_OBJECT_STACK_H
#define HOMEWORK_2_OBJECT_STACK_H
#include <iostream>
#include <cstdlib>
using namespace std;
const int MaxStackSizeObj=50;
template <class T>
class object_stack{
private:
    int top, kontenjan;
    T stacklist[MaxStackSizeObj];
public:
    object_stack();
    void SetSize (int size);
    void Push (const T& item);
    T Pop();
    void ClearStack();
    T Peek() const;
    int StackEmpty() const;
    int StackFull() const;
};
#endif //HOMEWORK_2_STACK_H
