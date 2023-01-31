#include <bits/stdc++.h>
using namespace std;
vector<tuple<long long, long long, long long>> res;

int main(){
    long long n, i, x , y, ordered;
    cin >> n;

    for(i = 0; i < n; i++){
        cin >> x >> y;
        res.push_back(make_tuple(x, y, i));
    }

    sort(res.begin(), res.end());
    for(i = 0; i < n-1; i++) {
        if(get<0>(res[i]) != get<0>(res[i+1]) && get<1>(res[i]) == get<1>(res[i+1]) && get<2>(res[i]) > get<2>(res[i+1])){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}