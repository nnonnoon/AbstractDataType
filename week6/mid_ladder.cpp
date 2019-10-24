#include<iostream>

using namespace std;

int main(){
    int n,m ; 
    int count = 0;
    cin>>n>>m;
    int map[n];
    int fun[m];

    for(int i = 0 ; i<n ; i++ ){
        cin>>map[i];
    }

    for(int i = 0 ; i < m ; i++){
        cin>>fun[i];
    }

    for(int i = 0 ; i<m ;i++){
        if(count+fun[i]>=n){
            count = n;
            break;
        }
        if(count<0){
            continue;
        }
        if(map[count+fun[i]-1] == 0){
            count+=fun[i];
        }
        else if(map[count+fun[i]-1] != 0 && count+fun[i]-1<n){
            //cout<<count<<"|";
            count+=map[count+fun[i]-1]+fun[i];
            if(count<=0){
                count=0;
            }
            //cout<<count<<"|";
        }
    }
    if(count<=0){
        count = 0;
    }
    cout << count<<endl;
}