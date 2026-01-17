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
        int ans = 0;
        unordered_map<int,pair<int,vector<int>>> empvalue;
        unordered_map<int,int> emp;
        queue<int> q;
        vector<int> allsub;
        for(int i = 0;i<employees.size();i++){
            empvalue[employees[i]->id] = {employees[i]->importance,employees[i]->subordinates};
            // emp[employees[i]->id] = employees[i]->importance;
            if(employees[i]->id == id){
                for(int j = 0;j<employees[i]->subordinates.size();j++){
                    q.push(employees[i]->subordinates[j]);
                }
            }
        }
        ans += empvalue[id].first;
        while(!q.empty()){
            int ids = q.front();
            q.pop();
            ans+=empvalue[ids].first;
            vector<int> temp = empvalue[ids].second;
            for(int i = 0;i<temp.size();i++){
                q.push(temp[i]);
            }
        }
        return ans;
    }
};