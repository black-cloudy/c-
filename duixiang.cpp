//----------------------------------------------类----------------------------------------------
// #include <iostream>
 
// using namespace std;
 
// class Box
// {
//    public:
//       double length;   // 长度
//       double breadth;  // 宽度
//       double height;   // 高度
//       // 成员函数声明
//       double get(void);
//       void set( double len, double bre, double hei );
// };
// // 成员函数定义                                                  放在类里面和外面定义差别不大，都可以
// double Box::get(void)
// {
//     return length * breadth * height;
// }
 
// void Box::set( double len, double bre, double hei)
// {
//     length = len;
//     breadth = bre;
//     height = hei;
// }
// int main( )
// {
//    Box Box1;        // 声明 Box1，类型为 Box
//    Box Box2;        // 声明 Box2，类型为 Box
//    Box Box3;        // 声明 Box3，类型为 Box
//    double volume = 0.0;     // 用于存储体积
 
//    // box 1 详述
//    Box1.height = 5.0; 
//    Box1.length = 6.0; 
//    Box1.breadth = 7.0;
 
//    // box 2 详述
//    Box2.height = 10.0;
//    Box2.length = 12.0;
//    Box2.breadth = 13.0;
 
//    // box 1 的体积
//    volume = Box1.height * Box1.length * Box1.breadth;
//    cout << "Box1 的体积：" << volume <<endl;
 
//    // box 2 的体积
//    volume = Box2.height * Box2.length * Box2.breadth;
//    cout << "Box2 的体积：" << volume <<endl;
 
 
//    // box 3 详述
//    Box3.set(16.0, 8.0, 12.0); 
//    volume = Box3.get(); 
//    cout << "Box3 的体积：" << volume <<endl;
//    return 0;
// }


//----------------------------------------------继承----------------------------------------------
// #include <iostream>
 
// using namespace std;
 
// // 基类
// class Shape 
// {
//    public:
//       void setWidth(int w)
//       {
//          width = w;
//       }
//       void setHeight(int h)
//       {
//          height = h;
//       }
//    protected:
//       int width;
//       int height;
// };
 
// // 派生类                               继承类的写法和基类（shape）类似，只是在类名前面加上关键字 class，然后在类名后面加上基类名，并用冒号 : 隔开
// class Rectangle: public Shape
// {
//    public:
//       int getArea()
//       { 
//          return (width * height);    //继承到shape类中的width和height成员变量
//       }
// };
 
// int main(void)
// {
//    Rectangle Rect;
 
//    Rect.setWidth(5);               //继承到shape的函数，所以Rectangle类中也有setHeight函数
//    Rect.setHeight(7);
 
//    // 输出对象的面积
//    cout << "Total area: " << Rect.getArea() << endl;
 
//    return 0;
// }

//----------------------------------------------------函数重载------------------------------------------
// #include <iostream>
// using namespace std;
 
// class printData
// {
//    public:
//       void print(int i) {
//         cout << "整数为: " << i << endl;
//       }
 
//       void print(double  f) {
//         cout << "浮点数为: " << f << endl;
//       }
 
//       void print(char c[]) {
//         cout << "字符串为: " << c << endl;
//       }
// };
 
// int main(void)
// {
//    printData pd;
//                                         //根据参数类别自动识别使用哪个函数
//    // 输出整数
//    pd.print(5);
//    // 输出浮点数
//    pd.print(500.263);
//    // 输出字符串
//    char c[] = "Hello C++";
//    pd.print(c);
 
//    return 0;
// }


//----------------------------------------------运算符重载----------------------------------------------
// #include <iostream>
// using namespace std;
 
// class Box
// {
//    public:
 
//       double getVolume(void)
//       {
//          return length * breadth * height;
//       }
//       void setLength( double len )
//       {
//           length = len;
//       }
 
//       void setBreadth( double bre )
//       {
//           breadth = bre;
//       }
 
//       void setHeight( double hei )
//       {
//           height = hei;
//       }
//       // 重载 + 运算符，用于把两个 Box 对象相加     重载运算符则是允许用户根据需要为自定义的数据类型定义特定运算符的行为
//       Box operator+(const Box& b)             //使用operator关键字来重载运算符  b 被声明为 const Box&，即一个常量引用，表示它是一个 Box 类的对象
//       {
//          Box box;
//          box.length = this->length + b.length;         //this 指针指向调用 operator+ 的 Box 对象。当你写 this->length 或 this->breadth 时，
//          box.breadth = this->breadth + b.breadth;      //你实际上是在访问调用这个运算符的 Box 对象的成员变量。这里的 b 是作为参数传递给重载运算符的另一个 Box 对象，用于与调用运算符的 Box 对象进行相加操作
//          box.height = this->height + b.height;         //Box1调用了operator+，Box2作为参数传递给operator+，Box3作为返回值返回给Box1
//          return box;
//       }
//    private:
//       double length;      // 长度
//       double breadth;     // 宽度
//       double height;      // 高度
// };
// // 程序的主函数
// int main( )
// {
//    Box Box1;                // 声明 Box1，类型为 Box
//    Box Box2;                // 声明 Box2，类型为 Box
//    Box Box3;                // 声明 Box3，类型为 Box
//    double volume = 0.0;     // 把体积存储在该变量中
 
//    // Box1 详述
//    Box1.setLength(6.0); 
//    Box1.setBreadth(7.0); 
//    Box1.setHeight(5.0);
 
//    // Box2 详述
//    Box2.setLength(12.0); 
//    Box2.setBreadth(13.0); 
//    Box2.setHeight(10.0);
 
//    // Box1 的体积
//    volume = Box1.getVolume();
//    cout << "Volume of Box1 : " << volume <<endl;
 
//    // Box2 的体积
//    volume = Box2.getVolume();
//    cout << "Volume of Box2 : " << volume <<endl;
 
//    // 把两个对象相加，得到 Box3
//    Box3 = Box1 + Box2;
 
//    // Box3 的体积
//    volume = Box3.getVolume();
//    cout << "Volume of Box3 : " << volume <<endl;
 
//    return 0;
// }


//----------------------------------------------多态----------------------------------------------  
// #include <iostream>
// using namespace std;

// // 基类 Animal
// class Animal {
// public:
//     // 虚函数 sound，为不同的动物发声提供接口
//     virtual void sound() const {
//         cout << "Animal makes a sound" << endl;
//     }
    
//     // 虚析构函数确保子类对象被正确析构
//     virtual ~Animal() { 
//         cout << "Animal destroyed" << endl; 
//     }
// };
// // Animal类中定义了一个虚析构函数virtual ~Animal()。这意味着如果有一个指向Animal类型的指针，
// // 但实际指向的是Dog（或任何其他继承自Animal的派生类）的对象，当你使用这个指针删除对象时，
// // // 程序会调用正确的析构函数，即派生类的析构函数~Dog()，而不是基类的析构函数~Animal()。
// // Animal* animalPtr = new Dog();
// // delete animalPtr;  // 这里会调用Dog的析构函数，然后是调用Animal的析构函数，如果Animal的析构函数不是虚函数，则只会调用Animal的析构函数，Dog的析构函数不会被调用。
// // 这样可以确保派生类的资源被正确释放，避免内存泄漏。因此，当设计一个类时，如果这个类可能会被继承，
// // 并且你希望确保派生类的对象能够被正确地销毁，你应该将这个类的析构函数声明为虚函数。


// // 公共成员 (public 成员) 可以被类的任何对象访问，包括基类和派生类的对象，也允许在类的外部通过类的对象进行访问。

// // 保护成员 (protected 成员) 可以被类的任何对象访问，包括基类和派生类的对象，但不能在类的外部直接访问。

// // 私有成员 (private 成员) 只能被类的成员函数访问，不能被类的对象或类的外部访问。在派生类中，基类的私有成员是完全不可见的。

// // 派生类 Dog，继承自 Animal
// class Dog : public Animal {
// public:
//     // 重写 sound 方法
//     void sound() const override {
//         cout << "Dog barks" << endl;
//     }
    
//     ~Dog() {
//         cout << "Dog destroyed" << endl;
//     }
// };

// // 派生类 Cat，继承自 Animal
// class Cat : public Animal {           //公共继承意味着基类（在这个例子中是 Animal）的公共成员在派生类（这里是 Dog）中仍然是公共成员，基类的保护成员在派生类中仍然是保护成员
// public:
//     // 重写 sound 方法
//     void sound() const override {
//         cout << "Cat meows" << endl;
//     }
    
//     ~Cat() {
//         cout << "Cat destroyed" << endl;
//     }
// };

// // 测试多态
// int main() {
//     Animal* animalPtr;  // 基类指针

//     // 创建 Dog 对象，并指向 Animal 指针
//     animalPtr = new Dog();              //这里的new关键字用于动态创建一个Dog对象。具体来说，new Dog()会在堆（heap）上分配足够的内存来存储一个Dog对象，并调用Dog的构造函数来初始化这个对象。
//                                         //返回的是指向这个新创建的Dog对象的指针。这样，animalPtr就可以指向这个动态创建的Dog对象。
//                                         //动态创建对象的好处是可以根据程序运行时的需要来分配和释放内存，而不是在编译时固定。使用new创建的对象，需要使用delete来释放内存，以避免内存泄漏。
//     animalPtr->sound();  // 调用 Dog 的 sound 方法
//     delete animalPtr;    // 释放内存，调用 Dog 和 Animal 的析构函数

//     // 创建 Cat 对象，并指向 Animal 指针
//     animalPtr = new Cat();
//     animalPtr->sound();  // 调用 Cat 的 sound 方法
//     delete animalPtr;    // 释放内存，调用 Cat 和 Animal 的析构函数

//     return 0;
// }


//----------------------------------------------多态和虚函数------------------------------------------
// #include <iostream>
// using namespace std;
 
// // 基类 Shape，表示形状
// class Shape {
//    protected:
//       int width, height; // 宽度和高度
 
//    public:
//       // 构造函数，带有默认参数
//       Shape(int a = 0, int b = 0) : width(a), height(b) { } //a代表width，b代表height,并且都赋值为0
//                                                             // 初始化成员变量：在构造函数体执行之前，初始化列表可以用来初始化类的成员变量。这种初始化方式更为安全和高效。
//                                                             // 设置默认值：int a = 0, int b = 0 表示如果创建 Shape 对象时没有提供参数，width 和 height 会自动被初始化为 0。
 
//       // 虚函数 area，用于计算面积
//       // 使用 virtual 关键字，实现多态
//       //虚函数的作用是支持多态性，即允许基类指针指向派生类对象时，
//       //调用的是派生类中重写的函数，而不是基类中的函数。这样可以实现“运行时多态”，使得程序在运行时根据对象的实际类型来决定调用哪个函数。
//       virtual int area() {
//          cout << "Shape class area: " << endl;
//          return 0;
//       }
// };
 
// // 派生类 Rectangle，表示矩形
// class Rectangle : public Shape {
//    public:
//       // 构造函数，使用基类构造函数初始化 width 和 height
//       Rectangle(int a = 0, int b = 0) : Shape(a, b) { }
 
//       // 重写 area 函数，计算矩形面积
//       // override是重写函数的标志
//       int area() override { 
//          cout << "Rectangle class area: " << endl;
//          return width * height;
//       }
// };
 
// // 派生类 Triangle，表示三角形
// class Triangle : public Shape {
//    public:
//       // 构造函数，使用基类构造函数初始化 width 和 height
//       Triangle(int a = 0, int b = 0) : Shape(a, b) { }
 
//       // 重写 area 函数，计算三角形面积
//       int area() override { 
//          cout << "Triangle class area: " << endl;
//          return (width * height / 2); 
//       }
// };
 
// // 主函数
// int main() {
//    Shape *shape;           // 基类指针
//    Rectangle rec(10, 7);   // 矩形对象
//    Triangle tri(10, 5);    // 三角形对象
 
//    // 将基类指针指向矩形对象，并调用 area 函数
//    shape = &rec;
//    cout << "Rectangle Area: " << shape->area() << endl;   

//                                                         //在C++中，shape 是一个指向 Shape 类的指针。对于指针，你需要使用箭头操作符 -> 来访问其指向对象的成员函数或成员变量。因此，shape->area() 是正确的写法。

//                                                         // 如果你有一个 Shape 类的对象而不是指针，比如 Shape shapeObj;，你可以使用点操作符 . 来访问成员函数或成员变量：shapeObj.area()。

//                                                         // 至于 shape::area，这种写法是用来调用类的静态成员函数的，而不是成员函数。area() 不是一个静态成员函数，所以不能用 shape::area 来调用。

//                                                         // 总结一下：

//                                                         // 如果 shape 是一个对象，使用 shape.area()。
//                                                         // 如果 shape 是一个指向对象的指针，使用 shape->area()。
//                                                         // shape::area 用于静态成员函数的调用，这里不适用。
 
//    // 将基类指针指向三角形对象，并调用 area 函数
//    shape = &tri;
//    cout << "Triangle Area: " << shape->area() << endl;
 
//    return 0;
// }


//----------------------------------------------------------封装----------------------------------------------
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // 构造函数
    Student(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
    }

    // 访问器函数（getter）
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    // 修改器函数（setter）
    void setName(string studentName) {
        name = studentName;
    }

    void setAge(int studentAge) {
        if (studentAge > 0) {
            age = studentAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }

    // 打印学生信息
    void printInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // 创建一个 Student 对象
    Student student1("Alice", 20);

    // 访问和修改数据
    student1.printInfo();

    student1.setName("Bob");
    student1.setAge(22);

    student1.printInfo();

    return 0;
}