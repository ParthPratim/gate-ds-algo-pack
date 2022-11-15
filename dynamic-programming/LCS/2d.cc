#include <bits/stdc++.h>
using namespace std;

int main(){
    string s , t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = n-1; i >= 0 ; i--){
        for(int j = m-1; j >=0 ; j--){
            // i is ptr of string s
            // j is ptr of string t
            if(s[i] == t[j]){
                dp[i][j] = dp[i+1][j+1] + 1; 
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout << "Maximum LCS Length : " << dp[0][0] << "\n";

    return 0;
}