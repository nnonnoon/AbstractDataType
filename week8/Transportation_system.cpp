#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1010;
const int M = 500010;
struct edge {
    int u, v;
    double cost;
}e[M];
int n, s, T, f[N];
double ans1, ans2, x[N], y[N], r;
bool cmp ( edge a, edge b ) {  return a.cost - b.cost < 1e-9; }
int find( int z ) {
    return f[z] == z ? z : f[z] = find(f[z]);
}
void Kru( int t ) {
    for ( int i = 0; i < t; ++i ) {
        int p = e[i].u, q = e[i].v;
        int a = find(p), b = find(q);
        double c = e[i].cost;
        if ( a != b ) {
            f[a] = b;
            if ( c - r < 1e-9 ) ans1 += c, s--;
            else ans2 +=c;
        }
    }
}
int main()
{
    int idx = 1;
    scanf("%d", &T);
    while ( T-- ) {
        int ei = 0;
        scanf("%d%lf", &n, &r);
        for ( int i = 1; i <= n; ++i ) { 
            scanf("%lf%lf", &x[i], &y[i]);
            f[i] = i;
        }
        for ( int i = 1; i <= n; ++i ) 
            for ( int j = i+1; j <= n; ++j ) 
               e[ei].u = i, e[ei].v = j, e[ei++].cost = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) ); 
        sort( e, e + ei, cmp );
        ans1 = ans2 = 0;
        s = n;
        Kru(ei);
        printf("Case #%d: %d %.0lf %.0lf\n", idx++, s, ans1, ans2);
    }
}
