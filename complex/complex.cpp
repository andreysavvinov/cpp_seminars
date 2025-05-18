#include "complex.h"
#include <iostream>

complex::~complex(){

};
void complex::read(){
        std::cout << "a: ";
        std::cin >> real_;
        std::cout << "b: ";
        std::cin >> imag_;
    };
void complex::display() 
    {
        std::cout << real_ << (imag_ < 0 ? " " : " + ") << imag_ << 'i';
    };
complex complex::operator+(const complex &c2) 
    {
        return complex(this->real_ + c2.real_, this->imag_ + c2.imag_);
    };
complex complex::operator-(const complex &c2) 
    {
        return complex(this->real_ - c2.real_, this->imag_ - c2.imag_);
    };
complex complex::operator*(const complex &c2) 
    {
        return complex(this->real_ * c2.real_ - this->imag_ * c2.imag_, this->real_ * c2.imag_ + this->imag_ * c2.real_);
    }   
complex complex::operator/(const complex &c2) 
    {
        return complex(this->real_ * c2.real_ + this->imag_ * c2.imag_, this->real_ * c2.imag_ - this->imag_ * c2.real_);
    } 
bool complex::operator==(const complex &c2) 
    {
        return this->real_ == c2.real_ && this->imag_ == c2.imag_;
    }
complex complex::operator-() 
    {
        return complex(-this->real_, -this->imag_);
    }
complex& complex::operator=(const complex &c) 
    {
        if (this == &c) {
            return *this;
        }
        this->real_ == c.real_;
        this->imag_ == c.imag_;
        return *this; 
    }
