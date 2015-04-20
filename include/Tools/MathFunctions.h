#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <math.h>       /* sqrt */
#include <boost/geometry.hpp>
#include "Entity.h"

namespace bg = boost::geometry;

class MathFunctions {

 public:
    static void multiplyMatrices4x4(double* result,double* mat1, double* mat2);
    static bg::model::point<double, 2, bg::cs::cartesian> convert3dTo2d(bg::model::point<double, 3, bg::cs::cartesian> point);
    static double isInAngle(Entity* ent1, Entity* ent2, double angleDir, double angleThreshold, double& angleResult);
    static double relativeAngle(Entity* ent1, Entity* ent2, double angleDir);
};

#endif
