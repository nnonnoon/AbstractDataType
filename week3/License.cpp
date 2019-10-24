#include<iostream>
#include <math.h>
using namespace std;

int main (){
    string a;
    int  ans[100000];
    int n,keep_A=0,keep_N=0,count, sum =0 ;
    cin>>n;

    for (int i = 0 ; i< n ; i++){
        cin>>a;
        for(int j = 0  ; j < a.length() ; j++){
            if (65<=(int)a[j] && (int)a[j]<=90){
                count = (int)a[j] - 65 ;
                keep_A+=count*(pow(26,2-j));
            }  
            else if (a[j] == '-'){
                continue;
            }
            else if (48<=(int)a[j] && (int)a[j]<=57 ){
                if (j==4){
                    keep_N+= ((int)a[j] - 48)*1000;
                }
                else if (j==5){
                    keep_N+= ((int)a[j] - 48)*100;
                }
                else if (j==6){
                    keep_N+= ((int)a[j] - 48)*10;
                }
                else if (j==7){
                    keep_N+= ((int)a[j] - 48)*1;
                }
            }
        }
        sum = abs(keep_A-keep_N);
            if (sum<=100){
                ans[i]=1;
            }
            else{
                ans[i]=0;
            }
            keep_A=0;
            keep_N=0;
    }
    for (int i = 0 ; i < n ; i++  ){
        if (ans[i] == 1){
            cout<<"nice"<<endl;
        }
        else if (ans[i] == 0){
            cout<<"not nice"<<endl;
        }
    }
}