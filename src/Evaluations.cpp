#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Evaluations.h"

Evaluation::Evaluation() {}

Mean::Mean(std::string path)
{
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

Mean::Mean(std::vector<float> s)
{
    this->sample = s;
}

float Mean::calculate()
{
    float sum = 0;
    for(float value: this->sample)
    {
        sum+=value;
    }
    return sum / this->sample.size();
}

SampleVariance::SampleVariance(std::string path)
{
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

SampleVariance::SampleVariance(std::vector<float> s)
{
    this->sample = s;
}

float SampleVariance::calculate()
{
    float meanValue = Mean(this->sample).calculate();
    float variance = 0;
    for(float value: this->sample)
    {
        variance += pow(value - meanValue, 2);
    }
    return variance / (this->sample.size() - 1);
}

GiniDifference::GiniDifference(std::string path)
{
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

GiniDifference::GiniDifference(std::vector<float> s)
{
    this->sample = s;
}

float GiniDifference::calculate()
{
    float n = 0;
    for(int i=0; i < this->sample.size()-1; i++)
    {
        for(int j=i+1; j < this->sample.size(); j++)
        {
            n += abs(this->sample[i] + this->sample[j]);
        }
    }
    return (2 * n) / (this->sample.size() * (this->sample.size() - 1));
}

CentralMoment::CentralMoment(std::string path, int k)
{
    this->k = k;
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

CentralMoment::CentralMoment(std::vector<float> s, int k)
{
    this->sample = s;
    this->k = k;
}

float CentralMoment::calculate()
{
    float meanValue = Mean(this->sample).calculate();
    float centralMoment = 0;
    for (float value: this->sample)
    {
        centralMoment += pow(value - meanValue, k);
    }
    return centralMoment / this->sample.size();
}

Quantile::Quantile(std::string path, float alpha)
{
    this->alpha = alpha;
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

Quantile::Quantile(std::vector<float> s, float alpha)
{
    this->alpha = alpha;
    this->sample = s;
}

float Quantile::calculate()
{
    std::sort(this->sample.begin(), this->sample.end());
    return this->sample[static_cast<int>(this->alpha * this->sample.size())];
}

HodgesLehmann::HodgesLehmann(std::string path)
{
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

HodgesLehmann::HodgesLehmann(std::vector<float> s)
{
    this->sample = s;
}

float HodgesLehmann::calculate()
{   
    std::vector<float> meansWalsh;
    for(int i=0; i < this->sample.size()-1; i++)
    {
        for(int j=i+1; j < this->sample.size(); j++)
        {
            meansWalsh.push_back((this->sample[i] + this->sample[j]) / 2);
        }
    }
    std::sort(meansWalsh.begin(), meansWalsh.end());
    if(meansWalsh.size() % 2 == 0)
    {
        return (meansWalsh[meansWalsh.size() / 2 - 1] + meansWalsh[meansWalsh.size() / 2]) / 2;
    }
    return meansWalsh[meansWalsh.size() / 2];
}

AssymetryFactor::AssymetryFactor(std::string path)
{
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

AssymetryFactor::AssymetryFactor(std::vector<float> s)
{
    this->sample = s;
}

    float AssymetryFactor::calculate()
{
    float centralMoment = CentralMoment(this->sample, 3).calculate();
    float sampleVariance = SampleVariance(this->sample).calculate();
    return centralMoment / pow(sampleVariance, 3/2);
}

KurtorisFactor::KurtorisFactor(std::string path)
{
    std::ifstream file(path);
    float value;
    while (file >> value) {
        this->sample.push_back(value);
    }
    file.close();
}

KurtorisFactor::KurtorisFactor(std::vector<float> s)
{
    this->sample = s;
}

float KurtorisFactor::calculate()
{
    float centralMoment = CentralMoment(this->sample, 4).calculate();
    float sampleVariance = SampleVariance(this->sample).calculate();
    return (centralMoment / pow(sampleVariance, 2)) - 3;
}