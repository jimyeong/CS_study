
#include<iostream>
#include<vector>

using namespace std;

class UnionQuickFind{
    public:
    UnionQuickFind(int size):connection(size){
        for(int i=0; i < size; i++){
            connection[i] = i;
        };
    };

    int quickFind(int node){
        return connection[node];
    };

    void unionSet(int x, int y){
        if(!connected(x, y)){
            //0 ,1
            int root_node = quickFind(y);
            connection[root_node] = quickFind(x);
            for(int i=0; i < connection.size(); i++){
                if(root_node == connection[i]) connection[i] = x; 
            }
        }
    };

    bool connected(int x, int y){
        return quickFind(x) == quickFind(y);
    }

    private:
    vector<int> connection;
};

int main(){
    int size = 7;
    UnionQuickFind uqf(size);
    uqf.unionSet(0, 1);
    uqf.unionSet(1, 3);
    uqf.unionSet(1, 4);

    uqf.unionSet(2, 5);
    uqf.unionSet(2, 6);
    cout << uqf.connected(2, 0) << endl;

    uqf.unionSet(0, 2); // which one should be root after merging
    
    cout << "connected node 0 with 2" << endl;
    cout << uqf.connected(2, 0) << endl;
    


    
    

    

    return 0;
}