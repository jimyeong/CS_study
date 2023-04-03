
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

#include <vector>
#include <utility>

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int isVisited[501][501] = {0,};
        int y_length = grid.size();
        int x_length = grid[0].size();
        int count = 0;
        for(int i=0; i < y_length; i++){
            for(int j=0; j < x_length; j++){
                if(grid[i][j] == 1 && isVisited[i][j] == 0){

                    pair<bool, int> result = dfs(grid, isVisited, y_length, x_length, i, j, count);
                    if(result.first){
                        count = result.second;
                    }
                }
            }
        }
        return count;
    };
    pair<bool, int> dfs(vector<vector<int>> & grid, int (&isVisited)[501][501], int y_length, int x_length, int y, int x, int count){
        if(x >= x_length || x <= -1) return {false, 0};
        if(y >= y_length || y <= -1) return {false, 0};

        if(isVisited[y][x] == 1 || grid[y][x] == 0) return {true, count};
        
        isVisited[y][x] = 1;
        count++;
        int isClosed = true;
        
        for(int i=0; i< 4;i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            pair <bool, int> result = dfs(grid, isVisited, y_length, x_length, next_y,next_x, count);
            count = result.second;
            if(!result.first){
                isClosed= false;
            }
        };
        return {isClosed, count};
    };
};