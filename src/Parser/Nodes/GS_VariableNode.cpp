#include <Nodes/GS_VariableNode.h>

namespace GSLanguageCompiler::Parser {

    GS_VariableNode::GS_VariableNode() = default;

    GS_VariableNode::GS_VariableNode(GSString name)
            : _name(std::move(name)) {}

    GS_VariableNode::GS_VariableNode(GSString name, GSString type)
            : _name(std::move(name)), _type(std::move(type)) {}

    GS_VariableNode::GS_VariableNode(GSString name, GSNodePtr node)
            : _name(std::move(name)), _node(std::move(node)) {
        tableOfVariables.addVariable(_name, _node->interpret());
    }

    GS_VariableNode::GS_VariableNode(GSString name, GSString type, GSNodePtr node)
            : _name(std::move(name)), _type(std::move(type)), _node(std::move(node)) {
        tableOfVariables.addVariable(_name, _node->interpret());
    }

    NodeType GS_VariableNode::getNodeType() {
        return NodeType::VARIABLE_NODE;
    }

    GSVoid GS_VariableNode::codegen(CodeGenerator::GS_BCBuilder &builder) {
        builder.createVariable(_name, _node->interpret()->getData<GSInt>());
    }

    GSValuePtr GS_VariableNode::interpret() {
        Interpreter::tableOfSymbols.addVariable(_name, _node->interpret());

        return nullptr;
    }

    GSString GS_VariableNode::toString() {
        return "[ "
               + _name
               + ": "
               + _type
               + " = "
               + _node->toString()
               + " ]";
    }

}
