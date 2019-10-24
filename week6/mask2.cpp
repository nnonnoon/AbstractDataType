#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ; 
    cin >> n ;
    int m ;

    vector<int> myvector;
    vector<int> :: iterator index;

    for(int i = 0 ;i<=4*n ; i++){
        cin >> m;
        myvector.push_back(m);
    }

    for(int i = 0 ;i<=4*n ; i++){
        if(){

        }
    }


    for(int i = 0 ; i<=4*n ; i++){
        cout << myvector[i] << endl;
    }
}