#pragma once

#include "matrix.hpp"
#include "vector.hpp"
#include "linearalgebra.hpp"

namespace Math {

   /*! General N dimension cartensian coordinate system.
    */
   template <size_t N> class CartesianCoordinateSystem;

   /*! Cartesian coordinate system in two dimensional space.
    */
   template <> class CartesianCoordinateSystem<2> {
   public:

      /*! Constructs an empty cartesian coordinate system.
       */
      CartesianCoordinateSystem();

      /*! Constructs a cartesian coordinate system from a homogeneous matrix.
       *
       * @param m Homogeneous matrix.
       */
      CartesianCoordinateSystem(const mat3x3& m);

      /*! Sets the right axis.
       *
       * @param v Vector pointing to right axis.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& right(const vector2& v);

      /*! Sets the up axis.
       *
       * @param v Vector pointing to up axis.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& up(const vector2& v);
      
      /*! Sets the base matrix.
       *
       * @param m Base matrix.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& base(const mat2x2& m);

      /*! Sets the origin.
       *
       * @param p Point representing the origin.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& origin(const vector2& p);

      /*! Gets right axis.
       *
       * @return Vector pointing to right axis.
       */
      vector2 right() const;

      /*! Gets the up axis.
       *
       * @return Vector pointing to up axis.
       */
      vector2 up() const;

      /*! Gets the base matrix.
       *
       * @return Base matrix.
       */
      mat2x2 base() const;

      /*! Gets the origin.
       *
       * @return Point representing the origin.
       */
      vector2 origin() const;

      /*! Converts cartesian coordinates to a homogeneous matrix.
       *
       * @return A homogeneous matrix representing this coordinate system.
       */
      operator mat3x3() const;

      /*! Projects a vector to this coordinate system.
       *
       * @param v Vector to project.
       * @return Projected vector.
       */
      vector2 project(const vector2& v) const;

      /*! Unprojects a vector from this coordinate system.
       *
       * @param v Vector to unproject.
       * @return Unprojected vector.
       */
      vector2 unproject(const vector2& v) const;

   private:
      mat2x2 _base;
      vector2 _origin;
   };

   /*! Cartesian coordinate system in three dimensional space.
    */
   template <> class CartesianCoordinateSystem<3> {
   public:

      /*! Constructs an empty cartesian coordinate system.
       */
      CartesianCoordinateSystem();

      /*! Constructs a cartesian coordinate system from a homogeneous matrix.
       *
       * @param m Homogeneous matrix.
       */
      CartesianCoordinateSystem(const mat4x4& m);

      /*! Sets the right axis.
       *
       * @param v Vector pointing to right axis.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& right(const vector3& v);

      /*! Sets the up axis.
       *
       * @param v Vector pointing to up axis.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& up(const vector3& v);

      /*! Sets the direction axis.
       *
       * @param v Vector pointing to direction axis.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& direction(const vector3& v);

      /*! Sets the base matrix.
       *
       * @param m Base matrix.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& base(const mat3x3& m);

      /*! Sets the origin.
       *
       * @param p Point representing the origin.
       * @return This coordinate system.
       */
      CartesianCoordinateSystem& origin(const vector3& p);

      /*! Gets right axis.
       *
       * @return Vector pointing to right axis.
       */
      vector3 right() const;

      /*! Gets the up axis.
       *
       * @return Vector pointing to up axis.
       */
      vector3 up() const;

      /*! Gets the direction axis.
       *
       * @return Vector pointing to direction axis.
       */
      vector3 direction() const;

      /*! Gets the base matrix.
       *
       * @return Base matrix.
       */
      mat3x3 base() const;

      /*! Gets the origin.
       *
       * @return Point representing the origin.
       */
      vector3 origin() const;

      /*! Converts cartesian coordinates to a homogeneous matrix.
       *
       * @return A homogeneous matrix representing this coordinate system.
       */
      operator mat4x4() const;

      /*! Projects a vector to this coordinate system.
       *
       * @param v Vector to project.
       * @return Projected vector.
       */
      vector3 project(const vector3& v) const;

      /*! Unprojects a vector from this coordinate system.
       *
       * @param v Vector to unproject.
       * @return Unprojected vector.
       */
      vector3 unproject(const vector3& v) const;

   private:
      mat3x3 _base;
      vector3 _origin;
   };

}

#include "cartesiancoordinates.inl"
