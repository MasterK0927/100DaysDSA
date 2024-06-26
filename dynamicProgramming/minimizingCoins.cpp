#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int minCoins(vector<int>& coins, int money, vector<int>& dp) {
    if (money == 0) return 0;
    if (money < 0) return INF; 
    if (dp[money] != -1) return dp[money];

    int result = INF;
    for (int coin : coins) {
        result = min(result, 1 + minCoins(coins, money - coin, dp));
    }
    
    dp[money] = result; 
    return dp[money];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1);
    int result = minCoins(coins, x, dp);

    if (result == INF) {
        cout << -1 << endl; 
    } else {
        cout << result << endl;
    }
}
