#pragma once

#include "unit.hpp"
#include <cmath>

namespace Math {

   /*!
    */
   template <class T> T Abs(const T& value);
   
   /*!
    */
   template <class T> T Sign(const T& value);

   /*!
    */
   template <class T> T Max(const T& lhs, const T& rhs);

   /*!
    */
   template <class T> T Min(const T& lhs, const T& rhs);

   /*!
    */
   template <class T> T Clamp(const T& value, const T& lower, const T& upper);

   /*!
    */
   template <class T> T Floor(const T& value);

   /*!
    */
   template <class T> T Ceil(const T& value);

   /*!
    */
   template <class T> T Round(const T& value, const T& precision = 1);

   /*!
    */
   template <class T> T Sqrt(const T& value);

   /*!
    */
   template <class T> T Sin(const Degree<T>& value);

   /*!
    */
   template <class T> T Cos(const Degree<T>& value);

   /*!
    */
   template <class T> T Tan(const Degree<T>& value);

   /*!
    */
   template <class T> Degree<T> ASin(const T& value);

   /*!
    */
   template <class T> Degree<T> ACos(const T& value);

}

#include "functions.inl"
