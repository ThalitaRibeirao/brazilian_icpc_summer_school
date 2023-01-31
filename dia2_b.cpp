#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

struct FORMIGA {
    long long int pos;
    int dir;
    int caiu;
} ant;

long long int resolve(vector<FORMIGA> res, long long int l){
    long long int tempo = 0;
    long long int i, j, resolvido;
    while(1){
        resolvido = 1;
        for(i = 0; i < res.size(); i++){
            cout << "pos: " << res[i].pos << " dir: " << res[i].dir << " caiu: " << res[i].caiu << "\n";
            if(!res[i].caiu){
                res[i].pos += res[i].dir;
                if(res[i].pos < 0 || res[i].pos > l) res[i].caiu = 1;
                resolvido = 0;
            }
        }
        if (resolvido) break;
        else{
            for(i = 0; i < res.size()-1; i++){
                if(res[i].pos == res[i+1].pos){
                    res[i].dir *= -1;
                    res[i+1].dir *= -1;
                }
            }
            tempo ++;
        }
    }
    cout << "> tempo: " << tempo << "\n";
    return tempo;
}


int main(){
    int cases;
    long long int l = 0, n = 0;
    long long int i, j, x, num_res, intervalo;
    long long int min = 0, max = 0, atual;
    FORMIGA aux;
    vector<FORMIGA> res, resaux;
    cin >> cases;

    
    while(cases){
        if(res.size()) {
            res.clear();
        }
        if(resaux.size()){
            resaux.clear();
        }


        cin >> l >> n;
        num_res = pow(2, n);
        intervalo = num_res;
        cout << "chegou aqui\n";

        for(i = 0; i < n; i++){
            cin >> x;
            aux.pos = x;
            aux.caiu = 0;

            intervalo/=2;
            for(j = 0; j < num_res; j++){
                if((j/intervalo)%2){
                    aux.dir = 1;   
                    res.push_back(aux);
                }
                else{
                    aux.dir = -1;
                    res.push_back(aux);
                }
            }
        }

        for(i = 0; i <num_res; i++){
            for(j = 0; j < n; j++) {
                resaux.push_back(res[i+(num_res*j)]);
            }
            
            atual = resolve(resaux, l);
            if(atual > max) max = atual;
            if(atual < min) min = atual;
            cout<< "\n-----------------------------\n";
        }
        cout << min << " " << max << "\n";
        cases--;
    }


    return 0;
}