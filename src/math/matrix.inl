
namespace Math {

   template <size_t M, size_t N, class T, class C> inline
   Matrix<M, N, T, C>::Matrix(const bool& initialize) : _data() {
      if (initialize) {
         for (size_t i = 0; i < M*N; ++i)
            _data[i] = (T)0;
      }
   }

   template <size_t M, size_t N, class T, class C>
   template <class Iter> inline
   Matrix<M, N, T, C>::Matrix(Iter begin, Iter end) : _data() {
      size_t i = 0;
      for (Iter it = begin; it != end; ++it)
         _data[i++] = (T)*it;
   }

   template <size_t M, size_t N, class T, class C>
   Matrix<M, N, T, C>::Matrix(const std::initializer_list<T>& list) {
      size_t i = 0;
      for (auto &item : list)
         _data[i++] = item;
   }

   template <size_t M, size_t N, class T, class C>
   template <class U> inline
   Matrix<M, N, T, C>::Matrix(const Matrix<M, N, U>& other) : _data() {
      for (size_t i = 1; i <= M; ++i) {
         for (size_t j = 1; j <= N; ++j)
            (*this)(i, j) = (T)other(i, j);
      }
   }

   template <size_t M, size_t N, class T, class C> inline
   size_t Matrix<M, N, T, C>::rows() const {
      return M;
   }

   template <size_t M, size_t N, class T, class C> inline
   size_t Matrix<M, N, T, C>::cols() const {
      return N;
   }

   template <size_t M, size_t N, class T, class C> inline
   T* Matrix<M, N, T, C>::data() {
      return _data;
   }

   template <size_t M, size_t N, class T, class C> inline
   T& Matrix<M, N, T, C>::operator ()(const size_t& i, const size_t& j) {
      assert(i > 0 && j > 0 && i <= M && j <= N);
      return _data[(j - 1) * M + (i - 1)];
   }

   template <size_t M, size_t N, class T, class C> inline
   const T& Matrix<M, N, T, C>::operator ()(const size_t& i, const size_t& j) const {
      assert(i > 0 && j > 0 && i <= M && j <= N);
      return _data[(j - 1) * M + (i - 1)];
   }

   template <size_t M, size_t N, class T, class C> inline
   T& Matrix<M, N, T, C>::operator [](const size_t& index) {
      assert(index > 0 && index <= M*N);
      return _data[index - 1];
   }

   template <size_t M, size_t N, class T, class C> inline
   const T& Matrix<M, N, T, C>::operator [](const size_t& index) const {
      assert(index > 0 && index <= M*N);
      return _data[index - 1];
   }

   template <size_t M, size_t N, class T, class C> inline
   bool Matrix<M, N, T, C>::operator ==(const Matrix<M, N, T, C>& other) const {
      for (size_t i = 1; i <= M; ++i) {
         for (size_t j = 1; j <= N; ++j) {
            if ((*this)(i, j) != other(i, j))
               return false;
         }
      }

      return true;
   }

   template <size_t M, size_t N, class T, class C> inline
   const T* Matrix<M, N, T, C>::data() const {
      return _data;
   }

   template <size_t M, size_t N, class T, class C> inline
   Matrix<M, 1, T> Matrix<M, N, T, C>::get_column(const size_t& column) const {
      Matrix<M, 1, T> m(false);

      for (size_t i = 1; i <= M; ++i)
         m(i, 1) = (*this)(i, column);

      return std::move(m);
   }

   template <size_t M, size_t N, class T, class C> inline
   Matrix<1, N, T> Matrix<M, N, T, C>::get_row(const size_t& row) const {
      Matrix<1, M, T> m(false);

      for (size_t i = 1; i <= N; ++i)
         m(1, i) = (*this)(row, i);

      return std::move(m);
   }

   template <size_t M, size_t N, class T, class C>
   template <size_t m, size_t n> inline
   Matrix<m, n, T> Matrix<M, N, T, C>::get_sub(const size_t& ii, const size_t& jj) const {
      Matrix<m, n, T> out(false);

      for (size_t i = ii; i <= m; ++i) {
         for (size_t j = jj; j <= n; ++j)
            out((size_t)(i - ii) + 1, (size_t)(j - jj) + 1) = (*this)(i, j);
      }

      return std::move(out);
   }

   template <size_t M, size_t N, class T, class C> inline
   void Matrix<M, N, T, C>::set_column(const size_t& column, const Matrix<M, 1, T>& m) {
      auto p = m.data();

      for (size_t i = 1; i <= M; ++i)
         (*this)(i, column) = *p++;
   }

   template <size_t M, size_t N, class T, class C> inline
   void Matrix<M, N, T, C>::set_row(const size_t& row, const Matrix<1, N, T>& m) {
      auto p = m.data();

      for (size_t i = 1; i <= N; ++i)
         (*this)(row, i) = *p++;
   }

   template <size_t M, size_t N, class T, class C>
   template <size_t m, size_t n, class c> inline
   void Matrix<M, N, T, C>::set_sub(const size_t& ii, const size_t& jj, const Matrix<m, n, T, c>& matrix) {
      for (size_t i = ii; i <= m; ++i) {
         for (size_t j = jj; j <= n; ++j)
            (*this)(i, j) = matrix((size_t)(i - ii) + 1, (size_t)(j - jj) + 1);
      }
   }

   template <size_t M, size_t N, class T, class C> inline
   auto Matrix<M, N, T, C>::begin() const -> decltype(std::declval<C>().begin()) {
      return _data.begin();
   }

   template <size_t M, size_t N, class T, class C> inline
   auto Matrix<M, N, T, C>::end() const -> decltype(std::declval<C>().end()) {
      return _data.end();
   }


   template <class T, class Chunk> inline
   Matrix<1, 1, T, Chunk>::Matrix(const bool& initialize) {
      if (initialize)
         _value = 0;
   }

   template <class T, class Chunk>
   template <class Iter> inline
   Matrix<1, 1, T, Chunk>::Matrix(Iter begin, Iter end) {
      for (Iter it = begin; it != end; ++it)
         _value = *it;
   }

   template <class T, class Chunk> inline
   Matrix<1, 1, T, Chunk>::Matrix(const T& value) {
      _value = value;
   }

   template <class T, class Chunk> inline
   Matrix<1, 1, T, Chunk>::operator T() const {
      return _value;
   }

   template <class T, class Chunk> inline
   T* Matrix<1, 1, T, Chunk>::data() {
      return &_value;
   }

   template <class T, class Chunk> inline
   size_t Matrix<1, 1, T, Chunk>::rows() const {
      return 1;
   }

   template <class T, class Chunk> inline
   size_t Matrix<1, 1, T, Chunk>::cols() const {
      return 1;
   }

   template <class T, class Chunk> inline
   T& Matrix<1, 1, T, Chunk>::operator ()(const size_t& i, const size_t& j) {
      assert(i == 1 && j == 1);
      return _value;
   }

   template <class T, class Chunk> inline
   const T& Matrix<1, 1, T, Chunk>::operator ()(const size_t& i, const size_t& j) const {
      assert(i == 1 && j == 1);
      return _value;
   }

   template <class T, class Chunk> inline
   T& Matrix<1, 1, T, Chunk>::operator [](const size_t& index) {
      assert(index == 1);
      return _value;
   }

   template <class T, class Chunk> inline
   const T& Matrix<1, 1, T, Chunk>::operator [](const size_t& index) const {
      assert(index == 1);
      return _value;
   }

   template <class T, class Chunk> inline
   const T* Matrix<1, 1, T, Chunk>::data() const {
      return &_value;
   }


   template <size_t N, class T> inline
   Matrix<N, N, T> eye() {
      Matrix<N, N, T> out(false);

      for (size_t i = 1; i <= N; ++i) {
         for (size_t j = 1; j <= N; ++j)
            out(i, j) = (T)(i == j ? 1 : 0);
      }

      return std::move(out);
   }
}


template <size_t M, size_t N, class T, class C> inline
Math::Matrix<M, N, T> operator -(const Math::Matrix<M, N, T, C>& m) {
   Math::Matrix<M, N, T> out(false);

   for (size_t i = 1; i <= M; ++i) {
      for (size_t j = 1; j <= N; ++j)
         out(i, j) = -m(i, j);
   }

   return std::move(out);
}

template <size_t M, size_t N, class T, class C> inline
Math::Matrix<N, M, T> operator ~(const Math::Matrix<M, N, T, C>& m) {
   Math::Matrix<N, M, T> out(false);

   for (size_t i = 1; i <= M; ++i) {
      for (size_t j = 1; j <= N; ++j)
         out(j, i) = m(i, j);
   }

   return std::move(out);
}

template <size_t M, size_t N, class T, class C, class D> inline
Math::Matrix<M, N, T> operator +(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<M, N, T, D>& rhs) {
   Math::Matrix<M, N, T> out(false);

   for (size_t i = 1; i <= M; ++i) {
      for (size_t j = 1; j <= N; ++j)
         out(i, j) = lhs(i, j) + rhs(i, j);
   }

   return std::move(out);
}

template <size_t M, size_t N, class T, class C, class D> inline
Math::Matrix<M, N, T> operator -(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<M, N, T, D>& rhs) {
   return std::move(lhs + (-rhs));
}

template <size_t M, size_t N, class T, class C> inline
Math::Matrix<M, N, T> operator *(const Math::Matrix<M, N, T, C>& m, const T& n) {
   Math::Matrix<M, N, T> out(false);

   for (size_t i = 1; i <= M; ++i) {
      for (size_t j = 1; j <= N; ++j)
         out(i, j) = m(i, j) * n;
   }

   return std::move(out);
}

template <size_t M, size_t N, size_t P, class T, class C, class D> inline
Math::Matrix<M, P, T> operator *(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<N, P, T, D>& rhs) {
   Math::Matrix<M, P, T> out(false);

   for (size_t i = 1; i <= M; ++i) {
      for (size_t j = 1; j <= P; ++j) {
         out(i, j) = (T)0;

         for (size_t r = 1; r <= N; ++r)
            out(i, j) += lhs(i, r) * rhs(r, j);
      }
   }

   return std::move(out);
}

template <size_t M, size_t N, size_t P, class T, class C, class D> inline
bool operator ==(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<M, N, T, C>& rhs) {
   for (size_t i = 1; i <= M; ++i) {
      for (size_t j = 1; j <= N; ++j) {
         if (lhs(i, j) != rhs(i, j))
            return false;
      }
   }

   return true;
}

template <size_t M, size_t N, size_t P, class T, class C, class D> inline
bool operator !=(const Math::Matrix<M, N, T, C>& lhs, const Math::Matrix<M, N, T, C>& rhs) {
   return !(lhs == rhs);
}
