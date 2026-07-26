class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char c:s)
            freq[c]++;

        priority_queue<pair<int,char>> pq;

        for(auto x:freq)
            pq.push({x.second,x.first});

        string ans;

        while(!pq.empty()){

            ans.append(pq.top().first,pq.top().second);

            pq.pop();
        }

        return ans;
    }
};