class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int max=-1;
            for(int j=0;j<nums2.size();j++){
                int index=j;
                if(nums1[i]==nums2[j]){ 
                     while(index!=nums2.size()){ 
                        if(nums2[index]>nums1[i]){
                            max=nums2[index]; 
                            break;
                        }
                        index++;
                    }
               }
            }
            ans.push_back(max);
        }
        return ans;
    }
};