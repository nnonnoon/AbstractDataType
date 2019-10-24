#include<iostream>
using namespace std;

int main(){ 
    string n,sum;
    int tid=1;
    cin>>n;
    for (int i = 0 ; i<n.length() ; i++ ){

        if (tid == 1 ){
            if (n[i]=='N'){
                sum+='F';
                tid=1;
                continue;
            }
            else if (n[i]=='E'){
                sum+="RF";
                tid=2;
                continue;
            }
            else if (n[i]=='S'){
                sum+="RRF";
                tid=3;
                continue;
            }
            else if (n[i]=='W'){
                sum+="RRRF";
                tid=4;
                continue;
            }
            else if (n[i]=='Z'){
                sum+='Z';
                tid=1;
                continue;
            }
        }

        if (tid == 2 ){
            if (n[i]=='N'){
                sum+="RRRF";
                tid=1;
                continue;
            }
            else if (n[i]=='E'){
                sum+='F';
                tid=2;
                continue;
            }
            else if (n[i]=='S'){
                sum+="RF";
                tid=3;
                continue;
            }
            else if (n[i]=='W'){
                sum+="RRF";
                tid=4;
                continue;
            }
            else if (n[i]=='Z'){
                sum+="Z";
                tid=1;
                continue;
            }
         }

        if (tid == 3 ){
            if (n[i]=='N'){
                sum+="RRF";
                tid=1;
                continue;
            }
            else if (n[i]=='E'){
                sum+="RRRF";
                tid=2;
                continue;
                
            }
            else if (n[i]=='S'){
                sum+='F';
                tid=3;
                continue;
                
            }
            else if (n[i]=='W'){
                sum+="RF";
                tid=4;
                continue;
                
            }
            else if (n[i]=='Z'){
                sum+='Z';
                tid=1;
                continue;
                
            }
        }

        if (tid == 4 ){
            if (n[i]=='N'){
                sum+="RF";
                tid=1;
               continue;
            }
            else if (n[i]=='E'){
                sum+="RRF";
                tid=2;
                continue;
            }
            else if (n[i]=='S'){
                sum+="RRRF";
                tid=3;
                continue;
            }
            else if (n[i]=='W'){
                sum+='F';
                tid=4;
                continue;
            }
            else if (n[i]=='Z'){
                sum+='Z';
                tid=1;
                continue;
            }
        }
    }
    cout<<sum<<endl;
}