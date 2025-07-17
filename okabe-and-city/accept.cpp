# include<iostream>
# include<cmath>
using namespace std;
long long n,m,k,t,i,s,ok,mx,x[10009],y[10009],a[10009],d[10009];
int main()
{
cin>>n>>m>>k;
mx=1000000009;a[0]=mx;
for(i=1;i<=k;i++)
{
cin>>x[i]>>y[i];
if(x[i]==n&&y[i]==m)ok=1;
if(x[i]==1&&y[i]==1)s=i;
a[i]=mx;
}
if(!ok){k++;x[k]=n+1;y[k]=m+1;}
a[k]=0;
while(1)
{
t=0;
for(i=1;i<=k;i++)
if(!d[i]&&a[i]<a[t])t=i;
if(t==s||!t)break;
d[t]=1;
for(i=1;i<=k;i++)
if(!d[i])
{
if(abs(x[i]-x[t])+abs(y[i]-y[t])<=1)a[i]=a[t];
else 
if(abs(x[i]-x[t])<=2||abs(y[i]-y[t])<=2)a[i]=min(a[i],a[t]+1);
}
}
if(a[s]==mx)cout<<-1;
else cout<<a[s];
}