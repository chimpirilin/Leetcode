// https://leetcode.com/problems/pass-the-pillow/
class Solution {
public:
    int passThePillow(int n, int time) {
        int person = 1, dir = 1;
        while(time--){
            person += dir;
            if (person == n){
                dir = -1;
            }else if (person == 1) dir = 1;
        }
        return person;
    }
};