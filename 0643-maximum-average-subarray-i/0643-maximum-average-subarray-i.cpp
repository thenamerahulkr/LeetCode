class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double prevSum=0;
        for(int i =0;i<k ;i++){
            prevSum += nums[i];
        }
        double mx=prevSum;
        int i = 1;
        int j=k;
        while(j<n){
            double currSum=prevSum+nums[j]-nums[i-1];
            mx=max(currSum,mx);
            prevSum=currSum;
            i++;
            j++;
        }
        return mx/double(k);
    }
};