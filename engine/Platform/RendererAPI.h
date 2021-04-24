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
#include "Renderer/Buffers.h"
#include "Renderer/VertexArray.h"
#include "glm/glm.hpp"

namespace Antomic
{
    enum class RenderAPI {

        NONE = 0,
        OPENGL = 1
    };

    RenderAPI RenderAPIFromStr(const std::string &api);
    std::string const RenderAPIToStr(RenderAPI api);

    class RendererAPI
    {
    public:

        virtual void Clear(glm::vec4 color) = 0;
        virtual void DrawIndexed(const Ref<VertexArray> vertexArray) = 0;

	public:
		static Scope<RendererAPI> Create(RenderAPI api = RenderAPI::OPENGL);
        static RenderAPI API() { return sRendererAPI; }
    private:
        static RenderAPI sRendererAPI;
    };

} // namespace Antomic
