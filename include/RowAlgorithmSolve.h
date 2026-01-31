#pragma once


#include "Strategy.h"


class RowAlgorithmSolve : public Strategy {
public:
    std::unique_ptr<Solution> solve(const ProblemInstance& problem) override;
};

