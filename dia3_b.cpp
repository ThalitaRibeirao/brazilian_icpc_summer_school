#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    long long i, a, b, total = 0, c = 0;
    pair<long, long> x;
    vector<pair<long long, long long>> res;
    
    cin >> n >> k;
    for(i = 0; i < n; i++){
        cin >> a >> b;
        x.first = a;
        x.second = b;
        res.push_back(x);
    }
    sort(res.begin(), res.end());
    for(i = 0; i < n; i++){
        total += res[i].second;
        if(total >= k){
            c = res[i].first;
            break;
        }
    }
    cout << c << "\n";
    return 0;
}