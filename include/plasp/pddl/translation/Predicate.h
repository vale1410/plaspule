#ifndef __PLASP__PDDL__TRANSLATION__PREDICATE_H
#define __PLASP__PDDL__TRANSLATION__PREDICATE_H

#include <colorlog/Formatting.h>

#include <pddl/NormalizedAST.h>
#include <pddl/Parse.h>

#include <plasp/pddl/translation/Primitives.h>
#include <plasp/pddl/translation/Variables.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Predicate
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void translatePredicate(colorlog::ColorStream &outputStream, const ::pddl::normalizedAST::Predicate &predicate, VariableIDMap &variableIDs);
void translatePredicateDeclaration(colorlog::ColorStream &outputStream, const ::pddl::normalizedAST::PredicateDeclaration &predicateDeclaration, VariableIDMap &variableIDs);

////////////////////////////////////////////////////////////////////////////////////////////////////

inline void translatePredicate(colorlog::ColorStream &outputStream, const ::pddl::normalizedAST::Predicate &predicate, VariableIDMap &variableIDs)
{
	const auto &arguments = predicate.arguments;

	if (arguments.empty())
	{
		outputStream << predicate.declaration->name;
		return;
	}

    outputStream << predicate.declaration->name;
    outputStream << "(";

	for (const auto &argument : arguments)
	{

		const auto handleConstant =
			[&](const ::pddl::normalizedAST::ConstantPointer &constant)
			{
				outputStream << constant->declaration->name;
			};

		const auto handleVariable =
			[&](const ::pddl::normalizedAST::VariablePointer &variable)
			{
				translateVariable(outputStream, *variable, variableIDs);
			};

		argument.match(handleConstant, handleVariable);
		if (&argument != &arguments.back()) {
            outputStream << ",";
		}
	}

	outputStream << ")";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

inline void translatePredicateDeclaration(colorlog::ColorStream &outputStream, const ::pddl::normalizedAST::PredicateDeclaration &predicateDeclaration, VariableIDMap &variableIDs)
{
	outputStream << "#ground predicate[";

	if (predicateDeclaration.parameters.empty())
	{
		outputStream << predicateDeclaration.name << "].";
		return;
	}

	outputStream << predicateDeclaration.name << "(";
	translateVariablesForRuleHead(outputStream, predicateDeclaration.parameters, variableIDs);
	outputStream << ")]." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void translatePredicateToVariable(colorlog::ColorStream &outputStream, const ::pddl::normalizedAST::Predicate &predicate, VariableIDMap &variableIDs,bool isPositive = true)
{


	translatePredicate(outputStream, predicate, variableIDs);

	if (isPositive) outputStream << "";


}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
