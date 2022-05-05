
#include <iostream>
#include <string>
#include <fstream>
#include "object_queue.h"
#include "object_stack.h"
#include "student.h"
#include "string"
using namespace std;

int main(){
    char id[50];
    object_stack<student> wednesday;
    object_stack<student> thursday;
    object_stack<student> friday;
    object_queue<student> waiting;
    ifstream inputtxt;
    ofstream outputtxt;
    inputtxt.open("preferences.txt");
    outputtxt.open("out.txt");
    char output[100];
    if (inputtxt) {
        cout << "reading is successfull" << endl;
        while (!inputtxt.eof()) {
            inputtxt >> output;
            if (isalpha(output[0])){
                if(output[0]=='F'){
                    friday.SetSize(output[2]-'0');
                }
                if(output[0]=='T'){
                    thursday.SetSize(output[2]-'0');
                }
                if(output[0]=='W'){
                    wednesday.SetSize(output[2]-'0');
                }
            }
            else{
                student ReadStudent;
                int i=0;
                if(output[5]==','&&output[7]!=','){
                    while(output[i]!=','){
                        id[i]=output[i];
                        i++;
                    }
                    ReadStudent.SetID(id);
                    ReadStudent.SetPrefOne(output[i+1]);
                    ReadStudent.SetPrefSecond(output[i+3]);
                    waiting.Qinsert(ReadStudent);
                }
                else if(output[5]==','&&output[7]==','){
                    while(output[i]!=','){
                        id[i]=output[i];
                        i++;
                    }
                    ReadStudent.SetID(id);
                    ReadStudent.SetPrefOne(output[i+1]);
                    ReadStudent.SetPrefSecond(output[i+3]);
                    ReadStudent.SetPrefThird(output[i+5]);
                    waiting.Qinsert(ReadStudent);
                }
                else{
                    while(output[i]!=','){
                        id[i]=output[i];
                        i++;
                    }
                    ReadStudent.SetID(id);
                    ReadStudent.SetPrefOne(output[4]);
                    if(output[4]=='W'){
                        wednesday.Push(ReadStudent);
                    }
                    if(output[4]=='T'){
                        thursday.Push(ReadStudent);
                    }
                    if(output[4]=='F'){
                        friday.Push(ReadStudent);
                    }
                    for(int k=0;k<waiting.QLength();k++){
                        if(waiting.QFront().available_cont(wednesday,thursday,friday)==1){
                            char tercih = waiting.QFront().GetPrefOne();
                            int done=0;
                            if(tercih){
                                switch (tercih) {
                                    case 'W':
                                        if (!wednesday.StackFull()) {
                                            wednesday.Push(waiting.Qdelete());
                                            done=1;
                                            break;
                                        }
                                    case 'T':
                                        if (!thursday.StackFull()) {
                                            thursday.Push(waiting.Qdelete());
                                            done=1;
                                            break;
                                        }
                                    case 'F':
                                        if (!friday.StackFull()) {
                                            friday.Push(waiting.Qdelete());
                                            done=1;
                                            break;
                                        }
                                }
                                tercih=waiting.QFront().GetPrefSecond();
                                if(!done&&tercih){
                                    switch (tercih) {
                                        case 'W':
                                            if (!wednesday.StackFull()) {
                                                wednesday.Push(waiting.Qdelete());
                                                done=1;
                                                break;
                                            }
                                        case 'T':
                                            if (!thursday.StackFull()) {
                                                thursday.Push(waiting.Qdelete());
                                                done=1;
                                                break;
                                            }
                                        case 'F':
                                            if (!friday.StackFull()) {
                                                friday.Push(waiting.Qdelete());
                                                done=1;
                                                break;
                                            }
                                    }
                                    tercih=waiting.QFront().GetPrefThird();
                                    if(!done&&tercih){
                                        switch (tercih) {
                                            case 'W':
                                                if (!wednesday.StackFull()) {
                                                    wednesday.Push(waiting.Qdelete());
                                                    done=1;
                                                    break;
                                                }
                                            case 'T':
                                                if (!thursday.StackFull()) {
                                                    thursday.Push(waiting.Qdelete());
                                                    done=1;
                                                    break;
                                                }
                                            case 'F':
                                                if (!friday.StackFull()) {
                                                    friday.Push(waiting.Qdelete());
                                                    done=1;
                                                    break;
                                                }
                                        }
                                    }
                                }
                            }
                            else if(!done){

                                waiting.Qinsert(waiting.Qdelete());
                            }
                        }
                        waiting.Qinsert(waiting.Qdelete());
                    }
                }
            }
        }
    }
    waiting.Qbackdelete();

    int upperbound_two=waiting.QLength();
    for(int k=0;k<upperbound_two;k++) {
        char tercih = waiting.QFront().GetPrefOne();
        int done = 0;
        if (tercih) {
            switch (tercih) {
                case 'W':
                    if (!wednesday.StackFull()) {
                        wednesday.Push(waiting.Qdelete());
                        done = 1;
                        break;
                    }
                case 'T':
                    if (!thursday.StackFull()) {
                        thursday.Push(waiting.Qdelete());
                        done = 1;
                        break;
                    }
                case 'F':
                    if (!friday.StackFull()) {
                        friday.Push(waiting.Qdelete());
                        done = 1;
                        break;
                    }
            }
            tercih = waiting.QFront().GetPrefSecond();
            if (!done && tercih) {
                switch (tercih) {
                    case 'W':
                        if (!wednesday.StackFull()) {
                            wednesday.Push(waiting.Qdelete());
                            done = 1;
                            break;
                        }
                    case 'T':
                        if (!thursday.StackFull()) {
                            thursday.Push(waiting.Qdelete());
                            done = 1;
                            break;
                        }
                    case 'F':
                        if (!friday.StackFull()) {
                            friday.Push(waiting.Qdelete());
                            done = 1;
                            break;
                        }
                }
                tercih = waiting.QFront().GetPrefThird();
                if (!done && tercih) {
                    switch (tercih) {
                        case 'W':
                            if (!wednesday.StackFull()) {
                                wednesday.Push(waiting.Qdelete());
                                done = 1;
                                break;
                            }
                        case 'T':
                            if (!thursday.StackFull()) {
                                thursday.Push(waiting.Qdelete());
                                done = 1;
                                break;
                            }
                        case 'F':
                            if (!friday.StackFull()) {
                                friday.Push(waiting.Qdelete());
                                done = 1;
                                break;
                            }
                    }
                }
            }
        } else if (!done) {

            waiting.Qinsert(waiting.Qdelete());
        }
    }

    outputtxt << "Wednesday:" << endl;
    while(!wednesday.StackEmpty()){
        outputtxt << wednesday.Pop().GetID() << endl;
    }
    outputtxt << "\n" << "Thursday:" << endl;
    while(!thursday.StackEmpty()){
        outputtxt << thursday.Pop().GetID() << endl;
    }
    outputtxt << "\n" << "Friday:" << endl;
    while(!friday.StackEmpty()){
        outputtxt << friday.Pop().GetID() << endl;
    }
    outputtxt << "\n" << "Unassigned:" << endl;
    while(!waiting.QEmpty()){
        outputtxt << waiting.Qdelete().GetID() << endl;
    }

    inputtxt.close();
    outputtxt.close();
}
