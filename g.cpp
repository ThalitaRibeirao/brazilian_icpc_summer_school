#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    ll n, m, pos;
    ll i, j, x, y, k, min, vizinho;
    
    cin >> n >> m;
    vector<vector<ll>> res(n);
    vector<ll> police(n), police_final(n), aux;

    min = n;

    for(i = 0; i < m; i++){
        cin >> x >> y;
        res[x-1].push_back(y-1);
        res[y-1].push_back(x-1);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) police[j] = j != i && find(res[i].begin(), res[i].end(), j) == res[i].end();

        x = 1;

        for(j = 0; j < res[i].size(); j++) {
            vizinho = 1;
            aux = res[res[i][j]];
            
            for(k = 0; k < aux.size(); k++){
                if(police[aux[k]]) vizinho = 0; 
            }
            if(vizinho){
                if(++x >= min) break;
            } 
        }

        if(x < min){
            min = x;
            for(j = 0; j < n; j++) police_final[j] = police[j];
            if(x == 1) break;
        }
    }
    for(i = 0; i < police_final.size();i++) cout << police_final[i] << " ";
    cout << endl;
    return 0;
}