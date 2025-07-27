#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back 
#define N 500005
ll n,m,q;
vector<ll> v[N];
struct edg{ll u,v,w,id,x,y;}ed[N];
struct dsu{
	unordered_map<ll,ll> fa;
	ll fnd(ll x){return !fa[x]?x:fa[x]=fnd(fa[x]);}
	bool unn(ll x,ll y){
		ll p=fnd(x),q=fnd(y);
		if(p==q) return 0;
		fa[p]=q;
		return 1;
	}
}g;
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++) scanf("%lld%lld%lld",&ed[i].u,&ed[i].v,&ed[i].w),ed[i].id=i,v[ed[i].w].pb(i);
	for(ll i=1;i<=500000;i++){
		for(ll j:v[i]) ed[j].x=g.fnd(ed[j].u),ed[j].y=g.fnd(ed[j].v);
		for(ll j:v[i]) g.unn(ed[j].u,ed[j].v);
	}
	scanf("%lld",&q);
	for(ll i=1;i<=q;i++){
		ll k;scanf("%lld",&k);
		bool f=1;
		dsu t;
		for(ll j=1,x;j<=k;j++){
			scanf("%lld",&x);
			if(!t.unn(ed[x].x,ed[x].y)) f=0;
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
			 	 	  	 	 	 	 	 			  	 		