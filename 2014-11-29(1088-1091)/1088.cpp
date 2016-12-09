#include <iostream>
using namespace std;

long long a, b, c, d;

void input(){
    cin >> a;
    getchar();
    cin >> b >> c;
    getchar();
    cin >> d;
}

long long  gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a%b);
}

void printr(long long a, long long b){
    if (b == 0){
        cout << "Inf";
        return;
    }
    if (a == 0){
        cout << 0;
        return;
    }
    if (b < 0){
        a = -a;
        b = -b;
    }
    if (a < 0) cout << "(";
    if (a / b != 0) {
        cout << a / b;
        if (a%b != 0){
            long long g = gcd(a, b);
            cout << " " << abs((a%b) / g) <<"/"<< abs(b / g);
        }
    }
    else{
        long long g = gcd(a, b);
        if (a > 0) cout << abs((a%b) / g) <<"/"<< abs(b / g);
        else cout << -1 * abs((a%b) / g) <<"/"<< abs(b / g);
    }
    if (a < 0) cout << ")";
}

void printadd(long long a, long long b, long long c, long long d){
    long long n, m;
    n = a*d + b*c;
    m = b*d;
    printr(n, m);
    cout << endl;
}

void printpro(long long a, long long b, long long c, long long d){
    long long n, m;
    n = a*c;
    m = b*d;
    printr(n, m);
    cout << endl;
}

int main(){
    input();
    printr(a, b);
    cout << " + ";
    printr(c, d);
    cout << " = ";
    printadd(a, b, c, d);
    printr(a, b);
    cout << " - ";
    printr(c, d);
    cout << " = ";
    printadd(a, b, -c, d);
    printr(a, b);
    cout << " * ";
    printr(c, d);
    cout << " = ";
    printpro(a, b, c, d);
    printr(a, b);
    cout << " / ";
    printr(c, d);
    cout << " = ";
    printpro(a, b, d, c);
    return 0;
}