#include "objcreator.h"

//конструктор
ObjCreator::ObjCreator(string str)
{
    setLongNumF(str);
}

string ObjCreator::setLongNumF(string str){    //получение длинного числа на вход
    for(int i=0;i<str.size();i++){    //проверка, что все члены строки цифры
        if(!isdigit(str[i])){
            cout<<"invalid Input\n";
            break;
        }
    }
    LongNumF=str;
    return LongNumF;
}

string ObjCreator::getLongNumR(){    //запись длинного числа нооборот
    for(string::reverse_iterator rit=LongNumF.rbegin();rit!=LongNumF.rend();++rit){
        temp=*rit;
        LongNumR.push_back(temp);
    }
    while(LongNumR.size()>1&&LongNumR.back()=='0')
        LongNumR.pop_back();
    return LongNumR;    //вывод длинного числа наоборот
}


