#include "math.hpp"

using namespace Math;

struct TestConstruction {
   template <size_t M, size_t N, class T>
   static void Call() {
      {
         Matrix<M, N, T> m;

         Equals(Matrix<M, N, T>::Rows, M);
         Equals(Matrix<M, N, T>::Cols, N);
         Equals(m.rows(), M);
         Equals(m.cols(), N);

         for (size_t i = 1; i <= M; ++i) {
            for (size_t j = 1; j <= N; ++j)
               Equals(m(i, j), 0.0);
         }
      }

      {
         T test[M * N];
         Matrix<M, N, T> m(test, test + M * N);
         size_t k = 0;

         for (size_t i = 1; i <= M; ++i) {
            for (size_t j = 1; j <= N; ++j)
               Equals(m(i, j), test[k++]);
         }
      }
   }
};

struct TestMatrixAddition {
   template <size_t M, size_t N, class T>
   static void Call() {
      T test[M * N];
      Matrix<M, N, T> m(test, test + M * N);
      Matrix<M, N, T> out = m + m;

      size_t k = 0;
      for (size_t i = 1; i <= M; ++i) {
         for (size_t j = 1; j <= N; ++j) {
            Equals(out(i, j), test[k] + test[k]);
            ++k;
         }
      }
   }
};

struct TestScalarMultiplication {
   template <size_t M, size_t N, class T>
   static void Call() {
      T test[M * N];
      Matrix<M, N, T> m(test, test + M * N);
      Matrix<M, N, T> out = m * 5.0;

      size_t k = 0;
      for (size_t i = 1; i <= M; ++i) {
         for (size_t j = 1; j <= N; ++j)
            Equals(out(i, j), test[k++] * 5.0);
      }
   }
};

template <size_t M, size_t N>
struct _TestMatrixMultiplication {
   template <size_t m, size_t n, class T>
   static void Call() {
      T src[M * N];
      T dest[m * n];
      Matrix<M, N, T> a(src, src + M * N);
      Matrix<N, n, T> b(dest, dest + m * n);

      Matrix<M, n, T> out = a * b;

      for (size_t i = 1; i <= M; ++i) {
         for (size_t j = 1; j <= n; ++j) {
            T sum = 0;

            for (size_t r = 1; r <= N; ++r)
               sum += a(i, r) * b(r, j);

            Equals(out(i, j), sum);
         }
      }
   }
};

struct TestMatrixMultiplication {
   template <size_t M, size_t N, class T>
   static void Call() {
      unroll<M, 1, M, 4, _TestMatrixMultiplication<M, N>, T>()();
   }
};

struct TestTranspose {
   template <size_t M, size_t N, class T>
   static void Call() {
      T test[M*N];
      Matrix<M, N, T> m(test, test + M * N);
      Matrix<N, M, T> out = ~m;

      for (size_t i = 1; i <= M; ++i) {
         for (size_t j = 1; j <= N; ++j)
            Equals(m(i, j), out(j, i));
      }
   }
};

struct TestAllocation {
   template <size_t M, size_t N, class T>
   static void Call() {
      Matrix<M, N, T> m;

      Equals(check<typename Matrix<M, N, T>::chunk>(M * N), true);
   }

private:
   template <class Chunk>
   static typename std::enable_if<Chunk::Location == Stack, bool>::type check(const size_t& size) {
      return size <= 1024;
   }

   template <class Chunk>
   static typename std::enable_if<Chunk::Location == Heap, bool>::type check(const size_t& size) {
      return size > 1024;
   }
};

template <class T, class U> void Equals(const T& test, const U& excepted) {
   if (!(test == excepted))
      throw "Not equal";
}

template <size_t M, size_t N, size_t MDepth, size_t NDepth, class Apply, class T> struct unroll {
   void operator ()() {
      Apply::Call<M, N, T>();
      callM<M>();
      callN<N>();
   }

private:

   template <size_t P, typename std::enable_if<P < MDepth>::type* = nullptr>
   void callM() {
      unroll<P + 1, N, MDepth, NDepth, Apply, T>()();
   }

   template <size_t P, typename std::enable_if<P < NDepth>::type* = nullptr>
   void callN() {
      unroll<M, P + 1, MDepth, NDepth, Apply, T>()();
   }

   template <size_t P, typename std::enable_if<P >= MDepth>::type* = nullptr>
   void callM() {}

   template <size_t P, typename std::enable_if<P >= NDepth>::type* = nullptr>
   void callN() {}
};

static void test_3x3_lu() {
   mat3x3 m({
      4, -2, 1,
      -3, -1, 4,
      1, -1, 3
   });

   const double L[] = {
      1, 0, 0,
      -0.75, 1, 0,
      0.25, 0.2, 1
   };

   const double U[] = {
      4, -2, 1,
      0, -2.5, 4.75,
      0, 0, 1.8
   };

   const double P[] = {
      1, 0, 0,
      0, 1, 0,
      0, 0, 1
   };

   mat3x3 l(false), u(false), pivot(false);

   lu(m, l, u, pivot);

   size_t k = 0;
   for (size_t i = 1; i <= m.rows(); ++i) {
      for (size_t j = 1; j <= m.cols(); ++j) {
         Equals(Round(l(i, j), 0.001), L[k]);
         Equals(Round(u(i, j), 0.001), U[k]);
         Equals(Round(pivot(i, j), 0.001), P[k]);
         ++k;
      }
   }
}

static void test_4x4_lu() {
   mat4x4 m({
      11, 9, 24, 2,
      1, 5, 2, 6,
      3, 17, 18, 1,
      2, 5, 7, 1
   });

   const double L[] = {
      1, 0, 0, 0,
      0.27273, 1, 0, 0,
      0.09091, 0.28750, 1, 0,
      0.18182, 0.23125, 0.00360, 1
   };

   const double U[] = {
      11, 9, 24, 2,
      0, 14.54545, 11.45455, 0.45455,
      0, 0, -3.4750, 5.68750, 
      0, 0, 0, 0.51079
   };

   const double P[] = {
      1, 0, 0, 0,
      0, 0, 1, 0,
      0, 1, 0, 0,
      0, 0, 0, 1
   };

   mat4x4 l(false), u(false), pivot(false);

   lu(m, l, u, pivot);

   size_t k = 0;
   for (size_t i = 1; i <= m.rows(); ++i) {
      for (size_t j = 1; j <= m.cols(); ++j) {
         Equals(Round(l(i, j), 0.001), Round(L[k], 0.001));
         Equals(Round(u(i, j), 0.001), Round(U[k], 0.001));
         Equals(Round(pivot(i, j), 0.001), Round(P[k], 0.001));
         ++k;
      }
   }
}

static void test_3x3_inv() {
   mat3x3 m({
      4, -2, 1,
      -3, -1, 4,
      1, -1, 3
   });

   auto r = inv(m) * m;

   for (size_t i = 1; i <= r.rows(); ++i) {
      for (size_t j = 1; j <= r.cols(); ++j) {
         if (i == j)
            Equals(Round(r(i, j), 0.001), 1.0);
         else
            Equals(Round(r(i, j), 0.001), 0.0);
      }
   }
}

static void test_4x4_inv() {
   mat4x4 m({
      11, 9, 24, 2,
      1, 5, 2, 6,
      3, 17, 18, 1,
      2, 5, 7, 1
   });

   auto r = inv(m) * m;

   for (size_t i = 1; i <= r.rows(); ++i) {
      for (size_t j = 1; j <= r.cols(); ++j) {
         if (i == j)
            Equals(Round(r(i, j), 0.001), 1.0);
         else
            Equals(Round(r(i, j), 0.001), 0.0);
      }
   }
}

int main() {
   unroll<1, 1, 4, 4, TestConstruction, double>()();
   unroll<1, 1, 4, 4, TestMatrixAddition, double>()();
   unroll<1, 1, 4, 4, TestScalarMultiplication, double>()();
   unroll<1, 1, 4, 4, TestMatrixMultiplication, double>()();
   unroll<1, 1, 4, 4, TestTranspose, double>()();
   unroll<31, 31, 33, 33, TestAllocation, double>()();

   test_3x3_lu();
   test_4x4_lu();
   test_3x3_inv();
   test_4x4_inv();

   return 0;
}
