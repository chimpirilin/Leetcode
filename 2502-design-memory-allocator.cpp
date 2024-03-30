// https://leetcode.com/problems/design-memory-allocator/
class Allocator {
public:
    vector<int> v;
    int m;
    Allocator(int n) {
        v.resize(n);
        fill(v.begin(), v.end(), 0);
        m=n;
    }
    
    int allocate(int size, int mID) {
        int cnt=0;
        int pos = 0;
        int i = 0;
        bool found = false;
        while(i < m){
            if(v[i]!=0){
                cnt = 0;
                pos = i+1;
            }else{
                ++cnt;
                if(cnt == size){
                    found = true;
                    break;
                }
            }
            ++i;
        }
        if(!found) return -1;
        for(i = pos;i<pos+size;++i) v[i] = mID;
        return pos;
    }
    
    int free(int mID) {
        int ans = 0;
        for(int i = 0;i<m;++i){
            if(v[i] == mID){
                v[i] = 0;
                ++ans;
            }
        }
            return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */