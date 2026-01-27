class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto it : stones) {
            pq.push(it);
        }    

        while(pq.size() > 1) {
            int p = pq.top();
            pq.pop();
            int q = pq.top();
            pq.pop();
            if(p == q) {
                pq.push(0);
            }    
            else {
                pq.push(abs(p - q));
            }    
        }

        return pq.top();
    }
};