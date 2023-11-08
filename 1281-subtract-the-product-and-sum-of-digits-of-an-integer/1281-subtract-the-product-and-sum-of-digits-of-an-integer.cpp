class Solution {
public:
    int subtractProductAndSum(int n) {
//         let the product and sum variable given below
        int product=1,sum=0;
        int ans;
        while(n>0){
            int last=n%10;
            n=n/10;
            sum = sum+last;
            product = product*last;
        } 
        ans=product-sum;
        return ans;
    }
};