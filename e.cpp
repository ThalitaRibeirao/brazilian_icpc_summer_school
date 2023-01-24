#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x, y, a, b, c;
    long long int i, aux, total = 0;
    long long int A, B, C;
    vector<long long int> red, green, transp;
    
    cin >> x >> y >> a >> b >> c;

    for(i = 0; i < a; i++){
        cin >> aux;
        red.push_back(aux);
    }
    sort(red.begin(), red.end());

    for(i = 0; i < b; i++){
        cin >> aux;
        green.push_back(aux);
    }
    sort(green.begin(), green.end());

    for(i = 0; i < c; i++){
        cin >> aux;
        transp.push_back(aux);
    }
    sort(transp.begin(), transp.end());

    A = red.back();
    B = green.back();
    C = transp.back();

    while(x || y){
        if(A >= B && A >= C){
            if(x){
                total += A;
                x--;
                red.pop_back();
                if(red.size()) A = red.back();
                else A = -1;
            }
            else A = -1;
        }
        else if (B >= C && B >= A){
            if (y){
                total += B;
                y--;    
                green.pop_back();

                if(green.size()) B = green.back();
                else B = -1;
            }
            else B = -1;       

        }
        else if (C >= A && C >= B){
            total += C;
            transp.pop_back();
            if(transp.size()) C = transp.back();
            else C = -1;

            if(x && B > A){
                red.pop_back();
                x--;
            }
            else if (y){
                green.pop_back();
                y--;
            }
        }

    }

    cout << total << "\n";
    return 0;
}