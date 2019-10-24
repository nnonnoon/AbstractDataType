#include<iostream>
using namespace std;

int main(){
    string a,b;
    int n;
    cin>>a;
    n=a.length();
    for (int i = n-1 ; i>=0 ; i--){
       cout<<a[i];
    }
}