
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int y_length = heights.size();
        int x_length = heights[0].size();
        vector<vector<bool>> pacific_map(y_length, vector<bool>(x_length));
        vector<vector<bool>> atlantic_map(y_length, vector<bool>(x_length));
        vector<vector<int>> ans;
        for(int i=0; i < y_length; i++){
            dfs(pacific_map, heights, y_length, x_length, i, 0);
            dfs(atlantic_map, heights, y_length, x_length, i, x_length-1);
        };
        for(int i=0; i < x_length; i++){
            dfs(pacific_map, heights, y_length, x_length, 0, i);
            dfs(atlantic_map, heights, y_length, x_length, y_length-1, i);
        };

        for(int i=0; i < y_length; i++){
            for(int j=0; j < x_length; j++){
                if(pacific_map[i][j] && atlantic_map[i][j]) ans.push_back({i, j});
            };
        };
        return ans;
    }
    void dfs(vector<vector<bool>> &ocean_map,vector<vector<int>> &height, int y_length, int x_length, int y, int x){
        if(ocean_map[y][x] == true) return;
        ocean_map[y][x] =true;
        if(y+1 < y_length && height[y+1][x] >= height[y][x] && ocean_map[y+1][x] == 0){
            dfs(ocean_map, height, y_length, x_length, y+1, x);
        };

        if(x+1 < x_length && height[y][x+1] >= height[y][x] && ocean_map[y][x+1] == 0){
            dfs(ocean_map, height, y_length, x_length, y, x+1);
        };
        if(y-1 > -1 && height[y-1][x] >= height[y][x] && ocean_map[y-1][x] == 0){
            dfs(ocean_map, height, y_length, x_length, y-1, x);
        };
        if(x-1 > -1 && height[y][x-1] >= height[y][x] && ocean_map[y][x-1] == 0){
            dfs(ocean_map, height, y_length, x_length, y, x-1);
        };
    };
};