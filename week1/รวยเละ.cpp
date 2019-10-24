#include<iostream>
using namespace std;

int main(){
    int n,sum=0 ;
    cin>>n;
    int box[n];
    if (1<=n && n<=1000){
        for (int i  = 0 ; i<n ; i++ ){
        cin>>box[i];
        }

    }

    for (int i  = 0 ; i<n ; i++ ){
        if (-1000<=box[i] && box[i]<=1000 ){
            if (box[i]>0){
            sum+=box[i];
            }
            else {
            sum+=0;
            }
        }  
    }
    cout<<sum;
}