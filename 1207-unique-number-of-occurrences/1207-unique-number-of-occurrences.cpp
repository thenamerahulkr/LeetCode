class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        int n =arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto x: mp){
            int y = x.second;
            if(st.find(y)!= st.end()){
                return false;
            }
            else{
                st.insert(y);
            }
        }
        return true;
    }
};