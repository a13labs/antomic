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
#include "Platform/Platform.h"
#include "Core/LayerStack.h"
#include "Input/Input.h"
#include "Renderer/Renderer.h"

namespace Antomic
{
    class Application
    {

    public:
        Application() : Application("Application", 640, 480){};
        Application(const char *name) : Application(name, 640, 480){};
        Application(const char *name, uint32_t width, uint32_t height, RenderAPI api = RenderAPI::OPENGL);

        virtual ~Application();

        void OnEvent(Event &event);
        void ToggleFullscreen(bool value);
        void Run();
        bool OnWindowClose(WindowCloseEvent &event);
        bool OnWindowResize(WindowResizeEvent &event);
        inline uint32_t CurrentWidth() const { return m_Width; }
        inline uint32_t CurrentHeight() const { return m_Height; }

        virtual void Update(const TimeStep &time) {};
        virtual void Render() {};

        static Application &Current() { return *s_Instance; }

    protected:
        LayerStack m_Stack;
        uint32_t m_Width, m_Height;

    private:
        static Application *s_Instance;
        bool m_Running;
        Scope<Platform> m_Platform;
        Scope<Input> m_Input;
        Scope<Renderer> m_Renderer;
        TimePoint m_LastRenderTime;
    };
} // namespace Antomic
