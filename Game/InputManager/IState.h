#pragma once

namespace InputManager {
    enum class Input {
        HOOVER,
        LEFT_CLICK,
        ESC
    };


    template<class T>
    class IState {
    public :
        virtual ~IState() = default;

        virtual IState* HandleInput(T& state, const Input& input) const = 0;
    };

}