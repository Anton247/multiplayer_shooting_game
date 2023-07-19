#include "Shooter.h"

int main() {
    Shooter game;

    // Optimal for standard monitors:
    //game.create(720, 480, ShooterConsts::PROJECT_NAME, true);
    game.create(1920, 1080, ShooterConsts::PROJECT_NAME, true);
    //game.create(1920, 1080, ShooterConsts::PROJECT_NAME, true, Consts::BACKGROUND_COLOR, sf::Style::Fullscreen);

    return 0;
}