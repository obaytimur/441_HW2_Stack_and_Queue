//
// Created by ogi on 15.12.2021.
//

#include "student.h"
student::student() {
    id="", prefone='0',prefsecond='0', prefthird='0';
}
void student::SetID(string number) {
    id=number;
}
string student::GetID() {
    return id;
}
void student::SetPrefOne(char pref) {
    prefone=pref;
}
void student::SetPrefSecond(char pref) {
    prefsecond=pref;
}
void student::SetPrefThird(char pref) {
    prefthird=pref;
}
char student::GetPrefOne() {
    return prefone;
}
char student::GetPrefSecond() {
    return prefsecond;
}
char student::GetPrefThird() {
    return prefthird;
}
int student::available_cont(object_stack<student> wed, object_stack<student> thurs, object_stack<student> fri) {
    int count=0;
    if(!wed.StackFull()&&(prefone=='W'||prefsecond=='W'||prefthird=='W')){
        count++;
    }
    if(!thurs.StackFull()&&(prefone=='T'||prefsecond=='T'||prefthird=='T')){
        count++;
    }
    if(!fri.StackFull()&&(prefone=='F'||prefsecond=='F'||prefthird=='F')){
        count++;
    }
    return count;
}
