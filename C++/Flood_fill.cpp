class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
     return (i>=0 && i<m && j>=0 && j<n);
    }
    
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,vector<vector<bool>> &vis)
    {
     int m = image.size();
     int n = image[0].size();   
     queue<pair<int,int>> q;
     q.push({sr,sc});
     vis[sr][sc] = true;
     int pc = image[sr][sc]; 
     image[sr][sc] = color;
     while(!q.empty())
       {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(isValid(r-1,c,m,n) && !vis[r-1][c] && image[r-1][c]==pc)
          {
           q.push({r-1,c}); 
           vis[r-1][c] = true; 
           image[r-1][c] = color;  
          }
        if(isValid(r+1,c,m,n) && !vis[r+1][c] && image[r+1][c]==pc)
          {
           q.push({r+1,c}); 
           vis[r+1][c] = true; 
           image[r+1][c] = color;  
          }  
        if(isValid(r,c-1,m,n) && !vis[r][c-1] && image[r][c-1]==pc)
          {
           q.push({r,c-1}); 
           vis[r][c-1] = true; 
           image[r][c-1] = color;  
          } 
        if(isValid(r,c+1,m,n) && !vis[r][c+1] && image[r][c+1]==pc)
          {
           q.push({r,c+1}); 
           vis[r][c+1] = true; 
           image[r][c+1] = color;  
          }
       }   
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int m = image.size();
     int n = image[0].size();
     vector<vector<bool>> vis(m,vector<bool>(n,false));
     bfs(image,sr,sc,color,vis);
     vis[sr][sc] = true;
     return image;   
    }
};
