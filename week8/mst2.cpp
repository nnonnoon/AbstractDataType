#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair< int , int > set;
class compare{
    public: 
    bool operator () (set a, set b){
        return a.first > b.first;
    }
};

vector< pair <int , int > >  adj[100010];
priority_queue < pair < int , int >, vector< pair < int , int > >, compare > q;
bool visited[100001] = {false};
int sum = 0 ;

void mst_prim(){
    q.push(make_pair(0,0));
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
    cin>>n>>m;

    for(int i = 0 ;i<m ;i++){
        cin>>a>>b>>w;
        adj[a-1].push_back(make_pair(w,b-1));
        adj[b-1].push_back(make_pair(w,a-1));
    }
    mst_prim();
    cout<<sum<<endl;
}