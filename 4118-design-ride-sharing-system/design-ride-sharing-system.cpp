class RideSharingSystem {
public:
    vector<int> rider;
    vector<int> driver;
    int riderIndex = -1;
    int driverIndex = -1;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ans(2,-1);
        driverIndex++;
        riderIndex++;
        if(driverIndex < driver.size())ans[0] = driver[driverIndex];
        else {
            driverIndex--;
            riderIndex--;
            return ans;
        }
        while(riderIndex < rider.size() && rider[riderIndex] == -1) riderIndex++;
        if(riderIndex == rider.size()){
            ans[0] = -1;
            driverIndex--;
            riderIndex--;
        }else ans[1] = rider[riderIndex];
        return ans;
    }
    
    void cancelRider(int riderId) {
        int temp = riderIndex;
        temp++;
        for(int i = temp;i<rider.size();i++){
            if(rider[i] == riderId) {
                rider[i] = -1;
                break;
            }
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */