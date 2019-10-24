#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int tod ;
    int swap ;
    int nub = 0;
    int box[1000] = {0};
    vector<int> myvector;
    while(cin>>n){
        nub=0;
        if(n == 0){
            break;
        }
        else{
            for(int i = 1 ; i<= n ; i++){
                myvector.push_back(i);
                nub++;
            }
            //cout<<myvector.size()<<endl;
            if(nub == 1){
                cout<<"Discarded cards:";
                cout<<endl;
                cout<<"Remaining card: 1";
                cout<<endl;
                myvector.erase(myvector.begin());
            }
            else if (nub>1){
                for(int j = 1 ; j<= n ; j++){
                    tod = myvector.front();
                    myvector.erase(myvector.begin());
                    if(!myvector.empty()){
                        swap = myvector.front();
                        myvector.erase(myvector.begin());
                        myvector.push_back(swap);
                    }
                    box[j] = tod;
                } 
                for(int i = 1 ; i <n; i++){
                    if(i == 1){
                        cout<<"Discarded cards: "<<box[i];
                    }
                    else{
                        cout<<", "<<box[i];
                    }
                }
                cout<<endl;
                cout<<"Remaining card: "<<box[n];
                cout<<endl;
            }  
        }
    }
}