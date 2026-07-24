/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>mp;

        for(auto emp: employees){
            mp[emp->id]=emp;
        }

        queue<int>q;
        q.push(id);

        int total = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            Employee* emp = mp[curr];
            total += emp->importance;

            for (int subId : emp->subordinates) {
                q.push(subId);
            }
        }

        return total;
        
    }
};