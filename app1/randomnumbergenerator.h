#ifndef RANDOMNUMBERGENERATOR_H  // Guard to prevent multiple inclusions
#define RANDOMNUMBERGENERATOR_H

#include <QObject>       // Base class for Qt objects
#include <random>        // C++ library for random number generation

// Definition of the RandomNumberGenerator class
class RandomNumberGenerator : public QObject {
    Q_OBJECT  // Macro enabling signals and slots
    // Define the randomNumber property for QML access
    Q_PROPERTY(int randomNumber READ randomNumber NOTIFY randomNumberChanged)

public:
    // Constructor with an optional parent parameter
    explicit RandomNumberGenerator(QObject *parent = nullptr);

    // Method callable from QML to generate a random number
    Q_INVOKABLE void generateNumber(int min, int max);
    // Getter for the randomNumber property
    int randomNumber() const;

signals:
    // Signal emitted when the random number changes
    void randomNumberChanged();

private:
    int m_randomNumber;  // Private variable storing the random number
};

#endif // RANDOMNUMBERGENERATOR_H
