#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n , countoper = 0 , countnum = 0;
    string a;
    cin>>n;
    scanf("%s",a);
    cout<<a.length();
    int sum = 0;

    if (1<=n && n<=1000){
        for (int i = 0 ; i < a.length() ; i++ ){
    
            cout<<(int)a[i]<<endl;
            if (a[i]=='+'){
                countoper+=1;
            }
            else if (a[i]=='-'){
                countoper+=1;
            }
            else if (a[i]==' '){

            }
            else if ((int)a[i] >= 48 && (int)a[i] <=57 ){
                    countnum+=1;

                }
            }
        }

    
    if (countoper == n-1 && countnum == n) {
        for (int i = 0 ; i < a.size() ; i++){
                if (a[i] =='+'){
                    sum+=a[i+2];
                }
                else if (a[i] =='-'){
                    sum-=a[i+2];
                }
        }

         cout<<sum;
    }     
}