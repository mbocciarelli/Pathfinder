
#include "IState.h"
#include "../Scene.hpp"

class EndState : public IState {
private:
    TileType* m_tileType;
public:
    EndState() {
        m_tileType = new TileType(TileType::End);
    }
    ~EndState() override = default;

    IState* handleInput(const Input& input) const override;
};