#include "closest_rotation.h"
#include <Eigen/SVD>
#include <Eigen/Dense>
void closest_rotation(
  const Eigen::Matrix3d & M,
  Eigen::Matrix3d & R)
{
  Eigen::JacobiSVD<Eigen::Matrix3d> svd(M, Eigen::ComputeThinV | Eigen::ComputeThinU);
  Eigen::Matrix3d U = svd.matrixU();
  Eigen::Matrix3d V = svd.matrixV();

  Eigen::Matrix3d omega;
  omega << 1, 0, 0,
           0, 1, 0,
           0, 0, (U*V.transpose()).determinant();

  R = U * omega * V.transpose();
}
