#include<iostream>
#include<stuck>
using namespace std;

int main (){
    string a,b,tod_a,tod_b,result;
    stuck<int>sum;
    int max;
    cin>>a;
    cin>>b;
    int a_length = a.length()-1;
    int b_length = b.length()-1;
    if(a.length() >= b.length()){
        max = a.length();
    } 
    else{
        max  = b.length();
    }

    for (int i = max  ; i >=0  ; i-- ){
        if (i < max ){

        }
        else{
            tod_a = (int)a[i]-48;
            tod_b = (int)b[i]-48;
            result=tod_a+tod_b+carry;
            sum.push(result/10);
            carry+=result%10;
        }
    }
    while (!sum.empty())
    {
        cout << sum.top();
        sum.pop();
    }
}
