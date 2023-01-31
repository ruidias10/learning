#include <iostream>

using namespace std;

class car {
    private:
        string brand;
        float kms;

    public:
        car(string brand, float kms);

        string getbrand();
        void setbrand(string brand);

        float getkms();
        void setkms(float kms);        
};