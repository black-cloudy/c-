#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
// 1. 基础结构体定义 
struct Date {
    int year;
    int month;
    int day;
};
 
// 2. 包含嵌套结构体、构造函数、动态内存 
struct Student {
    // 静态成员（类级别计数）                         静态成员变量在使用后不会被释放，且下一次使用时保留上一次的值
    static int totalStudents;  
    
    // 常规成员 
    char name[20];
    int age;
    float* scores;  // 动态数组 
    int scoreCount;
    
    // 嵌套结构体 
    struct Address {
        char city[20];
        char street[50];
    } address;
 
    
    //指针函数   本质是一个函数，返回值类型是一个指针。返回类型* 函数名(参数)
    int* getPointer(int x) { 
        int* ptr = &x;
        return ptr; // 返回一个int类型的指针
    }

    // 3. 函数指针   返回类型 (*指针名)(参数列表) 函数指针成员可以指向任何函数，包括全局函数、成员函数、lambda表达式等 
    float (*calcTotal)(const Student&);                                              //Student& 表示对 Student 类对象的 引用（Reference），其核心作用是 为现有对象创建一个别名，操作引用等同于直接操作原对象
 
    // 4. 构造函数与析构函数 
    Student(const char* n, int a) : age(a), scores(nullptr), scoreCount(0) {         //构造函数 Student(const char* n, int a)    const char* nage(a)：将参数 a 赋值给成员变量 age（通常为年龄） scores(nullptr)：初始化动态数组指针 scores 为空指针（后续可能需要动态分配内存存储成绩）。 scoreCount(0)：成绩数量初始化为 0。
        totalStudents++;                                                             //每次创建对象时都会加1
        cout << "totalStudents" << totalStudents << endl;
        strncpy(name, n, sizeof(name)-1);                                           //将参数 n（姓名字符串）复制到 name 字符数组中 
    }
 
    ~Student() {
        delete[] scores;                                                          //释放 scores 指向的动态分配内存           这段代码没有使用到
        totalStudents--;
        cout << "11111111111" << totalStudents << endl;

    }

    // 构造函数：用于初始化对象（名称强制相同）
    // 成员函数：对象的行为操作（自由命名）
    // 析构函数：用于资源清理（名称强制为~类名）
 
    // 5. 运算符重载（比较年龄）
    bool operator>(const Student& other) const {                                //一个结构体中可以有多个运算符重载，此时将需要计算的参数和重载中参数类型匹配，用相匹配的第一个重载计算
        return age > other.age; 
    }
};
int Student::totalStudents = 0;
 
// 6. 独立函数（用于函数指针）
float calculateTotalScore(const Student& s) {                                 //const Student& s将student重命名为s
    float total = 0;
    for(int i=0; i<s.scoreCount;  ++i)
        total += s.scores[i]; 
    return total;
}
 
// 7. 包含位域的结构体 
struct CompactData {
    unsigned gender : 1;   // 0-男 1-女 
    unsigned status : 2;   // 0-正常 1-警告 2-错误 
};
 
// 8. 输入/输出重载                                                             重载函数就是定义一个相同功能但是参数不同的函数（函数名相同），比如求和函数，add(int a, int b)和add(double a, double b)都可以求和，但是参数类型不同。
// 定义的时候还是需要定义两个不同类型不同参数的函数，只不过名字一样而已

// #include <iostream>
// using namespace std;

// // 整数求和的函数
// int add(int a, int b) {
//     return a + b;
// }

// // 浮点数求和的函数
// double add(double a, double b) {
//     return a + b;
// }

// int main() {
//     // 使用整数版本的 add 函数
//     int sumInt = add(3, 5);
//     cout << "整数求和结果: " << sumInt << endl;

//     // 使用浮点数版本的 add 函数
//     double sumDouble = add(3.5, 2.7);
//     cout << "浮点数求和结果: " << sumDouble << endl;

//     return 0;
// }

istream& operator>>(istream& is, Date& d) {                                 //istream 和 ostream 是用于处理输入和输出的类。
    char delimiter;
    return is >> d.year  >> delimiter >> d.month  >> delimiter >> d.day; 
}
 
ostream& operator<<(ostream& os, const Date& d) {
    return os << d.year  << "-" << d.month  << "-" << d.day; 
}
 
int main() {
    // 9. 结构体数组与动态内存 
    Student students[3] = {                   //创建结构体中的对象
        {"Alice", 18},        //自动匹配字符，然后整型
        {"Bob", 19},
        {"Charlie", 20}
    };
 
    // 动态分配成绩数组 
    students[0].scoreCount = 3;
    students[0].scores = new float[3]{85.5, 92.0, 78.5};
 
    // 设置函数指针 
    students[0].calcTotal = calculateTotalScore;                            //可在calculateTotalScore前面加地址符&,也可不加，习惯上不加
    cout << "Alice总成绩: " << students[0].calcTotal(students[0]) << endl;
 
    // 10. 使用嵌套结构体 
    students[0].address = {"Beijing", "Zhongguancun St."};
 
    // 11. 运算符重载应用 
    if(students[1] > students[0]) {                       //被编译器转换为students[1].operator>(students[0])
        cout << students[1].name << "年龄更大" << endl;
    }
 
    // 12. 静态成员使用 
    cout << "当前学生总数: " << Student::totalStudents << endl;     //结构体中单个量用::  嵌套结构用 结构体名字.结构体
 
    // 13. 位域结构体 
    CompactData cd;
    cd.gender  = 0;
    cd.status  = 1;
 
    // 14. 日期输入输出 
    Date today;
    cout << "输入日期(yyyy-mm-dd): ";
    cin >> today;
    cout << "今天是: " << today << endl;
 
    return 0;
}




// class Counter {
//     public:
//         static int count;  // 声明静态成员变量 
//         Counter() { count++; }
//     };
//     int Counter::count = 0;  // 类外初始化 
//     int main() {
//         Counter a;  // count=1 
//         Counter b;  // count=2 
//         std::cout << Counter::count;  // 输出2 
//         return 0;
//     }
// 要明确class Counter是定义一个名为Counter的类，而Counter()是这个类的构造函数。构造函数的名称必须与类名相同，所以当用户看到Counter()时，它属于类Counter的一部分。



