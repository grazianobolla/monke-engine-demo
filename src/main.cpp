#include <monke/core/engine.h>

class Game : public mk::Engine
{
    mk::Sprite sprite;
    mk::Vector2 scale = {1, 1};

    void start()
    {
        // load the texture into memory
        sprite.load("textures/sheet.png");
    }

    void update(float delta)
    {
        // detect W press and change scale
        if (input.is_key_pressed(GLFW_KEY_W))
            scale.x += delta * 0.5f;
    }

    void render()
    {
        // render sprite
        sprite_renderer.draw(sprite, input.get_mouse_pos(), scale);
    }
};

int main(int argc, char **argv)
{
    Game game;
    game.run(800, 600, "Monke Engine Demo");
    return 0;
}