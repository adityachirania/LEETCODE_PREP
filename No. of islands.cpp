class Solution {
public:
    //dfs,visited vector
    void dfs(vector<vector<char>>& grid,int x,int y,int n,int m)
    {
        grid[x][y] = '0';
        int inc_x[] = {1,-1,0,0};
        int inc_y[] = {0,0,1,-1};
        for(int i = 0; i < 4 ; i++ )
        {
            int nx = x+inc_x[i];
            int ny = y+inc_y[i];
            
            if(nx < 0 || nx >=n || ny <0 || ny >=m)
                continue;
            
            if(grid[nx][ny]=='0')continue;
            
            dfs(grid,nx,ny,n,m);
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        

        int n = grid.size();
        if(n==0)return 0;
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0;i < n; i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,n,m);
                    ans++;
                }
                    
            }
        }
        return ans;
        
        
        
    }
};
