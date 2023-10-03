class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int noz=0;
        int noo=0;
        int notwos=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                noz++;
            }
            else if(nums[i]==1){
                noo++;
            }
            else{
                notwos++;
            }
        }
        //filling the elements
        for(int i=0;i<noz;i++){
                nums[i]=0;
        }
        for(int i=noz;i<noo+noz;i++){
                nums[i]=1;
        }
        for(int i=noo+noz;i<n;i++){
                nums[i]=2;
        }
    }
};
