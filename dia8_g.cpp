#include <bits/stdc++.h>
using namespace std;
unsigned long long x, k, metade;




unsigned long long pl (unsigned long long linha){
    return (linha * (linha+1))/2;
}




unsigned long long soma (unsigned long long linha){
    unsigned long long result, aux;

    if(linha == k) return metade;

    result = pl(linha);

    if(linha > k){
        aux = pl(linha - linha%k);
        result += metade - aux;
    }
    return aux;

}





int met(unsigned long long linha){
   
   
    if(linha-1 >= 0) {
        met(linha - 1);
        met(linha + 1);
    }
    return 1;
}






int main() {
    unsigned long long t;
    unsigned long long i, j, per, sum;
    vector<unsigned long long> res;
    
    cin >> t;
    for(i = 0; i < t; i++){
        cin >> k >> x;
        metade = pl(k);


        for(j = 0; j < 2*k + 1; k++) {
            cout << soma(j) << endl;
        }
        // if(x >= k*k) res.push_back(2*k - 1);
        // else{
        //     
        //     met(k);
        // }
    }
    // for(i = 0; i < res.size(); i++) cout << res[i] << endl;
    return 0;
}