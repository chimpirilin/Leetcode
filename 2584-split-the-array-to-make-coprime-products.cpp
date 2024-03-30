// https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/
class Solution {
public:
    const static int maxn=1000010;
    bool v[maxn];
    int len, sp[maxn];
    map<int, int> lastPos;

    //sp stores the smallest prime that divides n
    void factsieve(){
        for (long long i = 2; i < maxn; i += 2)
            sp[i] = 2;
        for (long long i = 3; i < maxn; i += 2){
            if (!v[i]){
                sp[i] = i;
                for (long long j = i; (j*i) < maxn; j += 2){
                    if (!v[j*i])
                        v[j*i] = true, sp[j*i] = i;
                }
            }
        }
    }

    //o(log n)
    //first run factsieve
    void updatePos(int n, int pos){
        while(n>1){
            auto it = lastPos.find(sp[n]);
            if(it==lastPos.end()) lastPos[sp[n]] = pos;
            else lastPos[sp[n]] = max(pos, lastPos[sp[n]]);
            n/=sp[n];
        }
    }

    int getLastPos(int n){
        int pos = 0;
        while(n>1){
            pos = max(pos, lastPos[sp[n]]);
            n/=sp[n];
        }
        return pos;
    }

    int findValidSplit(vector<int>& nums) {
        factsieve();
        int idx = 0;
        for(auto x:nums){
            updatePos(x, idx);
            ++idx;
        }
        int pos = -1;
        idx = -1;
        int lim = (int)nums.size() - 1;
        if(lim==0) return -1;
        while(1){
            idx++;
            if(idx>=lim) break;
            auto x = nums[idx];
            int curLast = getLastPos(x);
            if(curLast == idx) continue;
            if (curLast > pos) {
                pos = curLast;
                lim = pos+1;
            }
            if(idx >= pos) break;
        }
        if(pos == -1) return 0;
        if (pos == (int)nums.size()-1) return -1;
        return pos;
    }
};