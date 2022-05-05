//
// Created by ogi on 15.12.2021.
//

#ifndef HOMEWORK_2_STUDENT_H
#define HOMEWORK_2_STUDENT_H
#include <iostream>
#include "object_stack.h"
using namespace std;
class student : public error_code {
private:
    string id;
    char prefone,prefsecond,prefthird;
public:
    student();
    void SetID (string number);
    string GetID ();

    void SetPrefOne (char pref);
    void SetPrefSecond (char pref);
    void SetPrefThird (char pref);
    char GetPrefOne ();
    char GetPrefSecond ();
    char GetPrefThird ();

    int available_cont (object_stack<student> wed, object_stack<student> thurs, object_stack<student> fri);
};


#endif //HOMEWORK_2_STUDENT_H
