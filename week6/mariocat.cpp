#include<iostream>
using namespace std;


int main(){
    int n,m,num_dan,sec;
    cin>>n>>m;
    int min[n];
    int lev[n];

    for(int i = 1 ; i<=n ; i++){
        min[i]=0;
    }

    for(int i = 0 ; i < m ;i++){
        cin>>num_dan>>sec;
        lev[num_dan] = sec;
        if(min[num_dan] == 0){
            min[num_dan] = lev[num_dan];
        }
        else if (lev[num_dan] < min[num_dan]){
            min[num_dan] = lev[num_dan];
        }
    }

    int sum = 0 ;
    for (int i  = 1 ; i <= n ; i++){
        sum+= min[i];
    }
    
    cout <<sum<<endl;
    for (int i = 1 ; i <= n ; i++){
        cout <<i<<" "<<min[i]<<endl;
    }
}