// 想象你正在火车上看风景，车窗是一个固定大小的框，随着火车前进，这个框里的景色会连续变化。滑动窗口算法就是这个原理：
// 窗口：一个连续的数据范围（如数组中的一段元素）。
// 滑动：窗口的左右边界根据条件同步或异步移动，遍历整个数据集。
// 窗口1: [x₀, x₁, x₂] → 窗口2: [x₁, x₂, x₃] → 窗口3: [x₂, x₃, x₄] ...

#include <iostream>
#include <unordered_set>
using namespace std;
 //查看字符串中不重复的连续子串的最大长度 
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window; // 存储窗口内的唯一字符  unordered_set<char> window; // 哈希集合存储窗口字符，实现O(1)重复检查 ，不会有重复的字符
    int max_len = 0;
    int left = 0; // 窗口左边界 
 
    // 右边界持续向右滑动 
    for (int right = 0; right < s.size();  right++) {
        // 发现重复字符时，左边界右移并删除左侧字符 
        while (window.count(s[right]))  {
            window.erase(s[left]); 
            left++;
        }
        // 将当前字符加入窗口 
        window.insert(s[right]); 
        cout << "窗口：";
        for (char c : window) {
            cout << c << " ";
        }
        cout << endl;
        // 更新最大窗口长度 
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}
 
int main() {
    string s = "abcabcbb";
    cout << "最长子串长度：" << lengthOfLongestSubstring(s); // 输出3（"abc"）
    return 0;
}