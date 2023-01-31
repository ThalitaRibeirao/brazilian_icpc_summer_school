#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int  n, m, a, b;
    long long int i, total = 0, compress = 0;
    vector<long long int> dif;

    cin >> n >> m;


    for(i = 0; i < n; i++){
        cin >> a >> b;
        dif.push_back(a - b);
        total += a;
    }

    sort(dif.begin(), dif.end());

    while(total > m){
        if(!dif.size()){
            printf("-1\n");
            return 0;
        }
        total -= dif.back();
        dif.pop_back();
        compress++;        
    }
    cout << compress << "\n";

    return 0;
}

