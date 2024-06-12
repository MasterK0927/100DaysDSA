#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& grid, int n, int m){
    if(n==0 && m==0) return grid[0][0];
    if(n<0 || m<0) return 1e9;
    int up = grid[n][m]+minimumPathSum(grid, n-1, m);
    int down =grid[n][m]+minimumPathSum(grid,n,m-1);
    return min(up,down);
    }

int main() {
    vector<vector<int>> grid {
        {5,9,6},
        {11,5,2}
    };
    int n = grid.size(); int m = grid[0].size();
    int result = minimumPathSum(grid, n-1, m-1);
    cout<<result;
    return 0;
}