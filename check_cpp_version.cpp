/*
Command:

g++ check_cpp_version.cpp -o check_cpp_version

./check_cpp_version

*/

#include <iostream>

int main()
{
#if __cplusplus == 199711L
    std::cout << "C++98/03\n";
#elif __cplusplus == 201103L
    std::cout << "C++11\n";
#elif __cplusplus == 201402L
    std::cout << "C++14\n";
#elif __cplusplus == 201703L
    std::cout << "C++17\n";
#elif __cplusplus >= 202002L
    std::cout << "C++20 or later\n";
#else
    std::cout << "Unknown C++ version\n";
#endif
    return 0;
}
