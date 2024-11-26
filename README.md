# The labwork of Matrix Analysis and Applications (2024) with Eigen (C++)

## QR Decomposition with Eigen

Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms, which is pretty elegant.

We implement QR decomposition with Eigen in three algorithms:

1. Modified Gram-Schmidt
2. Householder Reduction
3. Givens Reduction

The code is self-explanatory (if you understand C++ and has revisit the slides of this course). Anyway, either Eigen or cuBLAS contains high-efficiency QR decompostion algorithms and what I'm doing is building a wheel for this labwork.

## Build

Use `make` (You have to install Eigen first).

A `main` functions is required (you may use your own test and write backsubstitution yourself).

## Run 

Code is only tested under Ubuntu 24.04.

Use `make run` for running testcases.
