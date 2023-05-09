add_executable(music main.cpp mainwindow.cpp)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

target_link_libraries(music PRIVATE Qt5::Widgets)

set_target_properties(music PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )