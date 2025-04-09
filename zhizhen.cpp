#include <iostream>
#include <memory>  // 智能指针需要 
 
// 函数指针类型定义 
void printValue(int* val) {
    std::cout << "Value: " << *val << std::endl;
}
 
int main() {
    // 基础指针操作 [1]()
    int var = 10;
    int* ptr = &var;  // 指针声明与初始化    int*:可以认为表示指针符号，把var的地址赋予给ptr，即ptr指向/等同于这个地址    指针必须与指向数据类型匹配（int*只能指向int）
    *ptr = 20;        // 解引用修改值        把这个地址的内容修改，*ptr表示把这个地址的内容取出来一样
    std::cout << "var: " << var << std::endl;
    


    // 指针与数组 [6]()
    int arr[3] = {1,2,3};                   //数组也是一个地址，是连续的地址
    int* arrPtr = arr;          // 数组名隐式转换为指针 
    std::cout << *(arrPtr+1);   // 指针算术运算输出arr[1]    arrptr表示的是arr[0]  *(arrptr=1)表示地址加1（arr[1]的地址），然后解引用，表示这个地址的内容




    
    // 动态内存管理 [7]()  动态内存管理是程序在运行时根据需求动态分配和释放内存的技术，主要用于处理数据规模未知或变化的情况。
    int* dynamicPtr = new int(5);  // 堆内存分配 
    delete dynamicPtr;             // 手动释放内存   释放 dynamicPtr 指向的堆内存，避免内存泄漏
    //int* p = new int(5);       分配一个int类型的内存空间并初始化为 5         *p 为 5            delete p;
    //int* p = new int[5];       分配一个包含5个int型数据的数组                                  需用 delete[] p



    // 二级指针 [9]()
    int** pp = &ptr;          // 指向指针的指针    指针也需要占用内存空间，所以pp指向ptr的地址，而不是指向var的地址
    **pp = 30;                // 双重解引用修改原始值         第一次解引用 *pp：获取 ptr 的值（即 var 的地址 0x1000）。第二次解引用 *(*pp)：通过 0x1000 直接修改 var 的值为 30
    std::cout << "var: " << var << std::endl;
    


    // 函数指针 [3]()
    void (*funcPtr)(int*) = printValue;  // 函数指针赋值   定义函数指针，函数参数为int型的指针
    funcPtr(&var);                       // 通过指针调用函数 
    


    // 指针数组与数组指针 [2]()
    int* ptrArray[3] = {&var, arr, arrPtr+2};  // 指针数组       数组元素为指针  是一个数组，里面的元素为指针
    int (*arrayPtr)[3] = &arr;                 // 数组指针       指向整个数组的指针    是一个指针，这个指针指向数组
 
    

    // const指针 [8]()                          常量指针：const int*（值不可改）与int* const（指向不可改）
    const int* cptr1 = &var;  // 指向常量的指针 
    int* const cptr2 = &var;  // 常量指针 
    
    // 智能指针 [7]()
    std::unique_ptr<int> smartPtr(new int(100));  // 自动内存管理 
    
    // 字符串指针 [10]()
    const char* str = "Hello Pointer";  // 字符串字面量指针 
    char strArr[] = "Pointer";          // 字符数组指针 
    
    // 空指针与野指针 [1]()
    int* nullPtr = nullptr;     // 空指针初始化 
    int* wildPtr;               // 未初始化野指针（危险示例）
    
    return 0;
}

