class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

    int j= accounts.size() ;
    int max =0;
    for(int i=0 ;i<j ;i++){
        int sum = 0 ;
     for(int a=0;a<accounts[i].size() ;a++){
            sum = sum+accounts[i][a];
      }
      if(sum>max){max=sum;}  
    }
    return max;
}
};