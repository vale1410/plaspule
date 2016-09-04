#include <plasp/pddl/expressions/Type.h>

#include <plasp/pddl/Context.h>
#include <plasp/pddl/ExpressionContext.h>
#include <plasp/pddl/expressions/PrimitiveType.h>

namespace plasp
{
namespace pddl
{
namespace expressions
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Type
//
////////////////////////////////////////////////////////////////////////////////////////////////////

ExpressionPointer parseExistingPrimitiveType(Context &context, ExpressionContext &expressionContext)
{
	return PrimitiveType::parseAndFind(context, expressionContext.domain);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
