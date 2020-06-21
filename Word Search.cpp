class Solution {
public:
    bool findFn(vector<vector<char>>& board,int i,int j,int k,string word)
    {
        if(k==word.size()) return true;
        
        if(i>0 && board[i-1][j]==word[k])
        {
            char x=board[i-1][j];
            board[i-1][j]='.';
            bool next=findFn(board,i-1,j,k+1,word); 
            if(next) return true;
            board[i-1][j]=x;
        }
        if(i+1<board.size() && board[i+1][j]==word[k])
        {
            char x=board[i+1][j];
            board[i+1][j]='.';
            bool next=findFn(board,i+1,j,k+1,word); 
            if(next) return true;
            board[i+1][j]=x;
        }
        if(j+1<board[i].size() && board[i][j+1]==word[k])
        {
            char x=board[i][j+1];
            board[i][j+1]='.';
            bool next=findFn(board,i,j+1,k+1,word); 
            if(next) return true;
            board[i][j+1]=x;
        }
        if(j>0 && board[i][j-1]==word[k])
        {
            char x=board[i][j-1];
            board[i][j-1]='.';
            bool next=findFn(board,i,j-1,k+1,word); 
            if(next) return true;
            board[i][j-1]=x;
        }
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {      
        
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0] )
                {
                    char x=board[i][j];
                    board[i][j]='.';
                    if(findFn(board,i,j,1,word)) return true;
                    board[i][j]=x;
                }
            }
        }
        return false;        
    }
};
