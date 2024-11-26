#pragma once
#include <Eigen/Dense>

class OrthogonalDecomposition {
public:
    virtual ~OrthogonalDecomposition() = default;
    
    virtual void decompose(const Eigen::MatrixXd& A) = 0;
    virtual const Eigen::MatrixXd& getQ() const = 0;
    virtual const Eigen::MatrixXd& getR() const = 0;
}; 