class Solution {
public:
vector<string>ans;
bool memo[100000];
void dfs(int idx,int n, string A,unordered_set<string>&myset,string sentence){
    if(idx==n){
        if(sentence.length() >= n)
        {
             sentence.pop_back();
             ans.push_back(sentence);
        }
        return;
    }
    if(memo[idx]==false)
        return;
        
    int lhs = ans.size();
    for(int i=idx;i<n;i++){
        string word = A.substr(idx,i-idx+1);
        if(myset.find(word)!=myset.end()){
            string x = sentence;
            x+=word;
            x+=" ";
            dfs(i+1,n,A,myset,x);
        }
    }
    int rhs = ans.size();
    if(lhs==rhs)
        memo[idx]=false;
}
vector<string> wordBreak(string A, vector<string> &B) {
    ans.clear();
    memset(memo,true,sizeof(memo));
    unordered_set<string>myset;
    for(int i=0;i<B.size();i++)
        myset.insert(B[i]);
    int n = A.size();
    string empty;
    dfs(0,n,A,myset,empty);
    return ans;
}


};
