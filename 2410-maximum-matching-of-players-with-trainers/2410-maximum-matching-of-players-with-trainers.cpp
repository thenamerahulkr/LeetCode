class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ptr1 = 0;
        int ptr2 = 0;
        int total = 0;
        while(ptr1<players.size() and ptr2<trainers.size()){
            if(trainers[ptr2]>=players[ptr1]){
                ptr1++;
                ptr2++;
                total++;
            }
            else{
                ptr2++;
            }
        }
        return total;
    }
};