#include "./statements.hpp"

namespace syntax_tree::statements
{
    StatementContainer::StatementContainer(VariantStatement contained)
    : _contained(contained)
    {
    }

    const StatementContainer::VariantStatement & StatementContainer::contained() const
    {
        return _contained;
    }
}
