#include <iostream>
#include <array>
#include <vector>
#include "stdio.h"
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <math.h>
#include <numeric>
#include <functional>

template<std::size_t SIZE>
std::array<double, SIZE> ForEach(const std::array<double, SIZE>& values, double modifier, double(*func)(double, double))
{
    std::array<double, SIZE> modifiedArray;
    for (int i = 0; i < modifiedArray.size(); i++)
        modifiedArray[i] = func(values[i], modifier);

    return modifiedArray;
}

int main()
{
    const std::array<double, 4>yData = {1.0, 2.0, 1.5, 2.0};
    
    // do maths to array elements with function pointer
    std::array<double, 4> sumArray = ForEach(yData, 1.0, [](double a, double b) ->double {return a + b;});
    for(int i = 0; i < 4; ++i)
    {
        printf("%f, ", sumArray[i]);
    }

    // sum array elements with std::accumulate
    double sumPoints = std::accumulate(yData.begin() + 1, yData.end(), 0.0);
    printf("\n%f\n", sumPoints);

    // sum array elements with for loop
    double sum_of_elems;
    for(int i = 0; i < 3; ++i)
    {
        sum_of_elems += yData[i];
    }
    printf("%f\n", sum_of_elems);

    double halfWidth = round(2.5);
    printf("%f\n", halfWidth);

    for(auto val : yData)
    {
         printf("%f, ", val);
    }

    std::cin.get();
    return 0;
}