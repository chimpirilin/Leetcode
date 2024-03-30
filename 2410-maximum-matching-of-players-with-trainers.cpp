// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
 	sort(players.rbegin(), players.rend());
	int ans=0;
	multiset<int> t;
	for(auto x:trainers) t.insert(x);
	for(auto x:players){
		auto it=t.lower_bound(x);
		if(it!=t.end()){
			++ans;
			t.erase(it);
		}

	}
	return ans;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
	Solution s;
	vector<int> x{4,7,9};
vector<int> y{8,2,5,8};
	cout<<s.matchPlayersAndTrainers(x,y)<<endl;
    return 0;
}
