#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, i, b;
    int x, aux;

    vector<pair<int, int>> res;

    cin >> n;


    for(x = 0; x < n; x++){
        cin >> aux;
        res.push_back(make_pair(aux, x));
    }
    sort(res.begin(), res.end());

    for(x = 0; x < res.size(); x++){
        cout << res[x].first << " " << res[x].second << endl;
    } 


    




    // cin >> "? " >> endl;
    // cout << "! ";
    return 0;
}