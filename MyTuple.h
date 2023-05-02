
#include <iostream>
#include <string>
#include <cmath>

# pragma once
class MyTuple {
private:
    float x, y, z;
    int w;
    static constexpr float EPSILON = 0.00001f;
public:
    MyTuple() : x(0.0f), y(0.0f), z(0.0f), w(w == 0 ? 0 : 1) {}

    MyTuple(float x, float y, float z, int w) {
        this->x = x;
        this->y = y;
        this->z = z;
        if (w <= 0 ) { // needs to be either point or vector
            this->w = 0;
        }
        else {
            this->w = 1;
        }
    }

    // for performing basic algebraic calculations with vectors
    // 1st param: vector 2nd param: vector
    friend MyTuple operator -(const MyTuple& t1, const MyTuple& t2);
    friend MyTuple operator +(const MyTuple& t1, const MyTuple& t2);
    // 1st param: vector 2nd param: scalar
    friend MyTuple operator *(const MyTuple& t, const float& num);
    friend MyTuple operator /(const MyTuple& t, const float& num);
    
    friend std::ostream& operator<<(std::ostream& os, const MyTuple& t);

    bool equal(MyTuple t2);

    float magnitude() {
        return std::sqrt(x*x + y*y + z*z);
    }

    
    // calculating the normalization of a vector, does not give you the normal vector!
    // this is for making a unit vector and perserving its direction
    MyTuple normalize() {
        return MyTuple(this->x/this->magnitude(), this->y / this->magnitude(),
            this->z / this->magnitude(), this->w);
    }

    float dot(MyTuple t2) {
        float dotResult = this->x * t2.getX() + this->y * t2.getY() + this->z * t2.getZ();
        return dotResult;
    }

    MyTuple crossProduct(MyTuple t2) {
        return MyTuple( this->y*t2.getZ() - this->z*t2.getY(), 
            this->z*t2.getX() - this->x*t2.getZ(),
            this->x*t2.getY() - this->y*t2.getX(), this->w);
    }




    float getX() const {
        return x;
    }
    float getY() const {
        return y;
    }
    float getZ() const {
        return z;
    }
    int getW() const {
        return w;
    }

    void setX(float x) {
        this->x = x;
    }
    void setY(float y) {
        this->y = y;
    }
    void setZ(float z) {
        this->z = z;
    }
    void setW(int w) {
        this->w = w;
    }

    void negateTuple() {
        this->setX(this->getX() * -1);
        this->setY(this->getY() * -1);
        this->setZ(this->getZ() * -1);
        this->setW(this->getW() * -1);
    }

    std::string tupleType() {
        if (this->getW() == 0) {
            return "vector";
        }
        else {
            return "point";
        }
    }


};
