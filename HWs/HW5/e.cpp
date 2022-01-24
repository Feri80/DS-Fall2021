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

string names[1010];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string tmp;
    getline(cin,tmp);
    for(int i=0;i<n;i++)
    {
        getline(cin,names[i]);
    }
    set<string> s;
    s.clear();
    int k;
    cin>>k;
    int ans=0;
    getline(cin,tmp);
    for(int i=0;i<k;i++)
    {
        string x;
        getline(cin, x);
        s.insert(x);
        if(s.size()==n)
        {
            ans++;
            s.clear();
            s.insert(x);
        }
    }
    cout<<ans;
}








