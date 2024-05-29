/*
Given an integer array coint, which shows the coins of different denominations and an integer amount.
Coins can be used any number of times.
Return all possible ways for determining the amount.
*/

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount, int index, vector<vector<int> >& dp){
    //base cases
    //amount becomes zero i.e. its possible to make amount from coins
    if(amount==0) return 1;
    //amount becomes negative i.e. not possible to make amount from coins
    //and the case when index reaches dead end i.e. coins.size() whole array is traversed
    if(amount<0 || index==coins.size()) return 0;
    //if already calculated
    if(dp[index][amount]!=-1) return dp[index][amount];
    //main recurrence, its a pick and not pick approach
    //pick, if we have the ideal case of amount==0 so pick the element
    int pick = coinChange(coins,amount-coins[index], index,dp);
    //not pick, if we have the case of amount!=0 so not pick and just iterate over to next
    int notPick = coinChange(coins,amount,index+1, dp);
    //store the final ans as dp state
    return dp[index][amount]=pick+notPick;
}

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    int amount;
    cin>>amount;
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    //dp state array will be a matrix having 2 variables because 2 things are changing
    //amount, after subtracting coins[i]
    //size, after subtracting checking whether array is traversed or not
    vector<vector<int> >dp(n,vector<int>(amount+1,-1));
    cout<<coinChange(coins,amount,0,dp);
}