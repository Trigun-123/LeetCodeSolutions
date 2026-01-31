	class Solution {
	public:
		int minMoves(vector<int>& nums) {
			int minn = INT_MAX, result = 0;

			for(auto it : nums) {
                minn = min(minn, it);
            }    
			
			for(auto it : nums) {
                result += it - minn;
            }

			return result;
		}
	};