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
#include "Core/Layer.h"

namespace Engine
{
    class LayerStack
    {

    public:
        LayerStack();
        ~LayerStack();

        void PushFront(Ref<Layer> l);
        void PushBack(Ref<Layer> l);
        void PopFront();
        void PopBack();
        void Remove(Ref<Layer> l);
        void Update();
        void Render();
        void OnEvent(Event &e);

        inline int Empty() const { return m_Stack.empty(); }
        inline int Count() const { return m_Stack.size(); }
    protected:
        std::vector<Ref<Layer>> m_Stack;
    };
} // namespace Engine
