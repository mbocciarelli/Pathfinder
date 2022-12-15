#include <SFML/Graphics.hpp>
//#include <PathfindingSystem.hpp>

#include <vector>
#include "Scene.hpp"


int main()
{
    Scene scene;
    
    if(scene.init())
        scene.start();

    return 0;
}