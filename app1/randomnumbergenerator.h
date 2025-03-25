#ifndef RANDOMNUMBERGENERATOR_H  // Guard to prevent multiple inclusions
#define RANDOMNUMBERGENERATOR_H

#include <QObject>       // Base class for Qt objects
#include <random>        // C++ library for random number generation

// Definition of the RandomNumberGenerator class
class RandomNumberGenerator : public QObject {
    Q_OBJECT  // Macro enabling signals and slots

    // Define the randomNumber property for QML access
    Q_PROPERTY(int randomNumber READ randomNumber NOTIFY randomNumberChanged)

    // Define the result property to display the guessing outcome in QML
    Q_PROPERTY(QString result READ result NOTIFY resultChanged)  // Property for success/failure message

    // Define the showNumber property to control visibility of the random number in QML
    Q_PROPERTY(bool showNumber READ showNumber NOTIFY showNumberChanged)  // New property to toggle number visibility

public:
    // Constructor with an optional parent parameter
    explicit RandomNumberGenerator(QObject *parent = nullptr);

    // Method callable from QML to generate a random number within a range
    Q_INVOKABLE void generateNumber(int min, int max);

    // Method callable from QML to check if the user's guess matches the random number
    Q_INVOKABLE void checkGuess(int guess);  // Method to compare the guess and reveal the number

    // Getter for the randomNumber property
    int randomNumber() const;

    // Getter for the result property
    QString result() const;  // Getter to return the result string

    // Getter for the showNumber property
    bool showNumber() const;  // New getter to return whether the number should be shown

signals:
    // Signal emitted when the random number changes
    void randomNumberChanged();

    // Signal emitted when the guessing result changes
    void resultChanged();  // Signal to notify QML about result updates

    // Signal emitted when the visibility of the number changes
    void showNumberChanged();  // New signal to notify QML about visibility updates

private:
    int m_randomNumber;      // Private variable storing the random number
    QString m_result;        // Private variable storing the guessing result ("Success" or "Failure")
    bool m_showNumber;       // Private variable controlling whether the number is visible
};

#endif // RANDOMNUMBERGENERATOR_H
