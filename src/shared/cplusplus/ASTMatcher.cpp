/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#include "AST.h"
#include "ASTMatcher.h"
#include "TranslationUnit.h"

using namespace CPlusPlus;

ASTMatcher::ASTMatcher()
{ }

ASTMatcher::~ASTMatcher()
{ }

bool ASTMatcher::match(SimpleSpecifierAST *node, SimpleSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->specifier_token = node->specifier_token;

    return true;
}

bool ASTMatcher::match(AttributeSpecifierAST *node, AttributeSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->attribute_token = node->attribute_token;

    pattern->first_lparen_token = node->first_lparen_token;

    pattern->second_lparen_token = node->second_lparen_token;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    pattern->first_rparen_token = node->first_rparen_token;

    pattern->second_rparen_token = node->second_rparen_token;

    return true;
}

bool ASTMatcher::match(AttributeAST *node, AttributeAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->identifier_token = node->identifier_token;

    pattern->lparen_token = node->lparen_token;

    pattern->tag_token = node->tag_token;

    if (! pattern->expression_list)
        pattern->expression_list = node->expression_list;
    else if (! AST::match(node->expression_list, pattern->expression_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(TypeofSpecifierAST *node, TypeofSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->typeof_token = node->typeof_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(DeclaratorAST *node, DeclaratorAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    if (! pattern->ptr_operator_list)
        pattern->ptr_operator_list = node->ptr_operator_list;
    else if (! AST::match(node->ptr_operator_list, pattern->ptr_operator_list, this))
        return false;

    if (! pattern->core_declarator)
        pattern->core_declarator = node->core_declarator;
    else if (! AST::match(node->core_declarator, pattern->core_declarator, this))
        return false;

    if (! pattern->postfix_declarator_list)
        pattern->postfix_declarator_list = node->postfix_declarator_list;
    else if (! AST::match(node->postfix_declarator_list, pattern->postfix_declarator_list, this))
        return false;

    if (! pattern->post_attribute_list)
        pattern->post_attribute_list = node->post_attribute_list;
    else if (! AST::match(node->post_attribute_list, pattern->post_attribute_list, this))
        return false;

    pattern->equals_token = node->equals_token;

    if (! pattern->initializer)
        pattern->initializer = node->initializer;
    else if (! AST::match(node->initializer, pattern->initializer, this))
        return false;

    return true;
}

bool ASTMatcher::match(SimpleDeclarationAST *node, SimpleDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->qt_invokable_token = node->qt_invokable_token;

    if (! pattern->decl_specifier_list)
        pattern->decl_specifier_list = node->decl_specifier_list;
    else if (! AST::match(node->decl_specifier_list, pattern->decl_specifier_list, this))
        return false;

    if (! pattern->declarator_list)
        pattern->declarator_list = node->declarator_list;
    else if (! AST::match(node->declarator_list, pattern->declarator_list, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(EmptyDeclarationAST *node, EmptyDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(AccessDeclarationAST *node, AccessDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->access_specifier_token = node->access_specifier_token;

    pattern->slots_token = node->slots_token;

    pattern->colon_token = node->colon_token;

#ifdef ICHECK_BUILD
    pattern->invoke_token = node->invoke_token;
#endif

    return true;
}

#ifdef ICHECK_BUILD
bool ASTMatcher::match(QPropertyDeclarationAST *node, QPropertyDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->property_specifier_token = node->property_specifier_token;

    pattern->type_name_token = node->type_name_token;

    pattern->read_function_token = node->read_function_token;

    pattern->write_function_token = node->write_function_token;

    pattern->notify_function_token = node->notify_function_token;

    return true;
}

bool ASTMatcher::match(QEnumDeclarationAST *node, QEnumDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->enum_specifier_token = node->enum_specifier_token;

    if (! pattern->enumerator_list)
        pattern->enumerator_list = node->enumerator_list;
    else if (! AST::match(node->enumerator_list, pattern->enumerator_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(QFlagsDeclarationAST *node, QFlagsDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->flags_specifier_token = node->flags_specifier_token;

    if (! pattern->enumerator_list)
        pattern->enumerator_list = node->enumerator_list;
    else if (! AST::match(node->enumerator_list, pattern->enumerator_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(QDeclareFlagsDeclarationAST *node, QDeclareFlagsDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->declareflags_specifier_token = node->declareflags_specifier_token;
    pattern->flag_token = node->flag_token;
    pattern->enum_token = node->enum_token;

    return true;
}
#endif

bool ASTMatcher::match(AsmDefinitionAST *node, AsmDefinitionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->asm_token = node->asm_token;

    pattern->volatile_token = node->volatile_token;

    pattern->lparen_token = node->lparen_token;

    pattern->rparen_token = node->rparen_token;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(BaseSpecifierAST *node, BaseSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->virtual_token = node->virtual_token;

    pattern->access_specifier_token = node->access_specifier_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    return true;
}

bool ASTMatcher::match(CompoundLiteralAST *node, CompoundLiteralAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->initializer)
        pattern->initializer = node->initializer;
    else if (! AST::match(node->initializer, pattern->initializer, this))
        return false;

    return true;
}

bool ASTMatcher::match(QtMethodAST *node, QtMethodAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->method_token = node->method_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(QtMemberDeclarationAST *node, QtMemberDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->q_token = node->q_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(BinaryExpressionAST *node, BinaryExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->left_expression)
        pattern->left_expression = node->left_expression;
    else if (! AST::match(node->left_expression, pattern->left_expression, this))
        return false;

    pattern->binary_op_token = node->binary_op_token;

    if (! pattern->right_expression)
        pattern->right_expression = node->right_expression;
    else if (! AST::match(node->right_expression, pattern->right_expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(CastExpressionAST *node, CastExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(ClassSpecifierAST *node, ClassSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->classkey_token = node->classkey_token;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->colon_token = node->colon_token;

    if (! pattern->base_clause_list)
        pattern->base_clause_list = node->base_clause_list;
    else if (! AST::match(node->base_clause_list, pattern->base_clause_list, this))
        return false;

    pattern->lbrace_token = node->lbrace_token;

    if (! pattern->member_specifier_list)
        pattern->member_specifier_list = node->member_specifier_list;
    else if (! AST::match(node->member_specifier_list, pattern->member_specifier_list, this))
        return false;

    pattern->rbrace_token = node->rbrace_token;

    return true;
}

bool ASTMatcher::match(CaseStatementAST *node, CaseStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->case_token = node->case_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->colon_token = node->colon_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(CompoundStatementAST *node, CompoundStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbrace_token = node->lbrace_token;

    if (! pattern->statement_list)
        pattern->statement_list = node->statement_list;
    else if (! AST::match(node->statement_list, pattern->statement_list, this))
        return false;

    pattern->rbrace_token = node->rbrace_token;

    return true;
}

bool ASTMatcher::match(ConditionAST *node, ConditionAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    return true;
}

bool ASTMatcher::match(ConditionalExpressionAST *node, ConditionalExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->condition)
        pattern->condition = node->condition;
    else if (! AST::match(node->condition, pattern->condition, this))
        return false;

    pattern->question_token = node->question_token;

    if (! pattern->left_expression)
        pattern->left_expression = node->left_expression;
    else if (! AST::match(node->left_expression, pattern->left_expression, this))
        return false;

    pattern->colon_token = node->colon_token;

    if (! pattern->right_expression)
        pattern->right_expression = node->right_expression;
    else if (! AST::match(node->right_expression, pattern->right_expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(CppCastExpressionAST *node, CppCastExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->cast_token = node->cast_token;

    pattern->less_token = node->less_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    pattern->greater_token = node->greater_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(CtorInitializerAST *node, CtorInitializerAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->colon_token = node->colon_token;

    if (! pattern->member_initializer_list)
        pattern->member_initializer_list = node->member_initializer_list;
    else if (! AST::match(node->member_initializer_list, pattern->member_initializer_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(DeclarationStatementAST *node, DeclarationStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->declaration)
        pattern->declaration = node->declaration;
    else if (! AST::match(node->declaration, pattern->declaration, this))
        return false;

    return true;
}

bool ASTMatcher::match(DeclaratorIdAST *node, DeclaratorIdAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    return true;
}

bool ASTMatcher::match(NestedDeclaratorAST *node, NestedDeclaratorAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(FunctionDeclaratorAST *node, FunctionDeclaratorAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->parameters)
        pattern->parameters = node->parameters;
    else if (! AST::match(node->parameters, pattern->parameters, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->cv_qualifier_list)
        pattern->cv_qualifier_list = node->cv_qualifier_list;
    else if (! AST::match(node->cv_qualifier_list, pattern->cv_qualifier_list, this))
        return false;

    if (! pattern->exception_specification)
        pattern->exception_specification = node->exception_specification;
    else if (! AST::match(node->exception_specification, pattern->exception_specification, this))
        return false;

    if (! pattern->as_cpp_initializer)
        pattern->as_cpp_initializer = node->as_cpp_initializer;
    else if (! AST::match(node->as_cpp_initializer, pattern->as_cpp_initializer, this))
        return false;

    return true;
}

bool ASTMatcher::match(ArrayDeclaratorAST *node, ArrayDeclaratorAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbracket_token = node->lbracket_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rbracket_token = node->rbracket_token;

    return true;
}

bool ASTMatcher::match(DeleteExpressionAST *node, DeleteExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->scope_token = node->scope_token;

    pattern->delete_token = node->delete_token;

    pattern->lbracket_token = node->lbracket_token;

    pattern->rbracket_token = node->rbracket_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(DoStatementAST *node, DoStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->do_token = node->do_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    pattern->while_token = node->while_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(NamedTypeSpecifierAST *node, NamedTypeSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    return true;
}

bool ASTMatcher::match(ElaboratedTypeSpecifierAST *node, ElaboratedTypeSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->classkey_token = node->classkey_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    return true;
}

bool ASTMatcher::match(EnumSpecifierAST *node, EnumSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->enum_token = node->enum_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->lbrace_token = node->lbrace_token;

    if (! pattern->enumerator_list)
        pattern->enumerator_list = node->enumerator_list;
    else if (! AST::match(node->enumerator_list, pattern->enumerator_list, this))
        return false;

    pattern->rbrace_token = node->rbrace_token;

    return true;
}

bool ASTMatcher::match(EnumeratorAST *node, EnumeratorAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->identifier_token = node->identifier_token;

    pattern->equal_token = node->equal_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(ExceptionDeclarationAST *node, ExceptionDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    pattern->dot_dot_dot_token = node->dot_dot_dot_token;

    return true;
}

bool ASTMatcher::match(ExceptionSpecificationAST *node, ExceptionSpecificationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->throw_token = node->throw_token;

    pattern->lparen_token = node->lparen_token;

    pattern->dot_dot_dot_token = node->dot_dot_dot_token;

    if (! pattern->type_id_list)
        pattern->type_id_list = node->type_id_list;
    else if (! AST::match(node->type_id_list, pattern->type_id_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(ExpressionOrDeclarationStatementAST *node, ExpressionOrDeclarationStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    if (! pattern->declaration)
        pattern->declaration = node->declaration;
    else if (! AST::match(node->declaration, pattern->declaration, this))
        return false;

    return true;
}

bool ASTMatcher::match(ExpressionStatementAST *node, ExpressionStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(FunctionDefinitionAST *node, FunctionDefinitionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->qt_invokable_token = node->qt_invokable_token;

    if (! pattern->decl_specifier_list)
        pattern->decl_specifier_list = node->decl_specifier_list;
    else if (! AST::match(node->decl_specifier_list, pattern->decl_specifier_list, this))
        return false;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    if (! pattern->ctor_initializer)
        pattern->ctor_initializer = node->ctor_initializer;
    else if (! AST::match(node->ctor_initializer, pattern->ctor_initializer, this))
        return false;

    if (! pattern->function_body)
        pattern->function_body = node->function_body;
    else if (! AST::match(node->function_body, pattern->function_body, this))
        return false;

    return true;
}

bool ASTMatcher::match(ForeachStatementAST *node, ForeachStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->foreach_token = node->foreach_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    if (! pattern->initializer)
        pattern->initializer = node->initializer;
    else if (! AST::match(node->initializer, pattern->initializer, this))
        return false;

    pattern->comma_token = node->comma_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(ForStatementAST *node, ForStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->for_token = node->for_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->initializer)
        pattern->initializer = node->initializer;
    else if (! AST::match(node->initializer, pattern->initializer, this))
        return false;

    if (! pattern->condition)
        pattern->condition = node->condition;
    else if (! AST::match(node->condition, pattern->condition, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(IfStatementAST *node, IfStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->if_token = node->if_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->condition)
        pattern->condition = node->condition;
    else if (! AST::match(node->condition, pattern->condition, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    pattern->else_token = node->else_token;

    if (! pattern->else_statement)
        pattern->else_statement = node->else_statement;
    else if (! AST::match(node->else_statement, pattern->else_statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(ArrayInitializerAST *node, ArrayInitializerAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbrace_token = node->lbrace_token;

    if (! pattern->expression_list)
        pattern->expression_list = node->expression_list;
    else if (! AST::match(node->expression_list, pattern->expression_list, this))
        return false;

    pattern->rbrace_token = node->rbrace_token;

    return true;
}

bool ASTMatcher::match(LabeledStatementAST *node, LabeledStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->label_token = node->label_token;

    pattern->colon_token = node->colon_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(LinkageBodyAST *node, LinkageBodyAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbrace_token = node->lbrace_token;

    if (! pattern->declaration_list)
        pattern->declaration_list = node->declaration_list;
    else if (! AST::match(node->declaration_list, pattern->declaration_list, this))
        return false;

    pattern->rbrace_token = node->rbrace_token;

    return true;
}

bool ASTMatcher::match(LinkageSpecificationAST *node, LinkageSpecificationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->extern_token = node->extern_token;

    pattern->extern_type_token = node->extern_type_token;

    if (! pattern->declaration)
        pattern->declaration = node->declaration;
    else if (! AST::match(node->declaration, pattern->declaration, this))
        return false;

    return true;
}

bool ASTMatcher::match(MemInitializerAST *node, MemInitializerAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression_list)
        pattern->expression_list = node->expression_list;
    else if (! AST::match(node->expression_list, pattern->expression_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(NestedNameSpecifierAST *node, NestedNameSpecifierAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->class_or_namespace_name)
        pattern->class_or_namespace_name = node->class_or_namespace_name;
    else if (! AST::match(node->class_or_namespace_name, pattern->class_or_namespace_name, this))
        return false;

    pattern->scope_token = node->scope_token;

    return true;
}

bool ASTMatcher::match(QualifiedNameAST *node, QualifiedNameAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->global_scope_token = node->global_scope_token;

    if (! pattern->nested_name_specifier_list)
        pattern->nested_name_specifier_list = node->nested_name_specifier_list;
    else if (! AST::match(node->nested_name_specifier_list, pattern->nested_name_specifier_list, this))
        return false;

    if (! pattern->unqualified_name)
        pattern->unqualified_name = node->unqualified_name;
    else if (! AST::match(node->unqualified_name, pattern->unqualified_name, this))
        return false;

    return true;
}

bool ASTMatcher::match(OperatorFunctionIdAST *node, OperatorFunctionIdAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->operator_token = node->operator_token;

    if (! pattern->op)
        pattern->op = node->op;
    else if (! AST::match(node->op, pattern->op, this))
        return false;

    return true;
}

bool ASTMatcher::match(ConversionFunctionIdAST *node, ConversionFunctionIdAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->operator_token = node->operator_token;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->ptr_operator_list)
        pattern->ptr_operator_list = node->ptr_operator_list;
    else if (! AST::match(node->ptr_operator_list, pattern->ptr_operator_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(SimpleNameAST *node, SimpleNameAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->identifier_token = node->identifier_token;

    return true;
}

bool ASTMatcher::match(DestructorNameAST *node, DestructorNameAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->tilde_token = node->tilde_token;

    pattern->identifier_token = node->identifier_token;

    return true;
}

bool ASTMatcher::match(TemplateIdAST *node, TemplateIdAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->identifier_token = node->identifier_token;

    pattern->less_token = node->less_token;

    if (! pattern->template_argument_list)
        pattern->template_argument_list = node->template_argument_list;
    else if (! AST::match(node->template_argument_list, pattern->template_argument_list, this))
        return false;

    pattern->greater_token = node->greater_token;

    return true;
}

bool ASTMatcher::match(NamespaceAST *node, NamespaceAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->namespace_token = node->namespace_token;

    pattern->identifier_token = node->identifier_token;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    if (! pattern->linkage_body)
        pattern->linkage_body = node->linkage_body;
    else if (! AST::match(node->linkage_body, pattern->linkage_body, this))
        return false;

    return true;
}

bool ASTMatcher::match(NamespaceAliasDefinitionAST *node, NamespaceAliasDefinitionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->namespace_token = node->namespace_token;

    pattern->namespace_name_token = node->namespace_name_token;

    pattern->equal_token = node->equal_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(NewPlacementAST *node, NewPlacementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression_list)
        pattern->expression_list = node->expression_list;
    else if (! AST::match(node->expression_list, pattern->expression_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(NewArrayDeclaratorAST *node, NewArrayDeclaratorAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbracket_token = node->lbracket_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rbracket_token = node->rbracket_token;

    return true;
}

bool ASTMatcher::match(NewExpressionAST *node, NewExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->scope_token = node->scope_token;

    pattern->new_token = node->new_token;

    if (! pattern->new_placement)
        pattern->new_placement = node->new_placement;
    else if (! AST::match(node->new_placement, pattern->new_placement, this))
        return false;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->new_type_id)
        pattern->new_type_id = node->new_type_id;
    else if (! AST::match(node->new_type_id, pattern->new_type_id, this))
        return false;

    if (! pattern->new_initializer)
        pattern->new_initializer = node->new_initializer;
    else if (! AST::match(node->new_initializer, pattern->new_initializer, this))
        return false;

    return true;
}

bool ASTMatcher::match(NewInitializerAST *node, NewInitializerAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(NewTypeIdAST *node, NewTypeIdAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->ptr_operator_list)
        pattern->ptr_operator_list = node->ptr_operator_list;
    else if (! AST::match(node->ptr_operator_list, pattern->ptr_operator_list, this))
        return false;

    if (! pattern->new_array_declarator_list)
        pattern->new_array_declarator_list = node->new_array_declarator_list;
    else if (! AST::match(node->new_array_declarator_list, pattern->new_array_declarator_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(OperatorAST *node, OperatorAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->op_token = node->op_token;

    pattern->open_token = node->open_token;

    pattern->close_token = node->close_token;

    return true;
}

bool ASTMatcher::match(ParameterDeclarationAST *node, ParameterDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    pattern->equal_token = node->equal_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(ParameterDeclarationClauseAST *node, ParameterDeclarationClauseAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->parameter_declaration_list)
        pattern->parameter_declaration_list = node->parameter_declaration_list;
    else if (! AST::match(node->parameter_declaration_list, pattern->parameter_declaration_list, this))
        return false;

    pattern->dot_dot_dot_token = node->dot_dot_dot_token;

    return true;
}

bool ASTMatcher::match(CallAST *node, CallAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression_list)
        pattern->expression_list = node->expression_list;
    else if (! AST::match(node->expression_list, pattern->expression_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(ArrayAccessAST *node, ArrayAccessAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbracket_token = node->lbracket_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rbracket_token = node->rbracket_token;

    return true;
}

bool ASTMatcher::match(PostIncrDecrAST *node, PostIncrDecrAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->incr_decr_token = node->incr_decr_token;

    return true;
}

bool ASTMatcher::match(MemberAccessAST *node, MemberAccessAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->access_token = node->access_token;

    pattern->template_token = node->template_token;

    if (! pattern->member_name)
        pattern->member_name = node->member_name;
    else if (! AST::match(node->member_name, pattern->member_name, this))
        return false;

    return true;
}

bool ASTMatcher::match(TypeidExpressionAST *node, TypeidExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->typeid_token = node->typeid_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(TypenameCallExpressionAST *node, TypenameCallExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->typename_token = node->typename_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression_list)
        pattern->expression_list = node->expression_list;
    else if (! AST::match(node->expression_list, pattern->expression_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(TypeConstructorCallAST *node, TypeConstructorCallAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression_list)
        pattern->expression_list = node->expression_list;
    else if (! AST::match(node->expression_list, pattern->expression_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(PostfixExpressionAST *node, PostfixExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->base_expression)
        pattern->base_expression = node->base_expression;
    else if (! AST::match(node->base_expression, pattern->base_expression, this))
        return false;

    if (! pattern->postfix_expression_list)
        pattern->postfix_expression_list = node->postfix_expression_list;
    else if (! AST::match(node->postfix_expression_list, pattern->postfix_expression_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(PointerToMemberAST *node, PointerToMemberAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->global_scope_token = node->global_scope_token;

    if (! pattern->nested_name_specifier_list)
        pattern->nested_name_specifier_list = node->nested_name_specifier_list;
    else if (! AST::match(node->nested_name_specifier_list, pattern->nested_name_specifier_list, this))
        return false;

    pattern->star_token = node->star_token;

    if (! pattern->cv_qualifier_list)
        pattern->cv_qualifier_list = node->cv_qualifier_list;
    else if (! AST::match(node->cv_qualifier_list, pattern->cv_qualifier_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(PointerAST *node, PointerAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->star_token = node->star_token;

    if (! pattern->cv_qualifier_list)
        pattern->cv_qualifier_list = node->cv_qualifier_list;
    else if (! AST::match(node->cv_qualifier_list, pattern->cv_qualifier_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(ReferenceAST *node, ReferenceAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->amp_token = node->amp_token;

    return true;
}

bool ASTMatcher::match(BreakStatementAST *node, BreakStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->break_token = node->break_token;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(ContinueStatementAST *node, ContinueStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->continue_token = node->continue_token;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(GotoStatementAST *node, GotoStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->goto_token = node->goto_token;

    pattern->identifier_token = node->identifier_token;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(ReturnStatementAST *node, ReturnStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->return_token = node->return_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(SizeofExpressionAST *node, SizeofExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->sizeof_token = node->sizeof_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(NumericLiteralAST *node, NumericLiteralAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->literal_token = node->literal_token;

    return true;
}

bool ASTMatcher::match(BoolLiteralAST *node, BoolLiteralAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->literal_token = node->literal_token;

    return true;
}

bool ASTMatcher::match(ThisExpressionAST *node, ThisExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->this_token = node->this_token;

    return true;
}

bool ASTMatcher::match(NestedExpressionAST *node, NestedExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(StringLiteralAST *node, StringLiteralAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->literal_token = node->literal_token;

    if (! pattern->next)
        pattern->next = node->next;
    else if (! AST::match(node->next, pattern->next, this))
        return false;

    return true;
}

bool ASTMatcher::match(SwitchStatementAST *node, SwitchStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->switch_token = node->switch_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->condition)
        pattern->condition = node->condition;
    else if (! AST::match(node->condition, pattern->condition, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(TemplateDeclarationAST *node, TemplateDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->export_token = node->export_token;

    pattern->template_token = node->template_token;

    pattern->less_token = node->less_token;

    if (! pattern->template_parameter_list)
        pattern->template_parameter_list = node->template_parameter_list;
    else if (! AST::match(node->template_parameter_list, pattern->template_parameter_list, this))
        return false;

    pattern->greater_token = node->greater_token;

    if (! pattern->declaration)
        pattern->declaration = node->declaration;
    else if (! AST::match(node->declaration, pattern->declaration, this))
        return false;

    return true;
}

bool ASTMatcher::match(ThrowExpressionAST *node, ThrowExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->throw_token = node->throw_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(TranslationUnitAST *node, TranslationUnitAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->declaration_list)
        pattern->declaration_list = node->declaration_list;
    else if (! AST::match(node->declaration_list, pattern->declaration_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(TryBlockStatementAST *node, TryBlockStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->try_token = node->try_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    if (! pattern->catch_clause_list)
        pattern->catch_clause_list = node->catch_clause_list;
    else if (! AST::match(node->catch_clause_list, pattern->catch_clause_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(CatchClauseAST *node, CatchClauseAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->catch_token = node->catch_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->exception_declaration)
        pattern->exception_declaration = node->exception_declaration;
    else if (! AST::match(node->exception_declaration, pattern->exception_declaration, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(TypeIdAST *node, TypeIdAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    return true;
}

bool ASTMatcher::match(TypenameTypeParameterAST *node, TypenameTypeParameterAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->classkey_token = node->classkey_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->equal_token = node->equal_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    return true;
}

bool ASTMatcher::match(TemplateTypeParameterAST *node, TemplateTypeParameterAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->template_token = node->template_token;

    pattern->less_token = node->less_token;

    if (! pattern->template_parameter_list)
        pattern->template_parameter_list = node->template_parameter_list;
    else if (! AST::match(node->template_parameter_list, pattern->template_parameter_list, this))
        return false;

    pattern->greater_token = node->greater_token;

    pattern->class_token = node->class_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->equal_token = node->equal_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    return true;
}

bool ASTMatcher::match(UnaryExpressionAST *node, UnaryExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->unary_op_token = node->unary_op_token;

    if (! pattern->expression)
        pattern->expression = node->expression;
    else if (! AST::match(node->expression, pattern->expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(UsingAST *node, UsingAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->using_token = node->using_token;

    pattern->typename_token = node->typename_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(UsingDirectiveAST *node, UsingDirectiveAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->using_token = node->using_token;

    pattern->namespace_token = node->namespace_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(WhileStatementAST *node, WhileStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->while_token = node->while_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->condition)
        pattern->condition = node->condition;
    else if (! AST::match(node->condition, pattern->condition, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCClassForwardDeclarationAST *node, ObjCClassForwardDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    pattern->class_token = node->class_token;

    if (! pattern->identifier_list)
        pattern->identifier_list = node->identifier_list;
    else if (! AST::match(node->identifier_list, pattern->identifier_list, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(ObjCClassDeclarationAST *node, ObjCClassDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    pattern->interface_token = node->interface_token;

    pattern->implementation_token = node->implementation_token;

    if (! pattern->class_name)
        pattern->class_name = node->class_name;
    else if (! AST::match(node->class_name, pattern->class_name, this))
        return false;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->category_name)
        pattern->category_name = node->category_name;
    else if (! AST::match(node->category_name, pattern->category_name, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    pattern->colon_token = node->colon_token;

    if (! pattern->superclass)
        pattern->superclass = node->superclass;
    else if (! AST::match(node->superclass, pattern->superclass, this))
        return false;

    if (! pattern->protocol_refs)
        pattern->protocol_refs = node->protocol_refs;
    else if (! AST::match(node->protocol_refs, pattern->protocol_refs, this))
        return false;

    if (! pattern->inst_vars_decl)
        pattern->inst_vars_decl = node->inst_vars_decl;
    else if (! AST::match(node->inst_vars_decl, pattern->inst_vars_decl, this))
        return false;

    if (! pattern->member_declaration_list)
        pattern->member_declaration_list = node->member_declaration_list;
    else if (! AST::match(node->member_declaration_list, pattern->member_declaration_list, this))
        return false;

    pattern->end_token = node->end_token;

    return true;
}

bool ASTMatcher::match(ObjCProtocolForwardDeclarationAST *node, ObjCProtocolForwardDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    pattern->protocol_token = node->protocol_token;

    if (! pattern->identifier_list)
        pattern->identifier_list = node->identifier_list;
    else if (! AST::match(node->identifier_list, pattern->identifier_list, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(ObjCProtocolDeclarationAST *node, ObjCProtocolDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    pattern->protocol_token = node->protocol_token;

    if (! pattern->name)
        pattern->name = node->name;
    else if (! AST::match(node->name, pattern->name, this))
        return false;

    if (! pattern->protocol_refs)
        pattern->protocol_refs = node->protocol_refs;
    else if (! AST::match(node->protocol_refs, pattern->protocol_refs, this))
        return false;

    if (! pattern->member_declaration_list)
        pattern->member_declaration_list = node->member_declaration_list;
    else if (! AST::match(node->member_declaration_list, pattern->member_declaration_list, this))
        return false;

    pattern->end_token = node->end_token;

    return true;
}

bool ASTMatcher::match(ObjCProtocolRefsAST *node, ObjCProtocolRefsAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->less_token = node->less_token;

    if (! pattern->identifier_list)
        pattern->identifier_list = node->identifier_list;
    else if (! AST::match(node->identifier_list, pattern->identifier_list, this))
        return false;

    pattern->greater_token = node->greater_token;

    return true;
}

bool ASTMatcher::match(ObjCMessageArgumentAST *node, ObjCMessageArgumentAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->parameter_value_expression)
        pattern->parameter_value_expression = node->parameter_value_expression;
    else if (! AST::match(node->parameter_value_expression, pattern->parameter_value_expression, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCMessageExpressionAST *node, ObjCMessageExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbracket_token = node->lbracket_token;

    if (! pattern->receiver_expression)
        pattern->receiver_expression = node->receiver_expression;
    else if (! AST::match(node->receiver_expression, pattern->receiver_expression, this))
        return false;

    if (! pattern->selector)
        pattern->selector = node->selector;
    else if (! AST::match(node->selector, pattern->selector, this))
        return false;

    if (! pattern->argument_list)
        pattern->argument_list = node->argument_list;
    else if (! AST::match(node->argument_list, pattern->argument_list, this))
        return false;

    pattern->rbracket_token = node->rbracket_token;

    return true;
}

bool ASTMatcher::match(ObjCProtocolExpressionAST *node, ObjCProtocolExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->protocol_token = node->protocol_token;

    pattern->lparen_token = node->lparen_token;

    pattern->identifier_token = node->identifier_token;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(ObjCTypeNameAST *node, ObjCTypeNameAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->type_id)
        pattern->type_id = node->type_id;
    else if (! AST::match(node->type_id, pattern->type_id, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(ObjCEncodeExpressionAST *node, ObjCEncodeExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->encode_token = node->encode_token;

    if (! pattern->type_name)
        pattern->type_name = node->type_name;
    else if (! AST::match(node->type_name, pattern->type_name, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCSelectorWithoutArgumentsAST *node, ObjCSelectorWithoutArgumentsAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->name_token = node->name_token;

    return true;
}

bool ASTMatcher::match(ObjCSelectorArgumentAST *node, ObjCSelectorArgumentAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->name_token = node->name_token;

    pattern->colon_token = node->colon_token;

    return true;
}

bool ASTMatcher::match(ObjCSelectorWithArgumentsAST *node, ObjCSelectorWithArgumentsAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->selector_argument_list)
        pattern->selector_argument_list = node->selector_argument_list;
    else if (! AST::match(node->selector_argument_list, pattern->selector_argument_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCSelectorExpressionAST *node, ObjCSelectorExpressionAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->selector_token = node->selector_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->selector)
        pattern->selector = node->selector;
    else if (! AST::match(node->selector, pattern->selector, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    return true;
}

bool ASTMatcher::match(ObjCInstanceVariablesDeclarationAST *node, ObjCInstanceVariablesDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->lbrace_token = node->lbrace_token;

    if (! pattern->instance_variable_list)
        pattern->instance_variable_list = node->instance_variable_list;
    else if (! AST::match(node->instance_variable_list, pattern->instance_variable_list, this))
        return false;

    pattern->rbrace_token = node->rbrace_token;

    return true;
}

bool ASTMatcher::match(ObjCVisibilityDeclarationAST *node, ObjCVisibilityDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->visibility_token = node->visibility_token;

    return true;
}

bool ASTMatcher::match(ObjCPropertyAttributeAST *node, ObjCPropertyAttributeAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->attribute_identifier_token = node->attribute_identifier_token;

    pattern->equals_token = node->equals_token;

    if (! pattern->method_selector)
        pattern->method_selector = node->method_selector;
    else if (! AST::match(node->method_selector, pattern->method_selector, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCPropertyDeclarationAST *node, ObjCPropertyDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    pattern->property_token = node->property_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->property_attribute_list)
        pattern->property_attribute_list = node->property_attribute_list;
    else if (! AST::match(node->property_attribute_list, pattern->property_attribute_list, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->simple_declaration)
        pattern->simple_declaration = node->simple_declaration;
    else if (! AST::match(node->simple_declaration, pattern->simple_declaration, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCMessageArgumentDeclarationAST *node, ObjCMessageArgumentDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->type_name)
        pattern->type_name = node->type_name;
    else if (! AST::match(node->type_name, pattern->type_name, this))
        return false;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    pattern->param_name_token = node->param_name_token;

    return true;
}

bool ASTMatcher::match(ObjCMethodPrototypeAST *node, ObjCMethodPrototypeAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->method_type_token = node->method_type_token;

    if (! pattern->type_name)
        pattern->type_name = node->type_name;
    else if (! AST::match(node->type_name, pattern->type_name, this))
        return false;

    if (! pattern->selector)
        pattern->selector = node->selector;
    else if (! AST::match(node->selector, pattern->selector, this))
        return false;

    if (! pattern->argument_list)
        pattern->argument_list = node->argument_list;
    else if (! AST::match(node->argument_list, pattern->argument_list, this))
        return false;

    pattern->dot_dot_dot_token = node->dot_dot_dot_token;

    if (! pattern->attribute_list)
        pattern->attribute_list = node->attribute_list;
    else if (! AST::match(node->attribute_list, pattern->attribute_list, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCMethodDeclarationAST *node, ObjCMethodDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    if (! pattern->method_prototype)
        pattern->method_prototype = node->method_prototype;
    else if (! AST::match(node->method_prototype, pattern->method_prototype, this))
        return false;

    if (! pattern->function_body)
        pattern->function_body = node->function_body;
    else if (! AST::match(node->function_body, pattern->function_body, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(ObjCSynthesizedPropertyAST *node, ObjCSynthesizedPropertyAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->equals_token = node->equals_token;

    return true;
}

bool ASTMatcher::match(ObjCSynthesizedPropertiesDeclarationAST *node, ObjCSynthesizedPropertiesDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->synthesized_token = node->synthesized_token;

    if (! pattern->property_identifier_list)
        pattern->property_identifier_list = node->property_identifier_list;
    else if (! AST::match(node->property_identifier_list, pattern->property_identifier_list, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(ObjCDynamicPropertiesDeclarationAST *node, ObjCDynamicPropertiesDeclarationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->dynamic_token = node->dynamic_token;

    if (! pattern->property_identifier_list)
        pattern->property_identifier_list = node->property_identifier_list;
    else if (! AST::match(node->property_identifier_list, pattern->property_identifier_list, this))
        return false;

    pattern->semicolon_token = node->semicolon_token;

    return true;
}

bool ASTMatcher::match(ObjCFastEnumerationAST *node, ObjCFastEnumerationAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->for_token = node->for_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->type_specifier_list)
        pattern->type_specifier_list = node->type_specifier_list;
    else if (! AST::match(node->type_specifier_list, pattern->type_specifier_list, this))
        return false;

    if (! pattern->declarator)
        pattern->declarator = node->declarator;
    else if (! AST::match(node->declarator, pattern->declarator, this))
        return false;

    if (! pattern->initializer)
        pattern->initializer = node->initializer;
    else if (! AST::match(node->initializer, pattern->initializer, this))
        return false;

    pattern->in_token = node->in_token;

    if (! pattern->fast_enumeratable_expression)
        pattern->fast_enumeratable_expression = node->fast_enumeratable_expression;
    else if (! AST::match(node->fast_enumeratable_expression, pattern->fast_enumeratable_expression, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

bool ASTMatcher::match(ObjCSynchronizedStatementAST *node, ObjCSynchronizedStatementAST *pattern)
{
    (void) node;
    (void) pattern;

    pattern->synchronized_token = node->synchronized_token;

    pattern->lparen_token = node->lparen_token;

    if (! pattern->synchronized_object)
        pattern->synchronized_object = node->synchronized_object;
    else if (! AST::match(node->synchronized_object, pattern->synchronized_object, this))
        return false;

    pattern->rparen_token = node->rparen_token;

    if (! pattern->statement)
        pattern->statement = node->statement;
    else if (! AST::match(node->statement, pattern->statement, this))
        return false;

    return true;
}

