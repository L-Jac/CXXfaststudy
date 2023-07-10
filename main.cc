#include "b.h"
#include "a.h"
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::printf("a: %d\n", getA());
    std::cout << "a: ";
    std::cout << getA();
    std::cout << "\n";
    setA(1);
    std::printf("new a: %d\n", getA());

    auto b = B::get();
    std::printf("b: %f\n", b);

    auto d = B::Dummy{
        .a = 10
    };

    auto da = d.getA();
    std::cout << "da: " << da << "\n";

    // lambda匿名函数
    //语法:[](){}，
    //方括号内指定捕获列表，圆括号内指定参数列表，大括号内是函数体。
    auto l = [](int a, int b){
        return a+b;
    };

    std::cout << "l lambda result: " << l(1, 2) << "\n";

    // vecotor
    //Vector容器:动态数组，可以在运行时添加或删除元素。
    auto v = std::vector<int>{0, 1, 2, 3};

    // reference
    // lambda
    //范围for循环:简化的for循环，可以遍历容器中的所有元素。
    //"&"用于声明引用变量，
    //i引用了容器v中的元素，此时修改i同样修改了对应元素
    std::for_each(v.begin(), v.end(), [](auto& i){
        i = i * 2;
    });

    printf("1st: ");
    for(auto& i : v){
        i+=1;
        std::cout << i << " ";
    }
    printf("\n");
    printf("2nd: ");
    for(auto i: v){
        std::cout << i << " ";
    }
    std::cout << "\n";

    auto number = 0;

    // lambda capture
    //Lambda捕获允许lambda表达式访问其定义范围之外的变量。
    //捕获列表中可以指定要捕获的变量，以及是按值捕获还是按引用捕获。
    //"&"用于按引用捕获变量
    //此时捕获了number的引用，可在函数体内直接访问和修改number的值
    auto changeOut = [&number](){
        // auto n = number;
        // n += 100;
        number += 100;
        printf("number: %d\n", number);
        // printf("number: %d\n", n);
    };
    //等效
    // auto changeOut = [&](){
    //     number += 100;
    //     printf("number: %d\n", number);
    // };

    //按值捕获示例
    auto Getnumber = [number](){
        std::cout << "number = " << number << "\n";
    };
    // 等效
    // auto Getnumber = [=](){
    //     std::cout << "number = " << number << "\n";
    // };

    Getnumber(); // 输出0
    changeOut();
    Getnumber(); // 输出0
    changeOut();
    changeOut();

    return 0;
}
