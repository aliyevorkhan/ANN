#include <iostream>
#include <math.h>

using namespace std;

int x, y;
double a = 1;
double bias = 1;
double weights[3] = {1, 1, 1};
double outputP;
double error;

double Perceptron(double input1, double input2,
                  double output)
{

    outputP = input1 * weights[0] + input2 * weights[1] + bias * weights[2];
    if (outputP > 0)
    {
        outputP = 1;
    }
    else
    {
        outputP = 0;
    }
    error = output - outputP;
    weights[0] += error * input1 * a;
    weights[1] += error * input2 * a;
    weights[2] += error * bias * a;
}

int main()
{

    for (int i = 0; i < 50; i++)
    {
        Perceptron(1, 1, 1); //True or true
        Perceptron(1, 0, 1); //True or false
        Perceptron(0, 1, 1); //False or true
        Perceptron(0, 0, 0); //False or false return 0;
    }
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    outputP = x * weights[0] + y * weights[1] + bias * weights[2];

    if (outputP > 0)
    {
        outputP = 1;
    }
    else
    {
        outputP = 0;
    }

    cout << x << " or " << y << " is: " << outputP << endl;

    outputP = 1 / (1 + exp(-outputP));
}
