#include <bits/stdc++.h>
using namespace std;

long long n, m, d;
pair<long long, long long> inicio, fim;
vector<pair<long long, long long>> pilha;
vector<int> res;



void printa(){
    long long i, j;
    cout << "----------------------" << endl;
    for(i = 0; i < n; i++){     
        for(j = 0; j < m; j++){
            cout << res[i*m + j] << " ";
            if(res[i*m+j] < 10 && res[i*m + j] >= 0) cout << " "; 
        }
        cout << endl;
    }
}

void posiciona(long long i, long long j, long long atual){
    res[i*m+j] = res[atual] + 1;
    pilha.push_back(make_pair(i, j));
    return;
}

long long desloca(long long i, long long j){
    if(i == fim.first && j == fim.second) return res[i*m + j];
    
    cout << "atual = (" <<i << ", " << j << ") - " <<res[i*m + j] << endl;
    printa();

    if(i > 0){
        cout << "tentando ("<<  i-1 << ", " << j<< ")\n";
        if (res[(i-1)*m + j] == 0) {
            cout <<"("<< i << ", " << j << ") deslocou para (" << i-1 << ", " << j <<")\n";
            posiciona(i-1, j, i*m+j);
            return desloca(i-1, j); 
        }
    }
    if(i < n-1){
        cout << "tentando ("<< i+1<< ", " << j<< ")\n";
        if(res[(i+1)*m + j] == 0){
            cout <<"("<< i << ", " << j << ") deslocou para (" << i+1 << ", " << j <<")\n";
            posiciona(i+1, j, i*m+j);  
            return desloca(i+1, j);
        } 
    }
    if(j > 0){
        cout << "tentando ("<< i << ", " << j-1<< ")\n";
        if(res[i*m + j-1] == 0) {
            cout <<"("<< i << ", " << j << ") deslocou para (" << i << ", " << j-1 <<")\n";
            posiciona(i, j-1, i*m+j);
            return desloca(i, j-1);
        }
    }
    if(j < m-1){
        cout << "tentando ("<< i<< ", " << j+1<< ")\n";
        if(res[i*m + j+1] == 0){
            cout <<"("<< i << ", " << j << ") deslocou para (" << i << ", " << j+1 <<")\n";
            posiciona(i, j+1, i*m+j);
            return desloca(i, j+1);
        } 
    }
    pair<long long, long long> e;
    pilha.pop_back();

    e = pilha[pilha.size()-1];
    cout << "removendo  da pilha (" << e.first << " , " << e.second << ")" << endl;;
    if(e.first != inicio.first && e.second != inicio.second) return desloca(e.first, e.second);
    return 0;

}

int anula(pair<long long, long long> ponto){
    long long i, j, x, y;
    long long maxi, maxj, mini, minj;
    x = ponto.first;
    y = ponto.second;

    mini = x - d;
    if(mini <= 0) mini = 0;
    else {
        res[mini*m + y] = -1; 
        mini++;
    }    

    minj = y - d;
    if(minj <= 0) minj = 0;
    else{
        res[x*m + minj] = -1;
        minj++;
    } 

    maxi = x + d;
    if(maxi >= n) maxi = n;
    else{
        res[maxi*m + y] = -1; 
        maxi--;
    } 

    maxj = y + d;
    if(maxj >= m) maxj = m;
    else{
        res[x*m + maxj] = -1;
        maxj--;
    } 

    for(i = mini; i <= maxi; i++){
        for(j = minj; j <= maxj; j++){
            if((inicio.first == i && inicio.second == j) || (fim.first == i && fim.second == j)) return 0;
            res[i*m + j] = -1;
        }
    }

    return 1;
}


int main(){
    long long i, j;
    char c;    
    vector<pair<long long, long long>> anular;

    cin >> n >> m >> d;



    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> c;
            res.push_back(0);

            if(c == 'M'){
                anular.push_back(make_pair(i, j));
                res[i*m + j] = -1;
            }
            if(c == 'S') {
                res[i*m + j] = 1;
                inicio.first = i;
                inicio.second = j;
            }
            else if(c == 'F'){
                fim.first = i;
                fim.second = j;
            }
        }
    }

    for(i = 0; i < anular.size(); i++){
        if(!anula(anular[i])){
            cout << "-1" << endl;
            return 0;
        }
    }
    printa();
    return 0;
    cout << desloca(inicio.first, inicio.second) - 1 << endl;
    return 0;
}