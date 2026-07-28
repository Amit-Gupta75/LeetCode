class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>fr;

        for(char c:s){
            fr[c]++;
        }

        int length =0;
        bool hasOdd = false;

        for(auto it=fr.begin();it!=fr.end();it++){
            if(it->second%2==0){
                length+=it->second;
            }else{
                length+=it->second-1;
                hasOdd = true;
            }
        }

        if(hasOdd){
            length++;
        }

        return length;
        
    }
};