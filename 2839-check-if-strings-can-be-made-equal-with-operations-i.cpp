// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
class Solution {
public:
    bool canBeEqual(string s, string t) {
        vector<string> v1, v2;
        string s1 = s;
        swap(s1[0], s1[2]);
        string s2 = s1;
        swap(s2[1], s2[3]);
        string s3 = s;
        swap(s3[1], s3[3]);
        v1.push_back(s);
        v1.push_back(s1);
        v1.push_back(s2);
        v1.push_back(s3);

        string t1 = t;
        swap(t1[0], t1[2]);
        string t2 = t1;
        swap(t2[1], t2[3]);
        string t3 = t;
        swap(t3[1], t3[3]);
        v2.push_back(t);
        v2.push_back(t1);
        v2.push_back(t2);
        v2.push_back(t3);

        for(auto x:v1) {
            for(auto y:v2) {
                if(x == y){
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    return 0;
}