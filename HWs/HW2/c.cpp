// In The Name Of God

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int mod=1e9+7;
const ll inf=1e18;
const int maxn=1e4+10;
const double eps=1e-7;
const double pi=3.14159265359;

int n;
vector<int> s;
int a[maxn],b[maxn];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    int ok = 0;
    for(int i = 0; i < n; i++)
    {
        while(s.size() == 0 or s[s.size() - 1] != b[i])
        {
            s.push_back(a[ok]);
            ok++;
            if(ok > n)
            {
                cout<<"false";
                return 0;
            }
        }
        s.pop_back();
    }
    if(s.size() == 0)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

}








