// In The Name Of God

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int inf=1e8+10;
const int maxn=1e5+10;
const double eps=1e-7;
const double pi=3.14159265359;

vector<pair<int,int>> g[maxn];
int dis[maxn];
int n,m,sou;

void dijkstra(int sou)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
    }
    dis[sou] = 0;
    set<pair<int,int>> s;
    s.clear();
    for(int i=1;i<=n;i++)
    {
        s.insert({dis[i],i});
    }
    while(s.size())
    {
        int u = (*s.begin()).second;
        s.erase(s.begin());
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i].first;
            int w = g[u][i].second;
            if(dis[u] + w < dis[v])
            {
                s.erase({dis[v],v});
                dis[v] = dis[u] + w;
                s.insert({dis[v],v});
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
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    cin>>sou;
    dijkstra(sou);
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==inf)
        {
            cout<<"-1 ";
        }
        else
        {
            cout<<dis[i]<<" ";
        }
    }
}








