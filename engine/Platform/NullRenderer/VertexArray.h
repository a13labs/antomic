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
#include "Renderer/VertexArray.h"

namespace Antomic {

    class NullVertexArray : public VertexArray
    {
    public:
        NullVertexArray() {}
        virtual ~NullVertexArray() override {}
    
    public:
        virtual void Bind() const override {}
        virtual void Unbind() const override {}
        virtual void AddVertexBuffer(const Ref<VertexBuffer> &buffer) override { mVertextBuffers.push_back(buffer); }
        virtual void SetIndexBuffer(const Ref<IndexBuffer> &buffer) override { mIndexBuffer = buffer; }
        virtual const std::vector<Ref<VertexBuffer>> &GetVertexBuffers() const override { return mVertextBuffers; };
        virtual const Ref<IndexBuffer> &GetIndexBuffer() const override { return mIndexBuffer; };
        
    private:
        std::vector<Ref<VertexBuffer>> mVertextBuffers;
        Ref<IndexBuffer> mIndexBuffer;
    };

}