
#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

class NoNegative : public exception {
public:
    NoNegative(long long int n) : val(n) {};
    const char* what() const throw() {
        return "Cannot be negative";
    }
private:
    long long int val;
};

class Sin {
    public:
        double operator()(double r) {
            return sin(r);
        }
};
class Tan {
public:
    double operator()(double r) {
        return tan(r);
    }
};

class Cos {
public:
    double operator()(double r) {
        return cos(r);
    }
};

class Fib {
    public:
        Fib() {
            for (int i = 0; i < MAX_FIB; i++) {
                memo[i] = NOT_CALCED;
            }
        }

        long long int operator()(long long int n) {
            //cout << n << endl;
            if (n < 0) throw NoNegative(n);
            
            if (memo[n] != NOT_CALCED) return n;
            if (n <= 1) {
                memo[0] = 1;
                memo[1] = 1;
                return 1;
            }
            else {
                memo[n] = operator()(n-1) + operator()(n-2);
                return memo[n];
            }
        }

        const int MAX_FIB = 100;
        const int NOT_CALCED = -1;
    private:
            long long int* memo = new long long int[MAX_FIB];
};


double cube_func(double d, function<double(double)> f) {
    return f(d) * f(d) * f(d);
}

double square_func(double d, function<double(double)> f) {
    return f(d) * f(d);
}


int main() {
    const long long int FIB_NUM = -46;

    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    
    Fib fib = Fib();
    try {
    long long int f = fib(FIB_NUM);
    cout << "fib(" << FIB_NUM << ") == " << f << endl;
    }
    catch (NoNegative& e) {
        cout << e.what() << endl;
    }

    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg); });
    cout << "Square of sin 0 = " << d << endl;
    d = square_func(1, [](double arg) { return sin(arg); });
    cout << "Square of sin 1 = " << d << endl;
    d = square_func(1, [](double arg) { return cos(arg); });
    cout << "Square of cos 1 = " << d << endl;
    d = square_func(0, [](double arg) { return tan(arg); });
    cout << "Square of tan 0 = " << d << endl;
    d = cube_func(1,[](double arg) { return tan(arg); });

}
