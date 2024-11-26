#include "HouseholderDecomposition.h"

void HouseholderDecomposition::decompose(const Eigen::MatrixXd& A) {
    int m = A.rows();
    int n = A.cols();
    
    R = A;
    Q = Eigen::MatrixXd::Identity(m, m);
    
    for (int k = 0; k < std::min(m-1, n); k++) {
        Eigen::VectorXd x = R.col(k).segment(k, m-k);
        
        Eigen::VectorXd v = computeHouseholderVector(x);
        
        if (v.norm() < 1e-10) continue;
        
        Eigen::MatrixXd H = Eigen::MatrixXd::Identity(m-k, m-k) - 
                           2 * v * v.transpose();
        
        R.block(k, k, m-k, n-k) = H * R.block(k, k, m-k, n-k);
        
        Eigen::MatrixXd H_full = Eigen::MatrixXd::Identity(m, m);
        H_full.block(k, k, m-k, m-k) = H;
        Q = Q * H_full;
    }
}

Eigen::VectorXd HouseholderDecomposition::computeHouseholderVector(const Eigen::VectorXd& x) {
    double norm_x = x.norm();
    if (norm_x < 1e-10) return x;
    
    Eigen::VectorXd v = x;
    v(0) += (x(0) >= 0 ? -1 : 1) * norm_x;
    v.normalize();
    
    return v;
}