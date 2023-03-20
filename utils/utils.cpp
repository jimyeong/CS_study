#include <iostream>
using namespace std;

class Utils {
    public: 
        void reverse_string(string &s, int left, int right){
            while(left < right){
                char temp = s[left];
                s[left++] = s[right];
                s[right--] = temp;
            }
        };
};


int main(){
    return 0;
}