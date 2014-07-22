#pragma once

#include <cmath>

namespace Math {

   /*!
    */
   template <class T> T Abs(const T& value);

   /*!
    */
   template <class T> T Max(const T& lhs, const T& rhs);

   /*!
    */
   template <class T> T Min(const T& lhs, const T& rhs);

   /*!
    */
   template <class T> T Sqrt(const T& value);

   /*!
    */
   template <class T> T Floor(const T& value);

   /*!
    */
   template <class T> T Round(const T& value, const T& precision = 1);
}

#include "functions.inl"