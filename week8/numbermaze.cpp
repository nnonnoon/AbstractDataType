#include<iostream>
#include<queue>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   MS(a,b)        memset(a,b,sizeof(a))
#define   pb             push_back
#define   mp(a,b)        make_pair(a,b)
#define   lcm(a,b)       (a*b)/__gcd(a,b)
#define   xx              first
#define   yy              second
#define   inf             1000000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef pair<int , pair < int , int > > iii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
typedef priority_queue<iii, std::vector<iii>, std::greater<iii> > prs;
int d1[4]={1,0,-1,0};
int d2[4]={0,1,0,-1};
int main()
{
    int maze,n,m;
    cin>>maze;
    while(maze--) {
        cin>>n>>m;
        int arr[n+2][m+2];
        int dist[n+2][m+2];
        rep(i,0,n) {
            rep(j,0,m) dist[i][j]=inf;
        }

        //cout<<dist[0][0];
        rep(i,0,n) {
            rep(j,0,m) {
                cin>>arr[i][j];
            }
        }
        prs Q;
        dist[0][0]=arr[0][0];
        //cout<<endl<<dist[0][0]<<endl;
        Q.push(mp(dist[0][0],mp(0,0)));

        while(!Q.empty()) {
            int d=Q.top().xx;
            int x=Q.top().yy.xx;
            int y=Q.top().yy.yy;
            Q.pop();
            rep(i,0,4) {
                int a=y+d2[i];
                int b=x+d1[i];
                if(a>=0 && a<m && b>=0 && b<n) {
                    if(d> dist[b][a]) continue;
                    if(dist[b][a]> arr[b][a]+d) {
                        dist[b][a]=arr[b][a]+d;
                        Q.push(mp(dist[b][a],mp(b,a)));

                    }
                }
            }
        }
        cout<<dist[n-1][m-1]<<endl;
    }
    //cout<<endl;

}
