float zeros(int rows, int cols, double matrix[rows][cols])
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0.0;
        }
    }
}