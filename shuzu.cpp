#include <iostream>
#include <vector>             //#include <vector> 是 C++ 中引入动态数组容器的关键指令，
#include <algorithm>  // 用于排序和查找 
using namespace std;
 
// 函数1：打印数组内容（演示数组作为函数参数）
void printArray(int arr[], int size) {
    cout << "数组内容：";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
// 函数2：处理多维数组 
void processMultiArray() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "\n多维数组第二行第三列值：" << matrix[1][2] << endl;
}
 
int main() {
    // ------------------------- 基础操作 ------------------------- 
    // 1. 静态数组声明与初始化 
    int staticArr[5] = {3, 1, 4, 1, 5};
    cout << "1111111" <<sizeof(staticArr)<<endl;
    cout << "222222222" <<sizeof(staticArr[0])<<endl;
    cout << "静态数组大小：" << sizeof(staticArr)/sizeof(staticArr[0]) << endl;         //整个数组占了多少字节数，然后除以一个元素占的字节数，即为多少个元素
   
    
 
    // 2. 数组遍历与修改 
    staticArr[2] = 99;
    printArray(staticArr, 5);
 
    // 3. 数组排序（升序）
    sort(staticArr, staticArr + 5);
    cout << "排序后数组：";
    for (auto num : staticArr) {  // 范围for循环 
        cout << num << " ";
    }
    cout << endl;
 
    // ------------------------- 动态内存 ------------------------- 
    // 4. 动态数组分配与释放 
    int* dynamicArr = new int[3];
    dynamicArr[0] = 10;
    dynamicArr[1] = 20;
    dynamicArr[2] = 30;
    cout << "\n动态数组第二个元素：" << dynamicArr[1] << endl;
    delete[] dynamicArr;  // 必须手动释放内存 
 
    // ------------------------- STL容器 ------------------------- 
    // 5. vector动态数组操作 
    vector<int> vec = {7, 2, 5, 1};
    vec.push_back(8);   // 添加元素 
    vec.pop_back();     // 删除末尾元素 
    cout << "\nvector大小：" << vec.size()  << endl;
 
    // 6. 使用算法库查找元素 
    auto it = find(vec.begin(),  vec.end(),  5);
    if (it != vec.end())  {
        cout << "元素5在vector中的位置：" << distance(vec.begin(),  it) << endl;
    }
 
    // ------------------------- 多维数组 ------------------------- 
    processMultiArray();
 
    return 0;
}