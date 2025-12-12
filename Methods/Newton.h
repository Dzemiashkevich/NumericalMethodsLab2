//
// Created by Dzemiashkevich Vlad on 17.10.25.
//
#ifndef NEWTON_H
#define NEWTON_H


#include "Complex.h"
#include "General.h"
#include "diff.h"
#include "Complex.h"

template<typename T>
class Newton: public General<T> {
    public:
    Newton(std::function<T(T)> f, T a, T b) :General<T>(f,a,b){}
    explicit Newton(std::function<T(T)> f) :General<T>(f){}
    static T Answer(std::function<T(T)> f, T a, T b, int r=1, int MaxIter=1000, bool Iteration=false) {
        double epsilon = 1e-10;
        Newton N(f, a, b);
        N.FindNewAB();
        T x0;
        T f_a = f(N.a);
        T f_b = f(N.b);
        T f2_a = diff<T>::differ2(f,  N.a);

        if (f_a * f2_a > 0) {
            x0 = N.a;
        } else if (f_b * diff<T>::differ2(f,N.b) > 0) {
            x0 = N.b;
        } else {
            x0 = (N.a + N.b) / 2;
        }
        T oldx=x0;
        T x = x0;
        T newx=0;
        T fx = 0;
        T dfx = 0;
        fx = f(x);
        dfx = diff<T>::differ(f, x);
        x=oldx-fx/dfx;
        int i;
        for ( i = 0; i < MaxIter; ++i) {
            fx = f(x);
            dfx = diff<T>::differ(f, oldx, x, r);
            if (abs(dfx) < 1e-12) {
                break;
            }

            newx = x - fx / dfx;

            if (abs(newx - x) < epsilon) {
                if (Iteration==true) {
                    std::cout<<i<<"\n";
                }
                return newx;
            }
            oldx=x;
            x = newx;

        }

        return x;
    }



    static T Answer(std::function<T(T)> f, int r=3, int MaxIter=10000) {
        return Answer(f,-1e15, 1e15,r, MaxIter);
    }
    template <typename A>
    static Complex<A> Answer(std::function<Complex<A>(Complex<A>)> f,std::function<Complex<A>(Complex<A>)> df, Complex<A>  z0,  int MaxIter) {
        double epsilon = 1e-15;
        Complex<A> x0=z0;


        Complex<A> oldx=x0;
        Complex<A> x = x0;
        Complex<A> newx=Complex<A>(0.);
        Complex<A> fx = Complex<A>(0.);
        Complex<A> dfx = Complex<A>(0.);
        fx = f(x);
        dfx = df(x);
        x=oldx-fx/dfx;
        for (int i = 1; i < MaxIter; ++i) {
            fx = f(x);
            dfx = df(x);
            if (Complex<A>::abs(dfx) < 1e-15) break;

            newx = x - fx / dfx;

            if (Complex<A>::abs(newx - x) < epsilon) {
                return newx;
            }
            oldx=x;
            x = newx;
        }

        return x;
    }

};



#endif //NEWTON_H
