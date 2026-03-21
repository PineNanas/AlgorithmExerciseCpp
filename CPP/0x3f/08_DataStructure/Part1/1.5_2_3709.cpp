#include<bits/stdc++.h>
using namespace std;

class ExamTracker {
public:
    vector<int> timeTable;
    vector<long long> sumV;
    ExamTracker() {
        timeTable.reserve(110000);
        sumV.reserve(110000);
        timeTable.push_back(0);
        sumV.push_back(0);
    }
    
    void record(int time, int score) {
        timeTable.push_back(time);
        sumV.push_back(sumV.back() + score);
    }

    long long sumBeforeTime(int time)
    {
        int left = -1;
        int right = timeTable.size();
        int mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (timeTable[mid] > time)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return sumV[right - 1];
    }

    long long totalScore(int startTime, int endTime) {
        return sumBeforeTime(endTime) - sumBeforeTime(startTime - 1);
    }
};