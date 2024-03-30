// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
		int id=0, best=0;
		int curtime=0;
		for(int i=0;i<logs.size();++i){
			int timetaken=logs[i][1]-curtime;
			if(timetaken>best){
				best=timetaken;
				id=logs[i][0];
			}else if(timetaken==best){
				best=timetaken;
				id=min(logs[i][0],id);
			}
			curtime=logs[i][1];
		}
		return id;
    }
};