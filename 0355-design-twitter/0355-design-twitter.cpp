class Twitter {
public:
    int timer = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        followees[userId].insert(userId);

        for (int user : followees[userId]) {

            for (auto &t : tweets[user])
                pq.push(t);
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */