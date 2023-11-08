#include<iostream>
using namespace std;

int recFibb(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return recFibb(n-1)+recFibb(n-2);
}

int NrecFibb(int n){
    int a=0;
    int b=1;
    int c=0;
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<"Recursive Implemtation of Fibbo : "<<recFibb(n)<<endl;
    cout<<"Non Recursive Implemetation of Fibbo: "<<NrecFibb(n)<<endl;
}
/*
Recursive fibbonacci:
Time Complexity: O(n*2n)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/