#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, n, t;
    int i, j, max, x, y, v;
    vector<int> left, right, preenc;

    cin >> t;

    for(j = 0; j < t; j++){
        cin >> n >> a >> b;
        
        y = (a - 1);
        if(y < b) y++;
        x = (n - b);
        if(n - a > x) x++;

        if(x > n/2 || y > n/2) cout << -1 << endl;
        else {
            if(left.size() > 0) left.clear();
            if(right.size() > 0) right.clear();
            if(preenc.size() > 0) preenc.clear();

            for(i = 1; i <= n; i++){
                if(i > b || i == a) left.push_back(i);
                else if(i < a || i == b) right.push_back(i);
                else preenc.push_back(i);
            }

            for(i = 0; i < left.size(); i++) cout << left[i] << " ";
            for(i = 0; i < preenc.size(); i++) cout << preenc[i] << " ";
            for(i = 0; i < right.size(); i++) cout << right[i] << " ";
            cout << endl;
        }
    }
    return 0;
}