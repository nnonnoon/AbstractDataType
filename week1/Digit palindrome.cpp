#include <iostream>
using namespace std;
int main()
{
    int n ,num,digit, count = 0;
    cin >> num;
    n=num;

    do{
        int digit = num%10;
        count = (count * 10 ) + digit ;
        num/=10;
    } while (num!=0);
        if (n==count){
            cout<<"yes\n";
        }
        else {
            cout<<"no\n";
        }
    return 0 ;
}