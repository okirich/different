/* 
 * File:   main.cpp
 * Author: Дом
 *
 * Created on 14 августа 2015 г., 22:10
 */

#include <iostream>
using namespace std;
int i=0;
int x;

//pointers and references

void pointers_references(){
    int a;
    int *b;
    cout << "a=?" <<endl;
    cin >> a;
    b=&a;
    int *p=b;
    cout <<"b=&a=" << b << endl;
    cout <<"p=" << p << endl;
    cout <<"*p="<< *p <<endl;
}


//dynamic array

void DynArray(){
    int vol;
    cout << "enter volume of array" <<endl;
    cin >> vol;
    cout << "volume is:" << vol <<endl;
    int *p_DynArray = new int[vol];
    cout << "enter values of elements" <<endl;
    while(i<vol){
        cout << i << ':' <<endl;
        cin >> p_DynArray[i];
        i++;
    }
    cout << "Your array is:" <<endl;
    for (int i=0; i<vol;i++)
        cout << p_DynArray[i] <<',';
    delete [] p_DynArray;
}

//queue
//stack
//heap
//hash func

int main()
{
    cout << "x=?"<< endl;
    cout << "1.Dynamic Arrays"<<endl;
    cout << "2.Pointers_References"<<endl;
    cout << "0.exit"<<endl;
    cin >> x;
    while(x!=0){
    switch(x){
        case 1:
            DynArray();
            break;
        case 2:
            pointers_references();
            break;
    }
    cout<<"x=?"<<endl;
    cin>>x;
    }
    return 0;
}
