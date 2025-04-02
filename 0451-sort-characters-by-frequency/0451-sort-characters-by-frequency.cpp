class Solution {
public:
    string frequencySort(string s) {
        // first will store the frequency and second one will store the char
        unordered_map<char,int> freq;
        //build the frequency map 
        for(auto ch: s){
            freq[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        // now traverse into map 
        for(auto& [ch,f]:freq){
            pq.push({f,ch});
        }
        string answer = "";
        // now on heap 
        while(pq.size()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            answer.append(freq,ch);
        }
        return answer;
    }
};