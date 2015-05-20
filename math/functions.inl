
namespace Math {

   template <class T> inline
   T Abs(const T& value) {
      return std::abs(value);
   }

   template <class T> inline
   T Max(const T& lhs, const T& rhs) {
      return lhs < rhs ? rhs : lhs;
   }

   template <class T> inline
   T Min(const T& lhs, const T& rhs) {
      return lhs < rhs ? lhs : rhs;
   }

   template <class T> inline
   T Clamp(const T& value, const T& lower, const T& upper) {
      return Max(lower, Min(value, upper));
   }

   template <class T> T inline
   Floor(const T& value) {
      return std::floor(value);
   }

   template <class T> inline
   T Round(const T& value, const T& precision) {
      return Floor(value * ((T)1.0 / precision) + (T)0.5) / ((T)1.0 / precision);
   }

   template <class T> inline
   T Sqrt(const T& value) {
      return std::sqrt(value);
   }

   template <class T> inline
   T Sin(const Degree<T>& value) {
      return std::sin(Radian<T>(value));
   }

   template <class T> inline
   T Cos(const Degree<T>& value) {
      return std::cos(Radian<T>(value));
   }

   template <class T> inline
   T Tan(const Degree<T>& value) {
      return std::tan(Radian<T>(value));
   }

   template <class T> inline
   Degree<T> ASin(const T& value) {
      return std::asin(value) * ((T)180 / Pi<T>());
   }

   template <class T> inline
   Degree<T> ACos(const T& value) {
      return std::acos(value) * ((T)180 / Pi<T>());
   }

}
