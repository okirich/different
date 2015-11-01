#include <stdio.h>
#include <string>
#include <iostream>
#include <objcreator.h>
#include <operations.h>
using namespace std;

int main(){
    string LongNumR1,LongNumR2;
    string str;
    cout<<"longNum1: \n";
    cin>>str;
    ObjCreator LongNum1(str);
    LongNumR1=LongNum1.getLongNumR();
    str.clear();
    cout<<"longNum2: \n";
    cin>>str;
    ObjCreator LongNum2(str);
    LongNumR2=LongNum2.getLongNumR();
    Operations ResultOfAddition(&LongNumR1,&LongNumR2);
    ResultOfAddition.Addition();
    ResultOfAddition.getResult();
    return 0;
}
