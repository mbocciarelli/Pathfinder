#include "IState.h"
#include "../Scene.hpp"

class WallState : public IState {
public:
    WallState() = default;
    ~WallState() override = default;

    IState* handleInput(Scene& scene, const Input& input) const override;
};
