class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;

        for(auto p:points){
            int distance = p[0]*p[0]+p[1]*p[1];
            pq.push({distance,p});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        
    }
};