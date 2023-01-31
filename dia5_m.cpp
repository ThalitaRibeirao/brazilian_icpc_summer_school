#include <bits/stdc++.h>
using namespace std;
long long memobinaryreslen = 0;
vector<vector<int>> memobinaryres (200000);
vector<pair<long long, long long>> memobinary;
vector<tuple<long long, long long, long long>>






vector<int> decToBinary(long long n){
    vector<int> vec;
    long long i = 0;

    while (n > 0) {
        memobinaryres[memobinaryreslen][i] = n%2;
        vec.push_back(n % 2);
        n = n / 2;
        i++
    }

    memobinaryreslen++;
    return vec;
}

long long fxor(long long x, long long y){
    if(x == -1 || y == -1) return 0;
    vector<int> xbits, ybits;
    long long i, j, total = 0, pot = 1, size;

    


    xbits = decToBinary(x);
    ybits = decToBinary(y);
    






    for(j = ybits.size(); j < xbits.size(); j++) ybits.push_back(0);
    for(j = xbits.size(); j < ybits.size(); j++) xbits.push_back(0);

    for(i = 0; i < xbits.size(); i++) {
        total += ((xbits[i] && !ybits[i]) || (!xbits[i] && ybits[i])) * pot;
        pot *= 2;
    }
    return total;
}

int main(){
    long long n, i, j, x, maximo, rxor;
    char c;

    vector<long long> res, memores;
    res.push_back(0);

    cin >> n;
    for(i = 0; i < n; i++){
        cin >> c >> x;
        if(c == '+') res.push_back(x);
        else if (c == '-'){
            for(j = 0; j < res.size(); j++){
                if(res[j] == x) {
                    res[j] = -1;
                    break;
                }
            }
        }
        else {
            maximo = 0;
            for(j = 0; j < res.size(); j++) {
                if(res[j] == x) continue;
                else if(res[j] == 0) maximo = max(x, maximo); 
                else if(res[j] >= 0) {
                    maximo = max(maximo, fxor(x, res[j]));
                }
            }
            cout << maximo  << endl;
        } 
    }
    return 0;
}