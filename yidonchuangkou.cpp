// 想象你正在火车上看风景，车窗是一个固定大小的框，随着火车前进，这个框里的景色会连续变化。滑动窗口算法就是这个原理：
// 窗口：一个连续的数据范围（如数组中的一段元素）。
// 滑动：窗口的左右边界根据条件同步或异步移动，遍历整个数据集。
// 窗口1: [x₀, x₁, x₂] → 窗口2: [x₁, x₂, x₃] → 窗口3: [x₂, x₃, x₄] ...

// #include <iostream>
// #include <unordered_set>
// using namespace std;
//  //查看字符串中不重复的连续子串的最大长度 
// int lengthOfLongestSubstring(string s) {
//     unordered_set<char> window; // 存储窗口内的唯一字符  unordered_set<char> window; // 哈希集合存储窗口字符，实现O(1)重复检查 ，不会有重复的字符
//     int max_len = 0;
//     int left = 0; // 窗口左边界 
 
//     // 右边界持续向右滑动 
//     for (int right = 0; right < s.size();  right++) {
//         // 发现重复字符时，左边界右移并删除左侧字符 
//         while (window.count(s[right]))  {
//             window.erase(s[left]); 
//             left++;
//         }
//         // 将当前字符加入窗口 
//         window.insert(s[right]); 
//         cout << "窗口：";
//         for (char c : window) {
//             cout << c << " ";
//         }
//         cout << endl;
//         // 更新最大窗口长度 
//         max_len = max(max_len, right - left + 1);
//     }
//     return max_len;
// }
 
// int main() {
//     string s = "abcabcbb";
//     cout << "最长子串长度：" << lengthOfLongestSubstring(s); // 输出3（"abc"）
//     return 0;
// }


#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) 
        {
            // unordered_set<char> window;                                   //哈希表不允许出现重复字符
            vector<int> result;
            int s_len = s.size();
            int p_len = p.size();
            
            if (s_len < p_len) {
                return result;
            }
            
            unordered_map<char, int> p_count;
            unordered_map<char, int> window_count;
            
            // 统计 p 中每个字符的出现次数
            for (char c : p) {
                p_count[c]++;
            }
            
            // 初始化窗口中前 p_len 个字符的出现次数
            for (int i = 0; i < p_len; i++) {
                window_count[s[i]]++;
            }
            
            // 检查初始窗口是否是字谜
            if (window_count == p_count) {
                result.push_back(0);
            }
            
            // 滑动窗口
            for (int right = p_len; right < s_len; right++) {
                char new_char = s[right];
                char old_char = s[right - p_len];
                
                // 删除旧字符
                window_count[old_char]--;
                if (window_count[old_char] == 0) {
                    window_count.erase(old_char);
                }
                
                // 插入新字符
                window_count[new_char]++;
                
                // 检查当前窗口是否是字谜
                if (window_count == p_count) {
                    result.push_back(right - p_len + 1);
                }
            }
            
            return result;
        }

            
        }
    };

