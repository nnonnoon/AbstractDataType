#include<iostream>
#include<vector>
#include<set>
#include<utility>
using namespace std;

vector <int> adj[100010];
vector <int> lenght[100010];
int n , m ;
int val_node[100010];
set< pair < int,int > > edge;
bool scand[100010];

const int inf = 1000000;


void shortest_path(){
    for(auto const&s : edge){
        int count = 0;
        int i = s.second;
        if(!scand[i]){
            for(auto const&p : adj[i]){
                int weight = val_node[i] + lenght[i][count];
                if(weight<val_node[p]){
                    val_node[p] = weight;
                    edge.erase(make_pair(val_node[p],p));
                    edge.insert(make_pair(weight,p));
                }
                scand[i] = true;
                count++;
            }
        }
    }
}



int main(){
    int u , v ,w;
    cin>>n>>m;

    for(int i = 1 ; i<=n ; i++){
        if(i == 1 ){
            val_node[i] = 0;
        }
        else {
            val_node[i] = inf;
        }
        edge.insert(make_pair(val_node[i],i));
    }

    for(int i = 0 ; i<m ; i++){
        cin>>u>>v>>w;
        adj[u].push_back(v);
        lenght[u].push_back(w);

        adj[v].push_back(u);
        lenght[v].push_back(w);
    }
    shortest_path();
    cout<<val_node[n]<<endl;
}