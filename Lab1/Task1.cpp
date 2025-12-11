#include <iostream>
#include "../Methods/Dihotomia.h"
#include "../Methods/Iteration.h"
#include "../Methods/Newton.h"
#include <cmath>
#include <ctime>
#include <functional>
using namespace std;

auto to_micro = [](std::clock_t dt) {
   return static_cast<long long>(1e6 * dt / CLOCKS_PER_SEC);
};

int main(){
double a=1;
double b=3;
int r=1;
std::function<double(double)> f([](double x){return 2*log(x)+sin(log(x))-cos(log(x));});
   std::clock_t start_time=std::clock();
std::cout<<Newton<double>::Answer( f, a, b, r, 100)<<"\n";
   std::clock_t end_time=std::clock();
   std::cout<<to_micro(end_time-start_time)<<"\n"<<"\n";
   start_time=std::clock();
   std::cout<<Dihotomia<double>::Answer(f, a, b, 100)<<"\n";
   end_time=std::clock();
   std::cout<<to_micro(end_time-start_time)<<"\n"<<"\n";
   start_time=std::clock();
   std::cout<<Iteration<double>::Answer(f, a, b, 100)<<std::endl;
   end_time=std::clock();
   std::cout<<to_micro(end_time-start_time)<<"\n"<<"\n";
return 0;
}