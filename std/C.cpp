#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int p = min(n,m);
    for(int i=p;i<n;i++) cout<<v[i]<<' ';
    for(int i=0;i<p;i++) cout<<0<<' ';
    return 0;
}
