class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int min_index = -1;

        for (int i = 0; i < n; i++) {
            int digit_sum = 0;
            int num = nums[i];

            while (num > 0) {
                digit_sum += num % 10;
                num = num / 10;
            }

            if (digit_sum == i) {
                min_index = i;
                break;  
            }
        }

        return min_index;
    }
};