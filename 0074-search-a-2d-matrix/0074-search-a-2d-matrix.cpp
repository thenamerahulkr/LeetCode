class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m= mat.size();//3
        int n= mat[0].size();//4
        int flag=0;

        for(int i=0;i<m;i++){ 
            if(t <= mat[i][n-1]){ 
                for(int j=0;j<n;j++){ 
                    if(mat[i][j]== t){ 
                      return true;  
                      flag=1;
                    }
                    
                }
                if(flag==0)
                return false;
            }

        }
        return false;

    }
};