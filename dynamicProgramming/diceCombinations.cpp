#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int diceCombinations(int n, vector<int>& dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ways = 0;
    for(int i=1; i<=6; i++){
        ways = (ways + diceCombinations(n-i, dp))%MOD;
    }
    dp[n] = ways;
    return dp[n];
}

int main(){
    int n; 
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<diceCombinations(n,dp);
}