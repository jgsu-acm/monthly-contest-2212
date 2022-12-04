#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int u,v;
    cin>>u>>v;
    vector<vector<int>> G(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> vis(n+1);
    function<void(int)> dfs = [&](int u)
    {
        if(vis[u]) return;
        vis[u] = true;
        for(auto v : G[u]) dfs(v);
    };
    dfs(u);
    cout<<(vis[v]?"YES":"NO")<<endl;
    return 0;
}
