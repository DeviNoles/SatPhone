/**
 * @brief Point3D Class
 */

#include <cmath>
#include <iostream>
#include "point3d.hpp"

/**
 * @brief Default constructor.
 */
Point3D::Point3D() {
   x = y = z = 0;
}

/**
 * @brief Constructor.
 */
Point3D::Point3D(double x, double y, double z) {
   SetCoords(x, y, z);
}

/**
 * @brief Destructor.
 */
Point3D::~Point3D() {
}

/**
 * @brief Get x coordinate.
 */
double Point3D::GetX() const {
   return x;
}

/**
 * @brief Get y coordinate.
 */
double Point3D::GetY() const {
   return y;
}

/**
 * @brief Get z coordinate.
 */
double Point3D::GetZ() const {
   return z;
}

/**
 * @brief Sets the x, y, and z coordinates of the point.
 */
void Point3D::SetCoords(double x, double y, double z) {
   this->x = x;
   this->y = y;
   this->z = z;
}

/**
 * @brief Returns the distance between 2 points.
 */
double Point3D::DistanceTo(const Point3D& p) const {
   return (2 * exp(-1 * (std::pow(x-p.GetX(), 2) + std::pow(y-p.GetY(), 2)
         + std::pow(z-p.GetZ(), 2))));
}

