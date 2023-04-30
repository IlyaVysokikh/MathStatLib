#pragma onse
#include <string>
#include <vector>

class Evaluation
{
public:
    virtual float calculate() = 0;
protected:
    std::vector<float> sample;
};

class Mean: public Evaluation
{
public:
    Mean(std::string path);
    Mean(std::vector<float> s);
    float calculate() override;
};

class SampleVariance: public Evaluation
{
public:
    SampleVariance(std::string path);
    SampleVariance(std::vector<float> s);
    float calculate() override;
};

class GiniDifference: public Evaluation
{
public:
    GiniDifference(std::string path);
    GiniDifference(std::vector<float> s);
    float calculate() override;
};

class CentralMoment: public Evaluation
{
private:
    int k;
public:
    CentralMoment(std::string path);
    CentralMoment(std::vector<float> s);
    float calculate() override;
};

class Quantile: public Evaluation
{
public:
    Quantile(std::string path);
    Quantile(std::vector<float> s);
    float calculate() override;
};

class Quantile: public Evaluation
{
public:
    Quantile(std::string path);
    Quantile(std::vector<float> s);
    float calculate() override;
};

class AssymetryFactor: public Evaluation
{
public:
    AssymetryFactor(std::string path);
    AssymetryFactor(std::vector<float> s);
    float calculate() override;
};

class KurtorisFactor: public Evaluation
{
public:
    KurtorisFactor(std::string path);
    KurtorisFactor(std::vector<float> s);
    float calculate() override;
};

class HodgesLehmann: public Evaluation
{
public:
    HodgesLehmann(std::string path);
    HodgesLehmann(std::vector<float> s);
    float calculate() override;
};