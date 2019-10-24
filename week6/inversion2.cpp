#include<iostream>
#include<vector>
using namespace std;

long long nub=0;
vector<int> merge(vector<int> left , vector<int> right){
    vector<int> result ;
    while(left.size() > 0 || right.size() > 0){
        if(left.size() > 0 && right.size() > 0){
            if(left.front() <= right.front()){
                result.push_back(left.front());
                left.erase(left.begin());
            }
            else if(right.front() <= left.front()){
                result.push_back(right.front());
                right.erase(right.begin());
                nub+=left.size();
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


vector<int> mergesort(vector<int> val){
    if(val.size() <= 1){
        return val;
    }
   
    vector<int> left,right,result ; 
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
    int n , m;
    scanf("%d" ,&n);
    vector<int> myvector;


    for(int i = 0 ; i<n ; i++){
        scanf("%d" ,&m);
        myvector.push_back(m);
    }

    myvector = mergesort(myvector); 
    printf("%lli\n",nub);

}