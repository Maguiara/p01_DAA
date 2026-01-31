#pragma once 

#include "ProblemInstance.h"
#include "Solution.h"
#include <memory>

class Strategy {
public:
    virtual ~Strategy() = default;

    virtual std::unique_ptr<Solution> solve(const ProblemInstance& problem) = 0;
};

