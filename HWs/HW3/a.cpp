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

struct Node
{
    int data;
    int level;
    struct Node* left;
    struct Node* right;
};

vector<int> a;
vector<int> g[100];
int n;
struct Node* root;
int mxl;

void getOneLine()
{
    a.clear();
    string s;
    getline(cin, s);
    stringstream input(s);
    int v=0;
    while(input >> v)
    {
        a.push_back(v);
    }
}

void make(struct Node** par, int l, int r, int level)
{
    if(r<l)
    {
        g[level].push_back(-1);
        return;
    }
    mxl = max(level,mxl);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int mid = (l+r)/2;
    newNode->data = a[mid-1];
    newNode->level = level;
    newNode->left = NULL;
    newNode->right = NULL;
    g[level].push_back(a[mid-1]);
    (*par) = newNode;
    make(&(newNode->left), l, mid-1, level+1);
    make(&(newNode->right), mid+1, r, level+1);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    getOneLine();
    int n = a.size();
    make(&root, 1, n, 1);

    for(int i=1;i<=mxl;i++)
    {
        for(auto x:g[i])
        {
            if(x==-1)
            {
                cout<<"null ";
            }
            else
            {
                cout<<x<<" ";
            }
        }
    }
}








