#include <bits/stdc++.h>
using namespace std;
vector<int> res;
int k;

int contar(vector<int> padrao){
    int i, cont = 0;
    for(i = 0; i < res.size(); i++){
        if(res[i] != padrao[i%k]) cont++;
    }
    return cont;
}






int main(){
    int n, aux, p, f;
    int i, j, mudancas = 0;


    cin >> n >> k;
  

    
    for(i = 0; i < n; i++) {
        cin >> aux;
        res.push_back(aux);
    }


    p = pow(2, k);
    cout << p << " p\n";
    f = p;
    vector<vector<int>> padrao(p);

   
  
    f = f/2;
    for(i = 0; i < p; i++){
        for(j = 0; j < k; j++){
            if((j/f)%2) padrao[i].push_back(2);
            else padrao[i].push_back(1); 
        }
    }
    

    for(i = 0; i < p; i++){
        for(j = 0; j < k; j++){
            cout << padrao[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    // for(i = 0; i < n/k; i++){
    //     for(j= 0; j < k; j++) padrao[j] = res[i*k + j];
    //     mudancas = contar();
    //     if(!mudancas) mudancas = contar();
    //     else mudancas = min(mudancas, contar());
        
    //     if(!mudancas) break;
    // }
    // cout << mudancas << endl;

    // return 0;
}