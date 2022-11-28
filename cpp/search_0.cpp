// 三分探索を実装する
#include <iostream>
#include <cmath>

double o_func(double x){
    return x*x - 4*x - 10;  
}

double p_func(double x){
    return x*x + 4*x - 100; 
}

double r_func(double x){
    return x*x - 100;
}

using func = double(double);

double search_min(func* function, const double x0, const double x3, const double epsilon){
    double x0_k = x0, x3_k = x3;
    double x1_k = 0, x2_k = 0;
    while(std::abs(x3_k - x0_k) > epsilon){
        double three = std::abs(x3_k - x0_k)/3;
        x1_k = x0_k + three;
        x2_k = x3_k - three;
        if(function(x1_k) < function(x2_k)){
            x3_k = x2_k;
        }
        else if(function(x1_k) >= function(x2_k)){
            x0_k = x1_k;
        }
    }
    return x3_k;
}

int main(void){
    double epsilon = std::pow(10,-4);

    std::cout << "res = " << search_min(o_func, 0, 4, epsilon) << std::endl;
    std::cout << "res = " << search_min(p_func,-10,122, epsilon)<< std::endl;
    std::cout << "res = " << search_min(r_func,-10,10, epsilon)<< std::endl;
}
