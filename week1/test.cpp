#include<iostream>
#include <algorithm> 
#include <vector> 
using namespace std;

bool comp(int a, int b) { 
        return (a < b); 
    } 

int main(){
    int n ;
    int box[n];

    for (int i = 0 ; i<n ; i++ ){
        cin>>box[i];
    }
    for (int i =0 ; i<n ; i++){
        cout<<min(box[i],comp) << "\n"; 
    }
}