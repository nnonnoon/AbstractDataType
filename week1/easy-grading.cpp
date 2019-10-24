#include <iostream>
using namespace std;

int main(){
    int x ;
    cin>>x;

    if (x>=80){
        cout<< "Excellent job.";
    }

    else if(x<80 && x>=50){
         cout<< "Okay.";
    }
    else {
        cout<< "Please try harder.";
    }
}