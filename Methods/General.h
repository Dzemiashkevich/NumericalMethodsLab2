//
// Created by Dzemiashkevich Vlad on 17.10.25.
//

#ifndef GENERAL_H
#define GENERAL_H

#include <functional>
template <typename T>
class General {

public:
    std::function<T(T)> f;
    T a,b;

    void FindNewAB(){
        T ai=this->a;
        T bi=this->b;
        T i=T(0.);
        if constexpr(!std::is_class<T>::value) {
            while (this->f(ai)*this->f(bi)>0) {
                i=abs(ai-bi)/2;
                for (; this->f(ai+i)*this->f(ai)*this->f(bi)>0 && ai<bi; ai +=i){}
                for (; this->f(bi-i)*this->f(bi)*this->f(ai)<0 && bi>ai; bi -=i){}
            }
        }

        this->a=ai;
        this->b=bi;
    }

    explicit General(std::function<T(T)> f){
        this->a=-1e15;
        this->b=1e15;
        this->f = f;
    }
    General(std::function<T(T)> f, T a, T b) {
        this->a=a;
        this->b=b;
        this->f=f;
    }


};



#endif //GENERAL_H
