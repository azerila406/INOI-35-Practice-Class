#include <bits/stdc++.h>
using namespace std;
#define N 10005
 
const int inf = 1e9;
int r[N], c[N], d[N] = {inf};
int n, m, k, jd;
bool flag = 0, vis[N];
 
int main() {
  int i, id;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 1; i <= k; i ++) {
    scanf("%d %d", r + i, c + i);
    if(r[i] == n && c[i] == m) flag = 1;
    if(r[i] == 1 && c[i] == 1) jd = i;
    d[i] = inf;
  }
  if(!flag) r[++ k] = ++ n, c[k] = ++ m;
  d[k] = 0;
  while (1) {
    id = 0;
    for (i = 1; i <= k; i ++) {
      if(vis[i]) continue;
      if(d[i] < d[id]) id = i;
    }
    if(!id || jd == id) break;
    vis[id] = 1;
    for (i = 1; i <= k; i ++) {
      if(vis[i]) continue;
      if(abs(r[i] - r[id]) + abs(c[i] - c[id]) <= 1) d[i] = d[id];
      else if(abs(r[i] - r[id]) <= 2 || abs(c[i] - c[id]) <= 2) d[i] = min(d[id] + 1, d[i]);
    }
  }
  if(d[jd] == inf) puts("-1");
  else printf("%d\n", d[jd]);
}