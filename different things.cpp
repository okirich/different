/* 
 * File:   main.cpp
 * Author: Дом
 *
 * Created on 14 августа 2015 г., 22:10
 */
#include <iostream>
using namespace std;
int i=0;

/*pointers and references

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
*/

/*dynamic array

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
*/

/* //queue;

struct Node{ //Структура узла очереди
    int data;
    Node *next;
};

struct Queue{ // Структура очереди 
    int size; 
    Node *first;
    Node *last;
};

void CreationQueue(Queue *Q){ // Создаем новую очередь
    Q->first=new Node;
    Q->first->next=0;
    Q->last=Q->first;
    Q->size=0;
}

bool isEmpty(Queue *Q){ // Проверка на пустоту
    if (Q->first==Q->last)
        return true;
    else return false;
}

void AddQueue(Queue *Q){ // Добавление нового элемента в очередь
    int value;
    cout<<"Value =\n";
    cin>> value;
    Q->last->data=value;
    Q->last->next=new Node; // Указатель "последний" создает новый узел
    Q->last=Q->last->next; // указатель "последний" передвинул на только что созданный узел
    Q->last->next=0; // Указатель "последний" теперь указывает на пустоту
    Q->size++;
    cout<< "element added\n";
}

int Top(Queue *Q){
    return Q->first->data; // Вывод первого элемента
}

void Delete(Queue *Q){ // Удаление элемента из очереди
    Node *q=Q->first; // Сохраняем указатель на удаляемый элемент
    Q->first=Q->first->next; // Перемещаем указатель начала на следующий элемент
    delete q; //высвобождаем память  
    Q->size--;
    cout<<"Element deleted\n";
}

int Size(Queue *Q){
    return Q->size;
}
*/

//stack

struct Node{ //Cтруктура узла стэка
    int data;
    Node *link;
};

struct stack{
    int size;
    Node *top;
    Node *temp;
};


void creation(stack *S){
    S->top=0;
    S->size=0;
}

void push(stack *S){
    int value;
    cout<<"value =\n";
    cin>>value;
    S->temp=new Node;
    S->temp->data=value;
    S->temp->link=S->top;
    S->top=S->temp;
    S->size++;
}

void pop(stack *S){
    S->temp=S->top;
    S->top=S->top->link;
    delete S->temp;
    S->size--;
}

int Top(stack *S){
    return S->top->data;
}

int Size(stack*S){
    return S->size;
}

bool isEmpty(stack *S){
    if (S->top==0)
        return true;
    else return false;
}
//

//heap
//hash func

int main() {
    /* //DynArray
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
     */
    /* //Queue
    Queue Q;
    int choice;
    CreationQueue(&Q);
    cout << "1.Add elemnt\n";
    cout << "2.Delete element\n";
    cout << "3.show top\n";
    cout << "4.Show size\n";
    cout << "0.exit\n";
    while (choice != 0) {
        cin>>choice;
        switch (choice) {

            case 1:
            {
                AddQueue(&Q);
                break;
            }

            case 2:
            {
                if (isEmpty(&Q))
                    cout << "Queue is empty\n";
                else Delete(&Q);
                break;
            }

            case 3:
            {
                if (isEmpty(&Q))
                    cout << "Queue is empty\n";
                else cout << Top(&Q) << endl;
                break;
            }

            case 4:
            {
                if (isEmpty(&Q))
                    cout << "Queue is empty\n";
                else cout << Size(&Q) << endl;
                break;
            }
        }
    }
    cout << "Bye\n";
    */
    // //stak
    int choice;
    stack S;
    creation(&S);
    cout<<"1.push\n";
    cout<<"2.pop\n";
    cout<<"3.top\n";
    cout<<"4.size\n";
    cout<<"0.exit\n";
    while (choice != 0) {
        cin>>choice;
        switch (choice) {
            case 1:
            {
                push(&S);
                break;
            }
            case 2:
            {
                if(isEmpty(&S))
                    cout<<"stack is empty\n";
                else pop(&S);
                break;
            }
            case 3:
            {
                if(isEmpty(&S))
                    cout<<"stack is empty\n";
                else cout<<Top(&S)<<endl;
                break;
            }
            case 4:
            {
                if(isEmpty(&S))
                    cout<<"stack is empty\n";
                else cout<<Size(&S)<<endl;
                break;
            }            
        }
    }
    cout<<"bye\n";
     //
    return 0;
}
