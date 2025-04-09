// #include <iostream>   // 包含输入输出流库 
// using namespace std;  // 使用标准命名空间（简化代码）
 
// int main() {
//     // 输出语句：向控制台打印文本 
//     cout << "Hello, World!" << endl;
//     cout << "今天是2025年3月19日，农历二月廿十。" << endl;
    
//     return 0;  // 主函数返回0表示程序正常结束 
// }


// class Solution {
//     public:
//         int numIdenticalPairs(vector<int>& nums) {
//             int count=0;
//             for(int i=0;i<nums.size();i++)
//             {
//                 for(int j=i+1;j<nums.size();j++)
//                 {
//                     if(nums[i]==nums[j])
//                     {
//                         count++;
//                     }
//                 }
//                 return count;
//             }
//          }
//     };


// class Solution {
//     public:
//         int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
//             int count=0;
//             for(int i=0;i<arr.size();i++)
//             {
//                 for(int j=i+1;j<arr.size();j++)
//                 {
//                     for(int k=j+1;k<arr.size();k++)
//                     {
//                         if(abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c)
//                         {
//                             count++;
//                         }
//                     }

//                 }
//             }
//             return count;
            
//         }
//     };


// SELECT product_id
// FROM Products
// WHERE low_fats='Y' && recyclable = 'Y';


// class Solution {
//     public:
//         string toLowerCase(string s) {
//             for(int i=0;i<s.size();i++)
//             {
//                 if(s[i]>='A' && s[i]<='Z')
//                 {
//                     s[i]=s[i]+32;
//                 }
//             }
//             return s;
//         }
//     };


// #include <vector>
// #include <iostream> 
// using namespace std;

// class Solution 
// {
//     public:
//         int addDigits(int num)
//         {
//             int sum=0;
//             int temp;
//             vector<int> digits; // 用于存储各位数字
//             if (num < 10) 
//             { // 特殊情况
//                 temp=num;
//             }
//             if(num>=10)
//             {
//                 while(num>=10)
//                 {
//                     while (num > 0) 
//                     {
//                         digits.push_back(num % 10); // 获取个位数
//                         num /= 10;                 // 去掉个位
//                     } 
//                     for (int digit : digits) 
//                     {
//                         sum=sum+digit;
//                     }
//                     digits.clear(); // 清空 digits 容器
//                     num=sum;
//                     sum=0;
//                 }
//                 temp=num;

//             }
//             return temp;
//         }
// };

// int main() {
//     Solution s;
//     int num=14;
//     cout<<s.addDigits(num)<<endl;
//     return 0;
// }



// #include <vector>
// #include <iostream> 
// using namespace std;

// class Solution 
// {
//     public:
//         int subtractProductAndSum(int num)
//         {
//             int sum=0;
//             int product=1;
//             vector<int> digits;
//             while (num > 0) 
//             {
//                 digits.push_back(num % 10); // 获取个位数
//                 num /= 10;                 // 去掉个位
//             } 
//             for (int digit : digits) 
//             {
//                 sum=sum+digit;
//             }
//             for (int digit : digits) 
//             {
//                 product=product*digit;
//             }
//             digits.clear(); // 清空 digits 容器
//             return product-sum;
//         }
// };

// int main() {
//     Solution s;
//     int num=234;
//     cout<<s.subtractProductAndSum(num)<<endl;
//     return 0;
// }



// class Solution {
//     public:
//         bool isPowerOfTwo(int n) {
//             if (n > 0 && (n & (n - 1)) == 0) {
//                 return true;
//             } else {
//                 return false;
//             }
//         }
//     };

// #include <vector>
// #include <iostream> 
// using namespace std;

// class Solution {
//     public:                  //当一个成员被声明为public时，它可以在类的内部访问，也可以在类的外部通过类的对象访问
//         bool isUgly(int n) {
//             if (n <= 0) 
//             {
//                 return false;
//             }
//             for (int i = 2; i <= n / i; i++) 
//             {
//                 if (n % i == 0) 
//                 {
//                     if (i == 2 || i == 3 || i == 5) 
//                     {
//                         continue;
//                     }
//                     else 
//                     {
//                         return false;
//                     }
//                 }
//             }
//             return true;
//         }
//     };

// int main() {
//     Solution s;
//     int num=14;
//     if(s.isUgly(num)){
//         cout<<"true"<<endl;
//     }
//     else{
//         cout<<"false"<<endl;
//     }
//     return 0;
// }


// #include <vector>
// #include <iostream> 
// using namespace std;
// class Solution {
//     public:
//         vector<int> shuffle(vector<int>& nums, int n) {
//             vector<int> res(2*n);
//             for(int i=0;i<n;i++)
//             {
//                 res[2*i]=nums[i];  
//                 res[2*i+1]=nums[n+i];
//             }
//             return res;
            
//         }
//     };


// #include <vector>
// #include <iostream> 
// using namespace std;
// class Solution {
//     public:
//         vector<vector<int>> transpose(vector<vector<int>>& matrix) {
//             int m=matrix.size();
//             int n=matrix[0].size();
//             vector<vector<int>> res(n,vector<int>(m));
//             for(int i=0;i<m;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {

//                     res[j][i]=matrix[i][j];
//                 }
//             }
//             return res;
            
//         }
//     };


// #include <vector>
// #include <iostream> 
// using namespace std;
// class Solution {
//     public:
//         int maxScore(string s) {
//             int count0=0;
//             int count1=0;
//             int max=0;
//             for(int i=0;i<s.size()-1;i++)
//             {
//                 for(int j=0;j<=i;j++)
//                 {
//                     if (s[j]=='0')
//                     {count0++;}
//                 }
//                 for(int k=i+1;k<s.size();k++)
//                 {
//                     if (s[k]=='1')
//                     {count1++;}
//                 }
//                 if(count0+count1>max)
//                 {
//                     max=count0+count1;
//                 }
//                 count0=0;
//                 count1=0;
//             }
//             return max;
//         }

//     };


// #include <vector>
// #include <iostream> 
// using namespace std;
// class Solution {
//     public:
//         int vowelStrings(vector<string>& words, int left, int right) {
//             int count=0;
//             for(int i=left;i<=right;i++)
//             {
//                 int j=words[i].size()-1;
//                 if((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u')&&(words[i][j]=='a' || words[i][j]=='e' || words[i][j]=='i' || words[i][j]=='o' || words[i][j]=='u'))
//                 {
//                     count++;
//                 }

//             }
//             return count;
//         }
//     };



// #include <vector>
// #include <iostream> 
// using namespace std;
// class Solution {
//     public:
//         int peakIndexInMountainArray(vector<int>& arr) {
//             int index=0;
//             int max=arr[0];
//             for(int i=0;i<arr.size();i++)
//             {
//                 if(arr[i]>max)
//                 {
//                     max=arr[i];
//                     index=i;
//                 }
//             }
//             return index;
//         }
//     };

// class Solution {
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
//             for(int i=0;i<nums.size()-1;i++)
//             {
//                 for(int j=i+1;j<nums.size();j++)
//                 {
//                     if(nums[i]+nums[j]==target)
//                     {
//                         return {i,j};
//                     }
//                 }
//         }
//     };

// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> anagramMap; // 哈希表来存储分组结果

//         for (const string& str : strs) {
//             string sortedStr = str; // 拷贝原字符串 
//             sort(sortedStr.begin(), sortedStr.end()); // 对字母进行排序
//             anagramMap[sortedStr].push_back(str); // 以排序后的字符串为键，将原字符串添加到对应值的列表中
//         }

//         vector<vector<string>> result;
//         for (auto& entry : anagramMap) {
//             result.push_back(entry.second); // 将哈希表中的值添加到结果中
//         }

//         return result;
//     }
// };


// int main() {
//     Solution s;
//     vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//     vector<vector<string>> result = s.groupAnagrams(strs);
//     for (const auto& group : result) {
//         for (const string& str : group) {
//             cout << str << " ";
//         }
//     }
//     return 0;   
// }



// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> anagramMap; // 哈希表来存储分组结果

//         for (const string& str : strs) {
//             string sortedStr = str; // 拷贝原字符串 
//             cout << "1111111111: " << sortedStr << endl;
//             sort(sortedStr.begin(), sortedStr.end()); // 对字母进行排序
//             cout << "Original string: " << str << ", Sorted string: " << sortedStr << endl; // 输出原字符串和排序后的字符串
//             anagramMap[sortedStr].push_back(str); // 以排序后的字符串为键，将原字符串添加到对应值的列表中
//             cout << "Adding string \"" << str << "\" to anagram group with key \"" << sortedStr << "\"" << endl;
//             cout << "Current strings in group with key \"" << sortedStr << "\": ";
//             for (const string& s : anagramMap[sortedStr]) {
//                 cout << s << " ";
//             }
//             cout << endl;
//         }

//         vector<vector<string>> result;
//         for (auto& entry : anagramMap) {
//             cout << "Anagram group key: " << entry.first << endl; // 输出分组的键
//             for (const string& str : entry.second) {
//                 cout << "String in this group: " << str << endl; // 输出分组中的每个字符串
//             }
//             result.push_back(entry.second); // 将哈希表中的值添加到结果中
//         }

//         return result;
//     }
// };

// int main() {
//     Solution s;
//     vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//     cout << "Input strings: ";
//     for (const string& str : strs) {
//         cout << str << " ";
//     }
//     cout << endl;

//     vector<vector<string>> result = s.groupAnagrams(strs);

//     cout << "Grouped anagrams:" << endl;
//     for (const auto& group : result) {
//         for (const string& str : group) {
//             cout << str << " ";
//         }
//         cout << endl;
//     }

//     return 0;   
// }


// #include <iostream>
// #include <vector>
// #include <algorithm> // 包含sort函数
// using namespace std;

// class Solution {
//     public:
//         int longestConsecutive(vector<int>& nums) {
//          std::sort(nums.begin(), nums.end());
//          int max_len = 1;
//          int count=0;
//          for(int i=1; i<nums.size(); i++) 
//         {
//              if(nums[i] == nums[i-1]) 
//              {
//                  count++;
//              }
//         }

//          for(int j=nums.size()-1;j>0; j--) 
//          {
//             if(nums[0]==0)
//             {
//                 if(j == nums[j]+count)
//                 {
//                     max_len=max(nums[j]+1, count+1);
//                     break;
//                 }

//             }
//             if(nums[0]!=0)
//             {
//                 if(j == nums[j]+count-1)
//                 {
//                     max_len=max(nums[j], count+1);
//                     // cout<<nums[j]<<" "<<count+1<<endl;
//                     break;

//                 }
//             }
//         }
//          return max_len;
            
//         }
//     };

//     int main() {
//         std::vector<int> numbers = {100, 4, 200, 1, 3, 2}; // 定义一个整数向量
//         Solution s;
//         std::cout << "The longest consecutive sequence is: " << s.longestConsecutive(numbers) << std::endl;
//         return 0;
//     }   
//             // if(j == nums[j]+count)
            // {
            //     if(nums[0]=0)
            //     {
            //         max_len=max(nums[j]+1, count+1);
            //     }
            //     if(nums[0]!=0)
            //     {
            //         max_len=max(nums[j], count+1);
            //     }
            //     break;

            // }






// int main() {
//     std::vector<int> numbers = {5, 2, 9, 1, 5, 6}; // 定义一个整数向量

//     std::cout << "Before sorting: ";
//     for (int num : numbers) {                      //类似for num in numbers，遍历numbers中的元素
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     // 使用std::sort对numbers进行排序
//     std::sort(numbers.begin(), numbers.end());

//     std::cout << "After sorting: ";
//     for (int num : numbers) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }




// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <algorithm> // 包含sort函数
// using namespace std;

// class Solution {
//     public:
//         int longestConsecutive(std::vector<int>& nums) {
//             // 如果数组为空，直接返回 0
//             if (nums.empty()) {
//                 return 0;
//             }
    
//             // 将数组元素存入哈希集合
//             std::unordered_set<int> numSet(nums.begin(), nums.end());
//             int max_len = 0;
//             // 类比：想象你有一排书，每本书都有一个编号（例如第1本到第10本）。
//             // nums.begin() 相当于指向第一本书的指针。
//             // nums.end() 相当于指向“第十本书后面”的空白位置，它不代表任何实际的书，只是用来标记结束位置。
//             for (int num : nums) {
//                 // 如果当前数不是连续序列的起点，则跳过
//                 if (numSet.find(num - 1) != numSet.end()) {               //nums.end()就相当于最后一页的空白页，如果找到了就不等于空白页，说明找到了连续序列的起点，开始计算长度。如果==就说明list中没有这个数。
//                     continue;                                             //不排序，直接找这个数是否有前一个数（即是否有一个小于他1的数）
//                 }
    
//                 // 找到一个连续序列的起点，开始计算长度
//                 int current_num = num;
//                 int current_streak = 1;
    
//                 while (numSet.find(current_num + 1) != numSet.end()) {
//                     current_num += 1;
//                     current_streak += 1;
//                 }
    
//                 // 更新最长连续序列的长度
//                 max_len = std::max(max_len, current_streak);
//             }
    
//             return max_len;
//         }
//     };

// int main() {
//     std::vector<int> numbers = {1,0,1,2}; // 定义一个整数向量
//     Solution s;
//     std::cout << "The longest consecutive sequence is: " << s.longestConsecutive(numbers) << std::endl;
//     return 0;
// }   
    



// class Solution {
//     public:
//         void moveZeroes(vector<int>& nums) {
//             int write_ptr = 0;
//             for (int read_ptr = 0; read_ptr < nums.size();  ++read_ptr) {
//                 cout << "read_ptr: " << read_ptr << " write_ptr: " << write_ptr << endl;
//                 if (nums[read_ptr] != 0) {
//                     cout << "nums[read_ptr]: " << nums[read_ptr] << endl;
//                     nums[write_ptr++] = nums[read_ptr];
//                 }
//                 for(int i=0; i<nums.size(); i++)
//                 {
//                     cout << nums[i] << " ";
//                 }
//                 cout << endl;
//             }
//             fill(nums.begin()  + write_ptr, nums.end(),  0);
//             cout << "nums.size(): " << nums.size() << " write_ptr: " << write_ptr << endl;
//         }
//     };

// int main() {
//     vector<int> numbers = {1,1,0,3,12}; // 定义一个整数向量
//     Solution s;
//     s.moveZeroes(numbers);
//     for (int num : numbers) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

// class Solution {
//     public:
//         int maxArea(vector<int>& height) {
//             int left=0;
//             int right=height.size()-1;
//             int max_area=0;
//             while(left<right)
//             {
//                 max_area=max(max_area,(right-left)*min(height[left],height[right]));
//             }
//             if(height[left]<height[right])
//             {
//                 left++;
//             }
//             else
//             {
//                 right--;
//             }
//             return max_area;
//         }
//     };


// class Solution {
//     public:
//         vector<vector<int>> threeSum(vector<int>& nums) {
//             vector<vector<int>> result;
//             sort(nums.begin(), nums.end());
//             for(int i=0;i<nums.size()-2;i++)
//             {
//                 if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复的元素
//                 int j = i + 1;
//                 int k = nums.size() - 1;
//                 while (j < k) 
//                 {
//                     int sum = nums[i] + nums[j] + nums[k];
//                     if (sum == 0) 
//                     {
//                         result.push_back({nums[i], nums[j], nums[k]});
//                         // 跳过重复的元素
//                         while (j < k && nums[j] == nums[j + 1]) j++;
//                         while (j < k && nums[k] == nums[k - 1]) k--;
//                         j++;
//                         k--;
//                     }
//                     else if(nums[i]+nums[j]+nums[k]>0)
//                     {
//                         k--;
//                         // cout << "k: " << k << endl;
//                     }
//                     else
//                     {
//                         j++;
//                         // cout << "j: " << j << endl;
//                     }

//                 }
                
//             }
//             return result;
//         }
//     };
// int main() {
//     vector<int> numbers = {-1,0,1,2,-1,-4}; // 定义一个整数向量
//     Solution s;
//     vector<vector<int>> result = s.threeSum(numbers);
//     for (const auto& group : result) {
//         for (const int& num : group) {
//             std::cout << num << " ";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }


// class Solution {
//     public:
//         int trap(vector<int>& height) {
//             int all_area=0;
//             for(int i=0;i<height.size();)
//             {
                
//                 if(height[i+1]>=height[i])
//                 {continue;}
//                 else
//                 {
//                     int left=i+1;
//                     int right=i+2;
//                     int down_left=i;
//                     int down_right;
//                     while(height[left]>=height[right])
//                     {
//                         left++;
//                         right++;
//                     }
//                     down_right=left;
//                     int up_left=left;
//                     int up_right=right;
//                     while(height[up_left]<height[up_right])
//                     {
//                         up_left++;
//                         up_right++;
//                     }
//                     int sum=0;
//                     while(left+1<up_right-1)
//                     {
//                         int sum=sum+height[left+1];
//                         left++;

//                     }
//                     int area=min(height[left],height[up_right-1])*(up_right-1-left)-sum;
//                     all_area=all_area+area;
//                 }
//             }
//         return all_area;
//         }
//     };
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <algorithm> // 包含sort函数
// using namespace std;
// class Solution {
//     public:
//         int trap(std::vector<int>& height) {
//             int sum=0;
//             int area;
//             for(int i=0;i<height.size();i++)
//             {
//                 if(height[i]==0)
//                 {cout << "height[i]: " << height[i] << endl;
//                     continue;}
//                 int count=1;
//                 int j=i+1;
//                 cout << "i: " << i << endl;
//                 while(height[i]>=height[j])
//                 {
//                     count++;
//                     cout << "count: " << count << endl;
//                     j++;
//                     cout << "j: " << j << endl;
//                     int area=height[i]*count;
//                     cout << "area: " << area << endl;
//                 }
//                 sum=sum+area;
//                 i=j-1;
//             }
//             return sum;
//         }
          
//     };
// int main() {
//     vector<int> numbers = {0,1,0,2,1,0,1,3,2,1,2,1}; // 定义一个整数向量
//     Solution s;
//     std::cout << "The trap area is: " << s.trap(numbers) << std::endl;
//     return 0;
// }





#include <iostream> 
int main() { 
    try { 
        int numerator = 10; 
        int denominator = 0; 
        int result = numerator / denominator; 
        std::cout << "Result: " << result << std::endl; 
        if (denominator == 0) { 
            throw "Division by zero!"; // 抛出一个字符串类型的异常 
        } 
        
    } 
    catch (const char* msg) { 
        std::cerr << "Error: " << msg << std::endl; 
    } 
    return 0; 
} 