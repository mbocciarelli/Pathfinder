#include "IState.h"
#include "../Scene.hpp"

class RunState : public IState {
public:
    IState* handleInput(Scene& scene, const Input& input) const override;
};

