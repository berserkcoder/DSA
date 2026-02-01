class AuctionSystem {
public:
    map<int, set<pair<int, int>>> bids;
    map<int, unordered_map<int,int>> mapBids;
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if(mapBids[itemId].count(userId)){
            int amount = mapBids[itemId][userId];
            bids[itemId].erase({amount,userId});
        }
        bids[itemId].insert({bidAmount, userId});
        mapBids[itemId][userId] = bidAmount;
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int amount = mapBids[itemId][userId];
        bids[itemId].erase({amount,userId});
        bids[itemId].insert({newAmount, userId});
        mapBids[itemId][userId] = newAmount;
    }

    void removeBid(int userId, int itemId) {
        int amount = mapBids[itemId][userId];
        mapBids[itemId].erase(userId);
        bids[itemId].erase({amount,userId});
    }

    int getHighestBidder(int itemId) {
        if (bids.find(itemId) == bids.end() || bids[itemId].empty())return -1;
        auto it = --bids[itemId].end();
        return it->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */