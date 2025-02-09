class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int size = words.size();
        int count = 0;
        for(int i=0; i<size-1; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            for(int j=i+1; j<size; j++){
                if(rev== words[j]){
                    count++;
                }
            }
        }
        return count;
    }
};