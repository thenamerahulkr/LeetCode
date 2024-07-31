// class Solution {
// public:
//     int divisorSubstrings(int num, int k) {
//         string str = to_string(num);
//         int n = str.length();
//         int ans = 0;
//         if(n==k) return 1;
//         string prev = "";
//         for (int i = 0; i < k; i++) {
//             prev += str[i];
//         }
//         int checker = stoi(prev);
//         if (num % checker == 0) {
//             ans++;
//         }
//         // string curr=prev;
//         int i = 1;
//         int j = k;
//         while (j < n) {
//             string curr = str.substr(i, );
//             int checker = stoi(prev);
//             if (num % checker == 0) {
//                 ans++;
//                 i++;
//                 j++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string x = to_string(num);
        int n = x.length();
        int ans = 0;
        for(int i = 0;i<=(n-k);i++){
            if(stoi(x.substr(i,k)) != 0)
            if(num % stoi(x.substr(i,k)) == 0 )
                ans++;
        }
        return ans;
    }
};