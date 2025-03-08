class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int answer = k;
        int count_white = 0;
        for(int i = 0; i<k; i++){
            if(blocks[i]=='W') count_white++;
        }
        answer = count_white;
        for(int i = k; i<blocks.length(); i++){
            if(blocks[i]=='W') count_white++;
            if(blocks[i-k]=='W') count_white--;
            answer = min(answer, count_white);
        }
        return answer;
    }
};