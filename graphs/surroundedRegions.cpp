//Approach 1 (runtimeBeats->60% && memoryBeats->39%)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>>vis(row, vector<int>(col, 0));
        queue<pair<int, int>>q;
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (board[i][col - 1] == 'O' && !vis[i][col - 1]) {
                q.push({i, col - 1});
                vis[i][col - 1] = 1;
            }
        }
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if (board[row - 1][j] == 'O' && !vis[row - 1][j]) {
                q.push({row - 1, j});
                vis[row - 1][j] = 1;
            }
        }
        int traversalArray[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = x + traversalArray[i][0];
                int dy = y + traversalArray[i][1];
                if (dx >= 0 && dx < row && dy >= 0 && dy < col && board[dx][dy] == 'O' && !vis[dx][dy]) {
                    q.push({dx, dy});
                    vis[dx][dy] = 1;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

//Approach 2 (runtimeBeats->99.65% && memoryBeats->39%)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        for(int i=0; i<row; i++){
            if(board[i][0]=='O' && !vis[i][0]){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][col-1]=='O' && !vis[i][col-1]){
                q.push({i,col-1});
                vis[i][col-1]=1;
            }
        }
        for(int j=0; j<col; j++){
            if(board[0][j]=='O' && !vis[0][j]){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(board[row-1][j]=='O' && !vis[row-1][j]){
                q.push({row-1,j});
                vis[row-1][j]=1;
            }
        }
        int traversalArray[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int dx = x+traversalArray[i][0];
                int dy = y+traversalArray[i][1];
                if(dx>=0 && dx<row && dy>=0 && dy<col && board[dx][dy]=='O' && !vis[dx][dy]){
                    q.push({dx,dy});
                    vis[dx][dy]=1;
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};

//Approach 3 (runtimeBeats->73% && memoryBeats->73%)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        // vector<vector<int>>vis(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        for(int i=0; i<row; i++){
            if(board[i][0]=='O' && board[i][0]!='#'){
                q.push({i,0});
                board[i][0]='#';
            }
            if(board[i][col-1]=='O' && board[i][col-1]!='#'){
                q.push({i,col-1});
                board[i][col-1]='#';
            }
        }
        for(int j=0; j<col; j++){
            if(board[0][j]=='O' && board[0][j]!='#'){
                q.push({0,j});
                board[0][j]='#';
            }
            if(board[row-1][j]=='O' && board[row-1][j]!='#'){
                q.push({row-1,j});
                board[row-1][j]='#';
            }
        }
        int traversalArray[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int dx = x+traversalArray[i][0];
                int dy = y+traversalArray[i][1];
                if(dx>=0 && dx<row && dy>=0 && dy<col && board[dx][dy]=='O' && board[dx][dy]!='#'){
                    q.push({dx,dy});
                    board[dx][dy]='#';
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O' && board[i][j]!='#'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};

//Approach 4 (runtimeBeats->93% && memoryBeats->76%)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        // vector<vector<int>>vis(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        for(int i=0; i<row; i++){
            if(board[i][0]=='O' && board[i][0]!='#'){
                q.push({i,0});
                board[i][0]='#';
            }
            if(board[i][col-1]=='O' && board[i][col-1]!='#'){
                q.push({i,col-1});
                board[i][col-1]='#';
            }
        }
        for(int j=0; j<col; j++){
            if(board[0][j]=='O' && board[0][j]!='#'){
                q.push({0,j});
                board[0][j]='#';
            }
            if(board[row-1][j]=='O' && board[row-1][j]!='#'){
                q.push({row-1,j});
                board[row-1][j]='#';
            }
        }
        int traversalArray[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int dx = x+traversalArray[i][0];
                int dy = y+traversalArray[i][1];
                if(dx>=0 && dx<row && dy>=0 && dy<col && board[dx][dy]=='O' && board[dx][dy]!='#'){
                    q.push({dx,dy});
                    board[dx][dy]='#';
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O' && board[i][j]!='#'){
                    board[i][j]='X';
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

//Approach 5 (runtimeBeats->94% && memoryBeats->88%)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        // vector<vector<int>>vis(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        for(int i=0; i<row; i++){
            if(board[i][0]=='O' && board[i][0]!='#'){
                q.push({i,0});
                board[i][0]='#';
            }
            if(board[i][col-1]=='O' && board[i][col-1]!='#'){
                q.push({i,col-1});
                board[i][col-1]='#';
            }
        }
        for(int j=0; j<col; j++){
            if(board[0][j]=='O' && board[0][j]!='#'){
                q.push({0,j});
                board[0][j]='#';
            }
            if(board[row-1][j]=='O' && board[row-1][j]!='#'){
                q.push({row-1,j});
                board[row-1][j]='#';
            }
        }
        int traversalArray[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int dx = x+traversalArray[i][0];
                int dy = y+traversalArray[i][1];
                if(dx>=0 && dx<row && dy>=0 && dy<col && board[dx][dy]=='O' && board[dx][dy]!='#'){
                    q.push({dx,dy});
                    board[dx][dy]='#';
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};