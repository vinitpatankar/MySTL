#include <iostream>

namespace mystd
{
template<typename T>
class complex
{
    private:
    T r;
    T i;
    public:
    complex(){};
    complex(T r, T i): r(r), i(i){};
    complex(const complex& other)
    {
        r = other.r;
        i = other.i;
    }
    complex& operator=(const complex& other)
    {
        r = other.r;
        i = other.i;
        return *this;
    }
    ~complex(){};
    T real() const { return r; }
    T imag() const { return i; }
};
template<typename T>
std::ostream& operator<<(std::ostream& out, const complex<T>& c)
{
    out << c.real() << ": " << c.imag();
    return out;
}
template<typename T>
complex<T> operator+(const complex<T>& c1, const complex<T>& c2)
{
    return complex<T>(c1.real()+c2.real(), c1.imag()+c2.imag());
}
template<typename T>
bool operator==(const complex<T>& c1, const complex<T>& c2)
{
    return (c1.real() == c2.real() && c2.imag() == c2.imag());
}
template<typename T>
complex<T> operator*(const complex<T>& other)
{
    return complex<T>(other.real(), -1*other.imag());
}
}
