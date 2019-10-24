#include<iostream>
#include<vector>
using namespace std ;

int main(){
    string s,t;
    cin >> s;
    cin >> t;

    vector<char> myvector;

    for(int i = 0 ; i<t.length() ; i++){
        myvector.push_back(t[i]);
    }

    int i = 0;
    int tod = s.length();
    int nub = 0;
    int count = 0;

    while(!myvector.empty()){
        if(myvector.front() == s[i]){
            count++;
            i++;
        }
        if(i>=tod){
            i = 0;
        }
        if(count>=tod){
             nub+=1;
             count=0;
        }
        myvector.erase(myvector.begin());
    } 
    cout<<nub<<endl;   
    
}