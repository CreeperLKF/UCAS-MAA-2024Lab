#include "MGSDecomposition.h"

void MGSDecomposition::decompose(const Eigen::MatrixXd& A) {
    int m = A.rows();
    int n = A.cols();
    
    Q = A;
    R = Eigen::MatrixXd::Zero(n, n);
    
    for (int k = 0; k < n; k++) {
        double r_kk = Q.col(k).norm();
        R(k, k) = r_kk;
        
        if (r_kk > 1e-10) {
            Q.col(k) /= r_kk;
        }
        
        for (int j = k + 1; j < n; j++) {
            R(k, j) = Q.col(k).dot(Q.col(j));
            Q.col(j) -= R(k, j) * Q.col(k);
        }
    }
} 