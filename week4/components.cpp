#include<iostream>
#include<vector>
using namespace std;


void depthfirstsearch(int n,vector<int>adj[],bool visited[]){
    visited[n] = true;
       for(int i = 0;i < adj[n].size();i++){
         if(visited[adj[n][i]] == false) 
            depthfirstsearch(adj[n][i],adj,visited);
    }
}


int main(){
    int num_v,num_e,v,w;
    int count = 0 ;
    cin>>num_v>>num_e; 
    vector<int> adj[100000];
    bool visited[100000];

    for (int i = 0 ; i<num_e ; i++){
        cin>>v>>w;
        adj[w-1].push_back(v-1); 
        adj[v-1].push_back(w-1);
    }

    for(int i = 0 ; i<num_v ; i++){
        visited[i]=false;
    }

    for(int i = 0;i < num_v;++i){
         if(visited[i] == false){
            depthfirstsearch(i,adj,visited);
            count+=1;             
        }
    }
    cout<<count<<endl;
}