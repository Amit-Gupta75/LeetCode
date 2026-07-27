class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int max2=(nums[i]-1)*(nums[j]-1);
                max1=max(max1,max2);
            }
        }

        return max1;
    }
};