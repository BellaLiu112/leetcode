#include <map>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> count;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i){
            it = count.find(nums[i]);
            if (it != count.end())
                count.erase(it);
            else
                count.insert(make_pair(nums[i], 1));
        }
        return count.begin()->first;
    }
        
};