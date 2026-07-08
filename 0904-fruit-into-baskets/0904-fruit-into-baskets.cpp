class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> basket;

        int left = 0;
        int maxFruits = 0;

        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit
            basket[fruits[right]]++;

            // More than 2 fruit types
            while (basket.size() > 2) {

                basket[fruits[left]]--;

                // Remove fruit type if count becomes 0
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);

                left++;
            }

            // Update maximum fruits collected
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};