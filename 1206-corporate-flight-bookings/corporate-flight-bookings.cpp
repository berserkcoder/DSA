class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> count(n);
        for(int i = 0;i<bookings.size();i++){
            int left = bookings[i][0] - 1;
            int right = bookings[i][1] - 1;
            int seats = bookings[i][2];
            count[left] += seats;
            if(right != n-1) count[right+1] -= seats;
        }
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += count[i];
            count[i] = sum;
        }
        return count;
    }
};