#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int parent [100001];


int find(int x){
    if(parent[x] == x){
        return x;
    }
    else 
        return find(parent[x]);
}

void combine (int x , int y){
    int a = find(x);
    int b = find(y);
    parent[a] = b;
}


vector< pair < int, int  > > adj[100001];
vector< pair< int , pair < int , int > > > new_adj;
int unit[100001];

int n , m ;
int a,b,w;

int main(){
    cin>>n>>m;

    for(int i = 0 ; i<n ; i++){
        cin >> unit[i];
    }

    for(int j = 0 ; j<m ; j++){
        cin>>a>>b>>w;
        a--;
        b--;
        adj[a].push_back(make_pair(w,b));
        adj[b].push_back(make_pair(w,a));
    }
    
    int rate ;
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j < adj[i].size() ; j++){
            int weight = adj[i][j].first;
            int b = adj[i][j].second;
            if(weight%(unit[i]+unit[b])!= 0){
                rate = (weight/(unit[i]+unit[b]))+1;
            }
            else{
                rate = (weight/(unit[i]+unit[b]));
            }
            //cout<<i+1<<" " <<adj[i][j].second+1 <<" "<<weight<<" "<< rate<<endl;
            new_adj.push_back(make_pair(rate,make_pair(i,j)));
        }
    }

    for(int i = 0 ; i<n ; i++){
        parent[i]=i;
    }
    
    sort(new_adj.begin(),new_adj.end());

    int mst_weight = 0 ;
    int mst_edges = 0;
    int mst_ni = 0;

    int x,y,z;
    int sum = 0;

    while (( mst_edges<n-1 ) || (mst_ni < m)){
        x = new_adj[mst_ni].second.first;
        y = new_adj[mst_ni].second.second;
        z = new_adj[mst_ni].first;

        if (find(x) != find(y)){
            combine(x,y);
            if(z>sum){
                sum=z;
            }
            mst_edges++;
        }
        mst_ni++;
    
    }
    cout<<sum<<endl;
    
}
