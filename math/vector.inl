
namespace Math {

   template <class T> inline
   Vector<4, T>::Vector(const bool& initialize) : Matrix(initialize) {

   }

   template <class T> inline
   Vector<4, T>::Vector(const T& x, const T& y, const T& z, const T& w) : Matrix(false) {
      this->x() = x;
      this->y() = y;
      this->z() = z;
      this->w() = w;
   }

   template <class T> inline
   Vector<4, T>::Vector(const Matrix<4, 1, T>& other) : Matrix(other) {

   }

   template <class T> inline
   T& Vector<4, T>::x() {
      return (*this)(1, 1);
   }

   template <class T> inline
   T& Vector<4, T>::y() {
      return (*this)(2, 1);
   }

   template <class T> inline
   T& Vector<4, T>::z() {
      return (*this)(3, 1);
   }

   template <class T> inline
   T& Vector<4, T>::w() {
      return (*this)(4, 1);
   }

   template <class T> inline
   const T& Vector<4, T>::x() const {
      return (*this)(1, 1);
   }

   template <class T> inline
   const T& Vector<4, T>::y() const {
      return (*this)(2, 1);
   }

   template <class T> inline
   const T& Vector<4, T>::z() const {
      return (*this)(3, 1);
   }

   template <class T> inline
   const T& Vector<4, T>::w() const {
      return (*this)(4, 1);
   }


   template <class T> inline
   Vector<3, T>::Vector(const bool& initialize) : Matrix(initialize) {

   }

   template <class T> inline
   Vector<3, T>::Vector(const T& x, const T& y, const T& z) : Matrix(false) {
      this->x() = x;
      this->y() = y;
      this->z() = z;
   }

   template <class T> inline
   Vector<3, T>::Vector(const Matrix<3, 1, T>& other) : Matrix(other) {

   }

   template <class T> inline
   Vector<3, T>::Vector(const Vector<4, T>& other) : Matrix(false) {
      this->x() = other.x();
      this->y() = other.y();
      this->z() = other.z();
   }

   template <class T> inline
   T& Vector<3, T>::x() {
      return (*this)(1, 1);
   }

   template <class T> inline
   T& Vector<3, T>::y() {
      return (*this)(2, 1);
   }

   template <class T> inline
   T& Vector<3, T>::z() {
      return (*this)(3, 1);
   }

   template <class T> inline
   const T& Vector<3, T>::x() const {
      return (*this)(1, 1);
   }

   template <class T> inline
   const T& Vector<3, T>::y() const {
      return (*this)(2, 1);
   }

   template <class T> inline
   const T& Vector<3, T>::z() const {
      return (*this)(3, 1);
   }


   template <class T> inline
   Vector<2, T>::Vector(const bool& initialize) : Matrix(initialize) {

   }

   template <class T> inline
   Vector<2, T>::Vector(const T& x, const T& y) : Matrix(false) {
      this->x() = x;
      this->y() = y;
   }

   template <class T> inline
   Vector<2, T>::Vector(const Matrix<2, 1, T>& other) : Matrix(other) {

   }

   template <class T> inline
   Vector<2, T>::Vector(const Vector<3, T>& other) : Matrix(false) {
      this->x() = other.x();
      this->y() = other.y();
   }

   template <class T> inline
   T& Vector<2, T>::x() {
      return (*this)(1, 1);
   }

   template <class T> inline
   T& Vector<2, T>::y() {
      return (*this)(2, 1);
   }

   template <class T> inline
   const T& Vector<2, T>::x() const {
      return (*this)(1, 1);
   }

   template <class T> inline
   const T& Vector<2, T>::y() const {
      return (*this)(2, 1);
   }
}

template <size_t N, class T> inline
T operator *(const Math::Vector<N, T>& lhs, const Math::Vector<N, T>& rhs) {
   return ~lhs * rhs;
}

template <class T> inline
Math::Vector<3, T> operator %(const Math::Vector<3, T>& lhs, const Math::Vector<3, T>& rhs) {
   return std::move(Math::Vector<3, T>(
      y() * other.z - z() * other.y(),
      z() * other.x - x() * other.z(),
      x() * other.y - y() * other.x()
   ));
}
