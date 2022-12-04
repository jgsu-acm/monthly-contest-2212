#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n,o,p;
    cin>>m>>n>>o>>p;
    vector<string> alllang;
    map<string, vector<string>> mp;
    for(int i=0;i<m;i++)
    {
        string lang;
        cin>>lang;
        alllang.emplace_back(lang);
        for(int j=0;j<n;j++)
        {
            string keyword;
            cin>>keyword;
            mp[keyword].emplace_back(lang);
        }
    }
    sort(alllang.begin(), alllang.end());
    for(auto&& [k,v] : mp) sort(v.begin(), v.end());
    while(o--)
    {
        vector<string> uni, tmp;
        for(int i=0;i<p;i++)
        {
            string word;
            cin>>word;
            set_union(
                uni.begin(), uni.end(),
                mp[word].begin(), mp[word].end(),
                back_inserter(tmp)
            );
            uni = tmp;
            tmp.clear();
        }
        cout<<(uni.empty()?"Unknown":uni.back())<<'\n';
    }
    return 0;
}
