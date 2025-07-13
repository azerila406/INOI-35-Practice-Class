#include<bits/stdc++.h>
using namespace std;
vector<int>v[200005];
int dp[200005],col[200005],ans,n;
void dfs(int u,int p){
   for(int i=0;i<v[u].size();i++)
   if(v[u][i]!=p){
    dfs(v[u][i],u);
    ans=max(dp[u]+dp[v[u][i]]+1-(col[u]==col[v[u][i]]),ans);
    dp[u]=max(dp[v[u][i]]+1-(col[u]==col[v[u][i]]),dp[u]);
  }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;cin>>col[i++]);
   for(int i=1,x,y;i<n;i++){
     cin>>x>>y;
     v[x].push_back(y);
     v[y].push_back(x);
    assert(1 <= x && x <= n );
    assert(1 <= y && y <= n);
   }
   dfs(1,-1);
   return cout<<(ans+1)/2<<"\n",0;
}