#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pdi pair<double,int>
#define mp make_pair
#define F first
#define S second
using namespace std;
const double INF=1e18;
int n,a[200005],fa[200005],p[200005];
bool vis[200005];
ll ans,cnt1[200005],cnt0[200005];
int find(int x){return (fa[x]==x?x:find(fa[x]));}
void merge(int x,int y)//并查集合并操作
{
	x=find(x),y=find(y);
	ans+=cnt1[y]*cnt0[x];//记录对逆序对总数的贡献
	cnt1[y]+=cnt1[x];//合并后加上0 1个数
	cnt0[y]+=cnt0[x];
	fa[x]=y;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	p[0]=-1;
	for(int i=1;i<n;i++)
	{
		cin>>p[i];
		--p[i];
	}
	priority_queue<pdi,vector<pdi>,greater<pdi> > pq;//优先队列按权值升序存节点
	for(int i=0;i<n;i++)
	{
		fa[i]=i;
		cin>>a[i];
		if (a[i]) ++cnt1[i];
		else ++cnt0[i];
		pq.push(mp((cnt0[i]==0?INF:1.0*cnt1[i]/(1.0*cnt0[i])),i));
	}
	while(!pq.empty())
	{
		int u=pq.top().S;
		pq.pop();
		if (vis[u])
			continue;
		vis[u]=1;
		if (p[u]!=-1)//与父亲所在节点合并
		{
			int x=find(p[u]);
			merge(u,x);
			pq.push(mp((cnt0[x]==0?INF:1.0*cnt1[x]/(1.0*cnt0[x])),x));//将新节点加入优先队列
		}
	}
	cout<<ans<<endl;
	return 0;
}