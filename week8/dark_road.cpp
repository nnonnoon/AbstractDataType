#include<iostream>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;
typedef pair< int , int > set;
class compare{
    public: 
    bool operator () (set a, set b){
        return a.first > b.first;
    }
};

vector< pair <int , int > >  adj[200100];
priority_queue < pair < int , int >, vector< pair < int , int > >, compare > q;
bool visited[200100] = {false};
int sum ;

void  mst_prim(){
    q.push(make_pair(0,0));
    sum = 0;
    memset(visited,false,sizeof(visited));
    while(!q.empty()){
        int front = q.top().first;
        int end = q.top().second;
        q.pop();
        if(!visited[end]){
            visited[end] = true;
            sum+=front;
            for(int i  = 0 ; i < adj[end].size() ; i++){
                if(!visited[adj[end][i].second]){
                    q.push(make_pair(adj[end][i].first,adj[end][i].second));   
                }
            }
        }
    }
}


int main(){
    int n , m ;
    int a,b,w;
    int cost;
    while (cin>>n>>m){
        if(n == 0 && m==0){
            break;
        }
        cost = 0;
        for(int i=0;i<200100;i++){
			adj[i].clear();
		}
        for(int i = 0 ;i<m ;i++){
            cin>>a>>b>>w;
            adj[a].push_back(make_pair(w,b));
            adj[b].push_back(make_pair(w,a));
            cost+=w;
        }
        mst_prim();
        cout<<cost-sum<<endl;
    }
}