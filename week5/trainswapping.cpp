#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i = 0 ;
    while(i<n){
        vector<int> myvector;
        int l;
        int nub = 0;
        cin>>l;
        int weight;
        for(int i = 0 ; i<l ;i++){
            cin>>weight;
            myvector.push_back(weight);
        }
        for(int i = 0 ; i<l-1 ;i++){
            for(int j = 0 ; j<myvector.size()-1 ;j++){
                if(myvector[j] > myvector[j+1]){
                    swap(myvector[j],myvector[j+1]);
                    nub++;
                }
            }
        }
        

        // for(int i = 0 ;i<myvector.size();i++){
        //     cout<<myvector[i]<<" ";
        // }

        cout<<"Optimal train swapping takes " << nub << " swaps."<<endl;

        for(int i = 0 ; i<myvector.size() ;i++){
            myvector.erase(myvector.begin());
        }
        i++;
    }
}