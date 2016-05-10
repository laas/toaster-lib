#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <math.h>       /* sqrt */
#include <boost/geometry.hpp>
#include "Entity.h"

#define PI 3.14159265

//for convenience
typedef std::vector<double> Vec_t;
typedef std::vector<Vec_t> Mat_t;
typedef std::map<std::string, double> Map_t;
typedef std::pair<std::string, double> Pair_t;

namespace bg = boost::geometry;

class MathFunctions {

 public:
    static void multiplyMatrices4x4(double* result,double* mat1, double* mat2);
    static bg::model::point<double, 2, bg::cs::cartesian> convert3dTo2d(bg::model::point<double, 3, bg::cs::cartesian> point);
    static double isInAngle(Entity* ent1, Entity* ent2, double angleDir, double angleThreshold, double& angleResult);
    static double relativeAngle(Entity* ent1, Entity* ent2, double angleDir);
    static Vec_t multiplyMatVec(const Mat_t &a, const Vec_t &x);
    static Vec_t diffVec(const Vec_t &a , const Vec_t &b);
    static Mat_t matrixfromAngle(const int &angleType , const double &angle);
    static double magn(const Vec_t &a);
    static double dotProd(const Vec_t &a, const Vec_t &b);
};

#endif
