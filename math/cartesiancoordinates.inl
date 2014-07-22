namespace Math {
   
   inline
   CartesianCoordinateSystem<2>::CartesianCoordinateSystem()
      : _base(eye<2>()), _origin()
   {

   }

   inline
   CartesianCoordinateSystem<2>::CartesianCoordinateSystem(const mat3x3& m)
      : _base(m.get_sub<2,2>(1, 1)), _origin(m.get_column(3))
   {

   }

   inline
   CartesianCoordinateSystem<2>& CartesianCoordinateSystem<2>::right(const vector2& v) {
      _base.set_column(1, v);
      return *this;
   }

   inline
   CartesianCoordinateSystem<2>& CartesianCoordinateSystem<2>::up(const vector2& v) {
      _base.set_column(2, v);
      return *this;
   }

   inline
   CartesianCoordinateSystem<2>& CartesianCoordinateSystem<2>::base(const mat2x2& m) {
      _base = m;
      return *this;
   }

   inline
   CartesianCoordinateSystem<2>& CartesianCoordinateSystem<2>::origin(const vector2& p) {
      _origin = p;
      return *this;
   }

   inline
   vector2 CartesianCoordinateSystem<2>::right() const {
      return _base.get_column(1);
   }

   inline
   vector2 CartesianCoordinateSystem<2>::up() const {
      return _base.get_column(2);
   }

   inline
   mat2x2 CartesianCoordinateSystem<2>::base() const {
      return _base;
   }

   inline
   vector2 CartesianCoordinateSystem<2>::origin() const {
      return _origin;
   }

   inline
   CartesianCoordinateSystem<2>::operator mat3x3() const {
      mat3x3 out(false);

      out.set_sub(1, 1, _base);
      out.set_column(3, vector3(_origin.x(), _origin.y(), 1.0));

      return std::move(out);
   }

   inline
   vector2 CartesianCoordinateSystem<2>::project(const vector2& v) const {
      return _base * v + _origin;
   }

   inline
   vector2 CartesianCoordinateSystem<2>::unproject(const vector2& v) const {
      return inv(_base) * v + -_origin;
   }


   inline
   CartesianCoordinateSystem<3>::CartesianCoordinateSystem()
      : _base(eye<3>()), _origin()
   {

   }

   inline
   CartesianCoordinateSystem<3>::CartesianCoordinateSystem(const mat4x4& m)
      : _base(m.get_sub<3,3>(1, 1)), _origin(m.get_column(4))
   {

   }

   inline
   CartesianCoordinateSystem<3>& CartesianCoordinateSystem<3>::right(const vector3& v) {
      _base.set_column(1, v);
      return *this;
   }

   inline
   CartesianCoordinateSystem<3>& CartesianCoordinateSystem<3>::up(const vector3& v) {
      _base.set_column(2, v);
      return *this;
   }

   inline
   CartesianCoordinateSystem<3>& CartesianCoordinateSystem<3>::direction(const vector3& v) {
      _base.set_column(3, v);
      return *this;
   }

   inline
   CartesianCoordinateSystem<3>& CartesianCoordinateSystem<3>::base(const mat3x3& m) {
      _base = m;
      return *this;
   }

   inline
   CartesianCoordinateSystem<3>& CartesianCoordinateSystem<3>::origin(const vector3& p) {
      _origin = p;
      return *this;
   }

   inline
   vector3 CartesianCoordinateSystem<3>::right() const {
      return _base.get_column(1);
   }

   inline
   vector3 CartesianCoordinateSystem<3>::up() const {
      return _base.get_column(2);
   }

   inline
   vector3 CartesianCoordinateSystem<3>::direction() const {
      return _base.get_column(3);
   }

   inline
   mat3x3 CartesianCoordinateSystem<3>::base() const {
      return _base;
   }

   inline
   vector3 CartesianCoordinateSystem<3>::origin() const {
      return _origin;
   }

   inline
   CartesianCoordinateSystem<3>::operator mat4x4() const {
      mat4x4 out(false);

      out.set_sub(1, 1, _base);
      out.set_column(4, vector4(_origin.x(), _origin.y(), _origin.z(), 1.0));

      return std::move(out);
   }

   inline
   vector3 CartesianCoordinateSystem<3>::project(const vector3& v) const {
      return _base * v + _origin;
   }

   inline
   vector3 CartesianCoordinateSystem<3>::unproject(const vector3& v) const {
      return inv(_base) * v + -_origin;
   }
}
