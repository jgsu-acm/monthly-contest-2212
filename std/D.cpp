#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    ll sum = 0;
    vector<ll> o(m);
    for(int i=0;i<n;i++)
    {
        o[i%m] += v[i];
        sum += o[i%m];
        cout<<sum<<' ';
    }
    return 0;
}
