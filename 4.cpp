#include <bits/stdc++.h>
using namespace std;

#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define FI freopen("Data.in", "r", stdin);
#define FO freopen("Data.out", "w", stdout);
#define FIO                         \
    freopen("Data.in", "r", stdin); \
    freopen("Data.out", "w", stdout);
#define FCLS       \
    fclose(stdin); \
    fclose(stdout);
#define fr(i, a, b) for (int i = a; i <= b; ++i)
#define rfr(i, a, b) for (int i = a; i >= b; --i)
#define fr_(i, a, b) for (int i = a; i < b; ++i)
#define rfr_(i, a, b) for (int i = a; i > b; --i)
#define lc k << 1
#define rc k << 1 | 1
#define pk push_back
#define fs first
#define sc second
#define mkp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double dou;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 3;
const ll inf = 1e9 + 7;
const ll mod = 1e9 + 7;

ll ans = 0;
vector<int> pic[11];
vector<pii> edge;
int vis[11];
int n, m, q;
int u, v;
int clc[11];
bool f;

inline bool cherk(){
    for(auto&p:edge){
        if(clc[p.fs]==clc[p.sc]){
            return 0;
        }
    }
    return 1;
}
void draw(int u)
{
    if(u>n){
        ans+=cherk();
        return;
    }
    for(int i=1;i<=m;++i){
        clc[u]=i;
        draw(u+1);
    }
}

void solve()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; ++i)
    {
        cin >> u >> v;
        pic[u].pk(v);
        pic[v].pk(u);
        edge.pk(mkp(u,v));
    }
    clc[1]=1;
    draw(2);
    ans*=1LL*m;
    printf("%lld\n", ans);
}
int main(){
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
