
#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
    private:
    vector<int> root;
    public:

    int find(int node){        
        while(node != root[node]){
            node = root[node];
        }
        return node;
    }
    void unionSet(int nodeA, int nodeB){
        int root_a = find(nodeA);
        int root_b = find(nodeB);
        if(root_a!=root_b) root[root_b] = nodeA;
    };

    bool connected(int x, int y){
        if(find(x)!=find(y)) return false;
        return true;
    }
    UnionFind(int size): root(size){
        for(int i =0; i < size; i++){
            root[i] = i;
        };
    }
}

int main(){
    return 0;
}