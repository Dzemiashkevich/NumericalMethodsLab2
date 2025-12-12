#include <iostream>
#include "../Methods/Dihotomia.h"
#include "../Methods/Iteration.h"
#include "../Methods/Newton.h"
#include <cmath>
#include <functional>
#include <fstream>
#include "../Methods/Complex.h"
using namespace std;


int main(){
    int r=1;
    std::fstream File;
    std::string name[3] {"Newton", "Dihotamia", "Iteration"};
    File.open("../Tau(V0).txt",std::ios::out);
    double a=1, omega=1, l0=5, V=0, V0=1;
    std::function<double(double)> f([&](double t){return a*sin(omega*t)-l0+V*t;});
    for (int i=0; i<100; i++) {
        V=V0+i*0.5;
        File<<V<<"\t";
        File<<Newton<double>::Answer( f, r, 100)<<"\t"<<Dihotomia<double>::Answer(f, 100)<<"\t"<<Iteration<double>::Answer(f, 100)<<std::endl;
    }
    File.close();
    for (int i=2; i<=4;++i) {
        system(("gnuplot -e \"set terminal pngcairo size 1200,1200; set output '../"+name[i-2]+"Tau(V0).png'; plot  '../Tau(V0).txt' using 1:"+std::to_string(i)+" with linespoints\"").c_str());
    }
    return 0;
}
