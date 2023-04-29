#pragma onse
#include <string>
#include <vector>

class Evaluation
{
public:
    virtual float calculate() = 0;
private:
    std::vector<float> sample;

};