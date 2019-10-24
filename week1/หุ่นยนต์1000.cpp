#include<iostream>
using namespace std;

int main(){
    string n;
    cin>>n;
    int x=0 , y=0;
    for (int i = 0 ;i<100 ; i++ ){
        if (n[i]=='N'){
            y+=1;
        }
        else if (n[i]=='E'){
            x+=1;
        }
        else if (n[i]=='W'){
            x-=1;
        }
        else if (n[i]=='S'){
            y-=1;
        }
        else if (n[i]=='Z'){
            x=0;
            y=0;
        }
    }
    cout<<x<<" "<<y;
}