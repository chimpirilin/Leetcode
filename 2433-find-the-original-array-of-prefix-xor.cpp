// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
		vector<int> ans;
		ans.push_back(pref[0]);
		for(int i=1;i<int(pre.size());i++){
			int val=pref[i-1]^pref[i];
			ans.push_back(val);
		}
		return ans;
    }
};
	
