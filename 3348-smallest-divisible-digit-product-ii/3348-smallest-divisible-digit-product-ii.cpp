class Solution {
public:

    /*
        MUST REVISIT AFTER FEW DAYS.
        This problem was NOT solved completely by my own.
        Dekh-dekh ke / solution samajh ke banaya hai.
        Revisit and try to derive the approach independently.
    */

    // Prime contribution of digits 0...9
    // {power of 2, power of 3, power of 5, power of 7}
    vector<array<int, 4>> factor = {
        {0,0,0,0}, // 0 - not allowed
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4 = 2^2
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6 = 2*3
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8 = 2^3
        {0,2,0,0}  // 9 = 3^2
    };

    vector<vector<int>> dp;

    // remove contribution of digit d from required factors
    array<int,4> removeFactor(array<int,4> need, int d) {

        for (int k = 0; k < 4; k++) {
            need[k] = max(0, need[k] - factor[d][k]);
        }

        return need;
    }

    // minimum number of digits required to satisfy `need`
    int minimumDigits(array<int,4> need) {

        /*
            5 can only come from digit 5
            7 can only come from digit 7

            2 and 3 can be combined using:
            2,3,4,6,8,9
        */

        return need[2] + need[3] + dp[need[0]][need[1]];
    }

    // Build lexicographically smallest string of exactly len digits
    // whose product satisfies remaining factors.
    string buildSmallest(array<int,4> need, int len) {

        string ans;
        ans.reserve(len);

        for (int pos = 0; pos < len; pos++) {

            int remainingPlaces = len - pos - 1;

            // Try smallest digit first
            for (int d = 1; d <= 9; d++) {

                auto nextNeed = removeFactor(need, d);

                // Can remaining requirement be completed
                // using remaining positions?
                if (minimumDigits(nextNeed) <= remainingPlaces) {

                    ans.push_back(char('0' + d));
                    need = nextNeed;

                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        // ------------------------------------------------
        // STEP 1: Prime factorize t
        // ------------------------------------------------

        array<int,4> required = {0,0,0,0};

        long long temp = t;

        vector<int> primes = {2,3,5,7};

        for (int i = 0; i < 4; i++) {

            while (temp % primes[i] == 0) {
                required[i]++;
                temp /= primes[i];
            }
        }

        /*
            Digits 1..9 contain only primes:
            2,3,5,7

            If t contains something like 11,13,...
            impossible.
        */
        if (temp != 1)
            return "-1";


        // ------------------------------------------------
        // STEP 2: DP for minimum digits needed
        //         for powers of 2 and 3
        // ------------------------------------------------

        int maxTwo = required[0];
        int maxThree = required[1];

        const int INF = 1e9;

        dp.assign(
            maxTwo + 1,
            vector<int>(maxThree + 1, INF)
        );

        dp[0][0] = 0;

        vector<int> usefulDigits = {2,3,4,6,8,9};

        for (int two = 0; two <= maxTwo; two++) {

            for (int three = 0; three <= maxThree; three++) {

                if (two == 0 && three == 0)
                    continue;

                for (int d : usefulDigits) {

                    int prevTwo =
                        max(0, two - factor[d][0]);

                    int prevThree =
                        max(0, three - factor[d][1]);

                    dp[two][three] =
                        min(dp[two][three],
                            1 + dp[prevTwo][prevThree]);
                }
            }
        }


        int n = num.size();


        // ------------------------------------------------
        // STEP 3: remaining factors before every position
        // ------------------------------------------------

        vector<array<int,4>> remaining(n + 1);

        // number of zeroes in prefix
        vector<int> zeroPrefix(n + 1, 0);

        remaining[0] = required;

        for (int i = 0; i < n; i++) {

            remaining[i + 1] = remaining[i];

            int digit = num[i] - '0';

            zeroPrefix[i + 1] =
                zeroPrefix[i] + (digit == 0);

            if (digit != 0) {
                remaining[i + 1] =
                    removeFactor(remaining[i + 1], digit);
            }
        }


        // ------------------------------------------------
        // STEP 4: Is num itself already valid?
        // ------------------------------------------------

        if (zeroPrefix[n] == 0 &&
            minimumDigits(remaining[n]) == 0) {

            return num;
        }


        // ------------------------------------------------
        // STEP 5:
        // Try changing the RIGHTMOST possible digit
        // to something larger.
        //
        // Rightmost change gives smallest possible answer.
        // ------------------------------------------------

        for (int i = n - 1; i >= 0; i--) {

            /*
                Prefix num[0...i-1] must be zero-free,
                because we're keeping it unchanged.
            */
            if (zeroPrefix[i] > 0)
                continue;

            int currentDigit = num[i] - '0';

            /*
                Digit at i must become bigger than num[i]
                so final number > num.
            */
            for (int d = max(1, currentDigit + 1);
                 d <= 9;
                 d++) {

                auto nextNeed =
                    removeFactor(remaining[i], d);

                int suffixLength = n - i - 1;

                /*
                    Check whether suffix has enough positions
                    to satisfy remaining prime factors.
                */
                if (minimumDigits(nextNeed) <= suffixLength) {

                    string answer = num.substr(0, i);

                    answer.push_back(char('0' + d));

                    answer += buildSmallest(
                        nextNeed,
                        suffixLength
                    );

                    return answer;
                }
            }
        }


        // ------------------------------------------------
        // STEP 6:
        // Same length impossible.
        //
        // Any number with more digits will automatically
        // be greater than num.
        // ------------------------------------------------

        int requiredLength = minimumDigits(required);

        int newLength = max(n + 1, requiredLength);

        return buildSmallest(required, newLength);
    }
};