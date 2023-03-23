#include <stack>
#include <utility>

using namespace std;


int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int, int>> st;
        const int y = grid.size();
        const int x = grid[0].size();
        int isVisited[301][301] = {0,};
        int ans = 0;
        for(int i =0; i < y; i++){
            for(int j=0; j < x; j++){
                if(isVisited[i][j] == 1) continue;
                if(grid[i][j] == '0')continue;
                visitLands(grid, isVisited, st, i, j);
                isVisited[i][j] = 1;
                ans++;
            }
        };
        return ans;
    }
    void visitLands(vector<vector<char>>& grid, int (&isVisited)[301][301], stack<pair<int, int>> &st, int start_y, int start_x){
        st.push({start_y, start_x});
        int y_length = grid.size();
        int x_length = grid[0].size();
       
        while(!st.empty()){
            int y = st.top().first;
            int x = st.top().second;
            isVisited[y][x] = 1; // time consuming,, 
            
            st.pop();
            for(int i=0; i < 4; i++){
                int next_y = y + dy[i];
                int next_x = x + dx[i];
                if(next_y >= y_length || next_y <= -1) continue;
                if(next_x >= x_length || next_x <= -1) continue;
                if(isVisited[next_y][next_x] == 1) continue;
                if(grid[next_y][next_x] == '0') continue;
                st.push({next_y, next_x});
                
                
            }
        }
    }
};