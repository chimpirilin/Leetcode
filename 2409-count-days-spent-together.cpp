// https://leetcode.com/problems/count-days-spent-together/
class Solution {
public:
	vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int aliceMonth1 = stoi(arriveAlice.substr(0, 2));
		int aliceDay1 = stoi(arriveAlice.substr(3, 2));
		int aliceMonth2 = stoi(leaveAlice.substr(0, 2));
		int aliceDay2 = stoi(leaveAlice.substr(3, 2));
		int bobMonth1 = stoi(arriveBob.substr(0, 2));
		int bobDay1 =stoi(arriveBob.substr(3, 2));
		int bobMonth2 = stoi(leaveBob.substr(0, 2));
		int bobDay2 = stoi(leaveBob.substr(3, 2));

		int aliceStartDay=0;
		for(int i= 0; i < aliceMonth1; ++i){ 
			aliceStartDay+=months[i];
		}
		aliceStartDay+=aliceDay1;
		int aliceEndDay=0;
		for(int i= 0; i < aliceMonth2; ++i){ 
			aliceEndDay+=months[i];
		}
		aliceEndDay+=aliceDay2;

		int bobStartDay=0;
		for(int i= 0; i < bobMonth1; ++i){ 
			bobStartDay+=months[i];
		}
		bobStartDay+=bobDay1;
		int bobEndDay=0;
		for(int i= 0; i < bobMonth2; ++i){ 
			bobEndDay+=months[i];
		}
		bobEndDay+=bobDay2;
		int ans = min(aliceEndDay, bobEndDay)-max(aliceStartDay, bobStartDay)+1;
		ans=ans<0?0:ans;
		return ans;
	}
};


