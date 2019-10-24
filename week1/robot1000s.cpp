#include<iostream>
#include<cmath>
using namespace std;
int  x=0,y=0;
int N=0,E=0,W=0,S=0;


void tid  (string a){
    int box[a];
    for (int i = 0 ; i<a.length() ; i++ ){
        if (box[a]=='N'){
            N+=1;
            y+=1;
        }
        else if (box[a]=='E'){
            E+=1;
            x+=1;
        }
        else if (box[a]=='W'){
            W+=1;
            x-=1;
        }
        else if (box[a]=='S'){
            S+=1;
            y-=1;
        }
    }
}


int main(){
    string n ;
    cin>>n;

    int number;
    cin>>number;

    tid (n);

    for (int i =0 ; i<number ; i++){
        if (x>= 0 && y>0){
            if (W>0){
                W-=1;
            }
            else if(S>0){
                S-=1;
            }
            else if(N>0){
                N-=1;
            }
            else if(E>0){
                E-=1;
            }
        }
        else if (x<=0 && y>0){
            if (E>0){
                E-=1;
            }
            else if(S>0){
                S-=1;
            }
            else if(N>0){
                N-=1;
            }
            else if(W>0){
                W-=1;
            }
        }   
        else if (x<=0 && y<0){
            if (N>0){
                N-=1;
            }
            else if(E>0){
                E-=1;
            }
            else if(S>0){
                S-=1;
            }
            else if(E>0){
                E-=1;
            }
        }
        else if (x>=0 && y<0){
            if (W>0){
                W-=1;
            }
            else if(N>0){
                N-=1;
            }
            else if(S>0){
                S-=1;
            }
            else if(E>0){
                E-=1;
            }
        }
        else if (x==0 && y==0){
            N=0;
            W=0;
            S=0;
            E=0;
        }

    }
    total=abs(N+S)+abs(E+W);
    cout<<total;
}
