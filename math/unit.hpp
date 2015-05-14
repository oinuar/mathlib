#pragma once

#include <cmath>

namespace Math {

   template <class T>
   class Pi {
   public:

      Pi() {}

      operator T() const {
         return (T)3.14159265358979323846;
      }
   };

   template <class T>
   class Degree {
   public:

      Degree(const T& value) : _value(value) {}

      operator T() const {
         return _value;
      }

   private:
      T _value;
   };

   template <class T>
   class Radian {
   public:

      Radian(const T& value) : _value(value) {}

      operator T() const {
         return _value * ((T)180.0 / Pi<T>());
      }

   private:
      T _value;
   };

   template <class T, int N>
   class Exp {
   public:

      Exp(const T& value) : _value(value) {}

      operator T() const {
         return _value * std::pow(10, N);
      }

   private:
      T _value;
   };

   typedef Exp<double, 9> Giga;
   typedef Exp<double, 6> Mega;
   typedef Exp<double, 3> Kilo;
   typedef Exp<double, 2> Hecto;
   typedef Exp<double, 1> Deca;
   typedef Exp<double, -1> Deci;
   typedef Exp<double, -2> Centi;
   typedef Exp<double, -3> Milli;
   typedef Exp<double, -6> Micro;
   typedef Exp<double, -9> Nano;

   typedef Exp<float, 9> Gigaf;
   typedef Exp<float, 6> Megaf;
   typedef Exp<float, 3> Kilof;
   typedef Exp<float, 2> Hectof;
   typedef Exp<float, 1> Decaf;
   typedef Exp<float, -1> Decif;
   typedef Exp<float, -2> Centif;
   typedef Exp<float, -3> Millif;
   typedef Exp<float, -6> Microf;
   typedef Exp<float, -9> Nanof;
}
