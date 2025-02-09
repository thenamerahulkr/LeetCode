class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int size = arr.size();
        int count = 0;
        unordered_set<string> s;
        for(int i=0; i<size; i++){
            s.insert(arr[i]);
        }
        for(int i=0; i<size; i++){
            string rev = arr[i];
            reverse(rev.begin(), rev.end());
            if(rev == arr[i]){
                continue;
            }
            if(s.find(rev) != s.end()){
                count++;
                s.erase(arr[i]);
            }
        }
        return count;
    }
};