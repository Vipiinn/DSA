#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        long long y;
        int type; 
        long long x1, x2;
    };

    long long unionLength(vector<pair<long long, long long>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());

        long long total = 0;
        long long curL = intervals[0].first;
        long long curR = intervals[0].second;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > curR) {
                total += (curR - curL);
                curL = intervals[i].first;
                curR = intervals[i].second;
            } else {
                curR = max(curR, intervals[i].second);
            }
        }
        total += (curR - curL);
        return total;
    }

    long double areaBelow(long double Y, vector<Event>& events) {
        vector<pair<long long, long long>> active;
        long double area = 0;
        long long prevY = events[0].y;

        for (auto& e : events) {
            if (prevY >= Y) break;

            long long curY = e.y;
            long double height = min((long double)curY, Y) - prevY;

            if (height > 0) {
                long long width = unionLength(active);
                area += (long double)width * height;
            }

            if (e.type == 1) {
                active.push_back({e.x1, e.x2});
            } else {
                for (int i = 0; i < active.size(); i++) {
                    if (active[i].first == e.x1 && active[i].second == e.x2) {
                        active.erase(active.begin() + i);
                        break;
                    }
                }
            }
            prevY = curY;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        long long minY = LLONG_MAX, maxY = 0;

        for (auto& s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            events.push_back({y, +1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
            minY = min(minY, y);
            maxY = max(maxY, y + l);
        }

        sort(events.begin(), events.end(),
             [](const Event& a, const Event& b) {
                 return a.y < b.y;
             });

        long double totalArea = areaBelow(maxY, events);
        long double half = totalArea / 2.0;

        long double lo = minY, hi = maxY;
        for (int i = 0; i < 60; i++) { 
            long double mid = (lo + hi) / 2.0;
            if (areaBelow(mid, events) >= half)
                hi = mid;
            else
                lo = mid;
        }
        return (double)hi;
    }
};
