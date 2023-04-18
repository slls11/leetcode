class UserData{
public:
    UserData(int userId){ _userId = userId;}
    vector<int> Get_Followers(){return _following_IDs;}

    int Get_ID(){return _userId;}

    void Set_Followers(int followeeId){_following_IDs.push_back(followeeId);}

    void Remove_Followers(int followeeId){
        for (int i = 0; i < _following_IDs.size(); i++){
            /* change this to a unordered_set later */
            if (_following_IDs[i] == followeeId) _following_IDs[i] == -1;
        }
    }

private:
    int _userId;
    vector<int> _following_IDs;
};

class Twitter {
    /* Not optimized, just trying to get it working */
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        if (_users.find(userId) == _users.end()){
            _users[userId] = new UserData(userId);
        }
        _all_tweets[userId].insert(tweetId * -1);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> user_feed;
        for (auto user_followingId : _users[userId]->Get_Followers()){
            for (auto tweetId : _all_tweets[user_followingId]) 
                user_feed.push_back(tweetId);
        }
        sort(user_feed.begin(), user_feed.end());

        vector<int> res;
        for (int i = 0; i < user_feed.size() && i < 10; i++) {
            res.push_back(user_feed[i] * -1);
        }

    return res;
    }
    
    void follow(int followerId, int followeeId) {_users[followerId]->Set_Followers(followeeId);}
    
    void unfollow(int followerId, int followeeId) {
        _users[followerId]->Remove_Followers(followeeId);
    }

private:
    unordered_map<int, UserData*> _users;
    unordered_map<int,set<int>> _all_tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
