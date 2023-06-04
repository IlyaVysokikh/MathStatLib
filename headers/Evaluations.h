/**
 * @file
 * @brief Содержит определения различных классов оценки, используемых для вычисления статистических показателей.
 */

#pragma once

#include <string>
#include <vector>

/**
 * @class Evaluation
 * @brief Базовый класс для всех классов оценки.
 * 
 * Этот класс определяет общий интерфейс для всех классов оценки, используемых для вычисления статистических показателей.
 */
class Evaluation
{
public:
    /**
     * @brief Вычисляет статистический показатель.
     * @return Вычисленное значение статистического показателя.
     */
    virtual float calculate() = 0;
protected:
    std::vector<float> sample; /**< Выборка данных, используемая для оценки. */
};

/**
 * @class Mean
 * @brief Представляет оценку среднего значения.
 * 
 * Этот класс вычисляет среднее значение заданной выборки данных.
 */
class Mean: public Evaluation
{
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    Mean(std::string path);

    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    Mean(std::vector<float> s);

    /**
     * @brief Вычисляет среднее значение.
     * @return Вычисленное среднее значение.
     */
    float calculate() override;
};

/**
 * @class SampleVariance
 * @brief Представляет оценку выборочной дисперсии.
 * 
 * Этот класс вычисляет выборочную дисперсию заданной выборки данных.
 */
class SampleVariance: public Evaluation
{
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    SampleVariance(std::string path);

    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    SampleVariance(std::vector<float> s);

    /**
     * @brief Вычисляет выборочную дисперсию.
     * @return Вычисленное значение выборочной дисперсии.
     */
    float calculate() override;
};

/**
 * @class GiniDifference
 * @brief Представляет оценку разности Джини.
 * 
 * Этот класс вычисляет разность Джини заданной выборки данных.
 */
class GiniDifference: public Evaluation
{
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    GiniDifference(std::string path);

    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    GiniDifference(std::vector<float> s);

    /**
     * @brief Вычисляет разность Джини.
     * @return Вычисленное значение разности Джини.
     */
    float calculate() override;
};

/**
 * @class CentralMoment
 * @brief Представляет оценку среднего значения.
 * 
 * Этот класс вычисляет центральный момент заданной выборки данных.
 */
class CentralMoment: public Evaluation
{
private:
    int k;
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    CentralMoment(std::string path, int k);
    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    CentralMoment(std::vector<float> s, int k);
    /**
     * @brief Вычисляет центральный момент
     * @return Вычисленное значение центрального момента.
     */
    float calculate() override;
};


/**
 * @class Quantile
 * @brief Представляет оценку среднего значения.
 * 
 * Этот класс вычисляет центральный момент заданной выборки данных.
 */

class Quantile: public Evaluation
{
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    Quantile(std::string path, float alpha);
    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    Quantile(std::vector<float> s, float alpha);
    /**
     * @brief Вычисляет выборочный квантиль
     * @return Вычисленное значение выборочного квантиля.
     */
    float calculate() override;
private:
    float alpha;
};

/**
 * @class AssymetryFactor
 * @brief Представляет оценку коэффициента ассиметрии.
 * 
 * Этот класс вычисляет коэффициент ассиметрии заданной выборки данных.
 */
class AssymetryFactor: public Evaluation
{
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    AssymetryFactor(std::string path);
    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    AssymetryFactor(std::vector<float> s);
    /**
     * @brief Вычисляет коэффициент ассиметрии
     * @return Вычисленное значение коэффициента ассиметрии.
     */
    float calculate() override;
};

/**
 * @class KurtorisFactor
 * @brief Представляет оценку коэффициента эксцесса.
 * 
 * Этот класс вычисляет коэффициент эксцесса заданной выборки данных.
 */
class KurtorisFactor: public Evaluation
{
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    KurtorisFactor(std::string path);
    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    KurtorisFactor(std::vector<float> s);
    /**
     * @brief Вычисляет коэффициент эксцесса
     * @return Вычисленное значение коэффициента эксцесса.
     */
    float calculate() override;
};

/**
 * @class HodgesLehmann
 * @brief Представляет оценку Ходжса-Лемана.
 * 
 * Этот класс вычисляет оценку по методу Ходжса-Лемана заданной выборки данных.
 */
class HodgesLehmann: public Evaluation
{
public:
    /**
     * @brief Конструктор с параметром пути к файлу.
     * @param path Путь к файлу, содержащему выборку данных.
     */
    HodgesLehmann(std::string path);
    /**
     * @brief Конструктор с параметром выборки данных.
     * @param s Выборка данных.
     */
    HodgesLehmann(std::vector<float> s);
    /**
     *   @brief Вычисляет оценку по методу Ходжса-Лемана.
     *   @return Значение оценки.
     */
    float calculate() override;
};