#include <iostream>
#include <cmath>

using func = double(double);

double o_func(double x){
    return x*x - 4*x - 10;  
}

double p_func(double x){
    return x*x + 4*x - 100; 
}

double r_func(double x){
    return x*x - 100;
}

double golden_search(func* func, double x_l, double x_r, double epsilon){
    // 分割比
    const double e_db = (std::sqrt(5) - 1)/(std::sqrt(5) + 1);
    double b_k = std::abs(x_r - x_l); 
    double d_k = e_db * b_k;
    // x_0 ~ x_3
    double x[4];
    x[0] = x_l;
    x[1] = x_l + d_k;
    x[2] = x_r - d_k;
    x[3] = x_r;
    // x_1, x_2での関数値
    double f_1 = func(x[1]), f_2 = func(x[2]);
    while(b_k > epsilon){
        if(f_1 < f_2){
            double x2_prev = x[2];
            x[2] = x[1];
            x[1] = x2_prev - d_k;
            x[3] = x2_prev;

            f_2 = f_1;
            f_1 = func(x[1]);
        }
        else{
            double x1_prev = x[1];
            x[1] = x[2];
            x[2] = x1_prev + d_k;
            x[0] = x1_prev;

            f_1 = f_2;
            f_2 = func(x[2]);
        }
        /*
        std::cout<<" x0_k: " << x[0]; 
        std::cout<<" x1_k: " << x[1]; 
        std::cout<<" x2_k: " << x[2]; 
        std::cout<<" x3_k: " << x[3] << "\n"; 
        */

        b_k -= d_k;
        d_k = e_db * b_k;
        /*
        std::cout << " b_k = " << b_k;
        std::cout << " d_k = " << d_k << "\n";
        */
    }
    return x[1];
}

int main(void){
    constexpr double epsilon = std::pow(10,-5);

    std::cout << "res = " << golden_search(o_func, 0, 4, epsilon) << "\n";
    std::cout << "res = " << golden_search(p_func, -10, 122, epsilon) << "\n";
    std::cout << "res = " << golden_search(r_func, -10, 10, epsilon) << "\n";
}
