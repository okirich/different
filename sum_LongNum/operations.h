#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <string>
#include <objcreator.h>
#include <vector>
using namespace std;


class Operations
{
private: string long1,long2;
    vector<int> Result;
public:
    //конструктор
    Operations(string*,string*);
    void Addition();
    void getResult();
};

#endif // OPERATIONS_H
