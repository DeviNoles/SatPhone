/**
 * @brief Returns a pair of coordinates denoting the two satellites that will
 *       communicate w/ each other during the satphone call.
 */

#include <cfloat>
#include <iomanip>
#include <iostream>
#include "point3d.hpp"

using Sat = Point3D;
using SatPhone = Point3D;

Sat ClosestSat (const SatPhone&, const Sat*, const unsigned);

/**
 * @brief Reads in the coordinates of two satellite phones and X satellites
 */
int main () {

   const double SPEED_OF_LIGHT = 299792458;  /* In a vaccum (in m/s). */

   double x, y, z;         /* Coordinates.                               */
   double totalDistance;   /* Total distance traveled of radio signal.   */
   Sat *satArr;            /* Array of available satellites.             */
   Sat s1, s2;             /* Sats that will communicate w/ each other.  */
   SatPhone p1, p2;        /* Satphones used to communicate.             */
   unsigned numSats;       /* Number of available satellites.            */

   /* Store coordinates for both satphones. */
   std::cin >> x >> y >> z;
   p1.SetCoords(x, y, z);
   std::cin >> x >> y >> z;
   p2.SetCoords(x, y, z);

   /* Store coordinates for each satellite. */
   std::cin >> numSats;
   satArr = new Sat[numSats];
   for (unsigned i = 0; i < numSats; ++i) {
      std::cin >> x >> y >> z;
      satArr[i].SetCoords(x, y, z);
   }

   /* Get the closest satellite to each satphone. */
   s1 = ClosestSat(p1, satArr, numSats);
   s2 = ClosestSat(p2, satArr, numSats);

   if(s1.GetX() == s2.GetX() && s1.GetY() == s2.GetY() && s1.GetZ() == s2.GetZ()) {

      totalDistance = p1.DistanceTo(s1) + s1.DistanceTo(p2);

   } else {

      totalDistance = p1.DistanceTo(s1) + s1.DistanceTo(s2) + s2.DistanceTo(p2);
   }

   /* Display the total time taken for the message to be sent. */
   std::cout << std::setprecision(15) << std::showpoint << std::fixed
         << totalDistance/SPEED_OF_LIGHT << "\n";

   return 0;
}

/**
 * @brief Returns the closest satellite to the given satphone (using
 *       custom distance). If multiple satellites are the same
 *       distance away, choose the one that comes first.
 */
Sat ClosestSat (
   const SatPhone& phone,  /**< Phone to find closest satellite to.  */
   const Sat* satArr,      /**< Array of satellites to check.        */
   const unsigned numSats  /**< Number of available satellites.      */
) {

   double curDist, minDist;
   Sat s;

   minDist = DBL_MAX;
   for (unsigned i = 0; i < numSats; ++i) {
      curDist = phone.DistanceTo(satArr[i]);
      if (curDist < minDist) {
         minDist = curDist;
         s = satArr[i];
      }
   }

   return s;
}

