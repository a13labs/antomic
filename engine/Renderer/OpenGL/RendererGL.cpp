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
#include "Renderer/OpenGL/RendererGL.h"
#include <GL/gl.h>

namespace Engine
{

    void RendererGL::Init(uint32_t width, uint32_t height)
    {
        OnWindowResize(width, height);
    }

    void RendererGL::Shutdown()
    {
    }

    void RendererGL::OnWindowResize(uint32_t width, uint32_t height)
    {
    }

    void RendererGL::RenderFrame()
    {
        glClearColor(1,0,1,1);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void RendererGL::BeginScene()
    {
    }

    void RendererGL::EndScene()
    {
    }

} // namespace Engine