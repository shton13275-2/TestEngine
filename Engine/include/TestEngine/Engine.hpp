#pragma once

#include <string_view>

namespace testengine
{

class Engine
{
public:
    [[nodiscard]] static constexpr std::string_view name() noexcept
    {
        return "TestEngine";
    }
};

} // namespace testengine
