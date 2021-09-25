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
    return (c << v.x << " " << v.y);
}


int main() {

    return 0;
}
