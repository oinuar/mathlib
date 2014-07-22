
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
   T Sqrt(const T& value) {
      return std::sqrt(value);
   }

   template <class T> T inline
   Floor(const T& value) {
      return std::floor(value);
   }

   template <class T> inline
   T Round(const T& value, const T& precision) {
      return Floor(value * ((T)1.0 / precision) + (T)0.5) / ((T)1.0 / precision);
   }
}
