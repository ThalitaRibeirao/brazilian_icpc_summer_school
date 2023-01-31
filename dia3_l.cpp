#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

#define MAX 112345



int _p[MAX], _rank[MAX];
void _make(int u) {
    _p[u] = u;
    _rank[u] = 1;
}
int _find(int u) {
    return(_p[u] == u)?u:(_p[u] = _find(_p[u]));
}
void _union(int u, int v) {
    u = _find(u); v = _find(v);
    if(_rank[v] > _rank[u])
        _p[u] = v;
    else {
        _p[v] = u;
        if(_rank[u] == _rank[v])
            _rank[u]++;
    }
}


set<int> adj[MAX];
ii ar[MAX];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        _make(i);
    ii uv;
    int u, v;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
        if(_find(u) != _find(v)) _union(u, v);
        uv.first = u;
        uv.second = v;
        ar[i] = uv;
    }
    int q;
    scanf("%d", &q);
    int r;
    int com = 0;
    for(int i = 1; i <= n; i++) {
        if(_find(i) == i)
            com++;
    }
    for(int i = 1; i <= q; i++) {
        scanf("%d", &r);
        u = ar[i].first; v = ar[i].second;
        adj[u].erase(v);
        adj[v].erase(u);
        _make(u); _make(v);
        if(!adj[v].empty() && !adj[u].empty()) {
            _union(u, *(adj[u].begin()));
            _union(v, *(adj[v].begin()));
        }
        if(_find(u) != _find(v)) com++;
        (i == q)?printf("%d", com):printf("%d ", com);
    }
    return 0;
}