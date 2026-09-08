class Solution {
public:
    // --> i have to find the longest chain right and we have have to take care of order so that we can sort the array and then try to form the chain --> this question is a variation of lis just we have to form the longest chain jaise lis me krte the okay na 
    int longestChain(vector<vector<int>>& pairs){
        // O(n^2);
        int n = pairs.size();
        vector<int> lis(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        return longestChain(pairs);
    }
};