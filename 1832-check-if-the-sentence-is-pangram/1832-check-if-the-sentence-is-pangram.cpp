class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();

        int arr[26] = {0};

        for (int i = 0 ; i<n  ; i++)
        {
            
            int num = int(sentence[i]) - 97;
            arr[num]++;
        }
        for (int i = 0 ; i < 26 ; i++)
        {
            if(arr[i]==0)
            {
                // continue ; 
                return false;
            }
            // else return false ;
        }
        return true ;
    }
};