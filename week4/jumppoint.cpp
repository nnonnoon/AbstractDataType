#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int main(){
    int n,r,a,b;
    cin>>n>>r;
    typedef pair<int, int> mypair;
    vector<mypair> adj;
    queue<int> q;
    bool visited [n];
    int walk[n+2];

    vector<int> graph[n+2];

    for(int i = 0 ; i<n+2 ;i++){
        if(i == 0){
            adj.push_back(make_pair(0,0));
        }
        else if (i == n+1){
            adj.push_back(make_pair(100,100));
        }
        else{
            cin>>a>>b;
            adj.push_back(make_pair(a,b));
        }
    }

    for(int i = 0 ; i<n+1 ; i++){
        for(int j = i+1 ; j<n+2 ;j++){
            if(pow(adj[i].first-adj[j].first,2) + pow(adj[i].second-adj[j].second,2) <= pow(r,2)){
                graph[i].push_back(j);
                graph[j].push_back(i);
                //cout<< i << j<<endl ;
            }
        }
    }

    for(int i = 0 ; i<n+2 ; i++){
        visited[i] = false;
        walk[i]  = 0;
    }

    q.push(0);
    int nub ;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(!visited[front]){
            visited[front] = true;
            for(int i = 0 ; i<graph[front].size(); i++){
                nub = graph[front][i];
                if(walk[nub] == 0){
                    walk[nub] = walk[front]+1;
                    if(nub == n+1){
                        cout<< walk[nub] << endl;
                        goto noon;
                    }
                }
                q.push(nub);       
            }  
        }
   }
   cout<< "-1" <<endl;
   noon:{}
}