#include <iostream>

using namespace std;

double multiply_by_6(double x){
    return 6*x;
}

double sum(double a, double b){
    return a+b;
}

int main() {
    
    cout << "multiply_by_6(2) = " << multiply_by_6(2) << endl;
    cout << "sum(2,8) = " << sum(2, 8) << endl;

    return 0;

}