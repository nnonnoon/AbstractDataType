#include<iostream>
#include <math.h> 
#include <vector> 
using namespace std;

int main(){
    int a,b;
    int count = 0;
    int count2 = 0;
    vector<int> keep;
    cin>>a>>b;

    for(int i = a  ; i<=b ; i++){
        bool tod = true;
        for(int j = 2 ; j <= sqrt(i)  ; j++){
            if(i%j == 0){
                tod = false;
                break;
            }
        }
        if(tod){
            keep.push_back(i);
            count+=1;
        }
    }

    for(int i = 0 ; i<count ; i++){
        if(abs(keep[i]-keep[i+1])==2){
            count2+=1;
        }
    }
    cout<<count2<<endl;
}