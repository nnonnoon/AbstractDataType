#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent [1001];


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




int main(){
    int n , m ;
    int a,b,w;
    vector< pair < int , pair < int,int > > > edges;
    cin>>n>>m;
    
    for(int i = 0 ; i<n ; i++){
        parent[i]=i;
    }

    for(int i = 0 ; i < m ; i++){
        cin>>a>>b>>w;
        edges.push_back(make_pair( w,make_pair(a,b) ) );
    }

    sort(edges.begin(),edges.end());

    int mst_weight = 0 ;
    int mst_edges = 0;
    int mst_ni = 0;

    while (( mst_edges<n-1 ) || (mst_ni < m)){
        a = edges[mst_ni].second.first;
        b = edges[mst_ni].second.second;
        w = edges[mst_ni].first;

        if (find(a) != find(b)){
            combine(a,b);
            mst_weight+=w;
            mst_edges++;
        }
        mst_ni++;
    }

    cout<<mst_weight<<endl;
}