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

int cur=0;
int n;
vector<int> g[maxn];

int dfs(int a, int b)
{
    int res=0;
    int first=0;
    int second=0;
    for(int v:g[a])
    {
        if(v != b)
        {
            res=max(res, dfs(v, a));
            if(cur>first)
            {
                second=first;
                first=cur;
            }
            else
            {
                second=max(second,cur);
            }
        }
    }
    res = max(res, first+second);
    cur=first+1;
    return res;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0;
    int ans1=0;
    int ans2=0;
    for(int u=1;u<=n;u++)
    {
        for(int v:g[u])
        {
            cur=0;
            ans1=dfs(u,v);
            cur=0;
            ans2=dfs(v,u);
            ans = max(ans, ans1 * ans2);
        }
    }
    cout<<ans;
}








