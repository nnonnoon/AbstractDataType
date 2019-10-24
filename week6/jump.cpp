#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n , q;
    int tod,count=0;
    cin>>n>>q;
    vector<int> mai;
    vector<int> keep;
    vector<int> ask;
    vector<int>::iterator ip;  

    for(int i = 0 ; i<n ; i++){
        cin>>tod;
        mai.push_back(tod);
    }

    for(int i = 0 ; i<n ; i++){
        int yao = mai[i];
        keep.push_back(yao);
        count+=1;
        for(int j = i+1 ; j < n ;j++){
            yao += mai[j];
            keep.push_back(yao);
            count+=1;
        }
    }

    sort(keep.begin(),keep.end());
    ip=unique(keep.begin(),keep.end());
    keep.resize(distance(keep.begin(), ip)); 

    // for (ip = keep.begin(); ip != keep.end(); ip++) { 
    //     cout << *ip << " "<<endl; 
    // } 

    for(int i = 0 ; i<q ; i++){
        cin>>tod;
        ask.push_back(tod);
    }

    for(int i = 0 ; i<q ;i++){
        int check = false;
        for( ip = keep.begin()  ; ip != keep.end() ; ip++ ){
            if(ask[i] == *ip){
                check =  true;
                break;
            }
        }
        if(check){
            cout<<"Y";
        }
        else{
            cout<<"N";
        }
    } 
    cout<<endl;
}