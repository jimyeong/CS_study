
#include <vector>
using namespace std;

// idea: contain means getting narrow, if you start from narrowed bit, then it will automatically satisfy the bigger bit

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int isVisited[501][501] = {0,};
        int y_length = grid1.size();
        int x_length = grid1[0].size();
        int count = 0;

        for(int i=0; i < y_length; i++){
            for(int j=0; j < x_length; j++){
                if(grid2[i][j] == 1 && isVisited[i][j] == 0 && dfs(grid1, grid2, isVisited, y_length, x_length, i, j))count++;
                
            }
        };
        
        return count;
    };

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>> &grid2, int (&isVisited)[501][501], int y_length, int x_length, int y, int x){
        if(x >= x_length || x <= -1) return true;
        if(y >= y_length || y <= -1) return true;
        if(grid2[y][x] == 1 && grid1[y][x] != grid2[y][x]) {
            return false;
        };
        
        if(isVisited[y][x] == 1 || grid2[y][x] == 0) return true;
        isVisited[y][x] = 1;
        bool isClosed = true;
        for(int i=0; i < 4; i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            if(!dfs(grid1, grid2,isVisited, y_length, x_length, next_y, next_x)){
                isClosed = false;
            };
        };
        return isClosed;
    }
};