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

using func_1arg = double(double);
//  こっちの実装だとちゃんと収束する
double golden_search(func_1arg* func, double x_l, double x_r, double epsilon){
    // 分割比
    const double e_db = (std::sqrt(5) - 1)/(std::sqrt(5) + 1);
    double b = std::abs(x_r - x_l);
    double d = e_db * b;
    // x_0 ~ x_3
    double x[4];
    x[0] = x_l;
    x[1] = x_l + d;
    x[2] = x_r - d;
    x[3] = x_r;
    // x[1], x[2]での関数値
    double f_1 = func(x[1]), f_2 = func(x[2]);
    while(b > epsilon){
        if(f_1 < f_2){
            double x_2 = x[2];
            x[2] = x[1]; x[1] = x_2 - d; x[3] = x_2;
            f_2 = f_1; f_1 = func(x[1]);
        }else{
            double x_1 = x[1];
            x[1] = x[2]; x[2] = x_1 + d; x[0] = x_1;
            f_1 = f_2; f_2 = func(x[2]);
        }
        std::cout<<" x[0]: " << x[0]; 
        std::cout<<" x[1]: " << x[1]; 
        std::cout<<" x[2]: " << x[2]; 
        std::cout<<" x[3]: " << x[3] << "\n"; 

        b -= d;
        d = e_db * b;
        std::cout << " b = " << b;
        std::cout << " d = " << d << "\n";
    }
    return x[1]; 
}

int main(void){

    constexpr double epsilon = std::pow(10,-5);
    std::cout << "res = " << golden_search(o_func, 0, 4, epsilon) << "\n";
    /*
    std::cout << "res = " << golden_search(p_func,-10,122, epsilon)<< std::endl;
    std::cout << "res = " << golden_search(r_func,-10,10, epsilon)<< std::endl;
    */
}
