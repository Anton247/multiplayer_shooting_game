cmake_minimum_required(VERSION 3.17)
project(shooter)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(${CMAKE_PROJECT_NAME}
        # game:
        Source.cpp
        player/Player.cpp
        player/Player.h
        network/ShooterClient.cpp
        network/ShooterClient.h
        network/ShooterServer.cpp
        network/ShooterServer.h
        weapon/Weapon.cpp
        weapon/Weapon.h
        weapon/Ak47.h
        weapon/Shotgun.h
        weapon/Gun.h
        weapon/Gold_Ak47.h
        weapon/Rifle.h
        player/PlayerController.cpp
        player/PlayerController.h
        Shooter.cpp
        Shooter.h
        ShooterConsts.h
        network/ShooterMsgType.h
        network/ShooterMsgType.cpp
        network/Chat.cpp
        network/Chat.h
        # 3d engine:
        GameEngine/engine/Consts.h
        GameEngine/engine/math/Vec4D.h
        GameEngine/engine/math/Vec4D.cpp
        GameEngine/engine/math/Vec3D.cpp
        GameEngine/engine/math/Vec3D.h
        GameEngine/engine/math/Vec2D.cpp
        GameEngine/engine/math/Vec2D.h
        GameEngine/engine/math/Matrix4x4.h
        GameEngine/engine/math/Matrix4x4.cpp
        GameEngine/engine/Triangle.h
        GameEngine/engine/Triangle.cpp
        GameEngine/engine/math/Plane.h
        GameEngine/engine/math/Plane.cpp
        GameEngine/engine/Mesh.h
        GameEngine/engine/Mesh.cpp
        GameEngine/engine/utils/Log.h
        GameEngine/engine/utils/Log.cpp
        GameEngine/engine/utils/Time.h
        GameEngine/engine/utils/Time.cpp
        GameEngine/engine/utils/Timer.cpp
        GameEngine/engine/utils/Timer.h
        GameEngine/engine/utils/ResourceManager.h
        GameEngine/engine/utils/ResourceManager.cpp
        GameEngine/engine/World.h
        GameEngine/engine/World.cpp
        GameEngine/engine/Camera.h
        GameEngine/engine/Camera.cpp
        GameEngine/engine/io/Screen.h
        GameEngine/engine/io/Screen.cpp
        GameEngine/engine/Engine.h
        GameEngine/engine/Engine.cpp
        GameEngine/engine/io/Keyboard.cpp
        GameEngine/engine/io/Keyboard.h
        GameEngine/engine/io/Mouse.cpp
        GameEngine/engine/io/Mouse.h
        GameEngine/engine/io/SoundController.cpp
        GameEngine/engine/io/SoundController.h
        GameEngine/engine/utils/ObjectController.cpp
        GameEngine/engine/utils/ObjectController.h
        GameEngine/engine/animation/Animation.h
        GameEngine/engine/animation/Timeline.cpp
        GameEngine/engine/animation/Timeline.h
        GameEngine/engine/animation/Interpolation.h
        GameEngine/engine/animation/Animation.cpp
        GameEngine/engine/animation/ATranslate.h
        GameEngine/engine/animation/AScale.h
        GameEngine/engine/animation/ARotate.h
        GameEngine/engine/animation/AWait.h
        GameEngine/engine/animation/AFunction.h
        GameEngine/engine/animation/AAttractToPoint.h
        GameEngine/engine/animation/ARotateRelativePoint.h
        GameEngine/engine/animation/ARotateLeft.h
        GameEngine/engine/animation/Interpolation.cpp
        GameEngine/engine/animation/Animations.h
        GameEngine/engine/animation/AShowCreation.h
        GameEngine/engine/animation/AShowUncreation.h
        GameEngine/engine/animation/ARotateLeftUpLookAt.h
        GameEngine/engine/animation/ADecompose.h
        GameEngine/engine/physics/RigidBody.cpp
        GameEngine/engine/physics/RigidBody.h
        GameEngine/engine/physics/Simplex.h
        GameEngine/engine/physics/HitBox.cpp
        GameEngine/engine/physics/HitBox.h
        GameEngine/engine/Object.cpp
        GameEngine/engine/Object.h
        GameEngine/engine/gui/Button.cpp
        GameEngine/engine/gui/Button.h
        GameEngine/engine/gui/Window.cpp
        GameEngine/engine/gui/Window.h
        GameEngine/engine/network/ClientUDP.cpp
        GameEngine/engine/network/ClientUDP.h
        GameEngine/engine/network/MsgType.cpp
        GameEngine/engine/network/MsgType.h
        GameEngine/engine/network/ReliableMsg.cpp
        GameEngine/engine/network/ReliableMsg.h
        GameEngine/engine/network/ServerUDP.cpp
        GameEngine/engine/network/ServerUDP.h
        GameEngine/engine/network/UDPConnection.cpp
        GameEngine/engine/network/UDPConnection.h
        GameEngine/engine/network/UDPSocket.cpp
        GameEngine/engine/network/UDPSocket.h
        GameEngine/engine/utils/EventHandler.cpp
        GameEngine/engine/utils/EventHandler.h)

if(APPLE OR UNIX)
    include_directories(/usr/local/include)
else()
    set(SFML_DIR "C:/Libraries/SFML/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

# OpenGL part
if (APPLE)
    set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
    set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
    include_directories(${GLEW_H} ${GLFW_H})

    set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
    set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
    link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework OpenGL")
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework GLUT")
elseif(UNIX)
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)

    target_link_libraries(${CMAKE_PROJECT_NAME} ${OPENGL_LIBRARIES})
    target_link_libraries(${CMAKE_PROJECT_NAME} ${GLUT_LIBRARY})
endif()
