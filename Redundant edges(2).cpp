class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N=edges.size();
        vector<int>res(2);
        vector<int>in(edges.size()+1);
        vector<int>v;
        bool hastwo=false;
        int two=-1; 
        for(vector<int>&p:edges){
            int v1=p[0];
            int v2=p[1];
            in[v2]++;
            if(in[v2]==2){
                two=v2;
                hastwo=true;
            }
        }
        for(int i=0;i<=N;i++)v.push_back(i);
        if(!hastwo){//use solution1 =>all have degree one=>cycle  
            for(vector<int>&pair:edges){
                int v1=pair[0];
                int v2=pair[1];
                int root1=find(v,v1);
                int root2=find(v,v2);
                if(root1!=root2){
                    v[root2]=root1;
                }else{
                    res[0]=v1;
                    res[1]=v2;
                    return res;
                }
            }
        }else{//some node has indegree 2
            for(vector<int>&pair:edges){
                int v1=pair[0];
                int v2=pair[1];
                if(v2==two){
                    res[0]=v1;
                    res[1]=v2;
                    // cout<<v1<<" "<<v2<<"\n";
                    if(!check(edges,v1,v2)){
                        return res;
                    }
                }
            }
        }
        return res;
    }
    
    bool check(vector<vector<int>>& edges,int vv1,int vv2){ //[not vv1,vv2]:edge to ignore
        int N=edges.size();
        vector<int>v;
        for(int i=0;i<=N;i++)v.push_back(i);
        for(vector<int>&pair:edges){
                int v1=pair[0];
                int v2=pair[1];
                if(v1!=vv1&&v2==vv2)continue;
                int root1=find(v,v1);
                int root2=find(v,v2);
                if(root1!=root2){
                    v[root2]=root1;
                }else{
                    return false;
                }
        }
        return true;
    }
    
    int find(vector<int>&A,int x){
        if(A[x]==x)return x;
        int root=find(A,A[x]);
        A[x]=root;
        return root;
    }
};
