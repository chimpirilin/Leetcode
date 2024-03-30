#include <bits/stdc++.h>
// C++ STL: Policy based data structures
// gives us access to an order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace  __gnu_pbds;
// typedef tree<int,null_type,less<int>,//key,mapped type, comparator
//     rb_tree_tag,tree_order_statistics_node_update> myset;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>, //Use this when you need a multiset
   rb_tree_tag,tree_order_statistics_node_update> myset; //Use insert({x,++cnt}) to get unique elements

//find_by_order(i) devuelve iterador al i-esimo elemento, 0-indexed!
//That is, find_by_order returns the first element
//order_of_key(k): devuelve la pos del lower bound de k
//Ej: 12, 100, 505, 1000, 10000.
//order_of_key(10) == 0, order_of_key(100) == 1,
//order_of_key(707) == 3, order_of_key(9999999) == 5

// https://leetcode.com/problems/sliding-subarray-beauty/
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        myset orderStatistic;
        vector<int> ans;
        deque<pair<int, int>> toDelete;
        int cnt = 0;
        int n = int(nums.size());
        for(int i = 0; i < n; i++){
            auto insertedValue = make_pair(nums[i], ++cnt);
            toDelete.push_front(insertedValue);
            orderStatistic.insert(insertedValue);
            if(orderStatistic.size()<k) continue;
            auto val = *orderStatistic.find_by_order(x-1);
            if(val.first < 0) ans.push_back(val.first);
            else ans.push_back(0);
            pair<int, int> nextDelete = toDelete.back();
            toDelete.pop_back();
            orderStatistic.erase(orderStatistic.find_by_order(orderStatistic.order_of_key(nextDelete)));
        }

        return ans;
    }
};