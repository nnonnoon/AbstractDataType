#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m ;
    vector<int> myvector;
    while(scanf("%d" ,&n)){
        myvector.clear();
        if(n == 0){
            break;
        }
        for(int i = 0 ; i<n ;i++){
            scanf("%d" ,&m);
            myvector.push_back(m);
        }
        sort(myvector.begin() , myvector.end());
        for(int i = 0 ; i<n ;i++){
           printf("%d",myvector[i]);
           if(i<n-1){
               printf(" ");
           }
        }
        printf("\n");
    }
}

