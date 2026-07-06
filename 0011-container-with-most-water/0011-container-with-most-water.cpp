class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(); 
       int lp=0, rp=n-1, maxwater = 0;
       while(lp<rp){
        int w = rp-lp;
        int h = min(height[lp], height[rp]);
        int currentwater = w * h;
        maxwater = max(maxwater, currentwater);
        if (height[lp]<height[rp]){
            lp++;
        }
        else rp--;
       }
       return maxwater;
    }
};