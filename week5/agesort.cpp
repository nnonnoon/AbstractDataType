#include<iostream>
#include<vector>
using namespace std;

vector<long> merge(vector<long> left , vector<long> right){
    vector<long> result ;
    while(left.size() > 0 || right.size() > 0){
        if(left.size() > 0 && right.size() > 0){
            if(left.front() <= right.front()){
                result.push_back(left.front());
                left.erase(left.begin());
            }
            else if(right.front() <= left.front()){
                result.push_back(right.front());
                right.erase(right.begin());
            }
        }
        else if (left.size() > 0){
            for(int i = 0 ; i < left.size() ; i++){
                result.push_back(left[i]);
            }
            break;
        }
        else if (right.size() > 0){
            for(int j = 0 ; j < right.size() ; j++){
                result.push_back(right[j]);
            }
            break;
        }
    }
    return result;
}


vector<long> mergesort(vector<long> val){
    if(val.size() <= 1){
        return val;
    }
   
    vector<long> left,right,result ; 
    int middle = (val.size()+1) /2;
    for(int i = 0 ; i<middle ; i++){
        left.push_back(val[i]);
    }

    for(int j = middle ; j<val.size() ;j++){
        right.push_back(val[j]);
    }

    left = mergesort(left);
    right = mergesort(right);
    result = merge(left,right);
    return result;
}

int main(){
    long n , m;
    while(scanf("%ld" ,&n)){
        if(n == 0){
            break;
        }
        vector<long> myvector;

        for(int i = 0 ; i<n ; i++){
            scanf("%ld" ,&m);
            myvector.push_back(m);
        }

        myvector = mergesort(myvector); 

        for(int i = 0 ; i<myvector.size() ; i++){
            printf("%ld ",myvector[i]);
        }
    }
}