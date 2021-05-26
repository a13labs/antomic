/*
   Copyright 2020 Alexandre Pires (c.alexandre.pires@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#pragma once
#include "Core/Base.h"
#include "Script/Parser/Lexer.h"
#include "Script/Parser/Ast.h"

namespace Antomic
{
    struct ParserState
    {
        std::stack<uint8_t> IdentationStack;

        ParserState() {}
    };

    class Parser
    {
    public:
        Parser() = default;
        ~Parser() = default;
        mod_t FromFile(const std::string &name);
        mod_t FromExpression(const std::string &name);

    private:
        stmt_t TryStatement();
        stmt_t TryFunctionDef();
        stmt_t TryClassDef();
        stmt_t TryReturn();
        stmt_t TryDelete();
        stmt_t TryAssign();
        stmt_t TryAugAssign();
        stmt_t TryFor();
        stmt_t TryWhile();
        stmt_t TryIf();
        stmt_t TryWith();
        stmt_t TryRaise();
        stmt_t TryTry();
        stmt_t TryAssert();
        stmt_t TryImport();
        stmt_t TryImportFrom();
        stmt_t TryExpr();
        stmt_t TryPass();
        stmt_t TryBreak();
        stmt_t TryContinue();

        arguments_t TryArguments();
        baseclasses_t TryBaseClasses();
        
        expr_t TryExpression();
        void TryBoolOp(){};
        void TryNamedExpr(){};
        void TryBinOp(){};
        void TryUnaryOp(){};
        void TryLambda(){};
        void TryIfExp(){};
        void TryDict(){};
        void TrySet(){};
        void TryCompare(){};
        void TryCall(){};
        void TryFormattedValue(){};
        void TryJoinedStr(){};
        void TryConstant(){};
        void TryAttribute(){};
        void TrySubscript(){};
        void TryStarred(){};
        void TryName(){};
        void TryList(){};
        void TryTuple(){};
        void TrySlice(){};
        void TryExpr_Context(){};
        void TryBoolop(){};
        void TryOperator(){};
        void TryUnaryop(){};
        void TryCmpop(){};
        void TryExceptHandler(){};
        void TryArg(){};
        void TryKeyword(){};
        void TryAlias(){};
        void TryWithitem(){};

    private:
        inline Token ReadNextToken()
        {
            return mLexer->Read();
        }

        inline Token PeekNextToken()
        {
            return mLexer->Peek();
        }

        inline void PushIdentation(uint8_t i)
        {
            mState.IdentationStack.push(i);
        }

        inline void PopIdentation()
        {
            mState.IdentationStack.pop();
        }

        inline uint8_t CurrentIdentation()
        {
            if ( mState.IdentationStack.empty() )
            {
                return 0;
            }

            return mState.IdentationStack.top();
        }


    private:
        Ref<Lexer> mLexer = nullptr;
        ParserState mState;
    };
}