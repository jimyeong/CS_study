#include <vector>
#include <utility>
#include <queue>
using namespace std;


int dy[4] = {1,0, -1, 0};
int dx[4] = {0,1, 0, -1};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int y_length = mat.size();
        int x_length = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(y_length, vector<int>(x_length, -1));
        for(int i=0; i < y_length; i++){
            for(int j=0; j < x_length; j++){
                if(mat[i][j] == 0 ){
                    q.push({{i,j}, 0});
                }
            }
        }

        
        while(!q.empty()){
            int y = q.front().first.first;
            int x = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            if(ans[y][x] != -1) continue; // it's because it's bfs
            ans[y][x] = distance;
            for(int i=0; i < 4; i++){
                int next_y = y + dy[i];
                int next_x = x + dx[i];
                if(next_y >= y_length || next_y <= -1) continue;
                if(next_x >= x_length || next_x <= -1) continue;
                if(ans[next_y][next_x] < 0) q.push({{next_y, next_x}, distance + 1});
                
                
                
            }
        }
        return ans;
    };
};