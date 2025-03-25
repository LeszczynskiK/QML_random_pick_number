// Importing necessary Qt modules for building the UI
import QtQuick 2.15           // Core module for QML elements
import QtQuick.Controls 2.15  // Module for UI controls like Button and TextField
import QtQuick.Layouts 1.15   // Module for layout management (not used here)

// Main application window
ApplicationWindow {
    visible: true            // Makes the window visible on startup
    width: 720              // Window width in pixels
    height: 480             // Window height in pixels
    title: "Guess the Number"  // Title displayed in the window's title bar

    // Rectangle for a solid color background
    Rectangle {
        anchors.fill: parent  // Fills the entire window
        color: "lightblue"    // Sets the background color (can use hex like "#87CEEB")
    }

    // Text field for entering the minimum value
    TextField {
        id: minField         // Unique ID for referencing this field
        placeholderText: "Min value"  // Placeholder text shown when empty
        x: 20               // X position (from the left edge of the window)
        y: 50               // Y position (from the top edge of the window)
        width: 300          // Width of the text field
        height: 60          //  Height of text field
        inputMethodHints: Qt.ImhDigitsOnly  // Restricts input to digits only
    }

    // Text field for entering the maximum value
    TextField {
        id: maxField         // Unique ID for referencing this field
        placeholderText: "Max value"  // Placeholder text shown when empty
        x: 20               // X position
        y: 130              // Y position (50 pixels below minField)
        width: 300          // Width of the text field
        height: 60          //  Height of text field
        inputMethodHints: Qt.ImhDigitsOnly  // Restricts input to digits only
    }

    // Button to generate a random number (number is generated but not shown yet)
    Button {
        text: "Generate number"  // Text displayed on the button
        x: 20             // X position (roughly centered relative to text fields)
        y: 220              // Y position
        width: 130          // Button width
        height: 70          // Button height
        onClicked: {        // Function triggered when the button is clicked
            let minValue = parseInt(minField.text);  // Convert minField text to an integer
            let maxValue = parseInt(maxField.text);  // Convert maxField text to an integer
            // Check if values are valid numbers and min <= max
            if (!isNaN(minValue) && !isNaN(maxValue) && minValue <= maxValue) {
                randomNumberGenerator.generateNumber(minValue, maxValue); // Generate number without displaying it
            }
        }
    }

    // Label to display the generated random number (hidden until "Check Guess" is clicked)
    Label {
        id: generatedNumberLabel
        text: randomNumberGenerator.showNumber ? "Generated number: " + randomNumberGenerator.randomNumber : "Generated number: ?"  // Show number only if showNumber is true
        x: 340             // X position (approximately centered)
        y: 70             // Y position
        font.pixelSize: 36  // Font size in pixels
    }

    // Text field for entering the user's guess
    TextField {
        id: guessField       // Unique ID for referencing this field
        placeholderText: "Your guess"  // Placeholder text shown when empty
        x: 340              // X position
        y: 330             // Y position
        width: 300          // Width of the text field
        height: 60          //  Height of text field
        inputMethodHints: Qt.ImhDigitsOnly  // Restricts input to digits only
    }

    // Button to check the user's guess and reveal the generated number
    Button {
        text: "Check Guess"  // Text displayed on the button
        x: 20              // X position (roughly centered)
        y: 330            // Y position
        width: 130          // Button width
        height: 60          // Button height
        onClicked: {        // Function triggered when the button is clicked
            let guess = parseInt(guessField.text);  // Convert guessField text to an integer
            if (!isNaN(guess)) {
                randomNumberGenerator.checkGuess(guess); // Check the guess and reveal the number
            }
        }
    }

    // Label to display the result of the guessing attempt
    Label {
        id: resultLabel      // Unique ID for referencing this label
        text: randomNumberGenerator.result  // Display the result ("Success" or "Failure")
        x: 340             // X position (approximately centered)
        y: 150             // Y position
        font.pixelSize: 36  // Font size in pixels
    }
}
