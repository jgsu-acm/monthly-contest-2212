#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> tmp;
    tmp.reserve(n);
    function<ll(int,int,int)> merge = [&](int l,int m,int r)
    {
        tmp.clear();
        int p=l, q=m+1;
        ll sum = 0;
        while(p<=m&&q<=r)
        {
            if(v[p]<=v[q]) tmp.push_back(v[p++]);
            else
            {
                tmp.push_back(v[q++]);
                sum += m-p+1;
            }
        }
        while(p<=m) tmp.push_back(v[p++]);
        while(q<=m) tmp.push_back(v[q++]);
        copy(tmp.begin(), tmp.end(), v.begin()+l);
        return sum;
    };
    function<ll(int,int)> merge_sort = [&](int l,int r) -> ll
    {
        if(l>=r) return 0;
        int m = (l+r)>>1;
        ll sum = 0;
        sum += merge_sort(l, m);
        sum += merge_sort(m+1, r);
        sum += merge(l, m, r);
        return sum;
    };
    cout<<merge_sort(0, n-1)<<'\n';
    return 0;
}
