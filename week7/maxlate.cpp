#include<iostream>
#include<algorithm>
using namespace std;

struct maxlate{
    int start;
    int end;
}a[100001];

bool compare(struct maxlate a  ,struct maxlate b){
    return a.start < b.start;
}

int main(){
    int n ;
    cin>>n;

    for(int i = 0 ; i<n ;i++){
        cin>>a[i].start;
        cin>>a[i].end;
    }
    sort(a,a+n,compare);

    // for(int i = 0 ; i<n ;i++){
    //     cout << a[i].start <<" "<< a[i].end << endl;
    // }

    int keep = 0;
    int max_dateline = 0;
    int max_late = 0;
    int check = 0;
    for(int i = 0 ; i<n ; i++){
        keep += a[i].end;
        if(keep - a[i].start >= check){
            max_dateline = a[i].start;
            max_late = keep;
            check = keep - a[i].start;
        }
    }
    // cout<< max_late << " ";
    // cout<< max_dateline << " ";
    int sum = (max_late - max_dateline - 10)*1000;
    if(sum <= 0 ){
        sum = 0;
        cout<< sum  << endl;
    }
    else{
        cout<< sum  << endl;
    }
}