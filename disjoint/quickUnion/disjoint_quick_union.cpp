#include <vector>
#include <iostream>
using namespace std;

class UnionFind{
    private:
    vector<int> _root;

    public:
    int find(int node){
        while(_root[node] != node){
            node = _root[node];
        };
        return node;
    };

    void unionSet(int subject_node, int target_node){
        if(!isConnected(subject_node, target_node)){
            _root[find(subject_node)] = target_node;
        }
    };

    bool isConnected(int x, int y){
        // if they have the same root node
        return find(x) == find(y);
    }

    UnionFind(int size):_root(size){
        for(int i=0; i < size; i ++){
            _root[i] = i;
        }
    };
};


int main(){
    UnionFind uf(10);

    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);


    cout << uf.isConnected(1, 5) << endl;  // true
    cout << uf.isConnected(5, 7) << endl;  // true
    cout << uf.isConnected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.isConnected(4, 9) << endl;  // true

    return 0;
};