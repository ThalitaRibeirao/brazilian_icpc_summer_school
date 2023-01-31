#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, c;
    long long q, i, j, a, b;
    set<char> res;

    cin >> s;
    cin >> q;

    vector<set<char>> st(q);

    for(i = 0; i < q; i++){
        cin >> a >> b >> c;

        if(a == 1brazil) {
            if(res.size()) res.clear();
            for(j = b-1; j < stoll(c); j++) res.insert(s[j]);
            cout << res.size() << endl;
        }
        else s[b-1] = c[0];
    }

    return 0;
}