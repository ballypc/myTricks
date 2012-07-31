#ifndef _ANGLE_HPP_INCLUDED_
# define _ANGLE_HPP_INCLUDED_


# include <cmath>


namespace mytricks {

namespace math {

# ifdef M_PI
#  define PI M_PI
# else
#  define PI 3.14159265358979323846
# endif

template<typename Num>
class Angle;

template<typename Num>
    Angle<Num> rad (Num x) {return Angle<Num>(x);}

template<typename Num>
    Angle<Num> deg (Num x) {return Angle<Num>(x * PI / 180);}


template<typename Num>
class Angle {
public:
#if (defined _MSC_VER) && (_MSC_VER <= 1200) // VC6 compatible
    friend Angle rad(Num x);
    friend Angle deg(Num x);
#else // Morden Standard C++
    friend Angle rad<>(Num x);
    friend Angle deg<>(Num x);
#endif // VC6 compatible

    Num rad (void) const {return this->rads;}
    Num deg (void) const {return Num(this->rads / PI * 180);}
# undef PI
    Angle (void) : rads(0) {}
    Angle (const Angle& a) : rads(a.rads) {}

    Angle& operator= (const Angle& a) {this->rads = a.rads; return *this;}

    Angle& operator+= (const Angle& a) {this->rads += a.rads; return *this;}
    const Angle operator+ (const Angle& a) const {return Angle(*this) += a;}

    Angle& operator-= (const Angle& a) {this->rads -= a.rads; return *this;}
    const Angle operator- (const Angle& a) const {return Angle(*this) -= a;}

    const Angle operator- (void) const {return Angle(*this) *= -1;}

    Angle& operator*= (Num x) {this->rads *= x; return *this;}
    const Angle operator* (Num x) const {return Angle(*this) *= x;}

    friend const Angle operator* (Num x, const Angle& a) {return Angle(a) *= x;}

    Num sin (void) const {return ::std::sin(this->rads);}
    Num cos (void) const {return ::std::cos(this->rads);}
    Num tan (void) const {return ::std::tan(this->rads);}

private:
    explicit Angle (Num a) : rads(a) {}

    Num rads;
}; // class Angle

} // namespace math

} // namespace mytricks


#endif // _ANGLE_HPP_INCLUDED_