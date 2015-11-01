#include <operations.h>

//конструктор
Operations::Operations(string* x,string* y){
    Result.clear();
    long1=*x;
    long2=*y;
    cout<<"long1 ="<<long1<<"\n";
    cout<<"long2 ="<<long2<<"\n";
    if(long1.length()<long2.length()){
        long1.swap(long2);
        cout<<"long1 ="<<long1<<"\n";
        cout<<"long2 ="<<long2<<"\n";
}
}
void Operations::Addition(){
    int carry=0;
    for(int i=0;i<long1.length();i++){
        if(i>=long2.length())
            long2[i]='0';
        int temp=((long1[i]-'0')+(long2[i]-'0')+carry);
        if (temp>9)
            carry=1;
        else carry=0;
        Result.push_back(temp%10);
    }
}
void Operations::getResult(){
    for(int i=0;i<Result.size();i++)
        cout<<Result[i];
    cout<<"\n";
}
