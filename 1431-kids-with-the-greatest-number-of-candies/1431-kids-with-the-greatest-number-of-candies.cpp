class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> result(n,false);
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            if(candies[i]>maximum){
                maximum=max(candies[i],maximum);
            }
        }
        for(int j=0;j<n;j++){
            if(candies[j]+extraCandies>=maximum){
                result[j]=true;
            }
        }
       return result; 
    }
};