// In The Name Of God

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int inf=1e9;
const int maxn=1e6+10;
const double eps=1e-7;
const double pi=3.14159265359;

vector<int> g[maxn];
list<int> l;
int dis[maxn];
int mark[maxn];
int n,m;


void bfs(int s)
{
    for(int i=1;i<maxn;i++)
    {
        dis[i]=inf;
    }
    dis[s]=0;
    l.clear();
    l.push_back(s);
    while(!l.empty())
    {
        int u=l.front();
        l.pop_front();
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            if(dis[v] > dis[u]+1)
            {
                dis[v]=dis[u]+1;
                l.push_back(v);
            }
        }
    }
}

int main()
{
	cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        for(int j=0;j<w;j++)
        {
            if(j == w-1)
            {
                g[u+(j*n)].push_back(v);
            }
            else
            {
                g[u+(j*n)].push_back(u+((j+1)*n));
            }
        }
    }
    int sou;
    cin>>sou;
    bfs(sou);
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








