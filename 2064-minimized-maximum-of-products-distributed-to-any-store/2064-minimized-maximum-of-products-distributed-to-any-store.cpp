class Solution {
public:
    // kya mid number of itens dena possible h under given number of shops
    bool can_distribute(int shops, vector<int>& quantities, int items_q){
        int n = quantities.size();
        int kitneShops = 0;
        for(int i = 0; i < n; i++){
           kitneShops += (quantities[i] + items_q - 1) / items_q;
        }
        return kitneShops <= shops;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int sz = quantities.size();
        
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int answer = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(can_distribute(n, quantities, mid)){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return answer;
    }
};