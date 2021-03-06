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
#include "Graph/Node.h"
#include "glm/glm.hpp"

namespace Antomic
{
    class Scene : public Node
    {
    public:
        Scene() = default;
        virtual ~Scene() = default;

    public:
        // Scene Information
        inline const glm::mat4 &GetViewMatrix() const { return mViewMatrix; }
        inline const Ref<Camera> &GetActiveCamera() const { return mActiveCamera; }
        virtual NodeType GetType() override { return NodeType::SCENE; };

        // Load & Unloading
        void Load();
        void Unload();

        virtual void Update(const uint32_t &time) override;
        // Serialization
        virtual void Serialize(nlohmann::json &json) override;
        static Ref<Scene> Deserialize(const nlohmann::json &json);
        
    protected:
        virtual const Ref<Drawable> GetDrawable() const override { return nullptr; }
    virtual void UpdateSpatialInformation() override {}

    private:
        glm::mat4 mViewMatrix;
        Ref<Camera> mActiveCamera;
    };

} // namespace Antomic
