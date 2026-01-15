class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char, int> hm;
        for (char c : s) {
            hm[c]++;
        }
        for (const auto& entry : hm) {
            pq.push({entry.second,entry.first});
        }
        string result = "";
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            result.append(p.first, p.second);
        }
        return result;
    }
};