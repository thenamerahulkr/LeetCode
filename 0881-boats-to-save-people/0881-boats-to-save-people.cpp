class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size()-1;
        int minimum_no_of_boats = 0;
        while(i<=j){
            if(people[i]+people[j] <= limit){
                minimum_no_of_boats++;
                i++;
                j--;
            }
            else{
                j--;
                minimum_no_of_boats++;
            }
        }
        return minimum_no_of_boats;
    }
};