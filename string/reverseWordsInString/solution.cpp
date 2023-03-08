
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& s) 
    {
        reverse(s.begin(), s.end());
        int left =0, right = 0 , length = s.size();
        while(right < length){
            while(right < length && !isspace(s[right])) right++;
            reverse(s.begin()+left, s.begin() + right);
            left = ++right;
        }
    }
};