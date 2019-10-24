#include <cstdio>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair< int, int >
#define MAX 1001

vector< pair< int, edge > > GRAPH, MST;
int parent[MAX], total, N, E;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal()
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=total=0; i<E; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST.push_back(GRAPH[i]); // add to tree
            if(GRAPH[i].first > total){
                total = GRAPH[i].first;
            }
            parent[pu] = parent[pv]; // link
        }
    }
}

void reset()
{
    // reset appropriate variables here
    // like MST.clear(), GRAPH.clear(); etc etc.
    for(int i=1; i<=N; i++) parent[i] = i;
}

void print()
{
    int i, sz;
    // this is just style...
    printf("%d\n", total);
}

int main()
{
    int i, u, v, w;

    scanf("%d %d", &N, &E);
    reset();
    int unit [N+1];

    for(int i = 0 ; i<N ; i++){
       cin>>unit[i];
    }

    for(i=0; i<E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        if(w%(unit[u]+unit[v]) != 0){
            w = w/(unit[u]+unit[v])+1;
            GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
        }
        else {
            w = w/(unit[u]+unit[v]);
            GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
        }
    }
    
    kruskal(); // runs kruskal and construct MST vector
    print(); // prints MST edges and weights

    return 0;
}