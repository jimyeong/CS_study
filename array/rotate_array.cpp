#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> copynumb(length);
        for(int i=0; i < length; i++) copynumb[i] = nums[i];
        for(int i=0; i < length; i++){
            nums[ (i + k) % length] = copynumb[i];
        }
    }
    

};