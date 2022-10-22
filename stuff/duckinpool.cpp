// 四只鸭子同半圆，概率有多大?
// https://www.youtube.com/watch?v=7jTIwEmO5NI
// Solution using Monte Carlo simulation

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec)
    {
        os << el << ' ';
    }
    return os;
}

#define N 4
#define SAMPLECNT (10000000)
#define PI (3.14)
// #define PI (1.0)
#define THETA (PI*2.0/2.0)

// calculate the counter-clockwise distance of the 2 points (a->b)
inline float ccwdis(float a, float b)
{
    if (b>=a)
    {
        // cout << b-a << " ";
        return b-a;
    }
    else
    {
        // cout << 2*PI+b-a << " ";
        return 2*PI+b-a;
    }
}

int mcOneIter()
{
    // monte-carlo
    // generate n random float numbers in range [0, 2pi)
    float p[N];
    bool flag[N];

    for (int i=0; i<N; i++)
    {
        p[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX/PI/2.0);
        // cout << p[i] << " ";
    }
    // cout << endl;
    // For each number as head, check ccwdis of the others to this one.
    // If all ccwdis of a head < PI, set flag[i] to true.
    // <==> if any ccwdis of a head > PI, set flag[i] to false.

    for (int i=0; i<N; i++)
    {
        // cout << "head" << i << ": ";
        flag[i] = true;
        for (int j=0; j<N; j++)
        {
            if (ccwdis(p[i], p[j]) > THETA) {
                flag[i] = false;
                break;
            }
        }
        if (flag[i] == true)
            return 1;
        // cout << endl;
    }
    // If any flag is true, this monte-carlo iteration matches.
    // for (int i=0; i<N; i++)
    // {
    //     if (flag[i] == true)
    //         return 1;
    // }
    return 0;
}

int main()
{
    std::vector<std::string> vec = {
        "Hello", "from", "GCC", __VERSION__, "!" 
    };
    std::cout << vec << std::endl;
    
    // cout << time(0) << endl;
    srand(static_cast<unsigned>(time(0)));
    
    auto t_start = std::chrono::high_resolution_clock::now();

    int mctruecnt = 0;
    for (int i=0; i<SAMPLECNT; i++) {
        mctruecnt += mcOneIter();
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    cout << mctruecnt << endl;
    std::cout << "p: " << float(100.0*mctruecnt/SAMPLECNT) << "%" << std::endl;
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    cout << elapsed_time_ms << " ms" << endl;
    
    return 0;
    
}
