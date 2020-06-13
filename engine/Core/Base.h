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
#include "enginepch.h"

#ifdef ENGINE_DEBUG
	#if defined(ENGINE_PLATFORM_WINDOWS)
		#define ENGINE_DEBUGBREAK() __debugbreak()
	#elif defined(ENGINE_PLATFORM_LINUX)
		#include <signal.h>
		#define ENGINE_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define ENGINE_ENABLE_ASSERTS
#else
	#define ENGINE_DEBUGBREAK()
#endif

#ifdef ENGINE_ENABLE_ASSERTS
	#define ENGINE_ASSERT(x) { if(!(x)) { Logger.Error("Assertion Failed!"); ENGINE_DEBUGBREAK(); } }
#else
	#define ENGINE_ASSERT(x)
#endif

#define BIT(x) 1 << x

namespace Engine
{
    template <typename T>
    using Scope = std::unique_ptr<T>;
    
    template <typename T, typename... Args>
    constexpr Scope<T> CreateScope(Args &&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template <typename T>
    using Ref = std::shared_ptr<T>;
    
    template <typename T, typename... Args>
    constexpr Ref<T> CreateRef(Args &&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template <class T>
    class Singleton
    {
    public:
        static T &GetInstance()
        {
            static T instance;
            return instance;
        };

    public:
        Singleton(T const &) = delete;
        void operator=(T const &) = delete;

        Singleton(){};
    };
}