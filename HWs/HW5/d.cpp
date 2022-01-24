// In The Name Of God

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int mod=1e9+7;
const ll inf=1e8+10;
const int maxn=1e5+10;
const double eps=1e-7;
const double pi=3.14159265359;

int dp[1010][1010];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=i;
    }
    for(int j=1;j<=k;j++)
    {
        dp[1][j]=1;
        dp[0][j]=0;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j]=inf;
            for(int u=1;u<=i;u++)
            {
                dp[i][j]=min(dp[i][j],max(dp[u-1][j-1],dp[i-u][j]) + 1);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n][k];
}








