#include <iostream>
#include <cmath>
#include <vector>

namespace Path{
    struct Path{
        double x0_k, x1_k, x2_k, x3_k;
        double b_k, d_k;

        Path(void)
            :x0_k(0), x1_k(0), x2_k(0), x3_k(0), b_k(0), d_k(0)
        {}
        void set(double x0, double x1, double x2, double x3, double b, double d){
            x0_k = x0;
            x1_k = x1;
            x2_k = x2;
            x3_k = x3;

            b_k = b;
            d_k = d;
        }
        void show(void){
            std::cout << " x0_k = "<< x0_k;
            std::cout << " x1_k = "<< x1_k;
            std::cout << " x2_k = "<< x2_k;
            std::cout << " x3_k = "<< x3_k << "\n";
            std::cout << " b_k = "<< b_k;
            std::cout << " d_k = "<< d_k << "\n";
        }
    }; 
    using PathLog = std::vector<Path>;

    void show_path(const PathLog& path){
        for(auto i: path){
            i.show();
        }
    }
}


using func = double(double);

double o_func(double x){
    return x*x - 4*x - 10;  
}

double p_func(double x){
    return x*x + 4*x - 100; 
}

double golden_search(func* func, double x_l, double x_r, double epsilon, Path::PathLog& path){
    // 分割比
    const double e_db = (std::sqrt(5) - 1)/(std::sqrt(5) + 1);
    double b_k = std::abs(x_r - x_l); 
    double d_k = e_db * b_k;
    // x_0 ~ x_3
    double x0_k = x_l, x3_k = x_r;
    double x1_k = x_l + d_k, x2_k = x_r - d_k;
    // x_1, x_2での関数値
    double f_1 = func(x1_k), f_2 = func(x2_k);
    Path::Path p; 
    while(b_k > epsilon){
        if(f_1 < f_2){
            double x2_prev = x2_k;
            x2_k = x1_k;
            x1_k = x2_prev - d_k;
            x3_k = x2_prev;

            f_2 = f_1;
            f_1 = func(x1_k);
        }
        else{
            double x1_prev = x1_k;
            x1_k = x2_k;
            x2_k = x1_prev + d_k;
            x0_k = x1_prev;

            f_1 = f_2;
            f_2 = func(x2_k);
        }

        b_k -= d_k;
        d_k = e_db * b_k;

        p.set(x0_k, x1_k, x2_k, x3_k, b_k, d_k);
        path.push_back(p);
    }
    return x1_k;
}

int main(void){
    constexpr double epsilon = std::pow(10,-5);

    Path::PathLog path_o_func;
    std::cout << "res = " << golden_search(o_func, 0, 4, epsilon, path_o_func) << "\n";
    //Path::show_path(path_o_func);

    Path::PathLog path_p_func;
    std::cout << "res = " << golden_search(p_func, -10, 122, epsilon, path_p_func) << "\n";
    //Path::show_path(path_p_func);
}

