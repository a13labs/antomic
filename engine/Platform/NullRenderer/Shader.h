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
#include "Renderer/Shader.h"
#include "glm/glm.hpp"

namespace Antomic
{
    class NullShader : public Shader
    {
    public:
        NullShader(const std::string &vertexSrc, const std::string &fragmentSrc) {}
        virtual ~NullShader() override {}

    public:
        // Bind/Unbind commands
        virtual void Bind() const override {}
        virtual void Unbind() const override {}

        // Uniform Commands
        virtual void SetUniformValue(const std::string& name, float value) override {}
        virtual void SetUniformValue(const std::string& name, const glm::vec2 &value) override {}
        virtual void SetUniformValue(const std::string& name, const glm::vec3 &value) override {}
        virtual void SetUniformValue(const std::string& name, const glm::vec4 &value) override {}
        virtual void SetUniformValue(const std::string& name, const glm::mat3 &value) override {}
        virtual void SetUniformValue(const std::string& name, const glm::mat4 &value) override {}
    };

} // namespace Antomic
