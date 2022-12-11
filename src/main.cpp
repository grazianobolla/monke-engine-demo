#include <monke/core/engine.h>

class Game : public mk::Engine
{
    mk::Sprite sprite;
    bool shouldWave = false;
    double timePassed = 0;

    void start()
    {
        // load the texture into the sprite
        sprite.load("textures/sheet.png", {0, 0});
    }

    // called on input
    void on_input(mk::InputEvent event)
    {
        // detect click event
        if (event.type == mk::Input::MOUSE && event.code == GLFW_MOUSE_BUTTON_LEFT)
        {
            shouldWave = (event.action == GLFW_PRESS);
        }
    }

    void update(float delta)
    {
        // update the sprite position to be the mouse position each frame
        sprite.position = input.get_mouse_pos();

        // if user is clicking, we update the scale based on the sin of `timePassed`
        if (shouldWave)
            sprite.scale.x = sin(timePassed);

        timePassed += delta;
    }

    void render()
    {
        // render sprite
        sprite_renderer.draw(sprite);
    }
};

int main(int argc, char **argv)
{
    Game game;
    game.run(800, 600, "Monke Engine Demo");
    return 0;
}