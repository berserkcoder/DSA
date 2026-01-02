class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long time = 0;
        vector<long long> current(skill.size());
        vector<long long> previous(skill.size());
        for(int i = 0;i<skill.size();i++){
            time += skill[i] * mana[0];
            previous[i] = time;
            // cout << previous[i] << " ";
        }
        // cout << endl;
        for(int i = 1;i<mana.size();i++){
            time = previous[0];
            long long max = INT_MIN;
            for(int j = 0;j<skill.size();j++){
                time += skill[j] * mana[i];
                current[j] = time;
                if(j<skill.size()-1 && previous[j+1] - current[j] > max) max = previous[j+1] - current[j];
            }
            for(int j = 0;j<skill.size();j++){
                if(max>=0)current[j] += max;
                previous[j] = current[j];
                // cout << previous[j] << " ";
            }
            // cout << endl;
        }
        return previous[skill.size()-1];
    }
};