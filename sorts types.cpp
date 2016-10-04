/* 
 * File:   main.cpp
 * Author: Дом
 *
 * Created on 30 августа 2015 г., 11:06
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
int array[1];
    //unstable

/*    //quick sort [O(n log n)]

void QSort(int array[],int first,int last){
    int i=first; //№first elem
    int j=last; //№last elem
    int key=array[i+(j-i)/2]; //comp kernel
    while(i<=j){
        while(array[i]<key)i++;
        while(array[j]>key)j--;
        if(i<=j){
            swap(array[i],array[j]);
            i++;
            j--;
        }
    };
    if(i<last)
        QSort(array,i,last);
    if(first<j)
        QSort(array,first,j);
    }
*/

int main(){
    //generating array of rand
    int n,lim,min;
    cout<<"enter size of array\n";
    cin>>n;
    int array[n];
    cout<<"enter lim\n";
    cin>>lim;
    srand(time(0));
    for(int i=0;i<n;i++){
        array[i]=rand() % lim;
        cout<<array[i]<<' ';
    }
    cout<<'\n';
    
    //stable [O(n^2)]
    
    /* //selection
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(array[j]<array[min]){
                min=j;
            }        
        }
        if(array[min]!=array[i])
            swap(array[min],array[i]);
    }
     */
    /* //insertion
    for(int i=1;i<n;i++){
        int temp=array[i];
        for(int j=i-1;j>=0;j--){
            if(array[j]<temp)
                break;
            array[j+1]=array[j];
            array[j]=temp;
        }
    }
    */
    /* //bubble    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(array[j]>array[j+1])
                swap(array[j],array[j+1]);
        }
    }
     */
    /* //unstable  
    //QSort
    QSort(array,0,n-1);
     */
    
    for(int i=0;i<n;i++)
        cout<<array[i]<<' ';
    cout<<'\n';
    return 0;
}

