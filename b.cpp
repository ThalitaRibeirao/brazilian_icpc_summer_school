#include <bits/stdc++.h>
using namespace std;
vector<long long> res;
typedef pair<int, long long> resposta;


resposta ok (int x, int y, int n, int m){
    long long antc, antl;
    long long proxc, proxl;
    long long atual;
    resposta retorno;
    
    atual = res[x*m + y];

    if(x > 0) antc = res[(x-1)*m + y];
    else antc = 0;

    if(x < n-1) proxc = res[(x+1)*m + y];
    else proxc = atual + 1;

    
    if(y > 0) antl = res[(x*m + y + 1];
    else antl = 0;

    if(y < m-1) proxl = res[x*m + y - 1];
    else proxl = atual + 1;
    

    if(atual < proxl && atual < proxc )


    retorno.first = 0;

    return retorno

}




int main(){
    int n, m, total = 0;
    int i, j;
    long long aux, atual, anterior, proxc, proxl, antc, antl;

    cin >> n >> m;

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> aux;
            res.push_back(aux);
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            atual = res[i*m + j];
            
            if(i < n-1) proxl = res[(i+1)*m + j];
            else proxl = 0;
            if(j < m-1) proxc = res[(i*m + j + 1)];           
            else proxc = 0;
            


            if(!atual){
                if(proxl && proxc) atual = min(proxl, proxc) - 1;
                else{
                    if(proxl) atual = proxl-1;
                    else atual = proxc-1;
                }

                if(i) antl = res[(i-1)*m + j];
                else antl = 0;
                if(j) antc = res[(i*m + j -1)];
                else antc = 0;

                if(atual > antl && atual > antc) total += atual;
                else {
                    cout << "-1"<< endl;
                    return 0;
                }
            }
            else{
                if((atual >= proxl && proxl) || (atual >= proxc && proxc)){
                    cout << "-1" << endl;
                    return 0;
                }
                else total += atual;
            }
            cout << atual << " ";

        }
        cout << endl;
    }
    cout << total << endl;

    return 0;
}


