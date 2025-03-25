cmake_minimum_required(VERSION 3.16)

project(app1 VERSION 0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17) # set cpp standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5) #qt standard

qt_add_executable(appapp1
    main.cpp #callable file
)

qt_add_qml_module(appapp1
    URI app1
    VERSION 1.0
    RESOURCE_PREFIX "/"
    QML_FILES
        Main.qml
    SOURCES #addition sources to add here
        randomnumbergenerator.h
        randomnumbergenerator.cpp
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appapp1 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appapp1
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appapp1
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appapp1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
