// https://leetcode.com/problems/minimum-additions-to-make-valid-string/
class Solution {
public:
    int addMinimum(string word) {
        int n = static_cast<int>(word.size());
        int i = 0;
        string s = word;
        int ans = 0;
        while(i < n) { 
            char c = s[i];
            switch(c) {
                case 'a':
                    if(i == n-1 || s[i+1] == 'a') {
                        ans += 2;
                        i += 1;
                        break;
                    }
                    if(s[i+1] == 'b') {
                        if(i == n-2){
                            ans += 1;
                            i += 2;
                        }else if(s[i+2] == 'c'){
                            i += 3;
                        }else{
                            ans += 1;
                            i += 2;
                        }
                        break;
                    }
                    //Reach here if AC case
                    ans  += 1;
                    i += 2;
                    break;
                case 'b':
                    if(i == n-1 || s[i+1] != 'c'){
                        ans += 2;
                        i += 1;
                    }else{
                        ans += 1;
                        i += 2;
                    }
                    break;
                case 'c':
                    ans += 2;
                    i += 1;
                    break;
            }
        }
        return ans;
    }
};