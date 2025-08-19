class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int left = 0;
        int right = n - 1;
        // for(int i = 0; i < n; i++){
            
        // }
        while(left <= right){
            // score badhao if power > tokens[i];
            if(power >= tokens[left]){
                power -= tokens[left];
                score++;
                left++;
            }

            //score ghata ke power le lo
            else if(score > 0 and left < right){
                power += tokens[right];
                score--;
                right--;
            }
            else{
                break;
            }
        }
        return score;
    }
};