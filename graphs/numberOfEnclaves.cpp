//Approach 1
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        //declare a queue for storing the coords
        queue<pair<int,int>>q;
        //traversing through the boundaries
        for(int i=0; i<row; i++){
            //if top row is there, pushing to q and marking them visited
            if(grid[i][0]==1){
                q.push({i,0});
                //marking as visited
                grid[i][0]=0;
            }
            //checking for last row
            if(grid[i][col-1]==1){
                q.push({i,col-1});
                grid[i][col-1]=0;
            }
        }
        //traversing through the columns
        for(int j=0; j<col; j++){
            //checking the first column
            if(grid[0][j]==1){
                q.push({0,j});
                grid[0][j]=0;
            }
            //checking the last column
            if(grid[row-1][j]==1){
                q.push({row-1,j});
                grid[row-1][j]=0;
            }
        }
        //now we have the q filled with boundary nodes
        //now use the bfs technique and visit all the neighbours
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //declaring the traversal array
            int traversalArray[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
            //coords for traversal
            for(int i=0; i<4; i++){
                int dx = x+traversalArray[i][0];
                int dy = y+traversalArray[i][1];
                //now check for the boundary conditions as well the 1
                if(dx>=0 && dx<row && dy>=0 && dy<col && grid[dx][dy]==1){
                    q.push({dx,dy});
                    grid[dx][dy]=0;
                }
            }
        }
        //now calculate the rest nodes
        int count = 0;
        for(auto& i:grid){
            for(auto& j:i){
                if(j==1) count++;
            }
        }
        return count;
    }
};
