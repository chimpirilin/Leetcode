// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/

int digsum(int x){
    int sm=0;
    while(x>0){
        sm+=(x%10);
        x/=10;
    }
    return sm;
}

class Solution {
public:
    long long ten=10LL;
    int digsum(long long n){
        int sm=0LL;
        
        while(n>0){
            sm+=(x%ten);
            n/=ten;
        }
        return sm;
}
    long long makeIntegerBeautiful(long long n, int target) {
        long long p = 1;
        long long cur=0LL;
        while(1){
            if(digsum(n)<=target) break;
            lst = 0;
            long long tmp=n;
            for(int i=0;i<cnt;++i){
                tmp/=ten;
            }
            ++cnt;
            int lst = tmp%10;
            long long rm = 10-lst;
            cur+=p*rm;
            n+=p*rm
            P*=10;
        }
        return cur;
    }
};

int main(){
    int n = 467;
    for(int i =0 ;i<40;++i){
        cout<<n+i<<": "<<digsum(n+i)<<endl;
    }
    return 0;
}