#include "../include/Button.hpp"

void Button::makeEntity(Entity* e, int x, int y, int w, int h, float offsetX,
                        float offsetY, Color normal, Color hover,
                        std::string content, std::function<void(Entity*)> f,
                        bool* press)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<InputComponent>([f, press, normal, hover](Entity* t) {
        if (Button::clickCheckFunc(t, press, normal, hover)) {
            f(t);
        }
    });
    e->addComponent<ColorComponent>(normal);
    e->addComponent<DrawComponent>();
    e->addComponent<TextComponent>(content, Vector2{offsetX, offsetY});
}

bool Button::clickCheckFunc(Entity* e, bool* press, Color normal, Color hover)
{
    if (CheckCollisionPointRec(
            GetMousePosition(),
            e->getComponent<TransformComponent>()->getRec())) {
        if (press == nullptr || !(*press))
            e->getComponent<ColorComponent>()->color = hover;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return true;
        return false;
    }
    else {
        if (press == nullptr || !(*press))
            e->getComponent<ColorComponent>()->color = normal;
        return false;
    }
}
