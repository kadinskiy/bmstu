#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b,c;
    double d,f;

    cout << "Введите целые a, b, c\n";
    cin >> a >> b >> c;

    double d1=atan(pow(a,2))+(pow(a,2)+pow(b,2)/4);
    double d2=cbrt(25.6753*c)+pow(cos(a+b),2);
    double d3=(c+fabs(a))/sqrt(25.6753*a);
    d=d1/(d2+d3);

    double f1=1/25.6753+pow(cos(a+b),2);
    double f2=(c+fabs(a))/sqrt(25.6753*a);
    f=f1+f2;

    cout << "d: " << d << "\nf: " << f << endl;
}
