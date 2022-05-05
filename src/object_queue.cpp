//
// Created by ogi on 24.12.2021.
//

#include "object_queue.h"
#include "student.h"
template <class T>
object_queue<T>::object_queue(){
    front=0, rear=0,  count=0;
}
template <class T>
int object_queue<T>::QLength() const {
    return  count;
}
template <class T>
int object_queue<T>::QEmpty() const {
    return (count==0);
}
template <class T>
int object_queue<T>::QFull() const {
    return (count==MaxQSizeObj);
}
template <class T>
void object_queue<T>::Qinsert(const T& item) {
    if (QFull()){
        cerr << "Queue overflow!" << endl;
        exit(1);
    }
    count++;
    qlist[rear]=item;
    rear=(rear+1)%MaxQSizeObj;
}
template <class T>
T object_queue<T>::Qdelete() {
    T temp;
    if (QEmpty()){
        cerr << "Deleting from an empty queue" << endl;
        exit(1);
    }
    temp=qlist[front];
    count--;
    front=(front+1)%MaxQSizeObj;
    return temp;
}
template <class T>
T object_queue<T>::Qbackdelete() {
    T temp;
    if (QEmpty()){
        cerr << "Deleting from an empty queue" << endl;
        exit(1);
    }
    temp=qlist[rear];
    count--;
    rear=(rear-1)%MaxQSizeObj;
    return temp;
}
template <class T>
T object_queue<T>::QFront() const {
    return qlist[front];
}
template class object_queue<student>;

