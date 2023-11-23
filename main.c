#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zeros.h"
#include "function_1.h"
#include "function_2.h"
#include "increment.h"
#include "dataFormat.h"
#include "printMatrix.h"
#include "RungeKuttaForSystemsMethod.h"

int main()
{
    boundaryConditions problem = {.timeStart = 0,                  // 0.0,
                                  .timeEnd = 0.5,                  // 8.5,
                                  .NumberOfSteps = 5,              // 10
                                  .initialCondition = {0.0, 0.0}}; // 0.5};

    double step = increment(problem.timeStart, problem.timeEnd, problem.NumberOfSteps);

    double result[problem.NumberOfSteps + 1][3];

    zeros(problem.NumberOfSteps + 1, 3, result);

    result[0][0] = problem.timeStart;
    result[0][1] = problem.initialCondition[0];
    result[0][2] = problem.initialCondition[1];

    rungeKuttaForSystemsMethod(problem.NumberOfSteps + 1, problem.timeStart, step, result);

    printMatrix(problem.NumberOfSteps + 1, result);
}