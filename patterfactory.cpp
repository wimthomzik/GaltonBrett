#include "patterfactory.h"

void PatternFactory::registerPattern(GeneratorUPtr generator)
{
    auto it = m_generators.find(generator->name());

    if (it == m_generators.end())
    {
        m_generators.emplace(generator->name(), std::move(generator));
    }
}

QVector<Vec2> PatternFactory::build(const QString &name, const double distance) const
{
    auto it = m_generators.find(name);

    if (it == m_generators.end())
    {
        return QVector<Vec2>(1);
    }
    return it->second->generate(distance);
}

QStringList PatternFactory::names() const
{
    QStringList patterns;
    for (auto it = m_generators.begin(); it != m_generators.end(); it++)
    {
            patterns.append(it->first);
    }
    return patterns;
}
