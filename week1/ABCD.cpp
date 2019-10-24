#include<iostream>
using namespace std;

int main(){
    int x,y,z,l,sum;
    cin>>x>>y>>z>>l;

    if (0<=x && x<=1000){
           sum+= x ;
    }
    if (0<=y && y<=1000){
        sum+=y;
    }
    if(0<=z && z<=1000){
        sum+=z;
    }

    if (0<=l && l<=1000){
        sum+=l;
    }

    cout<<sum;

}


