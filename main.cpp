#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


typedef long long ll;


class Vector{
private:
    ll x, y;

public:

    Vector(ll x, ll y) : x(x), y(y) {}
    Vector() : x(0), y(0) {}

    ll get_x(){
        return x;
    }

    ll get_y(){
        return y;
    }

    void set_x(ll nx){
        x = nx;
    }

    void set_y(ll ny){
        y = ny;
    }

    Vector operator-();
    friend Vector operator+(const Vector&, const Vector&);
    friend Vector operator-(const Vector&, const Vector&);


    friend Vector operator*(const Vector&, ll);
    friend Vector operator/(const Vector&, ll);


    friend Vector operator*(const Vector&, ll);

    friend ll operator*(const Vector&, const Vector&);
    friend ll operator^(const Vector&, const Vector&);

    friend ostream& operator<<(ostream &, const Vector &);

    ll sln();
    double ln();

    double angle_to(const Vector& v);

    friend bool operator==(const Vector&, const Vector&);
    friend bool operator!=(const Vector&, const Vector&);
};


bool operator==(const Vector &v1, const Vector &v2){
    return (v1.x == v2.x) && (v1.y == v2.y);
}

bool operator!=(const Vector &v1, const Vector &v2){
    return (v1.x != v2.x) || (v1.y != v2.y);
}

double Vector::angle_to(const Vector &v) {
    return atan2(((*this) ^ v), ((*this) * v));
}


ll Vector::sln(){
    return x * x + y * y;
}


double Vector::ln(){
    return sqrt(this->sln());
}


Vector Vector::operator-(){
    return Vector(-x, -y);
}


Vector operator+(const Vector &v1, const Vector &v2){
    return Vector(v1.x + v2.x, v1.y + v2.y);
}


Vector operator-(const Vector &v1, const Vector &v2){
    return Vector(v1.x - v2.x, v1.y - v2.y);
}


Vector operator*(const Vector &v, ll a){
    return Vector(v.x * a, v.y * a);
}


ll operator*(const Vector &v1, const Vector &v2){
    return v1.x * v2.x + v1.y * v2.y;
}


ll operator^(const Vector &v1, const Vector &v2){
    return v1.x * v2.y - v1.y * v2.x;
}



ostream& operator<<(ostream &c, const Vector &v){
    return (c << "(" << v.x << " " << v.y << ")");
}


int main() {
    ll x1, y1, x2, y2, a;
    cout << "Type v1 vector coords:";
    cin >> x1 >> y1;
    cout << "Type v2 vector coords:";
    cin >> x2 >> y2;
    cout << "Type number a:";
    cin >> a;
    Vector v1(x1, y1), v2(x2, y2);
    cout << "v1 + v2 = " << v1 + v2 << "\n";
    cout << "v1 - v2 = " << v1 - v2 << "\n";
    cout << "v1 * a = " << v1 * a << "\n";
    cout << "v2 * a = " << v2 * a << "\n";
    cout << "v1 * v2 = " << (v1 * v2) << "\n";
    cout << "v1 ^ v2 = " << (v1 ^ v2) << "\n";
    cout << "v1 == v2 = " << (v1 == v2) << "\n";
    cout << "v1 != v2 = " << (v1 != v2) << "\n";
    cout << "Angle: " << v1.angle_to(v2) << "\n";
    return 0;
}
