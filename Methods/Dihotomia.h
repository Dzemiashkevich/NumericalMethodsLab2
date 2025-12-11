//
// Created by Dzemiashkevich Vlad on 17.10.25.
//

#ifndef DIHOTOMIA_H
#define DIHOTOMIA_H

#include "General.h"

template<typename T>
class Dihotomia:public General<T>{

public:
    explicit Dihotomia(std::function<T(T)> f):General<T>(f){}
    Dihotomia(std::function<T(T)> f, T a, T b) :General<T>(f,a,b){}
    static T Answer(std::function<T(T)> f, T a, T b, int MaxIter){
        Dihotomia dih(f, a, b);
        double epsilon=1e-12;
        dih.FindNewAB();
        T r;
        int i;
        for ( i=0; i<MaxIter; i++){
            r=(dih.b-dih.a)/2;
            if(f(dih.a+r)*f(dih.b)<0){
                dih.a=dih.a+r;
            }
            else if(f(dih.a)*f(dih.b-r)<0){
                dih.b=dih.b-r;
            }
            else{break;}
            if (abs(dih.a-dih.b)<epsilon){break;}
        }
        std::cout<<i<<"\n";
        return (dih.a+dih.b)/2;
    }

   static T Answer(std::function<T(T)> f, int MaxIter){
        return Answer(f,-1e15,1e15,MaxIter);
    }

};



#endif //DIHOTOMIA_H
