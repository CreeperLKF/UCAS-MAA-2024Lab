#pragma once
#include "OrthogonalDecomposition.h"

class GivensDecomposition : public OrthogonalDecomposition {
public:
    GivensDecomposition() = default;
    ~GivensDecomposition() override = default;
    
    void decompose(const Eigen::MatrixXd& A) override;
    const Eigen::MatrixXd& getQ() const override { return Q; }
    const Eigen::MatrixXd& getR() const override { return R; }

private:
    void computeGivensRotation(double a, double b, double& c, double& s);
    
    void applyGivensRotation(int i, int j, double c, double s, 
                            Eigen::MatrixXd& matrix, bool isQ = false);
    
    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
};