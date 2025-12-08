#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, long long> freq;
        for (int x : nums) freq[x]++;

        long long total = nums.size();
        long long left_sum = 0;
        long long ans = 0;

        // iterate over distinct values
        for (auto &p : freq) {
            long long ci = p.second;
            long long right_sum = total - left_sum - ci;
            ans += left_sum * ci * right_sum;
            left_sum += ci;
        }

        return (int)ans; // fits within int for given constraints, but computed in long long
    }
};
