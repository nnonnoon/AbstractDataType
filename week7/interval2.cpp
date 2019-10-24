#include<iostream>
#include<algorithm>
using namespace std;

struct interval{
    int start;
    int end;
}a[100001];

bool compare(struct interval a, struct interval b){
    return a.end < b.end;
}

int main(){
    int  n ;
    int nub=0;
    cin>>n;

    for(int i = 0 ; i<n ; i++){
       cin>>a[i].start;
       cin>>a[i].end;
    }
    sort(a, a + n, compare);
    
    int tod ;
    for(int i = 0 ; i<n;i++){
        if (i == 0 ){
            tod = a[i].end;
            nub++;
        }
        else if (a[i].start>=tod){
            nub++;
            tod = a[i].end;
        }
    }
    
    cout<<nub<<endl;
    // for(int i = 0 ; i<n ;i++){
    //    cout<<a[i].start; 
    //    cout<<a[i].end; 
    // }
}