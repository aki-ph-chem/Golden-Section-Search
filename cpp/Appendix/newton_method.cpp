#include <iostream>
#include <cmath>

using func = double(double);

double o_func(double x){
    return x * x - 4;
}

double d_o_func(double x){
    return 2 * x;
}

double p_func(double x){
    return x * x - 2;
}

double newton_method(func* function, func* d_function, double x0, double epsilon){
    double x_n = x0;
    double x_n_prev = 0;
    while(std::abs(x_n - x_n_prev) > epsilon){
        x_n_prev = x_n;
        x_n = x_n - function(x_n)/(d_function(x_n) + std::pow(10,-6));
    }
    return x_n;
}

int main(void){
    constexpr double epsilon = std::pow(10,-4);
    // 2
    std::cout <<"res = "<< newton_method(o_func, d_o_func, 3, epsilon) << std::endl;
    // sqrt(2)
    std::cout <<"res = "<< newton_method(p_func, d_o_func, 3, epsilon) << std::endl;
}
