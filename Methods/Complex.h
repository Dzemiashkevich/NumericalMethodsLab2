//
// Created by Dzemiashkevich Vlad on 31.10.25.
//

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>


template <typename T>
class Complex {
    T x, y;
    public:
    Complex(  const T x, const T y):x(x), y(y){};
    explicit Complex( const T x):x(x), y(0){};
    explicit Complex():x(0), y(0){};

    T real() const { return x; }
    T imag() const { return y; }


    friend Complex<T> operator+(const Complex<T>& c1, const Complex<T>& c2) {
        return Complex<T>(c1.x + c2.x, c1.y + c2.y);
    }

    friend Complex<T> operator-(const Complex<T>& c1, const Complex<T>& c2) {
        return Complex<T>(c1.x - c2.x, c1.y - c2.y);
    }

    friend Complex<T> operator*(const Complex<T>& c1, const Complex<T>& c2) {
        return Complex<T>(
            c1.x * c2.x - c1.y * c2.y,
            c1.x * c2.y + c1.y * c2.x
        );
    }


    friend Complex<T> operator/(const Complex<T>& c1, const Complex<T>& c2) {
        T denominator = c2.x * c2.x + c2.y * c2.y;
        return Complex<T>(
            (c1.x * c2.x + c1.y * c2.y) / denominator,
            (c1.y * c2.x - c1.x * c2.y) / denominator
        );
    }

    friend bool operator>(const Complex<T>& c1, const Complex<T>& c2) {
        return pow(c1.real(),2)+pow(c1.imag(),2) > pow(c2.real(),2)+pow(c2.imag(),2);
    }

    friend bool operator>=(const Complex<T>& c1, const Complex<T>& c2) {
        return pow(c1.real(),2)+pow(c1.imag(),2) >= pow(c2.real(),2)+pow(c2.imag(),2);
    }
    friend bool operator<(const Complex<T>& c1, const Complex<T>& c2) {
        return pow(c1.real(),2)+pow(c1.imag(),2) >= pow(c2.real(),2)+pow(c2.imag(),2);
    }

    template <typename A>
    friend Complex<T> operator*(const Complex<T>& c1, const A c2) {
        return Complex<T>(
            c1.x * c2,
            c1.y * c2
        );
    }

    template <typename A>
    friend Complex<T> operator/(const Complex<T>& c1, const A c2) {
        return Complex<T>(
            c1.x / c2,
            c1.y / c2
        );
    }

    template <typename A>
    friend Complex<T> operator+(const Complex<T>& c1, const A c2) {
        return Complex<T>(
            c1.x + c2,
            c1.y
        );
    }

    template <typename A>
    friend Complex<T> operator-(const Complex<T>& c1, const A c2) {
        return Complex<T>(
            c1.x - c2,
            c1.y
        );
    }

    template <typename A>
   friend Complex<T> operator*(const A c2, const Complex<T>& c1) {
        return Complex<T>(
            c1.x * c2,
            c1.y * c2
        );
    }

    template <typename A>
    friend Complex<T> operator/( const A C2, const Complex<T>& c1) {
        Complex<T> c2(C2);
        return c2/c1;
    }

    template <typename A>
    friend Complex<T> operator+( const A c2, const Complex<T>& c1) {
        return Complex<T>(
            c1.x + c2,
            c1.y
        );
    }

    template <typename A>
    friend Complex<T> operator-( const A c2, const Complex<T>& c1) {
        return Complex<T>(
            c1.x - c2,
            c1.y
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex<T>& c) {
        os << c.x;
        if (c.y >= 0) os << "+";
        os << c.y << "i";
        return os;
    }

    static Complex<T> pow(const Complex<T>& base, int exponent) {
        if (exponent == 0) {
            return Complex<T>(1, 0);
        }
        Complex<T> result(1, 0);
        Complex<T> powered = base;
        int absExp = exponent > 0 ? exponent : -exponent;

        while (absExp > 0) {
            if (absExp & 1) {
                result = result * powered;
            }
            powered = powered * powered;
            absExp >>= 1;
        }
        if (exponent < 0) {
            result = Complex<T>(1, 0) / result;
        }
        return result;
    }
    static double abs(const Complex<T>& base) {
        return sqrt(base.x*base.x + base.y*base.y);
    }
    template <typename A>
    Complex<T> operator()(const A c1) {
        return Complex<T>(
            c1,
            0
        );
    }
    Complex<T>& operator=(const Complex<T>& rhs) {
        if (this != &rhs) {
            x = rhs.x;
            y = rhs.y;
        }
        return *this;
    }

    Complex<T>& operator=(const T& ax) {
        x = ax;
        y = 0;
        return *this;
    }
};



#endif //COMPLEX_H
