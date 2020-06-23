class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void makeSet(int n){
        parent[n] = n;
        size[n] = 1;
    }
    
    int findSet(int v){
        if(parent[v] == v)  return v;
        else    return parent[v] = findSet(parent[v]);
    }
    
    void makeUnion(int a, int b){
        a = findSet(a);
        b = findSet(b);
        if(a != b){
            if(size[b] > size[a]){
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0;i<edges.size() + 1;i++){
            parent.push_back(-1);
            size.push_back(0);
        }
        for(int i = 1;i<=edges.size();i++){
            makeSet(i);
        }
        vector<int> result;
        for(vector<int> e : edges){
            int a = e[0];
            int b = e[1];
            parent[a] = findSet(a);
            parent[b] = findSet(b);
            // cout <<parent[a]<<' '<<parent[b]<<endl;
            if(parent[a] == parent[b]){
                result = {a, b};
                return result;
            }
            makeUnion(a, b);
        }
        return result;
    }
};
