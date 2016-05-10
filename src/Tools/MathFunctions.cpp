#include "Tools/MathFunctions.h"

// TODO: do this with boost!
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

Vec_t MathFunctions::multiplyMatVec(const Mat_t &a, const Vec_t &x)
{
  int i,j;
  int m = a.size();
  int n = x.size();

  Vec_t prod(m);

  for(i = 0; i < m; i++){
    prod[i] = 0.;
    for(j = 0; j < n; j++)
      prod[i] += a[i][j]*x[j];
  }
  return prod;
}

Vec_t MathFunctions::diffVec(const Vec_t &a , const Vec_t &b)
{
    int i;
    int m = a.size();
    int n = b.size();
    if (m == n)
    {
        Vec_t diff(m);
        for (int i = 0; i < m; ++i)
        {
            diff[i]=a[i]-b[i];
        }
        return diff;
    } else {

    }
        return (Vec_t)0;
}

Mat_t MathFunctions::matrixfromAngle(const int &angleType , const double &angle)
{
    Mat_t mat(3);
    Vec_t row0;
    Vec_t row1;
    Vec_t row2;

    if (angleType==0)
    {
        row0.push_back(1.0);
        row0.push_back(0.0);
        row0.push_back(0.0);
        
        row1.push_back(0.0);
        row1.push_back(cos(angle));
        row1.push_back(-sin(angle));
        
        row2.push_back(0.0);
        row2.push_back(sin(angle));
        row2.push_back(cos(angle));
        
    }else{
        if (angleType==1)
        {
            row0.push_back(cos(angle));
            row0.push_back(0.0);
            row0.push_back(sin(angle));
            
            row1.push_back(0.0);
            row1.push_back(1.0);
            row1.push_back(0.0);
            
            row2.push_back(-sin(angle));
            row2.push_back(0.0);
            row2.push_back(cos(angle));
        }else{
            row0.push_back(cos(angle));
            row0.push_back(-sin(angle));
            row0.push_back(0.0);
            
            row1.push_back(sin(angle));
            row1.push_back(cos(angle));
            row1.push_back(0.0);
            
            row2.push_back(0.0);
            row2.push_back(0.0);
            row2.push_back(1.0);
        }
    }
    mat[0]=row0;
    mat[1]=row1;
    mat[2]=row2;
    return mat;
}

double MathFunctions::magn(const Vec_t &a)
{
    int n=a.size();
    double magn=0;
    for (int i = 0; i < n; ++i)
    {
        magn+=a[i]*a[i];
    }
    return sqrt(magn);
}

double MathFunctions::dotProd(const Vec_t &a, const Vec_t &b)
{
    int n=a.size();
    int m=b.size();
    double dotProd=0;
    if (n==m)
    {
        for (int i = 0; i < m; ++i)
        {
            dotProd+=a[i]*b[i];
        }
    }
    return dotProd;
}