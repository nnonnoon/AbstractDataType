#include<iostream>
using namespace std;

int main(){
    string n;
    int a,b=-1;
    cin>>n;
    n += "_"; 
    a=n.length();
    for (int i = 0 ; i<a; i++){
        if (n[i] == '_'){
            for (int j = i; j>b ; j--){
                if(n[j] == '_' && b == -1) 
                    continue;
                else
                    cout << n[j];
            }
            b=i;
        }
    }
}