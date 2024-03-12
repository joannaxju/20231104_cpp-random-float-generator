#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double randFloat(double, double);

double mean(double [], int);

double variance(double [], int);

void calculations(double, double, double, double, int, int);

double rand_mv(double, double);

int main()
{
    srand(500);

    double mean;        
    double variance;

    cout << "Enter Mean: \n";
    cin >> mean;
    cout << "Enter Variance: \n";
    cin >> variance;

    double rand = rand_mv(mean, variance);
    cout << rand << endl;
    
    return 0;
}

double rand_mv(double mean, double var)
{
    double a, b;
    b = mean + sqrt(3 * var);
    a = b - sqrt(12 * var);

    cout << a << " " << b << endl; 

    return randFloat(a , b);
}

double randFloat(double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double mean(double sequence[], int size)
{
    double sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += sequence[i];
    }
    return (sum / size);
}

double variance(double sequence[], int size)
{
    double average = mean(sequence, size);
    double sumSquares = 0;
    for(int i = 0; i < size; i++)
    {
        sumSquares += pow((sequence[i] - average),2);
    }
    return sumSquares / (size);
}

void calculations(double lowA, double upA, double lowB, double upB, int size1, int size2)
{
    double list1[size1], list2[size2];
    double calculations[8];

    for(int i = 0; i < size1; i++)
        list1[i] = randFloat(lowA, upA);

    for(int i = 0; i < size2; i++)
        list2[i] = randFloat(lowB, upB);

    calculations[0] = (upA + lowA) / 2;
    calculations[1] = mean(list1, size1);
    calculations[2] = pow(upA - lowA,2) / 12;
    calculations[3] = variance(list1, size1);

    calculations[4] = (upB + lowB) / 2;
    calculations[5] = mean(list2, size2);
    calculations[6] = pow(upB - lowB,2) / 12;
    calculations[7] = variance(list2, size2);

    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        cout << calculations[i];
        count++;
        if(count == 4)
        {
            cout << endl;
            count = 0;
        }
        else
            cout << " ";
    }
    cout << endl;
}