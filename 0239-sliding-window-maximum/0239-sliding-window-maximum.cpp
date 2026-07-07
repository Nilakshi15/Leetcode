class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int n = nums.size();
        if (n == 0 || k == 0) return res;   
        if (k > n) k = n;                   

        // 1st window
        for(int i = 0; i < k; i++){

            while(!dq.empty() && nums[dq.back()] <= nums[i]){   
                dq.pop_back();
            }

            dq.push_back(i);
        }

        for(int i = k; i < n; i++){

            // front is max of previous window
            res.push_back(nums[dq.front()]);

            // Remove indices out of this window
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            // Remove smaller (or equal) values than current, as they are useless
            while(!dq.empty() && nums[dq.back()] <= nums[i]){   
                dq.pop_back();
            }

            dq.push_back(i);
        }
        
        // last window
        res.push_back(nums[dq.front()]);
        return res;
    }
};
