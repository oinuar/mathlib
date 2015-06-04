#pragma once

#include "matrix.hpp"
#include "functions.hpp"

namespace Math {

   /*! General N-dimensional vector.
    */
   template <size_t N, class T> class Vector : public Matrix<N, 1, T> {
   public:

      /*! Constructs a vector.
       *
       * @param initialize @c true to initialize all elements to zero;
       *                   otherwise elements are left uninitialized.
       */
      Vector(const bool& initialize = true) : Matrix(initialize) {};

      /*! Converts a matrix to vector.
       *
       * @param other Matrix to convert.
       */
      Vector(const Matrix<N, 1, T>& other) : Matrix(other) {};
   };

   /*! Specialized four dimensional vector.
    */
   template <class T> class Vector<4, T> : public Matrix<4, 1, T> {
   public:

      /*! Constructs a vector.
       *
       * @param initialize @c true to initialize all elements to zero;
       *                   otherwise elements are left uninitialized.
       */
      Vector(const bool& initialize = true);

      /*! Constructs a vector from elements.
       *
       * @param X element value.
       * @param Y element value.
       * @param Z element value.
       * @param W element value.
       */
      Vector(const T& x, const T& y, const T& z, const T& w);

      /*! Converts a matrix to vector.
       *
       * @param other Matrix to convert.
       */
      Vector(const Matrix<4, 1, T>& other);

      /*! Converts a 3-dimensional vector to 4-dimensional one.
       *
       * @param other Vector to convert.
       */
      explicit Vector(const Vector<3, T>& other, const T& w);

      /*! Gets X element of vector.
       *
       * @return Vector X element.
       */
      T& x();

      /*! Gets Y element of vector.
       *
       * @return Vector Y element.
       */
      T& y();

      /*! Gets Z element of vector.
       *
       * @return Vector Z element.
       */
      T& z();

      /*! Gets W element of vector.
       *
       * @return Vector W element.
       */
      T& w();
   
      /*! Gets X element of vector.
       *
       * @return Vector const X element.
       */
      const T& x() const;

      /*! Gets Y element of vector.
       *
       * @return Vector const Y element.
       */
      const T& y() const;

      /*! Gets Z element of vector.
       *
       * @return Vector const Z element.
       */
      const T& z() const;

      /*! Gets W element of vector.
       *
       * @return Vector const W element.
       */
      const T& w() const;
   };

   /*! Specialized three dimensional vector.
    */
   template <class T> class Vector<3, T> : public Matrix<3, 1, T>{
   public:

      /*! Constructs a vector.
       *
       * @param initialize @c true to initialize all elements to zero;
       *                   otherwise elements are left uninitialized.
       */
      Vector(const bool& initialize = true);

      /*! Constructs a vector from elements.
       *
       * @param X element value.
       * @param Y element value.
       * @param Z element value.
       */
      Vector(const T& x, const T& y, const T& z);

      /*! Converts a matrix to vector.
       *
       * @param other Matrix to convert.
       */
      Vector(const Matrix<3, 1, T>& other);

      /*! Converts a 4-dimensional vector to 3-dimensional one.
       *
       * @param other Vector to convert.
       */
      explicit Vector(const Vector<4, T>& other);

      /*! Gets X element of vector.
       *
       * @return Vector X element.
       */
      T& x();

      /*! Gets Y element of vector.
       *
       * @return Vector Y element.
       */
      T& y();

      /*! Gets Z element of vector.
       *
       * @return Vector Z element.
       */
      T& z();

      /*! Gets X element of vector.
       *
       * @return Vector const X element.
       */
      const T& x() const;

      /*! Gets Y element of vector.
       *
       * @return Vector const Y element.
       */
      const T& y() const;

      /*! Gets Z element of vector.
       *
       * @return Vector const Z element.
       */
      const T& z() const;
   };

   /*! Specialized two dimensional vector.
    */
   template <class T> class Vector<2, T> : public Matrix<2, 1, T>{
   public:

      /*! Constructs a vector.
       *
       * @param initialize @c true to initialize all elements to zero;
       *                   otherwise elements are left uninitialized.
       */
      Vector(const bool& initialize = true);

      /*! Constructs a vector from elements.
       *
       * @param X element value.
       * @param Y element value.
       */
      Vector(const T& x, const T& y);

      /*! Converts a matrix to vector.
       *
       * @param other Matrix to convert.
       */
      Vector(const Matrix<2, 1, T>& other);

      /*! Converts a 3-dimensional vector to 2-dimensional one.
       *
       * @param other Vector to convert.
       */
      explicit Vector(const Vector<3, T>& other);

      /*! Gets X element of vector.
       *
       * @return Vector X element.
       */
      T& x();

      /*! Gets Y element of vector.
       *
       * @return Vector Y element.
       */
      T& y();

      /*! Gets X element of vector.
       *
       * @return Vector const X element.
       */
      const T& x() const;

      /*! Gets Y element of vector.
       *
       * @return Vector const Y element.
       */
      const T& y() const;
   };

   typedef Vector<2, double> vec2;
   typedef Vector<2, float> vec2f;
   typedef Vector<3, double> vec3;
   typedef Vector<3, float> vec3f;
   typedef Vector<4, double> vec4;
   typedef Vector<4, float> vec4f;

   /*! Normalizes a vector.
    *
    * @param vector Subject vector.
    * @return A normalized vector.
    */
   template <size_t N, class T> Vector<N, T> normalize(const Vector<N, T>& vector);

   /*! Find outs the magnitude of a vector.
    *
    * @return Magnitude of the vector.
    */
   template <size_t N, class T> T length(const Vector<N, T>& vector);

}

/*! Calculates a dot product of two vectors.
 *
 * @param lhs Left hand side vector.
 * @param rhs Right hand side vector.
 * @return Dot product result.
 */
template <size_t N, class T> T operator *(const Math::Vector<N, T>& lhs, const Math::Vector<N, T>& rhs);

/*! Calculates a cross product of two vectors.
 *
 * @param lhs Left hand side vector.
 * @param rhs Right hand side vector.
 * @return Cross producted vector.
 */
template <class T> Math::Vector<3, T> operator %(const Math::Vector<3, T>& lhs, const Math::Vector<3, T>& rhs);

template <> struct std::hash<Math::vec2> {
   std::size_t operator()(const Math::vec2& k) const {
      return std::hash<double>()(k.x()) ^ std::hash<double>()(k.y());
   }
};

#include "vector.inl"
