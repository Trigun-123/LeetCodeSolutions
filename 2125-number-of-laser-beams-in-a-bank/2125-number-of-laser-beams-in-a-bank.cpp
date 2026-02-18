class Solution {
private:
    int countDevices(const string& row) {
        int deviceCount = 0;

        for(auto it : row) {
            i '1') {
                deviceCount++;
            }
        }

        return deviceCount;
    }

public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.
        if(bank.em) {
            return 0;
        }
        
        inttalBeams = 0, prevRowDevices = countDevices(bank[0]);
        
        for(int i = 1; i < n; i++) {
            int currentRowDevices = countDevices(bank[i]);
            if(currentRowDevices == 0) {
                continue;
            }
            totalBeams += prevRowDevices * currentRowDevices;
            prevRowDevices = currentRowDevices;
        }
        
        return totalBeams;
    }
};