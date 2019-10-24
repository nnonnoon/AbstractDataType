#include<iostream>
#include<stack>
using namespace std;

int main(){
    int change[1001];
    stack<int> mystack;
    int n;

    while(cin>>n){
        if(n == 0){
            break;
        }
        while(cin >> change[0]){
            if(change[0] == 0){
                break;
            }
            for(int i = 1 ; i<n ; i++){
                cin>>change[i];
            }
            while(!mystack.empty()){
                mystack.pop();
            }
            
            int nub = 1;
            bool yn = true ;

            for(int i = 0 ; i<n ; i++){
                if(nub == change[i]){
                    nub++;
                    continue;
                }
                else if (change[i] < nub){
                    if(!mystack.empty() && mystack.top() == change[i] )  {
                        mystack.pop();
                        continue;
                    }
                    yn = false;
                    break;
                }
                else if (change[i] > nub){
                    while(change[i] != nub){
                        mystack.push(nub);
                        nub++;
                    }
                    nub++;
                    continue;
                }
            }
            if (yn){
                cout << "Yes" << endl;
            } 
            else {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
}

