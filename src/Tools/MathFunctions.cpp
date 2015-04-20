#include "Tools/MathFunctions.h"

void MathFunctions::multiplyMatrices4x4(double* result, double* mat1, double* mat2) {

    result[0] = mat1[0] * mat2[0] + mat1[1]*(mat2 + 4)[0] + mat1[2]*(mat2 + 8)[0] + mat1[3]*(mat2 + 12)[0];
    result[1] = mat1[0] * mat2[1] + mat1[1]*(mat2 + 4)[1] + mat1[2]*(mat2 + 8)[1] + mat1[3]*(mat2 + 12)[1];
    result[2] = mat1[0] * mat2[2] + mat1[1]*(mat2 + 4)[2] + mat1[2]*(mat2 + 8)[2] + mat1[3]*(mat2 + 12)[2];
    result[3] = mat1[0] * mat2[3] + mat1[1]*(mat2 + 4)[3] + mat1[2]*(mat2 + 8)[3] + mat1[3]*(mat2 + 12)[3];

    (result + 4)[0] = (mat1 + 4)[0] * mat2[0] + (mat1 + 4)[1]*(mat2 + 4)[0] + (mat1 + 4)[2]*(mat2 + 8)[0] + (mat1 + 4)[3]*(mat2 + 12)[0];
    (result + 4)[1] = (mat1 + 4)[0] * mat2[1] + (mat1 + 4)[1]*(mat2 + 4)[1] + (mat1 + 4)[2]*(mat2 + 8)[1] + (mat1 + 4)[3]*(mat2 + 12)[1];
    (result + 4)[2] = (mat1 + 4)[0] * mat2[2] + (mat1 + 4)[1]*(mat2 + 4)[2] + (mat1 + 4)[2]*(mat2 + 8)[2] + (mat1 + 4)[3]*(mat2 + 12)[2];
    (result + 4)[3] = (mat1 + 4)[0] * mat2[3] + (mat1 + 4)[1]*(mat2 + 4)[3] + (mat1 + 4)[2]*(mat2 + 8)[3] + (mat1 + 4)[3]*(mat2 + 12)[3];

    (result + 8)[0] = (mat1 + 8)[0] * mat2[0] + (mat1 + 8)[1]*(mat2 + 4)[0] + (mat1 + 8)[2]*(mat2 + 8)[0] + (mat1 + 8)[3]*(mat2 + 12)[0];
    (result + 8)[1] = (mat1 + 8)[0] * mat2[1] + (mat1 + 8)[1]*(mat2 + 4)[1] + (mat1 + 8)[2]*(mat2 + 8)[1] + (mat1 + 8)[3]*(mat2 + 12)[1];
    (result + 8)[2] = (mat1 + 8)[0] * mat2[2] + (mat1 + 8)[1]*(mat2 + 4)[2] + (mat1 + 8)[2]*(mat2 + 8)[2] + (mat1 + 8)[3]*(mat2 + 12)[2];
    (result + 8)[3] = (mat1 + 8)[0] * mat2[3] + (mat1 + 8)[1]*(mat2 + 4)[3] + (mat1 + 8)[2]*(mat2 + 8)[3] + (mat1 + 8)[3]*(mat2 + 12)[3];

    (result + 12)[0] = (mat1 + 12)[0] * mat2[0] + (mat1 + 12)[1]*(mat2 + 4)[0] + (mat1 + 12)[2]*(mat2 + 8)[0] + (mat1 + 12)[3]*(mat2 + 12)[0];
    (result + 12)[1] = (mat1 + 12)[0] * mat2[1] + (mat1 + 12)[1]*(mat2 + 4)[1] + (mat1 + 12)[2]*(mat2 + 8)[1] + (mat1 + 12)[3]*(mat2 + 12)[1];
    (result + 12)[2] = (mat1 + 12)[0] * mat2[2] + (mat1 + 12)[1]*(mat2 + 4)[2] + (mat1 + 12)[2]*(mat2 + 8)[2] + (mat1 + 12)[3]*(mat2 + 12)[2];
    (result + 12)[3] = (mat1 + 12)[0] * mat2[3] + (mat1 + 12)[1]*(mat2 + 4)[3] + (mat1 + 12)[2]*(mat2 + 8)[3] + (mat1 + 12)[3]*(mat2 + 12)[3];


}

bg::model::point <double, 2, bg::cs::cartesian> MathFunctions::convert3dTo2d(bg::model::point<double, 3, bg::cs::cartesian> point) {
    bg::model::point <double, 2, bg::cs::cartesian> point2d;
    point2d.set<0>(point.get<0>());
    point2d.set<1>(point.get<1>());

    return point2d;
}

// Return true if ent2 is in the angle from ent1 with direction angleDir and size angleThreshold

double MathFunctions::isInAngle(Entity* ent1, Entity* ent2, double angleDir, double angleThreshold, double& angleResult) {
    angleResult = relativeAngle(ent1, ent2, angleDir);

    if (fabs(angleResult) > angleThreshold) {
        return 0.0;
    } else {
        return (angleThreshold - fabs(angleResult)) / angleThreshold;
    }
}

// Return angle between ent2 and ent1 and angleDir direction

double MathFunctions::relativeAngle(Entity* ent1, Entity* ent2, double angleDir) {
    double actualAngleDir = acos((fabs(ent1->getPosition().get<0>() - ent2->getPosition().get<0>()))
            / bg::distance(MathFunctions::convert3dTo2d(ent1->getPosition()), MathFunctions::convert3dTo2d(ent2->getPosition())));

    // Trigonometric adjustment
    if (ent2->getPosition().get<0>() < ent1->getPosition().get<0>())
        actualAngleDir = 3.1416 - actualAngleDir;

    if (ent2->getPosition().get<1>() < ent1->getPosition().get<1>())
        actualAngleDir = -actualAngleDir;

    return angleDir - actualAngleDir;
}