class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        int target = totalSum - x;

        if (target < 0) {
            return -1;
        }
        if (target == 0) {
            return n;
        }

        int max_length = -1;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                max_length = max(max_length, right - left + 1);
            }
        }

        if (max_length == -1) {

            return -1;
        }

        return n - max_length;
    }
};