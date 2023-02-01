#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> res;
long long n;


int decrease(long long pos){
    if(pos < 0 || pos == n-1) return 1;

    if(res[pos].first > res[pos+1].first){
        if(res[pos].first - res[pos+1].first > 1) return 0;
        else if(res[pos].second){
            res[pos].first--;
            res[pos].second = 0;
            return decrease(pos-1);
        }
        else return 0;
    }
    return decrease(pos+1);
}


int main(){
    long long h, i;

    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> h;
        res.push_back(make_pair(h, 1));
    }

    if(decrease(0)) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}