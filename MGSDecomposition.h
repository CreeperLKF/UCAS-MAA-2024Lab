#pragma once
#include "OrthogonalDecomposition.h"

class MGSDecomposition : public OrthogonalDecomposition {
public:
    MGSDecomposition() = default;
    ~MGSDecomposition() override = default;
    
    void decompose(const Eigen::MatrixXd& A) override;
    const Eigen::MatrixXd& getQ() const override { return Q; }
    const Eigen::MatrixXd& getR() const override { return R; }

private:
    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
}; 