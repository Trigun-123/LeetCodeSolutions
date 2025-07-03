class Solution {
private:
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        return p1.first > p2.first;
    }

public:
    string frequencySort(string& s) {
        int n = s.length();
        pair<int, char> freq[128]; 
        
        for(int i = 0; i < 128; i++)
            freq[i] = {0, (char)i};

        for(int i = 0; i < n; i++)
            freq[s[i]].first++;

        sort(freq, freq + 128, comparator);

        string result = "";
        for(int i = 0; i < 128; i++) {
            if(freq[i].first == 0)
                break;
            result += string(freq[i].first, freq[i].second);
        }
        return result;
    }
};
