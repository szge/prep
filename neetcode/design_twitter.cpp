class Twitter {
    // o(1) for follow/unfollow sounds like an unordered_set tracking follows
    // idea 1: unordered_map btw users and their tweets.
    // idea 2: unordered_map btw users and their feed
    // feed might be a q to track the ordering of the 10 recent tweets.
private:
    unordered_map<int, unordered_set<int>> following;
    // use vector instead of unordered_set because pair doesn't have a default hash fn
    unordered_map<int, vector<pair<int, int>>> user_tweets; // {time, tweetId}
    int time;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        // vector<int> feed;
        // vector<pair<int, int>> followingTweets = user_tweets[userId];
        // for (const int& followeeId : following[userId]) {
        //     vector<pair<int, int>>& followeeTweets = user_tweets[followeeId];
        //     for (const pair<int, int>& tweet : followeeTweets) followingTweets.push_back(tweet);
        // }
        // sort(followingTweets.rbegin(), followingTweets.rend());
        // for (int i = 0; i < min(10, (int)followingTweets.size()); i++) feed.push_back(followingTweets[i].second);
        // return feed;

        // above soln takes o(nm) for pushing tweets for each followee and o(tlogt) for sorting tweets
        // we can use a priority queue to get the
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId) > 0) following[followerId].erase(followeeId);
    }
};
