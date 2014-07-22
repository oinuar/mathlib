#pragma once

#include <type_traits>
#include <limits>
#include "matrix.hpp"
#include "functions.hpp"

namespace Math {

   /*! Constructs an identity matrix of given size.
    *
    * @return Identity matrix of size NxN.
    */
   template <size_t N, class T = double> Matrix<N, N, T> eye();

   /*! Calculates a LU decomposition and returns individual element matrices.
    *
    * @param m Subject matrix.
    * @param l Lower triangulation element matrix.
    * @param u Upper triangulation element matrix.
    * @param pivot A pivot or permutation matrix.
    * @return Number of swaps made to produce a permutation matrix.
    */
   template <size_t M, size_t N, class T> size_t lu(const Matrix<M, N, T>& m, Matrix<M, M, T>& l, Matrix<M, N, T>& u, Matrix<M, M, T>& pivot);

   /*! Solves a linear equation using LU decomposition.
    *
    * @param l Lower triangulated matrix.
    * @param u Upper triangulated matrix.
    * @param pivot Permutation matrix.
    * @param b Vector to solve.
    * @return A solved vector.
    */
   template <size_t M, size_t N, class T> Vector<M, T> solvelu(const Matrix<M, M, T>& l, const Matrix<M, N, T>& u, const Matrix<M, M, T>& pivot, const Vector<M, T>& b);

   /*! Finds out the determinant value of a matrix.
    *
    * @param m Subject matrix.
    * @return A determinant value.
    */
   template <size_t N, class T, class C> typename std::enable_if<N >= 2, T>::type det(const Matrix<N, N, T, C>& m);

   /*! Finds out the inverse matrix.
    *
    * @param m Subject matrix.
    * @return An inverted matrix.
    */
   template <size_t M, size_t N, class T, class C> Matrix<M, N, T> inv(const Matrix<M, N, T, C>& m);

   /*! Solves a linear system.
    *
    * @param a Coefficient matrix.
    * @param b Matrix to solve.
    * @return A solved matrix.
    */
   template <size_t M, size_t N, size_t P, class T, class C, class D> Matrix<M, P, T> solve(const Matrix<M, N, T, C>& a, const Matrix<N, P, T, D>& b);
}

#include "linearalgebra.inl"
