#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    auto check = [&](int g)
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
            if(cnt<=v[i].second&&g-cnt-1<=v[i].first)
                cnt++;
        return cnt>=g;
    };
    int l=0, r=n;
    while(l<r)
    {
        int m = midpoint(l,r)+1;
        if(check(m)) l = m;
        else r = m-1;
    }
    cout<<l<<'\n';
    return 0;
}
