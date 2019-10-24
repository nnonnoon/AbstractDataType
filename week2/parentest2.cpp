#include<iostream>
#include <stack> 
using namespace std;

int main(){
    int n ,count=0;
    cin >> n ;
    stack<char> my[n];
    string b[n];
    for (int i =0 ; i < n ; i++){
            cin >> b[i];
    }
    
    for(int i =0 ; i < n ; i++){
          for (int j = 0 ; j<b[i].length() ; j++){
             if (b[i][j] == '('){
                my[i].push(b[i][j]);
            }
            else if (b[i][j] == '['){
                my[i].push(b[i][j]);
            }
            else if (b[i][j] == '{'){
                my[i].push(b[i][j]);
            }
            else {
                if (!my[i].empty()){
                    if (b[i][j] == ')'){
                        if (my[i].top() == '('){
                            my[i].pop();
                        }
                        else{
                            break;
                        }
                    }
                    else if (b[i][j] == ']'){
                        if (my[i].top() == '['){
                            my[i].pop();
                        }
                        else{
                            break;
                        }
                    }
                    else if (b[i][j] == '}'){
                        if (my[i].top() == '{'){
                            my[i].pop();
                        }
                    else{
                        break;
                        }   
                    }
                }
                else {
                    count+=1;
                } 
            }
        }
        if (my[i].empty() && count == 0){
            cout<< "yes"<<endl; 
        }
        else {
            cout<< "no"<<endl; 
        }
    }
}