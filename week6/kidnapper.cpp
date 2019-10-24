#include<iostream>
#include <math.h>  
using namespace std;

int main(){
    int n , a , b ,r ,x,y;
    int count = 0 , tod;
    cin>>n>>a>>b>>r;

    for(int i = 1 ; i<=n ; i++){
        cin>>x>>y;
        tod = pow(x-a,2)+pow(y-b,2);
        if( tod <= pow(r,2)){
            count+=1;
        }
    }
    cout << count<<endl;
}