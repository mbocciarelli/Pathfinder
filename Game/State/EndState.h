
#include "IState.h"

class EndState : public IState {
public:
    EndState() = default;
    ~EndState() override = default;

    IState* handleInput(Scene& Scene, const Input& input) const override;
};