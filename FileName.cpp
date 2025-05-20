#include <iostream>
#include <cmath>
using namespace std;

double function_x(double x,double n ,double y)
{
    double f = 0.0;
    f = exp(x * n * y) / (1 + (x * x) + (y * y));
    return f;
}
double simpson_rule(int n, int interval) {
    double h = 1.0 / interval;
    double sum = 0.0;

    for (int i = 0; i <= interval; i++) {
        double x = i * h;
        double sum0 = 0.0;
        for (int j = 0; j <= interval; j++) {
            double y = j * h;
            double div = 1;
            if (j > 0 && j < interval) {
                div = (j % 2 == 0) ? 2 : 4;
            }
            sum0 += div * function_x(x, n, y);
        }
        sum0 *= h / 3;

        double mul = 1;
        if (i > 0 && i < interval)
        {
            mul = (i % 2 == 0) ? 2 : 4;
        }
        sum += mul * sum0;
    }
    return sum * h / 3;
}

int main() {
    const int interval = 1000;
    double total = 0.0;
    cout << "Studant: basil hazem ayyad" << endl;
    cout << "ID  :\t 2200901312\n" << endl;

    cout << "from 1 to 10 method integral will be : " << endl;
    cout << "using 1000 interval for both x and y :" << endl;

    for (int i = 1; i <= 10; i++) {
        double integral = simpson_rule(i, interval);
        total += integral;
        cout << "n = " << i << ": " << integral << endl;
    }
    cout << endl;
    cout << "the final result will be = " << total << endl;
    return 0;
}