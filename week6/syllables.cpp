#include<iostream>
#include <stack>
using namespace std;

int main(){
    int n,count = 0 ;
    string k;
    cin>>n;
    stack<char> ans;

    for (int i = 0 ; i < n ; i++){
        cin>>k;

        for(int j = 0 ; j < k.length() ; j++){
            ans.push(k[j]);
        }

        while(!ans.empty()){
            if (ans.top() == 'a' || ans.top() =='e' || ans.top() =='i' || ans.top() == 'o' || ans.top() =='u' ){
                ans.pop();
                while(!ans.empty() && (ans.top() == 'a' || ans.top() =='e' || ans.top() =='i' || ans.top() =='o' || ans.top() =='u')){
                    ans.pop();
                }
                count+=1;
            }
            else{
                ans.pop();
            } 
        }
        cout<<count<<endl; 
        count = 0;
    } 
}