#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ;
    cin >> n;
    int m;
    int tod = 4*n;

    vector<int> myvector;

    int cut [4];

    for(int i = 0 ; i<tod ; i++){
        cin>>m;
        myvector.push_back(m);
    }

    int count = 0;
    int range = 0;
    int max = 0;
    int keep = 0  ;
    for(int i = 1 ; i<=4 ; i++){
        int nub = n*i;
        for(int j = range  ; j< nub ; j++){
            if(myvector[range] > max ){
                max  = myvector[range];
            }
            count +=1;
        }
        cut[keep] = max;
        keep+=1;
        range = count;
        max = 0;
    }
        
        
    for(int i = 0 ; i<tod ; i++){
        cout<<cut[i]<<endl;
    }
}