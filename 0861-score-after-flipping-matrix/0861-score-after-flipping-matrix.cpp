class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            if(grid[i][0]==0){
                for(int j=0;j<cols;j++){
                       if(grid[i][j]==0) grid[i][j]=1;
                       else grid[i][j]=0;
                    }
                }
            }
     for(int j=0;j<cols;j++){       
        int noz=0;
        int no1=0;
        for(int i=0;i<rows;i++){
            if(grid[i][j]==0) noz++;
            else no1++;
        }
        if(noz>no1){
            for(int i=0;i<rows;i++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
     }
     int sum1=0;
     for(int i=0;i<rows;i++){
     int x=1;
         for(int j=cols-1;j>=0;j--){
                 sum1=sum1+grid[i][j]*x;
                 x=x*2;
         }
     }
     return sum1;
    }
};
