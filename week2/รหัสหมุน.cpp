#include<iostream>
using namespace std;

int main (){
    string a;
    cin>>a;

    for (int i = 0 ; i< a.length() ; i++){
        if ((int)a[i] >= 97  && (int)a[i] <= 118 ){
            a[i]=(int)a[i]+4;
        }
        else if (a[i]== 'w'){
            a[i]='a';
        }
        else if (a[i]== 'x'){
            a[i]='b';
        }
        else if (a[i]== 'y'){
            a[i]= 'c';
        }
        else if (a[i]== 'z'){
            a[i]= 'd';
        }
    }
    cout << a<<endl;
}