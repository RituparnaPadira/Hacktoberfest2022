class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
     if(i>=0 && i<n && j>=0 && j<m) return true;
     return false;
    }
  
    void bfs(vector<vector<char>> grid,int i,int j,vector<vector<bool>> &vis)
    {
     int n = grid.size();
     int m = grid[0].size();   
     queue<pair<int,int>> q;
     q.push({i,j});
     vis[i][j] = true;
     while(!q.empty())
        {
         int r = q.front().first;
         int c = q.front().second;
         q.pop();
         if(isValid(r+1,c,n,m) && !vis[r+1][c] && grid[r+1][c]=='1') 
           {
            q.push({r+1,c});
            vis[r+1][c] = true;
           }
         if(isValid(r-1,c,n,m) && !vis[r-1][c] && grid[r-1][c]=='1') 
           {
            q.push({r-1,c});
            vis[r-1][c] = true;
           }
         if(isValid(r,c+1,n,m) && !vis[r][c+1] && grid[r][c+1]=='1') 
           {
            q.push({r,c+1});
            vis[r][c+1] = true;
           }  
         if(isValid(r,c-1,n,m) && !vis[r][c-1] && grid[r][c-1]=='1') 
           {
            q.push({r,c-1});
            vis[r][c-1] = true;
           }  
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
     int n = grid.size();
     int m = grid[0].size();
     vector<vector<bool>> vis(n,vector<bool>(m,false));
     int a = 0;
     for(int i=0;i<n;i++)
        {
         for(int j=0;j<m;j++)
            {
             if(!vis[i][j] && grid[i][j]=='1')
               {
                bfs(grid,i,j,vis);
                vis[i][j] = true;
                a++;
               }
            }
        }
     return a;   
    }
};
