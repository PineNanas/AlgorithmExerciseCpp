#include<bits/stdc++.h>
using namespace std;

//time limit
class Router {
public:
    deque<vector<int>> buffer;
    stack<vector<int>> checkStk;
    int limit;
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> package = {source, destination, timestamp};
        if (buffer.empty())
        {
            buffer.push_back(package);
            return true;
        }
        while (!buffer.empty() && buffer.back()[2] == package[2])
        {
            if (buffer.back() == package)
            {
                while (!checkStk.empty())
                {
                    buffer.push_back(checkStk.top());
                    checkStk.pop();
                }
                return false;
            }
            checkStk.push(buffer.back());
            buffer.pop_back();
        }
        while (!checkStk.empty())
        {
            buffer.push_back(checkStk.top());
            checkStk.pop();
        }
        buffer.push_back(package);
        if (buffer.size() > limit)
        {
            buffer.pop_front();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if (buffer.empty())
        {
            return {};
        }
        vector<int> out = buffer.front();
        buffer.pop_front();
        return out;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        int n = buffer.size();
        vector<int> curPackage;
        for (int i = 0; i < n; i++)
        {
            curPackage = buffer.front();
            if (curPackage[1] == destination && curPackage[2] >= startTime && curPackage[2] <= endTime)
            {
                count++;
            }
            buffer.push_back(curPackage);
            buffer.pop_front();
        }
        return count;
    }
};

//0x3f
class Router {
public:
    int memory_limit;
    queue<tuple<int, int, int>> packet_q;
    set<tuple<int, int, int>> packet_set;
    unordered_map<int, deque<int>> dest_to_timestamps;

    Router(int memoryLimit) {
        memory_limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto packet = tuple(source, destination, timestamp);
        if (!packet_set.insert(packet).second) {
            return false;
        }
        if (packet_q.size() == memory_limit) {
            forwardPacket();
        }
        packet_q.push(packet);
        dest_to_timestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packet_q.empty()) {
            return {};
        }
        auto packet = packet_q.front();
        packet_q.pop();
        packet_set.erase(packet);
        auto [source, destination, timestamp] = packet;
        dest_to_timestamps[destination].pop_front();
        return {source, destination, timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& timestamps = dest_to_timestamps[destination];
        auto left = ranges::lower_bound(timestamps, startTime);
        auto right = ranges::upper_bound(timestamps, endTime);
        return right - left;
    }
};