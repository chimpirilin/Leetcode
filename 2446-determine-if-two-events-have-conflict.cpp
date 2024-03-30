// https://leetcode.com/problems/determine-if-two-events-have-conflict/
class Solution {
public:
    int convert2minutes(string s){
        int len = s.size()-1;
        return 60*(10*(s[0]-'0')+(s[1]-'0'))+10*(s[len-1]-'0')+(s[len]-'0');
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1 = convert2minutes(event1[0]);
        int end1 = convert2minutes(event1[1]);
        int start2 = convert2minutes(event2[0]);
        int end2 = convert2minutes(event2[1]);
        if(start1>start2){
            swap(start1, start2);
            swap(end1, end2);            
        }
        return start2 >= start1 && start2 <= end1;
    }
};