#include "randomnumbergenerator.h" // Include the class's own header file

// Constructor for RandomNumberGenerator
RandomNumberGenerator::RandomNumberGenerator(QObject *parent)
    : QObject(parent),        // Call the base class (QObject) constructor
    m_randomNumber(0)       // Initialize m_randomNumber to 0
{}

// Method to generate a random number within the given range
void RandomNumberGenerator::generateNumber(int min, int max) {
    std::random_device rd;    // Random device to generate a seed
    std::mt19937 gen(rd());   // Mersenne Twister generator initialized with the seed
    std::uniform_int_distribution<int> distrib(min, max); // Uniform distribution between min and max

    m_randomNumber = distrib(gen); // Generate a random number and store it
    emit randomNumberChanged();    // Emit a signal to notify QML of the change
}

// Getter method to return the current random number
int RandomNumberGenerator::randomNumber() const {
    return m_randomNumber;  // Return the value of the private m_randomNumber variable
}
