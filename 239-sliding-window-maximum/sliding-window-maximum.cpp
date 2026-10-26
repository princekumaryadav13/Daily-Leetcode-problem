        
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices
        vector<int> ans;

        for (int right = 0; right < nums.size(); right++) {

            // 1. Remove indices outside the current window
            while (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order of values
            while (!dq.empty() &&
                   nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(right);

            // 4. Record maximum once the first window is ready
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
