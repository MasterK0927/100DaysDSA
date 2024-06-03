#include <bits/stdc++.h>
using namespace std;

int traversalArray[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int iniColor, int finalColor){
    if(image[sr][sc]!=iniColor || ans[sr][sc]==2) return;
    ans[sr][sc]=2;
    for(int i=0; i<4; i++){
        int x = sr + traversalArray[i][0]; int y = sc + traversalArray[i][1];
        if(x>=0 && x<ans.size() && y>=0 && y<ans[0].size()){
            dfs(image,ans,x,y,iniColor,finalColor);
        }     
    }
}

vector<vector<int>>floodFill(vector<vector<int>>& image, int sr, int sc){
    if(sr<0 && sc<0 && sr>=image.size() && sc>=image[0].size()) return image;
    int iniColor = image[sr][sc];
    int finalColor = 2;
    vector<vector<int>>ans = image;
    dfs(image,ans,sr,sc,iniColor,finalColor);
    return ans;
}

int main(){
    vector<vector<int>>image = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    int sr=1,sc=1;
    vector<vector<int>> ans = floodFill(image,sr,sc);
    for(auto& i:ans){
      for(auto& j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}