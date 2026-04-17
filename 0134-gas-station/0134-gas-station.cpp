class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totGas = 0, totCost = 0;

        for(int i = 0; i < n; i++) {
            totGas += gas[i];
            totCost += cost[i];
        }

        if(totGas < totCost) {
            return -1;
        }

        int currentGas = 0, start = 0;

        for(int i = 0; i < n; i++) {
            currentGas += gas[i] - cost[i];

            if(currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }

        return start;        
    }
};