#include <iostream>
using namespace std;

int main (){
    int n , count=1 , num=0;
    cin>>n;

    int box[n];
    for (int i = 0 ; i<n ; i++){
        cin >> box[i];
    }

    for (int j = 0 ; j<n-1 ; j++ ){
        num+=box[j];
        if (num>1000){
            count +=1 ; 
            num=0;
            j-=1;
        }
    }
    if (num+box[n-1]>1000){
        count+=1;
    }
    cout<<count;
}

