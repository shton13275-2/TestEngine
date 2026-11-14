#include "TestEngine/Engine.hpp"

#include <iostream>
#include <string_view>

int main()
{
    if (testengine::Engine::name() != std::string_view{"TestEngine"})
    {
        std::cerr << "Engine name smoke test failed\n";
        return 1;
    }

    std::cout << "TestEngine smoke tests passed\n";
    return 0;
}
