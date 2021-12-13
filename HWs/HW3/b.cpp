// In The Name Of God

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int mod=1e9+7;
const ll inf=1e18;
const int maxn=3e5+10;
const double eps=1e-7;
const double pi=3.14159265359;

int a[maxn],rads[600];
int n,m,rad;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    rad=sqrt(m);
    for(int i=0;i<n;i++)
    {
        int l,r,c;
        cin>>l>>r>>c;
        l--;
        r--;
        int cur = l;
        while(cur <= r)
        {
            if(cur % rad == 0)
            {
                if(cur + rad - 1 <= r)
                {
                    rads[cur / rad] = max(rads[cur / rad], c);
                    cur += rad;
                }
                else
                {
                    a[cur] = max(a[cur], c);
                    cur++;
                }
            }
            else
            {
                a[cur] = max(a[cur], c);
                cur++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<max(a[i], rads[i / rad])<<" ";
    }

}








