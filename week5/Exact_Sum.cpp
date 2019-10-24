#include<iostream>
#include<vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;


int main(){
    int n;
    int tod;
    int peter_money;
    vector<int> check;

    while(scanf("%d", &n) != EOF){
        int book_a , book_b;
        int min = 1000010;
        check.clear();
        for(int i = 0 ; i<n ; i++){
            cin>>tod;
            check.push_back(tod);
        }
        sort(check.begin() , check.end());

        cin>>peter_money;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i+1 ; j< n ;  j++){
                if(abs(check[i]-check[j]) < min && check[i] + check[j] == peter_money ){
                    min = abs(check[i]-check[j]);
                    book_a = check[i];
                    book_b = check[j];
                }
            }
        }
        cout<<"Peter should buy books whose prices are "<<book_a<<" and "<<book_b<<"."<<endl<<endl;
    }
    return 0 ;
}