#include<bits/stdc++.h>
using namespace std;
const long long maxn=200000+10;
int ted=0,n,teda=0;
set<int>st;
int cntz[maxn],cntf[maxn];

void clear(){
	st.clear();
	ted=0;
	teda=0;
	for(int i=0;i<=n;i++){
		cntz[i]=cntf[i]=0;
	}
}

int wtf(int l,int r){
	if((r-l-1)&1){
		if((l+1)&1){
			return cntf[r-1]-cntf[l];
		}else{
			return cntz[r-1]-cntz[l];
		}
	}else{
		return max(cntf[r-1]-cntf[l],cntz[r-1]-cntz[l]);
	}
}

void tagh(int i){
	auto x=st.lower_bound(i);
	x++;
	int nx=*x;
	x--;
	x--;
	int ps=*x;
	ted-=(i-ps)/2;
	teda-=wtf(ps,i);
	ted-=(nx-i)/2;
	teda-=wtf(i,nx);
	st.erase(i);
	ted+=(nx-ps)/2;
	teda+=wtf(ps,nx);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin>>t;
	for(long long asd=0;asd<t;asd++){
		cin>>n;
		ted=0;
		teda=0;
		for(int i=0;i<=n+1;i++){
			st.insert(i);
		}
		vector<int>all(n+1);
		vector<pair<int,int>>alla;
		for(int i=1;i<=n;i++){
			cin>>all[i];
			alla.push_back(make_pair(all[i],i));
		}
		sort(alla.begin(),alla.end());
		long long mx=alla.back().first;
		for(int i=1;i<=n;i++){
			if(mx==all[i]){
				if(i&1){
					cntf[i]++;
				}else{
					cntz[i]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cntf[i]+=cntf[i-1];
			cntz[i]+=cntz[i-1];
		}
		long long res=mx*2+1;
		while((int)alla.size()>0){
			tagh(alla.back().second);
		//	cout<<alla.back().second<<" "<<ted<<" "<<mx+alla.back().first+ted<<" "<<teda<<endl;
			res=max(res,mx+alla.back().first+ted-(teda==0));
			alla.pop_back();
		}
		cout<<res<<"\n";
		clear();
	}
}