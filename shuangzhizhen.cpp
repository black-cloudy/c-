//双指针：快慢指针用于检测循环，左右指针用于数组的两端处理。
// 双指针的优势，比如时间复杂度的优化。比如，移除元素用暴力解法是O(n²)，而双指针可以做到O(n)



#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // 包含sort函数
using namespace std;
// 示例：移除数组中指定值（LeetCode 27）    将中间某个值去掉，然后其他不等于这个值的元素都往前挪一位，最后返回新的数组长度。
int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size();  ++fast) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast]; // 慢指针记录有效元素 
        }
    }
    return slow; // 返回新数组长度 
}


// 示例：两数之和 II（LeetCode 167）
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size()  - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {left+1, right+1};        //返回第几个数，从1开始
        sum < target ? left++ : right--; // 根据和大小移动指针 
    }
    return {};
}

