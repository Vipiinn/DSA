class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = 0.0;

        for (auto &s : squares) {
            double y = s[1], l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        auto areaBelow = [&](double h) {
            double area = 0.0;
            for (auto &s : squares) {
                double y = s[1], l = s[2];
                if (h <= y) continue;
                if (h >= y + l) area += l * l;
                else area += l * (h - y);
            }
            return area;
        };

        for (int i = 0; i < 60; i++) {   // sufficient for 1e-5 accuracy
            double mid = (low + high) / 2.0;
            if (areaBelow(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
