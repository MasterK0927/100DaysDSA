#include <bits/stdc++.h>
using namespace std;

int coinCombination(vector<int>& coins, int x, vector<int>& dp){
    if(x==0) return 1;
    if(x<0) return 0;
    if(dp[x]!=-1) return dp[x];
    int result = 0;
    for(int coin:coins){
        result += coinCombination(coins,x-coin,dp);
    }
    dp[x] = result;
    return dp[x];
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    vector<int>dp(x+1, -1);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    cout<<coinCombination(coins,x,dp);
    return 0;
}