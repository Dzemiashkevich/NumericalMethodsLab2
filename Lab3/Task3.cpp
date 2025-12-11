#include "Complex.h"
#include <cmath>
#include <fstream>
#include "Newton.h"

const double xmin = -2.00, xmax = 2.00, ymin = -2.00, ymax = 2.00;
const double step = 0.004;
const double epsilon = 1e-12;

Complex<double> roots[3] = {
    Complex<double>(1.0, 0.0),
    Complex<double>(cos(2.0 * M_PI / 3.0), sin(2.0 * M_PI / 3.0)),
    Complex<double>(cos(-2.0 * M_PI / 3.0), sin(-2.0 * M_PI / 3.0))
};

int findRoot(const Complex<double>& z) {
    int idx = 0;
    double minDist = Complex<double>::abs(z - roots[0]);
    for (int i = 1; i < 3; ++i) {
        double d = Complex<double>::abs(z - roots[i]);
        if (d < minDist) { minDist = d; idx = i; }
    }
    return idx;
}

int main() {
    int Nx = int((xmax - xmin) / step) + 1;
    int Ny = int((ymax - ymin) / step) + 1;
    std::function<Complex<double>(Complex<double>)> f = [=](Complex<double> z) { return Complex<double>::pow(z, 3)-1; };
    std::function<Complex<double>(Complex<double>)> df = [=](Complex<double> z) { return 3*Complex<double>::pow(z, 2); };
    std::ofstream ofs("../newton_attractors.txt");
    if (!ofs.is_open()) {
        std::cerr << "Could not open file!" << std::endl;
        return 1;
    }
    for (int iy = 0; iy < Ny; ++iy) {
        double y = ymin + iy * step;
        for (int ix = 0; ix < Nx; ++ix) {
            double x = xmin + ix * step;
            Complex<double> z = Newton<Complex<double>>::Answer(f, df, Complex<double>(x, y), 30);
            int root_ix = findRoot(z);
            ofs << root_ix << (ix + 1 < Nx ? " " : "");
        }
        ofs << "\n";
    }
    ofs.close();
    system("gnuplot -e \"set terminal pngcairo size 1200,1200; set output '../attractors.png'; set palette defined (0 'blue', 1 'red', 2 'green'); plot  '../newton_attractors.txt' matrix with image\"");
}

