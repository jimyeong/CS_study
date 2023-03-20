#include <string>
using namespace std;

class Solution {
private:
    void reverse(string &s, int i, int j){
        while(i<j){
          char temp=s[i];
          s[i++]=s[j];
          s[j--]=temp;
        }
    }
public:
    string reverseWords(string &s) {
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        while(true){
            while(i<len && s[i] == ' ') i++;
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverse(s,l,j-1);                
            wordcount++;   
        }
        s.resize(j);                           
        reverse(s,0,j-1);  
        return s;        
    }
};