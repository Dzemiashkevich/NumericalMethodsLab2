//
// Created by Dzemiashkevich Vlad on 17.10.25.
//

#ifndef ITERATION_H
#define ITERATION_H


#include "General.h"
#include "diff.h"

template<typename T>
class Iteration: public General<T> {

    public:

    Iteration(std::function<T(T)> f, T a, T b) :General<T>(f,a,b){};
	explicit Iteration(std::function<T(T)> f) :General<T>(f){};
   static T  Answer(std::function<T(T)> f, T a, T b, int MaxIter, bool iteration=false) {
        T xnew=T(0), x=T(0), tau=T(0);
        double epsilon=1e-12;
        Iteration I(f, a, b);
        I.FindNewAB();
        x=(I.a+I.b)/2;
        T A=diff<T>::differ (I.f,I.a);
        T m=A, M=A;
        for (T ai=I.a; ai<=I.b; ai+=abs(ai/1e3)+1e-3) {
            A=abs(diff<T>::differ(I.f, ai));
            if (m>A){m=A;}
            if(M<A){M=A;}
        }
        tau=2/(M+m);
        std::function<T(T)> f2;
        if (diff<T>::differ (I.f, x)<0){
            f2 = [f, tau](T x) {return x + tau * f(x);};
        }
        else {
            f2 = [f, tau](T x) {return x - tau * f(x);};
        }

       int i;
        for(i=0;i<=MaxIter; ++i){
            xnew=f2(x);
            if (abs(xnew - x) < epsilon) {
                if (iteration==true) {
                    std::cout<<i<<"\n";
                }
                return xnew;
            }
            x=xnew;
        }

        return xnew;
    }

   static T Answer(std::function<T(T)> f, int MaxIter){
        return Answer(f, -1e15, 1e15, MaxIter);
    }


};



#endif //ITERATION_H
