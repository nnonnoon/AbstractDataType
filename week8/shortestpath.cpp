#include<iostream>
#include<vector>
using namespace std;

vector <int> adj[100010];
vector <int> lenght[100010];
int n , m ;

int d[10010];
bool scanned[10010];

void shortest_path(int s){
    for(int u = 0 ; u<n ; u++){
        d[u] = 1000000;
        scanned[u] = false;
    }

    d[s] = 0 ;
    for(int i = 0 ; i<n ; i++){
        int bestu = -1;

        for (int u = 0 ; u < n ; u++){
            if(!scanned[u]){
                if(bestu == -1 || d[bestu] > d[u]){
                    bestu = u;
                }
            }
        }
        //cout<<bestu<<" bestu " << endl;

        int deg = adj[bestu].size();
        //cout<<deg<<" deg"<<endl;
        for(int i = 0 ; i<deg ; i++){
            int v = adj[bestu][i];
            int len = lenght[bestu][i];

            if(d[bestu] + len < d[v]){
                d[v] = d[bestu] + len ;
            }
             //cout<<d[v]<<" d[v]"<<endl;
        }
        scanned[bestu] = true;
    }
}

int main(){
    int u , v ,w;
    cin>>n>>m;

    for(int i = 0 ; i<m ; i++){
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back(v);
        lenght[u].push_back(w);

        adj[v].push_back(u);
        lenght[v].push_back(w);
    }

    shortest_path(0);
    cout<<d[n-1] << endl;

}