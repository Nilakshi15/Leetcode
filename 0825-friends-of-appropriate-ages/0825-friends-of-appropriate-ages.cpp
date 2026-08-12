class Solution {
public:
    int numFriendRequests(vector<int>& ages) {

        vector<int> count(121, 0);

        for (int age : ages)
            count[age]++;

        int ans = 0;

        for (int ageA = 1; ageA <= 120; ageA++) {

            if (count[ageA] == 0)
                continue;

            for (int ageB = 1; ageB <= 120; ageB++) {

                if (count[ageB] == 0)
                    continue;

                // B cannot receive request from A
                if (ageB <= 0.5 * ageA + 7)
                    continue;

                if (ageB > ageA)
                    continue;

                if (ageB > 100 && ageA < 100)
                    continue;

                ans += count[ageA] * count[ageB];

                // A cannot send request to themselves
                if (ageA == ageB)
                    ans -= count[ageA];
            }
        }

        return ans;
    }
};