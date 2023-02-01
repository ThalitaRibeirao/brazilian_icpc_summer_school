#include <bits/stdc++.h>
using namespace std;
long long n;
vector<pair<long long, long long>> edges;
vector<int> consultas;

long long len_tree(long long value, long long len){
    long long i;
    
    for(i = 0; i < n - 1; i++){
        if(edges[i].first == value && !consultas[i]){

            consultas[i]++;
            return len_tree(edges[i].second, len+1);
        } 
        else if(edges[i].second == value && !consultas[i]){
            consultas[i]++;
            return len_tree(edges[i].first, len+1);
        }
    }
    return len;
}




long long tree(long long pos){
    long long i, aux=1;

    if(consultas.size() > 0) consultas.clear();
    for(i = 0; i < n - 1; i++) consultas.push_back(0);


    while(1){
        aux = len_tree(pos, 0);
        if(!aux) break;
        if(aux+1 < n/2) return 0;
    }    
    return 1;
}




int main(){
    long long i, j, a, b;    
    cin >> n;

    for (i = 0; i < n-1; i++){
        cin >> a >> b;
        if(a < b) edges.push_back(make_pair(a-1, b-1));
        else edges.push_back(make_pair(b-1, a-1));
    }
    

    for(i = 0; i < n; i++){
        if(tree(i)){
            cout << i+1 << endl;
            break;
        } 
    }
    return 0;
}