#ifndef __PLASP__PDDL__TYPE_H
#define __PLASP__PDDL__TYPE_H

#include <unordered_map>

#include <boost/variant.hpp>

#include <plasp/pddl/TypePrimitive.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Type
//
////////////////////////////////////////////////////////////////////////////////////////////////////

using Type = boost::variant<TypePrimitive>;
using TypeHashMap = std::unordered_map<std::string, Type>;

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
