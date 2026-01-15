class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i])%n == 0)
                continue;
            int slow = nums[i];
            int fast = nums[i];
            int islow = i;
            int ifast = i;
            bool flag = true;
            if (nums[i] < 0)
                flag = false;
            if (flag) {
                do {
                    int s = slow;
                    slow = nums[(islow + slow) % n];
                    islow = (islow + s) % n;
                    if (abs(slow)%n == 0)
                        break;
                    // cout << slow << " ";
                    if (slow < 0)
                        break;
                    int f = fast;
                    fast = nums[(ifast + fast) % n];
                    if (fast < 0)
                        break;
                    ifast = (ifast + f) % n;
                    if (abs(fast)%n == 0)
                        break;
                    // cout << fast << " ";
                    f = fast;
                    fast = nums[(ifast + fast) % n];
                    if (abs(fast)%n == 0)
                        break;
                    ifast = (ifast + f) % n;
                    // cout << fast << endl;
                    if (fast < 0)
                        break;
                    if (islow == ifast)
                        return true;
                } while (islow != ifast);
            } else {
                do {
                    int s = slow;
                    int val = islow + slow;
                    while (val < 0)
                        val += n;
                    slow = nums[val];
                    islow = val;
                    if (abs(slow) % n == 0)
                        break;
                    // cout << slow << " ";
                    if (slow > 0)
                        break;
                    int f = fast;
                    val = ifast + fast;
                    while (val < 0)
                        val += n;
                    if (abs(fast) % n == 0)
                        break;
                    fast = nums[val];
                    ifast = val;
                    // cout << fast << " ";
                    if (abs(fast) % n == 0)
                        break;
                    if (fast > 0)
                        break;
                    f = fast;
                    val = ifast + fast;
                    while (val < 0)
                        val += n;
                    fast = nums[val];
                    ifast = val;
                    // cout << fast << endl;
                    if (fast > 0)
                        break;
                    if (islow == ifast)
                        return true;
                } while (islow != ifast);
            }
        }
        return false;
    }
};