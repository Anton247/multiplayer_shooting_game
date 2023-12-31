

#ifndef SHOOTER_WEAPON_H
#define SHOOTER_WEAPON_H


#include <string>
#include "../GameEngine/engine/World.h"
#include "../GameEngine/engine/Camera.h"
#include <SFML/Audio/Sound.hpp>
#include "../GameEngine/engine/Mesh.h"
#include "../GameEngine/engine/utils/Time.h"
#include "../GameEngine/engine/io/SoundController.h"
#include "../GameEngine/engine/Consts.h"

struct FireInformation final {
    const std::map<ObjectNameTag, double> damagedPlayers;
    const bool shot;
};

class Weapon : public RigidBody {
private:
    const int _initialPack = 100; // how much ammo do you have when you find the weapon
    const int _clipCapacity = 30; // how much ammo can be stored in one clip
    int _stockAmmo; // how much ammo do you have in stock
    int _clipAmmo; // how much ammo do you have in current clip
    const double _reloadTime = 3.0;
    const double _fireDelay = 0.1; // time delay between fires
    const double _damage = 300;
    const double _spreading = 2.0;

    const std::string _fireSound;
    const std::string _reloadSound;

    double _lastFireTime = std::numeric_limits<double>::min();
    double _lastReloadTime = std::numeric_limits<double>::min();

protected:
    std::map<ObjectNameTag, double>
    fireABullet(std::function<IntersectionInformation(const Vec3D &, const Vec3D &)> rayCastFunction,
                const Vec3D &position, const Vec3D &direction) const;

    virtual std::map<ObjectNameTag, double>
    processFire(std::function<IntersectionInformation(const Vec3D &, const Vec3D &)> rayCastFunction,
                const Vec3D &position, const Vec3D &direction) const;

public:
    Weapon(int initialPack, int clipCapacity, double reloadTime, double fireDelay, double damage, double spreading,
           std::string fireSound, std::string reloadSound, ObjectNameTag weaponName, const std::string &objFileName,
           const Vec3D &s, const Vec3D &t, const Vec3D &r);

    FireInformation
    fire(std::function<IntersectionInformation(const Vec3D &, const Vec3D &)> rayCastFunction, const Vec3D &cameraPosition,
         const Vec3D &direction);

    void reload();
    [[nodiscard]] double reloadTime() const { return _reloadTime; }
    [[nodiscard]] double fireDelay() const { return _fireDelay; }

    [[nodiscard]] std::pair<double, double> balance() const { return std::make_pair(_clipAmmo, _stockAmmo); }

    void addAPack() { _stockAmmo += initialPack(); }

    [[nodiscard]] int initialPack() const { return _initialPack; }
};


#endif //SHOOTER_GameEngine_WEAPON_H
