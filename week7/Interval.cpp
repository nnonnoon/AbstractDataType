#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ;
    int p,j;
    cin>>n;
    
    vector<int> myvector[100001];
    vector<int>::iterator noon;
    for(int i = 0 ; i<n; i++){
        cin>>p>>j;
        myvector[p].push_back(j);
    }

    for(int i = 0 ; i<n ;i++){
        sort(myvector[i].begin() , myvector[i].end());
    }

    // for(int i = 0 ; i<n ; i++){
    //     int tod = myvector[i].begin();
    //     for(int j = 0 ; j<n ; j++){
    //         myvector[tod].begin();
    //     }
    // }
    

    for(int i = 0 ; i<n ; i++){
        for(noon = myvector[i].begin() ; noon<myvector[i].end() ; noon++){
        cout<< *noon << endl;
        }
    }
    
}