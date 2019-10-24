#include<iostream>
using namespace std;

int main(){
    int n ;
    cin >> n;

    int day[n];
    int keep ;
    int sum = 0 ;
    for(int i = 1 ; i<=n ; i++){
        cin>>day[i];
    }
    for(int j = 1 ; j<=n-1;j++){
        keep = 0;
        if(day[j] - day[j+1] > 10){
            keep = (day[j] - day[j+1] )*10;
            if(keep > 700){
                keep = 700;
            }
        }
        sum+=keep;
    }
    cout<<sum<<endl;
}