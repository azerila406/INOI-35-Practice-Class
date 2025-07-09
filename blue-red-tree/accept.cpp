#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
//const int inf=0x3f3f3f3f;
const ll inf=1e15;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction  (not adding u->pre[u] is ok)
// build_hld(rt)  preferred son moved to the beginning of linkedlist
// 	dfn[u] continuous integers down along a preferred chain (up[u] -> leaf)

const int TREE_MAXV=100000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
int dfn[TREE_MAXV],rig[TREE_MAXV],pre[TREE_MAXV],h[TREE_MAXV];
int seq[TREE_MAXV],up[TREE_MAXV];
void build_hld(int rt){
	static int qu[TREE_MAXV],sz[TREE_MAXV],son[TREE_MAXV];
	int p=0,q=0;
	qu[q++]=rt;
	pre[rt]=0;
	h[rt]=0;
	while(p!=q){
		int u=qu[p++];sz[u]=1,son[u]=0;
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u])
			qu[q++]=e[i].v,pre[e[i].v]=u,h[e[i].v]=h[u]+1;
	}
	sz[0]=0;
	for (int i=q-1;i>=1;i--){
		sz[pre[qu[i]]]+=sz[qu[i]];
		if(sz[qu[i]]>sz[son[pre[qu[i]]]])son[pre[qu[i]]]=qu[i];
	}
	for (int j=0;j<q;j++)
		if(!son[qu[j]]){
			int s=qu[j];while(son[pre[s]]==s)s=pre[s];
			int t=s;while(t)up[t]=s,t=son[t];
		}else{
			int u=qu[j],v=son[u];
			if(e[g[u]].v!=v){
				for (int i=g[u],j;~i;j=i,i=e[i].next)if(e[i].v==v){
					e[j].next=e[i].next;
					e[i].next=g[u];
					g[u]=i;
					break;
				}
			}
		}
	static int stk[TREE_MAXV],cur[TREE_MAXV];
	int top=0,ind=0;
	stk[++top]=rt;
	cur[top]=g[rt];
	while(top){
		int u=stk[top];
		if(cur[top]==g[u]){
			dfn[u]=++ind;
			seq[ind]=u;	
		}
		if(cur[top]==-1){
			rig[u]=ind;	
			top--;
		}else{
			int v=e[cur[top]].v;cur[top]=e[cur[top]].next;
			if(v==pre[u])continue;
			stk[++top]=v;
			cur[top]=g[v];
		}
	}

}	


// range update, range query
// index 1..n
// first call seginit(n)

typedef ll seg_nu;
typedef ll seg_tag;
const int SEG_MAXN=100000+5;

int seglen[SEG_MAXN*4];
seg_nu seg[SEG_MAXN*4];
seg_tag tag[SEG_MAXN*4];
seg_tag tag0 = 0;						//modify
inline void segadd(int x,seg_tag v){
	seg[x]=seg[x]+v;				//modify
	tag[x]=tag[x]+v;					//modify
}
inline void segpd(int x){
	if(tag[x]!=tag0){
		segadd(x<<1,tag[x]);
		segadd(x<<1|1,tag[x]);
		tag[x]=tag0;					
	}
}
inline void segpu(int x){
	seg[x]=min(seg[x<<1],seg[x<<1|1]);				//modify
}
void seginit_in(int l,int r,int x){
	tag[x]=tag0;						
	seglen[x]=r-l+1;
	if(l==r){
		//seg[x]=a[l];
		seg[x]=0;					//modify
	}else{
		int mid=l+r>>1;
		seginit_in(l,mid,x<<1);
		seginit_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int l1,r1;
seg_nu sans; bool ans_bo;
seg_tag stag;
void segupd_in(int l,int r,int x){
	//if(l1>r1)return;
	if(l1<=l && r<=r1){
		segadd(x,stag);
	}else{
		int mid=l+r>>1;
		segpd(x);
		if(l1<=mid)segupd_in(l,mid,x<<1);
		if(r1>mid)segupd_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
/* void segque_in(int l,int r,int x){ */
	/* //if(l1>r1)return; */
	/* if(l1<=l && r<=r1){ */
	/* 	if(!ans_bo)ans_bo=1,sans=seg[x]; */
	/* 	else sans=sans+seg[x];				//modify */
	/* }else{ */
	/* 	int mid=l+r>>1; */
	/* 	segpd(x); */
	/* 	if(l1<=mid)segque_in(l,mid,x<<1); */
	/* 	if(r1>mid)segque_in(mid+1,r,x<<1|1); */
	/* } */
/* } */
int segn;
void segupd(int l,int r,seg_tag v){
	if(l>r)return;
	stag=v,l1=l,r1=r;
	segupd_in(1,segn,1);
}
/* seg_nu segque(int l,int r){ */
/* 	if(l>r)return 0;					//modify */
/* 	ans_bo=0,l1=l,r1=r; */
/* 	segque_in(1,segn,1); */
/* 	return sans; */
/* } */
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}

const int B = 1e6;
void addit(int a,int b,int id,int sg){
	int l1,r1;
	while(up[a]!=up[b]){
		if(h[up[a]]<h[up[b]])swap(a,b);
		l1=dfn[up[a]],r1=dfn[a];	
		segupd(l1,r1,(B+id)*sg);
		a=pre[up[a]];
	}
	if(h[a]>h[b])swap(a,b);

	// work on edges:
	l1=dfn[a]+1,r1=dfn[b];
	if(a!=b){
		segupd(l1,r1,(B+id)*sg);
	}

}

int getpos(int l,int r,int x){
	if(l==r)return l;
	else{
		int mid=l+r>>1;
		segpd(x);
		if(seg[x<<1]<seg[x<<1|1])return getpos(l,mid,x<<1);
		else return getpos(mid+1,r,x<<1|1);
	}
}

/* int lca(int a,int b){	// using hld, O(log n) */
/* 	while(up[a]!=up[b]){ */
/* 		if(h[up[a]]<h[up[b]])swap(a,b); */
/* 		a=pre[up[a]]; */
/* 	} */
/* 	if(h[a]>h[b])swap(a,b); */
/* 	return a; */
/* } */
void tree_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=n;i++)g[i]=-1;
	}
	etot=0;
}
void readedge(){
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);ae(y,x);
	}
}

pii lin[111111];

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	tree_init();
	gn(n);
	readedge();
	rep(i,1,n){
		gn(lin[i].fi);gn(lin[i].se);
	}
	build_hld(1);
	seginit(n);
	rep(i,1,n){
		addit(lin[i].fi,lin[i].se,i,1);
	}
	rep(_,1,n){
		while(seg[1]==0){
			int t=getpos(1,n,1);
			segupd(t,t,inf);
		}
		ll t= seg[1];
		if(t>=2*B){
			printf("NO\n");
			return 0;
		}
		int id=t-B;
		addit(lin[id].fi,lin[id].se,id,-1);
	}
	printf("YES\n");

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
