#include "randomnumbergenerator.h" // Include the class's own header file

// Constructor for RandomNumberGenerator
RandomNumberGenerator::RandomNumberGenerator(QObject *parent)
    : QObject(parent),        // Call the base class (QObject) constructor
    m_randomNumber(0),      // Initialize m_randomNumber to 0
    m_result(""),           // Initialize m_result to an empty string
    m_showNumber(false)     // Initialize m_showNumber to false (number hidden by default)
{}

// Method to generate a random number within the given range
void RandomNumberGenerator::generateNumber(int min, int max) {
    std::random_device rd;    // Random device to generate a seed
    std::mt19937 gen(rd());   // Mersenne Twister generator initialized with the seed
    std::uniform_int_distribution<int> distrib(min, max); // Uniform distribution between min and max

    m_randomNumber = distrib(gen); // Generate a random number and store it
    m_result = "";                 // Reset the result to empty when a new number is generated
    m_showNumber = false;          // Hide the number until "Check Guess" is clicked
    emit resultChanged();          // Emit a signal to notify QML of the result reset
    emit showNumberChanged();      // Emit a signal to notify QML that the number is hidden
}

// Method to check if the user's guess matches the generated number and reveal the number
void RandomNumberGenerator::checkGuess(int guess) {
    m_showNumber = true;           // Reveal the generated number when checking the guess
    if (guess == m_randomNumber) { // Compare the user's guess with the stored random number
        m_result = "Success";      // Set result to "Success" if the guess is correct
    } else {
        m_result = "Failure";      // Set result to "Failure" if the guess is incorrect
    }
    emit randomNumberChanged();    // Emit a signal to notify QML of the random number update
    emit resultChanged();          // Emit a signal to notify QML of the result change
    emit showNumberChanged();      // Emit a signal to notify QML that the number is now visible
}

// Getter method to return the current random number
int RandomNumberGenerator::randomNumber() const {
    return m_randomNumber;  // Return the value of the private m_randomNumber variable
}

// Getter method to return the current guessing result
QString RandomNumberGenerator::result() const {
    return m_result;  // Return the value of the private m_result variable
}

// Getter method to determine if the generated number should be shown
bool RandomNumberGenerator::showNumber() const {
    return m_showNumber;  // Return the value of the private m_showNumber variable
}
