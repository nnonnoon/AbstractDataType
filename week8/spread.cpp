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

vector< pair < int, int  > > adj[100001];
vector<pair<int , int > > new_adj[100001];
int unit[100001];
priority_queue < pair < int , int >, vector< pair < int , int > >, compare > q;
bool visited[100001] = {false};
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
            new_adj[i].push_back(make_pair(rate,j));
            new_adj[j].push_back(make_pair(rate,i));
        }
    }
    
    int sum = 0;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int front = q.top().first;
        int end = q.top().second;
        q.pop();
        if(!visited[end]){
            visited[end] = true;
            if(front>sum){
                sum=front;
            }
            for(int i  = 0 ; i < new_adj[end].size() ; i++){
                if(!visited[new_adj[end][i].second]){
                    q.push(make_pair(new_adj[end][i].first,new_adj[end][i].second));
                }  
            }
        }
    }
    cout<<sum<<endl;
}
