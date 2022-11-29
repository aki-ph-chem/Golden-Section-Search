#include <iostream>
#include <cmath>

double o_func(double x){
    return x * x - 2 * x + 3;
}

int o_func_int(int x){
    return x * x - 2 * x + 3;
}

double p_func(double x){
    return std::pow(x - 1.5, 2) + 3;
}

template<typename T> 
using func_1arg = T(T);

template<typename T>
T grid_search_generic(func_1arg<T>* func, T x_left, T x_right, T step){
    int iter = (int)((x_right - x_left)/step);
    T min = (T)114514; 
    T x = x_left;
    T x_min = (T)0;
    for(int i = 0; i < iter; ++i){
        x +=  step;
        if(func(x) < min){
            min = func(x);
            x_min = x;
        }
    }
    return x_min;
}


int main(void){
    std::cout<<"res-o_func = " << grid_search_generic<double>(o_func, 0, 4, 0.01) << std::endl;
    std::cout<<"res-o_func_int = " << grid_search_generic<int>(o_func_int, 0, 10, 1) << std::endl;
    std::cout<<"res-o_p_func = " << grid_search_generic<double>(p_func, 0, 4, 0.01) << std::endl;
}
