#include <iostream>
#include <algorithm>

using namespace std;

unsigned int gcd (unsigned int n1, unsigned int n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

int main(){
    int  n,l;
    cin>>n>>l;
    cout <<n/gcd(n,l)<<"/"<<l/gcd(n,l);
}