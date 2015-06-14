namespace Math {

   template <size_t M, size_t N, class T> inline
   size_t lu(const Matrix<M, N, T>& m, Matrix<M, M, T>& l, Matrix<M, N, T>& u, Matrix<M, M, T>& pivot) {
      pivot = eye<M, T>();
      l = Matrix<M, M, T>();
      u = Matrix<M, N, T>();
      size_t swaps = 0;

      // Make a permutation matrix from the identity matrix. And count how
      // many swaps were made.
      for (size_t i = 1; i <= M; ++i) {
         auto max = m(i, i);
         size_t row = i;

         for (size_t j = i; j <= M; ++j) {
            if (m(j, i) > max) {
               max = m(j, i);
               row = j;
            }
         }

         // Swap the rows.
         if (i != row) {
            auto tmp = pivot.get_row(i);
            pivot.set_row(i, pivot.get_row(row));
            pivot.set_row(row, tmp);
            ++swaps;
         }
      }

      auto a = pivot * m;

      for (size_t j = 0; j < M; ++j) {
         l(j + 1, j + 1) = (T)1;

         for (size_t i = 0; i <= j; ++i) {
            auto s1 = (T)0;

            for (size_t k = 0; k < i; ++k)
               s1 += u(k + 1, j + 1) * l(i + 1, k + 1);

            u(i + 1, j + 1) = a(i + 1, j + 1) - s1;
         }

         for (size_t i = j; i < M; ++i) {
            auto s2 = (T)0;

            for (size_t k = 0; k < j; ++k)
               s2 += u(k + 1, j + 1) * l(i + 1, k + 1);

            l(i + 1, j + 1) = (a(i + 1, j + 1) - s2) / u(j + 1, j + 1);
         }
      }

      return swaps;
   }

   template <size_t M, size_t N, class T> inline
   Vector<M, T> solvelu(const Matrix<M, M, T>& l, const Matrix<M, N, T>& u, const Matrix<M, M, T>& pivot, const Vector<M, T>& b) {
      Vector<M, T> x(false), y(false);

      // Rearrange the elements in b.
      auto pb = pivot * b;

      // Forward solve Ly = b.
      for (size_t i = 0; i < M; ++i) {
         y(i + 1, 1) = pb(i + 1, 1);

         for (size_t j = 0; j < i; ++j)
            y(i + 1, 1) -= l(i + 1, j + 1) * y(j + 1, 1);

         y(i + 1, 1) /= l(i + 1, i + 1);
      }

      // Backward solve Ux = y.
      for (size_t i = M - 1; ; --i) {
         x(i + 1, 1) = y(i + 1, 1);

         for (size_t j = i + 1; j < M; ++j)
            x(i + 1, 1) -= u(i + 1, j + 1) * x(j + 1, 1);

         x(i + 1, 1) /= u(i + 1, i + 1);

         if (i == 0)
            break;
      }

      return std::move(x);
   }

   template <size_t N, class T, class C> inline
   typename std::enable_if<N >= 2, T>::type det(const Matrix<N, N, T, C>& m) {
      Matrix<N, N, T> l(false), u(false), pivot(false);
      const T sgn = (T)(lu(m, l, u, pivot) % 2 == 0 ? +1 : -1);

      auto out = u(1, 1) * sgn;

      for (size_t i = 2; i <= N; ++i)
         out *= u(i, i);

      return out;
   }

   template <size_t M, size_t N, class T, class C> inline
   Matrix<M, N, T> inv(const Matrix<M, N, T, C>& m) {
      return std::move(solve(m, eye<N, T>()));
   }

   template <size_t M, size_t N, size_t P, class T, class C, class D> inline
   Matrix<M, P, T> solve(const Matrix<M, N, T, C>& a, const Matrix<N, P, T, D>& b) {
      Matrix<M, M, T> l(false), pivot(false);
      Matrix<M, N, T> u(false);
      Matrix<M, P, T> out(false);

      lu(a, l, u, pivot);

      for (size_t i = 1; i <= P; ++i)
         out.set_column(i, solvelu(l, u, pivot, Vector<N, T>(b.get_column(i))));

      return std::move(out);
   }

}
