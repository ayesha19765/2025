class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSurplus = 0, currentSurplus = 0, start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            totalSurplus += gas[i] - cost[i];
            currentSurplus += gas[i] - cost[i];

            if (currentSurplus < 0) {
                start = i + 1;
                currentSurplus = 0;
            }
        }

        return totalSurplus >= 0 ? start : -1;
    }
};
