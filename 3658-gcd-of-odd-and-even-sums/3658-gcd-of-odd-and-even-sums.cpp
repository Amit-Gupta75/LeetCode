class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int SumOdd = n*(n+1);
        int SumEven = n*n;

        int ans = gcd(SumOdd,SumEven);

        return ans;
        
    }
};