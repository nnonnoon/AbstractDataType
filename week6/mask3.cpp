#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n ;
    cin>>n;

    int val[1500] = {0};

    for(int i = 1 ; i<=4*n ; i++){
        cin>>val[i] ;
    }
    // val[0] =-1;
    int max_index[1500] = {0};
    int rounds = 1;
    for(int i = 1 ; i<=4*n ; i++){
        if(val[i] >  val[max_index[rounds]]){
            max_index[rounds] = i;
        }
        if(i == n || i == n*2 || i == n*3){
            rounds++;
        }
    }

    vector< pair<int , int > >  ans;

    for(int i = 1 ; i <5 ; i++){
        ans.push_back(make_pair(val[max_index[i]],max_index[i]));
    }
    int number1 = 0, i1;
    int number2 = 0, i2;
    int number3 = 0;
    int number4 = 0;
    if(ans[0].first > ans[1].first){
        number3 = ans[1].second;
        number1 = ans[0].first;
        i1=ans[0].second;
    }
    else if (ans[1].first > ans[0].first){
         number3 = ans[0].second;
         number1 = ans[1].first;
         i1=ans[1].second;
    }

    if(ans[2].first > ans[3].first){
        number4 = ans[3].second;
        number2 = ans[2].first;
        i2=ans[2].second;
    }
    else if (ans[3].first > ans[2].first){
        number4 = ans[2].second;
        number2 = ans[3].first;
        i2=ans[3].second;
    }
    if(number1>number2) cout << i1<<' ' << i2<<' ';
    else cout << i2<<' ' <<i1<<' ';

    cout<<number3<<' ';
    cout<<number4<<' ';

}