class Solution {
public:
    bool kya_sab_car_dho_payega(vector<int>& ranks, int cars, long long given_time){
        long long number_of_car = 0;
        for(int i = 0; i < ranks.size(); i++){
            number_of_car += sqrt(given_time/ (long long)ranks[i]);
        }
        if(number_of_car>= cars) return true;
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        
        long long n = ranks.size();
long long low = 1;
long long max_ele = *max_element(ranks.begin(), ranks.end());
long long x = (long long)cars;
long long high = max_ele * x * x; 
long long answer = high;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(kya_sab_car_dho_payega(ranks, cars, mid)){
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