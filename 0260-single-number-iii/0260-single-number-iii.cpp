class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
            int n = nums.size();
			vector<int> result;
            unordered_map<int, int> mpp;

            for(int i = 0; i < n; i++)
                mpp[nums[i]]++;

            for(auto it : mpp) {
                if(it.second == 1)
                    result.push_back(it.first);
            }
            sort(result.begin(), result.end());
            return result;
		}
};