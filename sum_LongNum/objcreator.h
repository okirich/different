#ifndef OBJCREATOR_H
#define OBJCREATOR_H
#include <string>
#include <iostream>
using namespace std;


class ObjCreator
{
private:
    string LongNumF,LongNumR,str;
    int temp;
public:
    ObjCreator(string);
    string setLongNumF(string);
    string getLongNumR();
};

#endif // OBJCREATOR_H
