double func_1(double time, double y_1, double y_2);
double func_2(double time, double y_1, double y_2);

double rungeKuttaForSystemsMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1][3])
{
    double K_1_1, K_2_1, K_3_1, K_4_1, K_1_2, K_2_2, K_3_2, K_4_2, t0, y01, y02, currentTime;

    unsigned int iterator = 1;

    do
    {
        currentTime = timeStart + iterator * step;

        t0 = solution[iterator - 1][0];
        y01 = solution[iterator - 1][1];
        y02 = solution[iterator - 1][2];

        K_1_1 = step * func_1(t0, y01, y02);
        K_1_2 = step * func_2(t0, y01, y02);

        K_2_1 = step * func_1(t0 + step / 2, y01 + K_1_1 / 2, y02 + K_1_2 / 2);
        K_2_2 = step * func_2(t0 + step / 2, y01 + K_1_1 / 2, y02 + K_1_2 / 2);

        K_3_1 = step * func_1(t0 + step / 2, y01 + K_2_1 / 2, y02 + K_2_2 / 2);
        K_3_2 = step * func_2(t0 + step / 2, y01 + K_2_1 / 2, y02 + K_2_2 / 2);

        K_4_1 = step * func_1(t0 + step, y01 + K_3_1, y02 + K_3_2);
        K_4_2 = step * func_2(t0 + step, y01 + K_3_1, y02 + K_3_2);

        solution[iterator][0] = currentTime;
        solution[iterator][1] = y01 + (K_1_1 + 2 * K_2_1 + 2 * K_3_1 + K_4_1) / 6;
        solution[iterator][2] = y02 + (K_1_2 + 2 * K_2_2 + 2 * K_3_2 + K_4_2) / 6;

        iterator++;

    } while (iterator <= numberOfSteps);
}
