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
    int sum = accumulate(v.begin(), v.end(), 0);
    int x = v.front();
    if(sum==m||(sum>m&&count(v.begin(), v.end(), x)==v.size()&&m%x==0)) cout<<-1<<'\n';
    else
    {
        vector<pair<int,int>> w(n);
        for(int i=0;i<n;i++) w[i] = {v[i], i+1};
        sort(w.begin(), w.end());
        int pre = 0;
        for(int i=0;i<n;i++)
        {
            pre += w[i].first;
            if(pre==m)
            {
                reverse(w.begin(), w.begin()+i+1);
                swap(w[i], w.back());
                break;
            }
        }
        for(auto&& i : w) cout<<i.second<<' ';
        cout<<'\n';
    }
    return 0;
}
