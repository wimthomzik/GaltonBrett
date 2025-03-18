#ifndef PATTERNFACTORY_H
#define PATTERNFACTORY_H

#include "vec2.h"
#include "constants.h"
#include "patterngenerator.h"
#include <memory>

using Vec2 = wtm::Vec2T<double>;
using GeneratorUPtr = std::unique_ptr<PatternGenerator>;

class PatternFactory
{
public:
    static PatternFactory& Instance()
    {
        static PatternFactory factory;
        return factory;
    }

    void registerPattern(GeneratorUPtr generator);

    QVector<Vec2> build(const QString &name, const double distance) const;

    QStringList names() const;

private:
    PatternFactory() = default;
    ~PatternFactory() = default;

    std::map<QString, GeneratorUPtr> m_generators;
};

#endif // PATTERNFACTORY_H

