class KthLargest {
private:
  int K;
  priority_queue<int, vector<int>, greater<int>> pq;

public:
  KthLargest(int k, vector<int>& nums) {
    int n = nums.size();
    K = k;

    for(int i = 0; i < n; i++) {
      if(pq.size() < K)
        pq.push(nums[i]);
      else if(nums[i] > pq.top()){
        pq.pop();
        pq.push(nums[i]);
      }
    }
  }

  int add(int val) {
    if(pq.size() < K) {
      pq.push(val);
      return pq.top();
    }

    if(val > pq.top()) {
      pq.pop();
      pq.push(val);
    }
    return pq.top();
  }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */