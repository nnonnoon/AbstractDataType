#include <iostream>
using namespace std;

int main() {
	int t,w,h,sum=0;
    cin>>t;

    for (int i = 0 ; i<t ; i++){
        cin>>w;
        cin>>h;
        sum=(w/3)*(h/3);
        cout<<sum<<endl;
    }

	
}