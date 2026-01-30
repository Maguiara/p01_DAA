#pragma once 

#include "ProblemInstance.h"
#include "SolutionInstace.h"
#include <memory>

class Strategy {
public:
    virtual ~Strategy() = default;

    virtual std::unique_ptr<SolutionInstance> solve(const ProblemInstance& problem) = 0;
};

