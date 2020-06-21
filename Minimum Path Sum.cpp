class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int columns = grid[0].size();
        
        for(int i = 0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                int upx = i - 1;
                int backy = j - 1;
                if(upx>=0 && backy<0)
                {
                    grid[i][j] += grid[upx][j];
                }
                else if(upx<0 && backy>=0)
                {
                    grid[i][j] += grid[i][backy];
                }
                else if(upx>=0 && backy>=0)
                {
                    grid[i][j] += min(grid[i][backy],grid[upx][j]);
                }
                
            }
        }
        
        return grid[rows-1][columns-1];
        
    }
};
