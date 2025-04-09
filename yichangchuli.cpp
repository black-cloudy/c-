#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>
 
// 自定义异常类 [3]()
class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom exception: Data validation failed";
    }
};
 
// 带异常规范的函数 
void process_input(int value) {
    if (value < 0) {
        throw std::invalid_argument("Input cannot be negative");  // 标准异常 [1]()
    }
    if (value == 0) {
        throw MyException();  // 自定义异常 [3]()
    }
}
 
// 资源管理类 
class FileHandler {
public:
    FileHandler(const std::string& filename) {
        file.open(filename); 
        if (!file) {
            throw std::runtime_error("Failed to open file");  // 文件操作异常 [4]()
        }
    }
    
    ~FileHandler() { if(file) file.close();  }  // RAII机制 
    
private:
    std::fstream file;
};
 
int main() {
    try {
        // 示例1：标准库异常 [5]()
        int divisor = 0;
        std::cout << "Enter divisor: ";
        std::cin >> divisor;
        process_input(divisor);                    //这里出问题后就跳到catch块, 然后打印异常信息    try后面内容就不执行了
 
        // 示例2：内存分配异常 [2]()
        auto arr = std::make_unique<int[]>(1000000000000L);  // 智能指针管理资源 
 
        // 示例3：文件操作异常 [4]()
        FileHandler fh("nonexistent.txt"); 
 
    } 
    catch (const MyException& e) {  // 优先捕获具体异常 [3]()
        std::cerr << "Caught custom exception: " << e.what()  << "\n";
    }
    catch (const std::invalid_argument& e) {  // 标准异常捕获 [1]()           //catch块的后四种情况主要是为了处理那些可能由标准库函数或系统调用自动抛出的异常，确保程序在遇到问题时能够优雅地处理错误，而不是直接崩溃。
        std::cerr << "Invalid argument: " << e.what()  << "\n";             //所以后四种就不需要throw语句了
    }
    catch (const std::bad_alloc& e) {  // 内存异常 [2]()
        std::cerr << "Memory allocation failed: " << e.what()  << "\n";
    }
    catch (const std::exception& e) {  // 通用异常捕获 [5]()
        std::cerr << "Standard exception: " << e.what()  << "\n";
    }
    catch (...) {  // 捕获所有未知异常 [4]()
        std::cerr << "Unknown exception occurred\n";
    }
 
    return 0;
}