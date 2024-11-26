#include "GivensDecomposition.h"
#include <cmath>

void GivensDecomposition::decompose(const Eigen::MatrixXd& A) {
    int m = A.rows();
    int n = A.cols();
    
    R = A;
    Q = Eigen::MatrixXd::Identity(m, m);
    
    for (int j = 0; j < n; j++) {
        for (int i = m-1; i > j; i--) {
            if (std::abs(R(i,j)) < 1e-10) continue;
            
            double c, s;
            computeGivensRotation(R(j,j), R(i,j), c, s);
            
            Eigen::MatrixXd G = Eigen::MatrixXd::Identity(m, m);
            G(j, j) = c;
            G(j, i) = s;
            G(i, j) = -s;
            G(i, i) = c;
            
            R = G.transpose() * R;
            Q = Q * G;
        }
    }
}

void GivensDecomposition::computeGivensRotation(double a, double b, 
                                               double& c, double& s) {
    if (std::abs(b) < 1e-10) {
        c = 1.0;
        s = 0.0;
    } else {
        double r = std::hypot(a, b);
        c = a / r;
        s = -b / r;
    }
}
