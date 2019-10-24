#include<iostream>
#include<stdio.h>
using namespace std;

int main (){
    int n ;
    int sum,num;

    cin>>n;
    cin>>num;
    sum=num;
    char oper;
    

    for (int i =0  ;i<n-1;i++){
        cin>>oper;
        cin>>num;

        if (oper == '+'){
            sum+=num;
        }
        else if (oper == '-'){
             sum-=num;
        }
    }
    cout<<sum;

}