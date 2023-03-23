#include<stack>
#include<utility>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        stack<pair<int, int>> st;
        int visitedMap[51][51] = {0, };
        int y_length = grid.size();
        int x_length = grid[0].size();
        int area = 0;
        for(int i=0; i < y_length; i++){
            for(int j=0; j < x_length; j++){
                if(grid[i][j] == 1 && visitedMap[i][j] == 0){
                    int new_area = exploreIsland(grid, visitedMap, st, i, j);
                    if(area <= new_area) area = new_area;
                }
            }
        }
        return area;
    }
    int exploreIsland(vector<vector<int>>& grid, int (&visitedMap)[51][51], stack<pair<int, int>> &st, int start_y, int start_x){
        int area = 0;
        st.push({start_y, start_x});

        while(!st.empty()){
            int cur_y = st.top().first;
            int cur_x = st.top().second;
            if(visitedMap[cur_y][cur_x] == 1){
                st.pop();
                continue;
            };
            
            area++;
            visitedMap[cur_y][cur_x] = 1;
            st.pop();
        
            for(int i=0; i < 4; i++){
                int next_y = cur_y + dy[i];
                int next_x = cur_x + dx[i];
                if(next_y >= grid.size() || next_y <= -1) continue;
                if(next_x >= grid[0].size() || next_x <= -1) continue;
                if(visitedMap[next_y][next_x]==1) continue;
                if(grid[next_y][next_x] == 0) continue;
                st.push({next_y, next_x});
            }
        }
        return area;
    }
};