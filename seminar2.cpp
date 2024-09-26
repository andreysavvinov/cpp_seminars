#include <iostream>
#include <math.h>
using namespace std;
struct complex{s
    float Re;
    float Im;
    complex(float x=0, float y=0){
        Re=x;
        Im=y;
    }
   // complex(float x){
     //   Re=x;
   //     Im=0;
 //   }
    ~complex(){};
    complex(const complex &c){ 
        *this=c;
    }
    complex& operator=(const complex& c)
    {
        if(&c != this){
            Re=c.Re;
            Im=c.Im;
        }
        return *this;
    }
    complex operator+(const complex& b) const {
        complex sum=*this;
        sum.Re+=b.Re;
        sum.Im+=b.Im;
        return sum;
    }
    complex operator-(const complex& b) const {
        complex r=*this;
        r.Re-=b.Re;
        r.Im-=b.Im;
        return r;
    }
    complex operator-() const {
        return {-Re,-Im};
    }
    float abs(const complex& b){
        return sqrt(b.Re*b.Re+b.Im*b.Im);
    }
    complex operator/(const complex& b) const {
        complex divide=*this;

    }
    complex operator*(const complex& b) const {
        complex multiplex(this->Re * b.Re - this->Im * b.Im, this->Re * b.Im + this->Im * b.Re);
        return multiplex;
    }
};
ostream& operator<<(ostream&  o, const complex& x){
     o << x.Re << ((x.Im < 0)?'-':'+') << abs(x.Im) << "i";
     return o;
}

int main(){
   complex a(10.0F,3.0F);
   cout<< a.Re << " "<< a.Im;
   return 0;
}