class Solution {
public:
    int minChanges(int n, int k) {
        int ans=0;
        for(int i=0;i<50;i++){
            if(n%2!=k%2){
                if(n%2==1)ans++;
                else return -1;
            }
            n/=2;
            k/=2;
        }
        return ans;
    }
};