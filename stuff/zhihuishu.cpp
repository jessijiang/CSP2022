// 智慧数 s = a^2-b^2, a,b均为正整数
// e.g. 3, 5, 7, 8, 9, 11, 12, 13, ...
// 问：第2000个智慧数是多少？
// tested on http://coliru.stacked-crooked.com/

#include <iostream>
#include <string>
#include <vector>
#include <set>

// template<typename T>
// std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
// {
//     for (auto& el : vec)
//     {
//         os << el << ' ';
//     }
//     return os;
// }

int main()
{
    // std::vector<std::string> vec = {
    //     "Hello", "from", "GCC", __VERSION__, "!" 
    // };
    // std::cout << vec << std::endl;
    
    std::cout << "brutal enum" << std::endl;
    std::set<int> smartn;
    for (int i=2; i<2000; i++) {
        for (int j=i-1; j>0; j--) {
            smartn.insert(i*i-j*j);
        }
    }
    std::cout << smartn.size() << std::endl;
    auto iter=smartn.begin();
    for (int i=0; (i<50)&&(iter!=smartn.end()); i++) {
        std::cout << *std::next(iter++, 0) << " ";
    }
    std::cout << std::endl;
    std::cout << *std::next(smartn.begin(), 1999) << std::endl;
    // ****************************
    std::cout << "output first nth numbers" << std::endl;
    std::cout << "3 5 ";
    int k=3;
    int nth = 50;
    for (int cnt=2; cnt<nth; cnt++,k++) {
        if ((k*2)%4 == 0) {
            std::cout << k*2 << " ";
            cnt++;
        }
        std::cout << k*2+1 << " ";
    }
    std::cout << std::endl;
    // ****************************
    std::cout << "calculate the nth number" << std::endl;
    int i=3;
    nth = 2000;
    for (int cnt=2; cnt<nth; cnt++,i++) {
        if ((i*2)%4 == 0) {
            if ((cnt+1)==nth)
                std::cout << i*2 << " ";
            cnt++;
            if ((cnt+1)==nth)
                std::cout << i*2+1 << " ";
        } else {
            if ((cnt+1)==nth)
                std::cout << i*2+1 << " ";
        }
    }
    std::cout << std::endl;
    // ****************************
    std::cout << "4d+3+m" << std::endl;
    int d, m;
    nth = 2000;
    d = nth / 3;
    m = nth % 3;
    std::cout << 4*d+3+m << std::endl;
}
