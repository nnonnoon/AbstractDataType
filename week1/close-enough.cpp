#include <iostream>
#include <stdlib.h>
using namespace std;


int main (){
    int n,l,dis,x;
    cin>>n>>l;

    int box[n];
    for (int i=0;i<n;i++){
        cin>>box[i];
    }

    for (int a = 0 ; a<n ;a++){
        for (int b = a ; b<n;b++){
            if (a!=b){
                dis = abs(box[a] - box[b]);
                if (dis<=l){
                     x=x+1;
                }
            }
        }
    }
    cout<<x;
}
