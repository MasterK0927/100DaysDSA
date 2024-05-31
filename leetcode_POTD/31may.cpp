#include <vector>
#include <iostream>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    unsigned int xorResult = 0;
    for (int num : nums) {
        xorResult ^= num;
    }
    
    unsigned int diffBit = xorResult & (-xorResult);

    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & diffBit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }

    return {num1, num2};
}

int main() {
    vector<int> nums = {1, 1, 0, -2147483648};
    vector<int> result = singleNumber(nums);
    cout << result[0] << result[1] << endl;
    return 0;
}
