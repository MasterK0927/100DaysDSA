/*
In this question, we will be given a matrix like this
----------------------------------------------------
{
    [2, 1, 1],
    [0, 1, 1],
    [1, 0, 1],
}
----------------------------------------------------
1-> fresh orange, 2-> rotten ornage

-> one rotten orange can rott the adjacent fresh oranges as per this 
rottSteps={
    [0,0,1,-1],
    [1,-1,0,0],
}
So the idea is to traverse the whole matrix first, and keep a count of all the oranges (rotten+fresh)
and push the rotten orange in the queue<pair<int,int>>, using that queue, keep the count of total 
oranges and based on their count run a while loop, which will ensure that, while graph has any rotten
orange, the loop will keep running, while running, we will take the coordinates of the rotten orange
from the queue, and pops out the rotten orange from the queue. Then we will run the loop from 0 to 4,
where we will be checking for fresh orange at coordinateX+rottSteps[i] coordinate, if found fresh, we
will update its value to 2 and keep on doing so, until we get the count of rott oranges as 0. And if 
queue becomes empty, we will get out of the loop. While making the oranges rott, we will keep a time_taken
timer increasing too, after successful, while loop execution.
*/

#include <bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>>& grid){
    //if grid doesn't have any orange.
    if(grid.empty()) return 0;
    //number of columns
    int m=grid.size();
    //number of rows
    int n=grid[0].size();
    //variables for storing days and other things
    int days=0,total=0,cnt=0;
    //queue for storing the coordinates of rotten oranges
    queue<pair<int,int>>rotten;
    //iterating through the matrix and storing the rotten orange's coordinates
    for(int i=0; i<m; i++){
        for(int  j=0; j<n; j++){
            if(grid[i][j]!=0) total++;
            if(grid[i][j]==2) rotten.push({i,j});
        }
    }
    //array for traversing in four directions
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    //unless the queue is not empty traverse in it
    while(!rotten.empty()){
        //total amount of rotten oranges;
        int k = rotten.size();
        cnt+=k;
        //while there are rotten orange left, traverse;
        while(k--){
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                //agr boundary mai na rhe tb continue kr jao
                if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1) continue;
                //assign the rotten value to the rest oranges
                grid[nx][ny] = 2;
                //push this newly rotten orange in the queue
                rotten.push({nx,ny});
            }
        }
        if(!rotten.empty()) days++;
    }
    return total==cnt ? days : -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid {{2,1,1},{0,1,1},{1,0,1}};
    cout<<rottenOranges(grid);
    return 0;
}