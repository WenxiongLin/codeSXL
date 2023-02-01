#include <unordered_set>

using namespace std;

class Solution {
public:
    // 获取每个位置上的数字平方和
    int getSum(int n) {
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        // 使用hash表
        // unordered_set<int> num;
        // while(1) {
        //     if(n == 1) return true;
        //     if(num.find(n) == num.end()){
        //         num.insert(n);
        //     } else {
        //         return false;
        //     }
        //     n = getSum(n);
        // }

        // 快慢指针法
        int slow = n;
        int fast = getSum(getSum(n));
        while(fast != 1 && slow != fast){
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        }
        return fast == 1;
    }
};