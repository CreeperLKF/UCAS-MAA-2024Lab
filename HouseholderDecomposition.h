#pragma once
#include "OrthogonalDecomposition.h"

class HouseholderDecomposition : public OrthogonalDecomposition {
public:
    HouseholderDecomposition() = default;
    ~HouseholderDecomposition() override = default;
    
    void decompose(const Eigen::MatrixXd& A) override;
    const Eigen::MatrixXd& getQ() const override { return Q; }
    const Eigen::MatrixXd& getR() const override { return R; }

private:
    Eigen::VectorXd computeHouseholderVector(const Eigen::VectorXd& x);
    
    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
};