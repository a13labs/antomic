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
#include "Events/Event.h"

namespace Engine
{
    class Layer
    {

    public:
        Layer(const std::string &name = "layer");
        virtual ~Layer();
        
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void Update() {}
        virtual void OnEvent(Event &e) {}

        inline const std::string &GetName() const { return m_Name; }

    protected:
        std::string m_Name;
    };
} // namespace Engine