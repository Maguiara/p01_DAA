#pragma once

#include "Strategy.h"

class ColumnsAlgorithmSolve : public Strategy {
public:
    std::unique_ptr<Solution> solve(const ProblemInstance& problem) override;
};