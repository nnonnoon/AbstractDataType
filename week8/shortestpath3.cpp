#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
class compare{
    public: 
    bool operator () (pair<int, int> i, pair<int, int> ii){
        return i.first > ii.first;
    }
};

int n,m;
int val_node[100010];
bool visit[100001] = {false};

priority_queue < pair < int , int >, vector< pair < int , int > >, compare > q;
vector < pair <int , int > > adj[100010];


void shortest_path(){
    q.push(make_pair(0,0));
    while(!q.empty()){
        int front  = q.top().second;
        q.pop();

        if(!visit[front]){
            visit[front] = true;
            for(int i = 0 ; i<adj[front].size(); i++ ){
                if(!visit[adj[front][i].second]){
                    if(val_node[front] + adj[front][i].first < val_node[adj[front][i].second] ){
                        val_node[adj[front][i].second] = val_node[front] + adj[front][i].first;
                    }
                    q.push(make_pair(val_node[adj[front][i].second] , adj[front][i].second));
                }
            }
        }
    }
}


int main(){
    int u , v ,w;
    cin>>n>>m;
    for(int i = 0 ; i<n ; i++){
        if(i == 0 ){
            val_node[i] = 0;
        }
        else {
            val_node[i] =100010 ;
        }
    }

    for(int i = 0 ; i<m ; i++){
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }
    shortest_path();
    cout<<val_node[n-1]<<endl;
}