class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubarray = nums[0];
        int bestEnding = nums[0];

        for(int i=1;i<nums.size();i++){
            int v1 = bestEnding + nums[i];
            int v2 = nums[i];

            bestEnding = max(v1,v2);

            maxSubarray = max(maxSubarray,bestEnding); 
        }

        return maxSubarray;
        
    }
};