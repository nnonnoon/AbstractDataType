#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include <math.h>
using namespace std;


int  change (int x, int y){
    int r,sum=0;

    stack<int> ans;
    string bina   = "00000000000000000000000000000000";
    string binb   = "00000000000000000000000000000000";
    for (int pos = 31; pos >= 0; --pos)
    {
        if (x % 2) 
            bina[pos] = '1';
        x /= 2;
    }

    for (int pos = 31; pos >= 0; --pos)
    {
        if (y % 2) 
            binb[pos] = '1';
        y /= 2;
    }

    //cout<<bina<<endl;
    //cout<<binb<<endl;

    for (int i = 31 ; i >= 0  ; i--){
        r = (int)bina[i]-48 + (int)binb[i]-48;
        r=r%2;
        ans.push(r);
    }
    /*while (!ans.empty())
    {

        cout << ans.top();
        ans.pop();
    }*/
    
    for (int j = 31 ; j >= 0; j--){
        sum = sum + (ans.top()*(pow(2,j)));
        ans.pop();
    }
    return sum;
}

int main (){
    int a,b;

    while (cin >> a >> b ){
        cout <<  change(a,b) << '\n';
    }
}