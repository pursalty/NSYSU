#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    double earth = 6440.0;
    double r, d;
    string degree;
    while (cin >> r >> d >> degree)
    {
        double arc, chord;
        double rad;
        if (degree == "min")
            d /= 60.0;
        if (d > 180) d = abs(360 - d);
        rad = d * M_PI / 180.0;
        arc = 2.0 * (earth + r) * M_PI * d / 360.0;
        chord = (earth + r) * sin(rad / 2.0) * 2.0;
        cout << fixed << setprecision(6) << arc << " " << chord << endl;
    }
    return 0;
}
