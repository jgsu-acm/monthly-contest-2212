#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const pair<int,int> dir[] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int t;
    cin>>t;
    while(t--)
    {
        vector<vector<int>> bod(3, vector<int>(3));
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>bod[i][j];
        set<pair<int,int>> s;
        vector<vector<bool>> vis(3, vector<bool>(3));
        int f=1, sum=0;
        function<void(int,int,int)> dfs = [&](int x,int y,int d)
        {
            vis[x][y] = true;
            int ls=sum, lf=f;
            if((x+y)&1) f = bod[x][y];
            else
            {
                sum += f*bod[x][y];
                s.emplace(sum, (d+1)/2);
            }
            for(auto [e,f] : dir)
            {
                int p=x+e, q=y+f;
                if(p>=0&&p<=2&&q>=0&&q<=2&&!vis[p][q])
                    dfs(p,q,d+1);
            }
            vis[x][y] = false;
            sum=ls; f=lf;
        };
        dfs(0,0,1); dfs(0,2,1); dfs(1,1,1); dfs(2,0,1); dfs(2,2,1);
        int m;
        cin>>m;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            cout<<(s.find(make_pair(x,y))!=s.end()?"Yes":"No")<<'\n';
        }
    }
    return 0;
}
