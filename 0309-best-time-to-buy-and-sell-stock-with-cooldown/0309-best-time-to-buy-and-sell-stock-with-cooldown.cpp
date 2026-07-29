class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int hold = -prices[0]; // bought stock
        int sold = 0;          // sold today
        int rest = 0;          // doing nothing

        for (int i = 1; i < prices.size(); i++) {

            int prevSold = sold;

            // Sell today
            sold = hold + prices[i];

            // Buy today or keep holding
            hold = max(hold, rest - prices[i]);

            // Stay in rest or come from cooldown
            rest = max(rest, prevSold);
        }

        return max(sold, rest);
    }
};