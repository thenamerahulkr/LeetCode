
class Solution {
public:
    int minimumPushes(string word) {
        // int n = word.length();
        // if(n <= 8) return n;
        // else if(n <= 16 and n > 8) return 8 + (n-8) * 2;
        // else if(n > 16 and n <= 24) return 24 + (n - 16) * 3;
        // else{
        //     return 48 + (n - 24) * 4;
        // }
        // return -1;
        int n = word.length();
        map<char, int> mp;
        for(auto &ch : word){
            mp[ch]++; 
        }

        // map ready hai
        int m = mp.size();
        int totalPushes = 0;
        for (int i = 0; i < m; i++) {
            int pushesPerPress = (i / 8) + 1; // 0-7: 1, 8-15: 2, 16-23: 3, 24+: 4
            totalPushes += pushesPerPress;
        }

        return totalPushes;
    }
};