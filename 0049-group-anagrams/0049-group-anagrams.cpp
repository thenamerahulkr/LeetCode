class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        for(int i=0; i<n; i++){
            string str = strs[i];
            string s = strs[i];
            sort(s.begin(),s.end());
            if(mp.find(s) == mp.end()){
                vector<string> v;
                v.push_back(str);
                mp[s] = v;
            }
            else{
                mp[s].push_back(strs[i]);
            }
        }
        for(auto ele: mp){
            // vector<string> v = ele.second;
            ans.push_back(ele.second);
        }
        return ans;
    }
};