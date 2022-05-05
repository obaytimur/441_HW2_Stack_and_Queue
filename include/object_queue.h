//
// Created by ogi on 25.12.2021.
//

#ifndef HOMEWORK_2_OBJECT_QUEUE_H
#define HOMEWORK_2_OBJECT_QUEUE_H
#include <iostream>
#include <cstdlib>
using namespace std;
const int MaxQSizeObj=20;
template <class T>
class object_queue{
private:
    int front, rear, count;
    T qlist[MaxQSizeObj];
public:
    object_queue();
    void Qinsert(const T& item);
    T Qdelete();
    T Qbackdelete();
    void ClearQueue();
    T QFront() const;
    int QLength() const;
    int QEmpty() const;
    int QFull() const;

};


#endif //HOMEWORK_2_OBJECT_QUEUE_H
