#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

class compare{
    public: 
    bool operator () (pair<int, int> i, pair<int, int> ii){
        return i.first > ii.first;
    }
};

int val_node[100010];
bool visit[100010] = {false};

priority_queue < pair < int , int >, vector< pair < int , int > >, compare > q;
vector < pair <int , int > > adj[100010];


int n;
void dijkstra(int s) {
    q.push(make_pair(0,s));
    memset(visit,false,sizeof(visit));
    val_node[s] = 0;
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

int main() {
    int test, m, u, v, w, s, t, kase = 0;
    scanf("%d", &test);
    while(test--) {

        cin>>n>>m>>s>>t;
        for(int i = 0; i < n; i++) 
            adj[i].clear();

        for(int i = 0 ; i<n ; i++){
            val_node[i] =100010 ;
        }   

        for(int i = 0; i < m; i++) {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(w, v));
            adj[v].push_back(make_pair(w, u)); 
        }

        dijkstra(s);
        if(val_node[t] == 100010) 
            printf("Case #%d: unreachable\n", ++kase);
        else 
            printf("Case #%d: %d\n", ++kase, val_node[t]);
    }
    return 0;
}