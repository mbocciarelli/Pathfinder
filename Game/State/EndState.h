
#include "IState.h"
#include "../Scene.hpp"

class EndState : public IState {
public:
    EndState() = default;
    ~EndState() override = default;

    IState* handleInput(Scene& scene, const Input& input) const override;
};