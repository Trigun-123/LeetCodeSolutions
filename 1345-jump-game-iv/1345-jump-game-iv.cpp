class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>mpp;

        for(int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }    
        
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        int minSteps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int currentIndex = q.front();
                q.pop();

                if(currentIndex == n-1) {
                    return minSteps;
                }    
                if(currentIndex + 1 < n && !visited[currentIndex + 1]) {
                    visited[currentIndex + 1] = true;
                    q.push(currentIndex + 1);
                }
                if(currentIndex - 1 >= 0 && !visited[currentIndex - 1]) {
                    visited[currentIndex - 1] = true;
                    q.push(currentIndex - 1);
                }

                for(int newIndex : mpp[arr[currentIndex]]) {                            
                    if(!visited[newIndex]) {
                        visited[newIndex] = true;
                        q.push(newIndex);
                    }
                }
                mpp[arr[currentIndex]].clear();   
            }
            minSteps++;
        }

        return -1;
    }
};