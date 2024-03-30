// https://leetcode.com/problems/prime-subtraction-operation/
class Solution {

    long long sieve_size;
    bitset<10000009> bs;

    void sieve(long long upperbound){
        sieve_size = upperbound;
        bs.set();
        bs[0] = bs [1] = 0;
        for(long long i = 2; i <= sieve_size; i++)
            if(bs[i]) {
                for (long long j = i*i; j <= sieve_size; j+=i)
                    bs[j] = 0;
            }
    }

    bool isPrime(int x){
        return bs[x];
    }

public:
    bool isSorted(vector<int>& nums){
        for(int i=0;i<(int)nums.size()-1;++i){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        sieve(2000);
        int pre = 0;
        bool isPossible = true;
        for(auto x:nums){
            int cur = x;
            for(int i=x-1;i>=2;--i){
                if(isPrime(i)) {
                    if(x-i>pre){
                        cur = x-i;
                        break;
                    }
                }
            }
             if(pre>=cur){
                    isPossible = false;
                    break;
                }
                pre = cur;
            
        }
        return isPossible;
    }
};