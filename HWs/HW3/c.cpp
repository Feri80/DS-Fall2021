// In The Name Of God

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

const int mod=1e9+7;
const ll inf=1e18;
const int maxn=5e6+10;
const double eps=1e-7;
const double pi=3.14159265359;

int q[maxn];
int k;
int sz = 1;

void getOneLine()
{
    string s;
    getline(cin, s);
    stringstream input(s);
    int v=0;
    while(input >> v)
    {
        q[sz++] = v;
    }
}

void heapify(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;
    if(left <= sz)
    {
        if(q[left] < q[smallest])
        {
            smallest = left;
        }
    }
    if(right <= sz)
    {
        if(q[right] < q[smallest])
        {
            smallest = right;
        }
    }
    if(smallest != i)
    {
        swap(q[i], q[smallest]);
        heapify(smallest);
    }
}

void build()
{
    for(int i=sz/2; i>=1; i--)
    {
        heapify(i);
    }
}

int pop_min()
{
    if(sz <= 0)
    {
        return -1;
    }
    int res = q[1];
    q[1] = q[sz];
    sz--;
    heapify(1);
    return res;
}

int main()
{
	cin>>k;
	string tmp;
	getline(cin, tmp);
    for(int i=0;i<k;i++)
    {
        getOneLine();
    }
    sz--;
    build();
    int n = sz;
    for(int i=0; i<n; i++)
    {
        cout<<pop_min()<<" ";
    }


}








