#include <iostream>
#include "car.h"

using namespace std;

car::car(string brand, float kms) {
    this->brand = brand;
    this->kms = kms;
}

string car::getbrand() {
    return this->brand;
}

void car::setbrand(string brand) {
    this->brand = brand;
}

float car::getkms() {
    return this->kms;
}

void car::setkms(float kms) {
    this->kms = kms;
} 