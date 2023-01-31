#include <bits/stdc++.h>
using namespace std;
string s;
long change = 0;
int alt = 0;

int palindrome(int i, int j){
    if(i >= j) return 1;
    if(s[i] == s[j]) return(palindrome(i+1, j-1));
    if(!alt++) {
        if(palindrome(i+1, j)) {
            change = i+1;
            return 1;
        }
        else if (palindrome(i, j-1)){
            change = j+1;
            return 1;
        }
    }
    return 0;
    
} 
int main(){
    int result;
    cin >> s;
    result = palindrome(0, s.size() -1);

    if(result){
        cout << "YES" << endl;
        if(alt) cout << change << endl;
        else cout << s.size()/2 +1 << endl;
    }
    else cout << "NO" << endl;
    return 0;
}