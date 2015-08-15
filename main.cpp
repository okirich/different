/* 
 * File:   main.cpp
 * Author: Дом
 *
 * Created on 14 августа 2015 г., 22:10
 */

#include <iostream>
using namespace std;
int i=0;

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
    DynArray();
    return 0;
}
