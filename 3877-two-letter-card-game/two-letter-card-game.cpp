class Solution {
public:
    int score(vector<string>& cards, char x) {
        vector<int> store1(26,0);
        vector<int> store2(26,0);
        vector<int> store3(26,0);
        int ans = 0;
        for(int i = 0;i<cards.size();i++){
            if(cards[i][0] == x && cards[i][1] == x){
                store3[cards[i][0]-'a']++;
            }else if(cards[i][0] == x){
                store1[cards[i][1]-'a']++;
            }else if(cards[i][1] == x) store2[cards[i][0]-'a']++;
        }
        sort(store1.begin(),store1.end());
        sort(store2.begin(),store2.end());
        int s1 = 0;
        int s2 = 0;
        int s3 = 0;
        int s4 = 0;
        for(int i = 0; i<26;i++){
            if(i!=25){
                s1 += store1[i];
                s3 += store2[i];
            }else {
                s2 += store1[i];
                s4 += store2[i];
            }
        }
        int m = store3[x-'a'];
        cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << m << endl;
        if(s2 > s1){
            if(m <= s2-s1) {
                s2 = s2-m;
                ans += m;
                m = 0;
            }
            else {
                ans += (s2-s1);
                m = m - (s2-s1);
                s2 = s2 - (s2-s1);
                
            }
        }
        cout << ans << " ";
        if(s4 > s3){
            if(m <= s4-s3) {
                s4 = s4-m;
                ans += m;
                m = 0;
            }
            else {
                ans += (s4-s3);
                m = m - (s4-s3);
                s4 = s4 - (s4-s3);
            }
        }
        cout << ans << " ";
        int sum1 = 0;
        int sum2 = 0;
        if(s2 > s1) ans += s1;
        else {
            int sum = s1 + s2;
            // if(m >= sum){
            //     ans += sum;
            //     m = m - sum;
            // }else {
            //     ans += m;
            //     sum = sum - m;
            //     m = 0;
            //     ans += sum/2;
            // }
            if(sum % 2 == 1 && m >= 1) {
                ans++;
                m--;
                sum--;
            }
            sum1 = sum;
        }
        cout << ans << " ";
        if(s4 > s3) ans += s3;
        else {
            int sum = s3+s4;
            // if(m >= sum){
            //     ans += sum;
            //     m = m - sum;
            // }else {
            //     ans += m;
            //     m = 0;
            //     sum = sum - m;
            //     ans += sum/2;
            // }
            if(sum % 2 == 1 && m >= 1) {
                ans++;
                m--;
                sum--;
                
            }
            sum2 = sum;
        }
        if(m >= sum1+sum2) ans += sum1+sum2;
        else if(m!=0) {
            ans += m;
            int value = sum1 + sum2;
            value = value-m;
            ans += value/2;
        }else if(m == 0){
            ans += sum1/2;
            ans += sum2/2;
        }
        cout << ans << " ";
        return ans;
    }
};