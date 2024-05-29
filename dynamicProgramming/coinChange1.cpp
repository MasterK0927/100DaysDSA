/*
Minimum number of coins required to give the amount
Can use the coins unlimited number of times
Similar to bestSum from ALvin's DP lectures
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChange(int amount, vector<int>& coins, vector<int>& memo) {
    //base case
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;
    if (memo[amount] != -1) return memo[amount];
    
    int mini = INT_MAX;
    //not of the pattern of pick and not pick, rather its a simple approach
    for (int i = 0; i < coins.size(); i++) {
        int remAmount = amount - coins[i];
        int res = coinChange(remAmount, coins, memo);
        if (res != INT_MAX) {
            mini = min(mini, res + 1);
        }
    }
    
    memo[amount] = mini;
    return mini;
}

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    vector<int> memo(amount + 1, -1);
    int result = coinChange(amount, coins, memo);

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
