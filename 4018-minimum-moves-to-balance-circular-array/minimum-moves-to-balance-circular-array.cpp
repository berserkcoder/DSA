class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long ans = 0;
        int index = -1;
        long sum = 0;
        for(int i = 0;i<balance.size();i++){
            if(balance[i] < 0) index = i;
            else sum += balance[i];
        }
        if(index == -1) return ans;
        long val = -balance[index];
        if(sum < val) return -1;
        long count = 1;
        while(val>0){
            if(balance[(index+count)%balance.size()] < val){
                ans += (balance[(index+count)%balance.size()] * count);
                val = val - balance[(index+count)%balance.size()];
            }else {
                ans += (val * count);
                break;
            }
            // cout << ans << " ";
            if(index-count >= 0){
                if(balance[index-count] < val){
                    ans += (balance[index-count] * count);
                    val = val - balance[index-count];
                }else {
                    ans += (val * count);
                    break;
                }
            }else {
                if(balance[index-count+balance.size()] < val){
                    ans += (balance[index-count+balance.size()] * count);
                    val = val - balance[index-count+balance.size()];
                }else {
                    ans += (val * count);
                    break;
                }
            }
            // cout << ans << " ";
            count++;
        }
        return ans;
    }
};