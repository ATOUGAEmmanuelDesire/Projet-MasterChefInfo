cmake_minimum_required(VERSION 3.29)
project(Projet_Programmation_Systeme)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
# Activer les options de MySQL si nécessaire
set(MYSQL_INCLUDE_DIR "src/MySQL/include")
set(MYSQL_LIB_DIR "src/MySQL/lib")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Projet_Programmation_Systeme main.cpp
        src/Models/classDeclaration/ClientModel.h
        src/Models/classDefinition/ClientModel.cpp
        src/Models/classDefinition/Order.cpp
        src/Models/classDeclaration/Order.h
        src/Models/classDeclaration/Recipe.h
        src/Models/classDefinition/Recipe.cpp
        src/Models/classDefinition/Human.cpp
        src/Models/classDeclaration/Human.h
        src/Models/classDeclaration/UstensilModel.h
        src/Models/classDefinition/UstensilModel.cpp
        src/Models/classDeclaration/Table.h
        src/Models/classDeclaration/DinningRoom.h
        src/Models/classDefinition/DinningRoom.cpp
        src/Models/classDefinition/Table.cpp
        src/Models/classDeclaration/Butler.h
        src/Models/classDefinition/Butler.cpp
        src/Models/classDeclaration/ClientGroupCreator.h
        src/Models/classDefinition/ClientGroupCreator.cpp
        src/Models/classDeclaration/RestaurantDiver.h
        src/Models/classDefinition/RestaurantDiver.cpp
        src/Models/classDeclaration/Server.h
        src/Models/classDefinition/Server.cpp
        src/Models/classDeclaration/RoomClerk.h
        src/Models/classDefinition/RoomClerk.cpp
        src/Models/classDeclaration/CardModel.h
        src/Models/classDefinition/CardModel.cpp
        src/Models/classDeclaration/Chief.h
        src/Models/classDefinition/Chief.cpp
        src/Models/classDeclaration/Cook.h
        src/Models/classDefinition/Cook.cpp
        src/Models/classDeclaration/StorageModel.h
        src/Models/classDefinition/StorageModel.cpp
        src/Models/classDeclaration/headWaiter.h
        src/Models/classDefinition/HeadWaiter.cpp
        src/Models/classDeclaration/KitchenCounter.h
        src/Models/classDefinition/KitchenCounter.cpp
        src/Models/classDeclaration/KitchenAssistant.h
        src/Models/classDefinition/KitchenAssistant.cpp
        src/Models/classDeclaration/DishwasherModel.h
        src/Models/classDefinition/DishwasherModel.cpp
        src/Models/classDeclaration/MaterialModel.h
        src/Models/classDefinition/MaterialModel.cpp
        src/Models/classDeclaration/WashingMachine.h
        src/Models/classDefinition/WashingMachine.cpp
        src/Models/classDeclaration/DirtyDishesStorage.h
        src/Models/classDefinition/DirtyDishesStorage.cpp
        src/Controllers/classDeclaration/MainController.h
        src/Controllers/classDefinition/MainController.cpp
        src/Controllers/classDeclaration/DBController.h
        src/Controllers/classDefinition/DBController.cpp
        src/Controllers/classDeclaration/MoveController.h
        src/Controllers/classDefinition/MoveController.cpp
        src/Controllers/classDeclaration/MotionlessElementController.h
        src/Controllers/classDefinition/MotionlessElementController.cpp
        src/Models/classDefinition/ClientModel.cpp
        src/Controllers/classDefinition/SocketController.cpp
        src/Controllers/classDefinition/SocketController.cpp
        src/Controllers/classDeclaration/SocketController.h
        src/Vue/diningroomcontroller.cpp
        src/MySQL/include/jdbc/mysql_connection.h
        src/MySQL/include/jdbc/mysql_driver.h
        src/MySQL/include/jdbc/cppconn/driver.h
        src/MySQL/include/jdbc/cppconn/connection.h
        src/MySQL/include/jdbc/cppconn/statement.h
        src/MySQL/include/jdbc/cppconn/prepared_statement.h
        src/MySQL/include/jdbc/cppconn/resultset.h
        src/Vue/client.cpp
        src/Vue/database.cpp
        src/Vue/dish.cpp
        src/Vue/kitchencontroller.cpp
        src/Vue/mainview.cpp
        src/Vue/mainwindow.cpp
        src/Vue/order.cpp
        src/Vue/restaurant.cpp
        src/Vue/similationmanager.cpp
        src/Vue/staff.cpp
        src/Vue/stockmanger.cpp
        src/Vue/table.cpp

)
target_link_libraries(Projet_Programmation_Systeme
        Qt::Core
        Qt::Gui
        Qt::Widgets
)





if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
