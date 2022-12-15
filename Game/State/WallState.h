#include "IState.h"
#include <SFML/Window/Keyboard.hpp>

class WallState : public IState {
public:
    WallState()
    {
        m_tileType = TileType::Wall;
    }
    ~WallState() override = default;

    IState* handleInput(IState* currentState, const sf::Keyboard::Key& input) const override;

};
