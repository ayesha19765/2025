class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 1, maxV = 1;

        // Horizontal bars
        int start = hBars[0], prev = hBars[0];
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == prev + 1) {
                prev = hBars[i];
            } else {
                maxH = max(maxH, prev - start + 2);
                start = prev = hBars[i];
            }
        }
        maxH = max(maxH, prev - start + 2);

        // Vertical bars
        start = vBars[0];
        prev = vBars[0];
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == prev + 1) {
                prev = vBars[i];
            } else {
                maxV = max(maxV, prev - start + 2);
                start = prev = vBars[i];
            }
        }
        maxV = max(maxV, prev - start + 2);

        int side = min(maxH, maxV);
        return side * side;
    }
};
