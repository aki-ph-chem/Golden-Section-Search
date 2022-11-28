#include <iostream>
#include <vector>
#include <cmath>

using func = double(double);

double o_func(double x){
    return x*x - 4;
}

double p_func(double x){
    return x * x - 2;
}

double bin_method(func* func, double x1, double x2, double epsilon){
    double left = x1, right = x2;
    while(std::abs(right - left) > epsilon){
        double mid = left + std::abs(right - left)/2;
        if(func(mid) * func(left) > 0){
            left = mid;
        }else if(func(mid) * func(right) > 0)
            right = mid;
    }
    return right;
}

int main(void){
    constexpr double epsilon = std::pow(10,-6);
    std::cout <<"res = " << bin_method(o_func, 0, 3, epsilon) << "\n";
    std::cout <<"res = " << bin_method(p_func, 0, 2, epsilon) << "\n";
}
