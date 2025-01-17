#ifndef GSLANGUAGE_GS_UNARYNODE_H
#define GSLANGUAGE_GS_UNARYNODE_H

#include <map>

#include <Parser/Nodes/GS_Node.h>

#include <Parser/Nodes/GS_IntegerValue.h>

#include <Exceptions/GS_Exception.h>

namespace GSLanguageCompiler::Parser {

    /**
     *
     */
    enum class UnaryOperation {
        MINUS
    };

    /**
     *
     */
    extern std::map<UnaryOperation, GSString> unaryOperationToString;

    /**
     *
     */
    class GS_UnaryNode : public GS_Node {
    public:

        /**
         *
         * @param operation
         * @param node
         */
        GS_UnaryNode(UnaryOperation operation, GSNodePtr node);

    public:

        /**
         *
         * @return
         */
        UnaryOperation getUnaryOperation();

        /**
         *
         * @return
         */
        GSNodePtr getNode();

    public:

        /**
         *
         * @return
         */
        NodeType getNodeType() override;


        /**
         *
         * @param builder
         * @return
         */
        GSVoid codegen(CodeGenerator::GS_BCBuilder &builder) override;

        /**
         *
         * @return
         */
        GSValuePtr interpret() override;

        /**
         *
         * @return
         */
        GSString toString() override;

    private:

        /**
         *
         */
        UnaryOperation _operation;

        /**
         *
         */
        GSNodePtr _node;
    };

}

#endif //GSLANGUAGE_GS_UNARYNODE_H
