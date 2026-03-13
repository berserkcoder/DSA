// class Solution {
// public:
//     vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
//         sort(rooms.begin(),rooms.end(),[](const vector<int>& a,const vector<int>& b){
//             return a[1] < b[1];
//         });
//         for(int i = 0;i<queries.size();i++){
//             queries[i].push_back(i);
//         }
//         sort(queries.begin(),queries.end(),[](const vector<int>& a,const vector<int>& b){
//             return a[1] < b[1];
//         });
//         set<int> store;
//         vector<int> ans(queries.size());
//         int previous = rooms.size();
//         for(int i = queries.size()-1;i>=0;i--){
//             int roomId = queries[i][0];
//             int minSize = queries[i][1];
//             int index = queries[i][2];
//             int start = 0;
//             int end = rooms.size()-1;
//             while(start <= end){
//                 int mid = (start+end)/2;
//                 if(rooms[mid][1] >= minSize) end = mid-1;
//                 else start = mid+1;
//             }
//             if(start == rooms.size()){
//                 ans[index] = -1;
//                 continue;
//             }
//             for(int ch = start;ch < previous; ch++){
//                 store.insert(rooms[ch][0]);
//             }
//             previous = start;
//             auto it = store.lower_bound(roomId);
//             if(it != store.end()){
//                 int val1 = *it;
//                 int val2 = -1e8;
//                 if(it != store.begin()){
//                     it--;
//                     val2 = *it;
//                 }
//                 if(abs(val1-roomId) < abs(val2-roomId)) ans[index] = val1;
//                 else ans[index] = val2;
//             }else {
//                 int val2 = -1e8;
//                 if(it != store.begin()){
//                     it--;
//                     val2 = *it;
//                 }
//                 ans[index] = val2;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {

        int n = rooms.size();
        int k = queries.size();

        vector<int> ans(k, -1);

        // store queries with index
        vector<vector<int>> q;
        for(int i = 0; i < k; i++){
            q.push_back({queries[i][1], queries[i][0], i});
        }

        // sort rooms by size descending
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b){
            return a[1] > b[1];
        });

        // sort queries by minSize descending
        sort(q.begin(), q.end(), [](auto &a, auto &b){
            return a[0] > b[0];
        });

        set<int> validRooms;

        int j = 0;

        for(auto &query : q){

            int minSize = query[0];
            int preferred = query[1];
            int idx = query[2];

            // add valid rooms
            while(j < n && rooms[j][1] >= minSize){
                validRooms.insert(rooms[j][0]);
                j++;
            }

            if(validRooms.empty()){
                ans[idx] = -1;
                continue;
            }

            auto it = validRooms.lower_bound(preferred);

            int best = -1;
            int dist = INT_MAX;

            // candidate ≥ preferred
            if(it != validRooms.end()){
                best = *it;
                dist = abs(*it - preferred);
            }

            // candidate < preferred
            if(it != validRooms.begin()){
                auto prev_it = prev(it);
                int id = *prev_it;

                if(abs(id - preferred) <= dist){
                    best = id;
                    dist = abs(id - preferred);
                }
            }

            ans[idx] = best;
        }

        return ans;
    }
};