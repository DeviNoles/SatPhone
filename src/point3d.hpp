/**
 * @brief Header for Point3D class.
 */

#ifndef POINT3D_H
#define POINT3D_H

#include <ostream>

class Point3D {

   private:
      double x, y, z;   /**< Coordinates. */

   public:
      Point3D();
      Point3D(double, double, double);
      ~Point3D();
      double GetX() const;
      double GetY() const;
      double GetZ() const;
      void SetCoords(double, double, double);
      double DistanceTo(const Point3D&) const;
};

#endif

