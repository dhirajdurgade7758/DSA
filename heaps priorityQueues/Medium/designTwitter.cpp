#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    int count;  
    unordered_map<int, vector<pair<int,int>>> tweetMap; 
    // userId -> vector of {count, tweetId}
    
    unordered_map<int, unordered_set<int>> followMap;
    // userId -> set of followeeIds

public:
    Twitter() {
        count = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count, tweetId});
        count++; // newer tweets have larger count
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // maxHeap: {count, tweetId, followeeId, index}
        priority_queue<vector<int>> maxHeap;

        // user follows himself
        followMap[userId].insert(userId);

        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                int index = tweetMap[followeeId].size() - 1;
                auto [cnt, tweetId] = tweetMap[followeeId][index];
                maxHeap.push({cnt, tweetId, followeeId, index - 1});
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int cnt = top[0];
            int tweetId = top[1];
            int followeeId = top[2];
            int index = top[3];

            res.push_back(tweetId);

            if (index >= 0) {
                auto [nextCnt, nextTweetId] = tweetMap[followeeId][index];
                maxHeap.push({nextCnt, nextTweetId, followeeId, index - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);
    vector<int> feed1 = twitter.getNewsFeed(1);
    cout << "User 1 feed: ";
    for (int x : feed1) cout << x << " ";
    cout << endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);

    vector<int> feed2 = twitter.getNewsFeed(1);
    cout << "User 1 feed after following user 2: ";
    for (int x : feed2) cout << x << " ";
    cout << endl;

    twitter.unfollow(1, 2);

    vector<int> feed3 = twitter.getNewsFeed(1);
    cout << "User 1 feed after unfollowing user 2: ";
    for (int x : feed3) cout << x << " ";
    cout << endl;

    return 0;
}
