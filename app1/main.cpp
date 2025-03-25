#include <QGuiApplication>         // Class for managing the GUI application
#include <QQmlApplicationEngine>   // Engine for loading and running QML
#include <QQmlContext>            // Allows passing C++ objects to QML
#include "randomnumbergenerator.h"

int main(int argc, char *argv[]) {
    // Create an instance of the GUI application
    QGuiApplication app(argc, argv);
    // Create a QML engine to load the interface
    QQmlApplicationEngine engine;

    // Create an instance of RandomNumberGenerator
    RandomNumberGenerator rng;
    // Expose the rng object to QML under the name "randomNumberGenerator"
    engine.rootContext()->setContextProperty("randomNumberGenerator", &rng);

    // Load the main QML file from resources (qrc)
    engine.load(QUrl("qrc:/app1/Main.qml"));
    // Check if the QML loaded successfully
    if (engine.rootObjects().isEmpty())
        return -1;  // Exit with an error if no root objects are found

    // Start the application's event loop
    return app.exec();
}
