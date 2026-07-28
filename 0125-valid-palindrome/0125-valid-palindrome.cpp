class Solution {
public:
    bool isPalindrome(string s) {
        string a ="";
        for(char c:s){
            if(isalnum(c)){
                a+=tolower(c);
            }
        }

        int start = 0;
        int end  = a.size()-1;
        while(start<end){
            if(a[start]!=a[end]){
                return false;
            }

            start++;
            end--;
        }

        return true;
        
    }
};