#include <iostream>
#include "../Methods/Dihotomia.h"
#include "../Methods/Iteration.h"
#include "../Methods/Newton.h"
#include <cmath>
#include <functional>
#include "../Methods/Complex.h"
using namespace std;


int main(){
    int r=1;
    double a=1, omega=1, l0=5, V0=1;
    std::function<double(double)> f([=](double t){return a*sin(omega*t)-l0+V0*t;});
    std::cout<<Newton<double>::Answer( f, r, 100)<<"\n"<<Dihotomia<double>::Answer(f, 100)<<"\n"<<Iteration<double>::Answer(f, 100)<<std::endl;
    return 0;
}
