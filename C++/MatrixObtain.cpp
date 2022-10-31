class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();
     for(int i=0;i<n;i++) for(int j=0;j<i;j++) swap(matrix[i][j],matrix[j][i]);    
     for(int i=0;i<n;i++) reverse(matrix[i].begin(),matrix[i].end()); 
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
     rotate(mat);
     for(int i=0;i<4;i++) 
        {
         rotate(mat);
         if(mat==target) return true;
        }   
     return false;
    }
};
