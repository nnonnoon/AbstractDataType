#include<iostream>
using namespace std;

int main(){
    int find,year;
    char walk [3000];
    int count = 0;
    cin>>find;
    
    cin>>year;
    while(year != 0){
        count+=1;
        cin>>year;
    }

    if(count%2 == 0){
        for(int i = 0 ; i < 442 ; i++ ){
            if(i%2 == 0){
                walk[i] = 'K';
            }
            else{
                walk[i] = 'C';
            }
        }
    }
    else if(count%2 != 0){
        for(int i = 0 ; i < 442 ; i++ ){
            if(i%2 == 0){
                walk[i] = 'C';
            }
            else{
                walk[i] = 'K';
            }
        }
    }

    cout<<walk[find - 2558]<<endl;
    
}