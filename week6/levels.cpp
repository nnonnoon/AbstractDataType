#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    int val;
    int a,b,c;
    int x,y,z;
    cin>>n>>m;

    vector < pair <int , bool > > myvector[1010];
    for(int i = 0 ; i < n-1 ; i++){
        cin >> a >> b >> c;
        myvector[i].push_back(make_pair(a,false));
        myvector[i].push_back(make_pair(b,false));
        myvector[i].push_back(make_pair(c,false));
    }

    int cur_level = 0;
    for(int i = 0 ; i <m ; i++){
        if(cur_level<n-1){
            cin >> x >> y >> z;
            if(x>=myvector[cur_level][0].first){
                myvector[cur_level][0].second = true;
            }
            if(y>=myvector[cur_level][1].first){
                myvector[cur_level][1].second = true;
            }
            if(z>=myvector[cur_level][2].first){
                myvector[cur_level][2].second = true;
            }
            if (myvector[cur_level][0].second == true &&  myvector[cur_level][1].second == true && myvector[cur_level][2].second == true){
                cur_level++;
            }
        }
    }
    cout<<cur_level+1<<endl; 
}

