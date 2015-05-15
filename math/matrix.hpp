#pragma once

#include "matrixchunk.hpp"
#include <cstring>
#include <cassert>
#include <utility>

namespace Math {

   /*! MxN matrix.
    */
   template < size_t M, size_t N, class T, class Chunk = MatrixChunk<M, N, T> >
   class Matrix {
   public:

      //! Matrix row size constant.
      static const size_t Rows = M;

      //! Matrix column size constant.
      static const size_t Cols = N;

      //! Type alias for element types.
      typedef T type;

      //! Type alias for chunk type.
      typedef Chunk chunk;

      /*! Constructs a matrix.
       *
       * @param initialize @c true to initialize all elements to zero;
       *                   otherwise elements are left uninitialized.
       */
      Matrix(const bool& initialize = true);

      /*! Constructs a matrix from range.
       *
       * @param begin Range begin.
       * @param end Range end.
       */
      template <class Iter> Matrix(Iter begin, Iter end);

      /*! Constructs a matrix from an intializer list.
       *
       * @param list The initializer list.
       */
      Matrix(const std::initializer_list<T>& list);

      /*! Constructs a matrix from another type by casting.
       *
       * @param other Matrix to construct.
       */
      template <class t> explicit Matrix(const Matrix<M, N, t>& other);

      /*! Tells the number of rows.
       *
       * @return Number of rows.
       */
      const size_t rows() const;

      /*! Tells the number of columns.
       *
       * @return Number of columns.
       */
      const size_t cols() const;

      /*! Gets raw data pointer to matrix data.
       *
       * @return Data pointer to matrix data.
       */
      T* data();

      /*! Access matrix elements.
       *
       * @param i Row number, 1-based.
       * @param j Column number, 1-based.
       * @return Element at given location.
       */
      T& operator ()(const size_t& i, const size_t& j);

      /*! Access matrix elements.
       *
       * @param i Row number, 1-based.
       * @param j Column number, 1-based.
       * @return Const element at given location.
       */
      const T& operator ()(const size_t& i, const size_t& j) const;

      /*! Access flattened matrix elements.
       *
       * @param index Element index, 1-based.
       * @return Element at given location.
       */
      T& operator [](const size_t& index);

      /*! Access flattened matrix elements.
       *
       * @param index Element index, 1-based.
       * @return Const element at given location.
       */
      const T& operator [](const size_t& index) const;

      /*! Gets raw data pointer to matrix data.
       *
       * @return Cost data pointer to matrix data.
       */
      const T* data() const;

      /*! Gets matrix column at given location.
       *
       * @param column Column index, 1-based.
       * @return Sub matrix for given column.
       */
      Matrix<M, 1, T> get_column(const size_t& column) const;

      /*! Gets matrix row at given location.
       *
       * @param row Row index, 1-based.
       * @return Sub matrix for given row.
       */
      Matrix<1, N, T> get_row(const size_t& row) const;

      /*! Gets a sub matrix at given location.
       *
       * @param i Sub matrix first row index, 1-based.
       * @param j Sub matrix first column index, 1-based.
       * @return Extracted sub matrix.
       */
      template <size_t m, size_t n> Matrix<m, n, T> get_sub(const size_t& i, const size_t& j) const;

      /*! Sets matrix column.
       *
       * @param column Column index, 1-based.
       * @param m Matrix to set to given column.
       */
      void set_column(const size_t& column, const Matrix<M, 1, T>& m);

      /*! Sets matrix row.
       *
       * @param row Row index, 1-based.
       * @param m Matrix to set to given row.
       */
      void set_row(const size_t& row, const Matrix<1, N, T>& m);

      /*! Sets a sub matrix at given location.
       *
       * @param i Sub matrix first row index, 1-based.
       * @param j Sub matrix first column index, 1-based.
       * @param matrix Sub marix to set.
       */
      template <size_t m, size_t n, class c> void set_sub(const size_t& i, const size_t& j, const Matrix<m, n, T, c>& matrix);

   private:
      Chunk _data;
   };

   /*! Scalar specialization of 1 by 1 dimensional matrix.
    */
   template < class T, class Chunk> class Matrix< 1, 1, T, Chunk> {
   public:

      //! Matrix row size constant.
      static const size_t Rows = 1;

      //! Matrix column size constant.
      static const size_t Cols = 1;

      //! Type alias for element types.
      typedef T type;

      /*! Constructs a matrix.
       *
       * @param initialize @c true to initialize all elements to zero;
       *                   otherwise elements are left uninitialized.
       */
      Matrix(const bool& initialize = true);

      /*! Constructs a matrix from range.
       *
       * @param begin Range begin.
       * @param end Range end.
       */
      template <class Iter> Matrix(Iter begin, Iter end);

      /*! Constructs a matrix as from a scalar value.
       *
       * @param value Scalar value.
       */
      Matrix(const T& value);

      /*! Implicitly converts matrix to a scalar.
       */
      operator T() const;

      /*! Gets raw data pointer to matrix data.
       *
       * @return Data pointer to matrix data.
       */
      T* data();

      /*! Tells the number of rows.
       *
       * @return Number of rows.
       */
      const size_t rows() const;

      /*! Tells the number of columns.
       *
       * @return Number of columns.
       */
      const size_t cols() const;

      /*! Access matrix elements.
       *
       * @param i Row number, 1-based. Must always be 1.
       * @param j Column number, 1-based. Must always be 1.
       * @return Element at given location.
       */
      T& operator ()(const size_t& i, const size_t& j);

      /*! Access matrix elements.
       *
       * @param i Row number, 1-based. Must always be 1.
       * @param j Column number, 1-based. Must always be 1.
       * @return Const element at given location.
       */
      const T& operator ()(const size_t& i, const size_t& j) const;

      /*! Access flattened matrix elements.
       *
       * @param index Element index, 1-based. Must always be 1.
       * @return Element at given location.
       */
      T& operator [](const size_t& index);

      /*! Access flattened matrix elements.
       *
       * @param index Element index, 1-based. Must always be 1.
       * @return Const element at given location.
       */
      const T& operator [](const size_t& index) const;

      /*! Gets raw data pointer to matrix data.
       *
       * @return Const data pointer to matrix data.
       */
      const T* data() const;

   private:
      T _value;
   };

   typedef Matrix<2, 2, double> mat2x2;
   typedef Matrix<2, 2, float> mat2x2f;
   typedef Matrix<3, 3, double> mat3x3;
   typedef Matrix<3, 3, float> mat3x3f;
   typedef Matrix<4, 4, double> mat4x4;
   typedef Matrix<4, 4, float> mat4x4f;

   /*! Constructs an identity matrix of given size.
    *
    * @return Identity matrix of size NxN.
    */
   template <size_t N, class T = double> Matrix<N, N, T> eye();
}

/*! Negates a matrix.
 *
 * @param m Matrix to negate.
 * @return Negated matrix.
 */
template <size_t M, size_t N, class T, class C> Math::Matrix<M, N, T> operator -(const Math::Matrix<M, N, T, C>& m);

/*! Transposes a matrix.
 *
 * @param m Matrix to transpose.
 * @return Transposed matrix.
 */
template <size_t M, size_t N, class T, class C> Math::Matrix<N, M, T> operator ~(const Math::Matrix<M, N, T, C>& m);

/*! Adds two matrices.
 *
 * @param lhs Left hand side matrix.
 * @param rhs Right hand side matrix.
 * @return Added matrix.
 */
template <size_t M, size_t N, class T, class C, class D> Math::Matrix<M, N, T> operator +(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<M, N, T, D>& rhs);

/*! Substracts two matrices.
 *
 * @param lhs Left hand side matrix.
 * @param rhs Right hand side matrix.
 * @return Substracted matrix.
 */
template <size_t M, size_t N, class T, class C, class D> Math::Matrix<M, N, T> operator -(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<M, N, T, D>& rhs);

/*! Multiplies matrix with a scalar.
 *
 * @param m Matrix to multiply.
 * @param n Scalar to multiply with.
 * @return Multiplied matrix.
 */
template <size_t M, size_t N, class T, class C> Math::Matrix<M, N, T> operator *(const Math::Matrix<M, N, T, C>& m, const T& n);

/*! Multiplies two matrices.
 *
 * @param lhs Left hand side matrix.
 * @param rhs Right hand side matrix.
 * @return Multiplied matrix.
 */
template <size_t M, size_t N, size_t P, class T, class C, class D> Math::Matrix<M, P, T> operator *(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<N, P, T, D>& rhs);

#include "matrix.inl"
