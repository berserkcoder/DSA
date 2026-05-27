class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        vector<int> lowercase(26,0);
        vector<int> uppercase(26,0);
        vector<int> numbers(10,0);
        vector<int> special(4,0);
        for(int i = 0;i<password.size();i++){
            if(password[i] >= 65 && password[i] <= 91){
                uppercase[password[i]-'A'] = 1;
            }else if(password[i] >= 48 && password[i] <= 57){
                numbers[password[i]-'0'] = 1;
            }else if(password[i] >= 97 && password[i] <= 122){
                lowercase[password[i]-'a'] = 1;
            }else if(password[i] == '!'){
                special[0] = 1;
            }else if(password[i] == '@'){
                special[1] = 1;
            }else if(password[i] == '#'){
                special[2] = 1;
            }else if(password[i] == '$'){
                special[3] = 1;
            }
        }
        int count = 0;
        for(int i = 0;i<lowercase.size();i++){
            if(lowercase[i] == 1) count++;
        }
        ans += (count*1);
        count = 0;
        for(int i = 0;i<uppercase.size();i++){
            if(uppercase[i] == 1) count++;
        }
        ans += (count*2);
        count = 0;
        for(int i = 0;i<numbers.size();i++){
            if(numbers[i] == 1) count++;
        }
        ans += (count*3);
        count = 0;
        for(int i = 0;i<special.size();i++){
            if(special[i] == 1) count++;
        }
        ans += (count*5);
        return ans;
    }
};