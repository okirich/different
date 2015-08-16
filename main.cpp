/* 
 * File:   main.cpp
 * Author: Дом
 *
 * Created on 16 августа 2015 г., 11:59
 */

#include <iostream>

using namespace std;

struct Singly{
    int data;
    Singly *next;
};

Singly *head=0;

void AddNode(int x){
    Singly *Next=new Singly;
    Next->data=x;
    Next->next=0;
    if (head==0){
        head=Next;
        return;
    }
    Singly *Cur=head;
    while(Cur){
        if(Cur->next==0){
            Cur->next=Next;
            return;
        }
        Cur=Cur->next;
    }
}

void display(){
        Singly *Cur = head;
        while(Cur){
            cout<< Cur->data<<" ";
            Cur=Cur->next;
        }
        cout<<endl;
    }

int main() {
    int x;
    while(x!=0){
        cout<<"enter x"<<endl;
        cout<<"1.AddNode"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"0.exit"<<endl;
        cin>>x;
        switch(x){
            case 1:
                int a;
                cout<<"enter data"<<endl;
                cin>>a;
                AddNode(a);
                break;
            case 2:
                display();
                break;
        }
    }
    return 0;
}