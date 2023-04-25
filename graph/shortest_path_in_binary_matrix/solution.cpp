#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int y_length = grid.size();
        int x_length = grid[0].size();
        vector<vector<int>> steps(y_length, vector<int>(x_length, 0));
        queue<pair<int, int>> q;
        if(grid[0][0] != 0) return -1;
        
        q.push({0,0});
        steps[0][0] = 1;
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            grid[y][x] = 1;
            q.pop();
            for(int i=0; i < 8; i++){

                int next_y = y + dy[i];
                int next_x = x + dx[i];

                if(next_y >= y_length || next_y <= -1) continue;
                if(next_x >= x_length || next_x <= -1) continue;
                if(grid[next_y][next_x] == 1) continue;
                // if(steps[next_y][next_x] > 0) continue;

                q.push({next_y,next_x});
                grid[next_y][next_x] = 1;
                
                int k =steps[next_y][next_x];
                int next_step =steps[y][x] + 1;
                if(k != 0){
                    if(next_step > k) steps[next_y][next_x] = k;
                    if(next_step <= k) steps[next_y][next_x] = next_step;
                }else{
                    steps[next_y][next_x] = next_step;
                }
                
            }
        };

        int ans = steps[y_length-1][x_length-1];
        return ans == 0 ? -1 : ans;



        
    };
};