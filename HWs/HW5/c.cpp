// In The Name Of God

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int mod=1e9+7;
const ll inf=1e18;
const int maxn=1e5+10;
const double eps=1e-7;
const double pi=3.14159265359;

int n,m;
vector<int> g[maxn];
int mark[maxn],inter[maxn],mint[maxn];
int timer;

void dfs(int u, int p)
{
    mark[u]=1;
    inter[u]=mint[u]=timer;
    timer++;
    for(auto v:g[u])
    {
        if(v==p)
        {
            continue;
        }
        if(mark[v])
        {
            mint[u]=min(mint[u], inter[v]);
        }
        else
        {
            dfs(v, u);
            mint[u]=min(mint[u], mint[v]);
            if(mint[v]>inter[u])
            {
                cout<<-1;
                exit(0);
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        inter[i]=-1;
        mint[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            dfs(i,-1);
        }
    }
    cout<<1;
}








