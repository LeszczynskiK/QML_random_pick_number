// Importing necessary Qt modules for building the UI
import QtQuick 2.15           // Core module for QML elements
import QtQuick.Controls 2.15  // Module for UI controls like Button and TextField
import QtQuick.Layouts 1.15   // Module for layout management (not used here)

// Main application window
ApplicationWindow {
    visible: true            // Makes the window visible on startup
    width: 400              // Window width in pixels
    height: 300             // Window height in pixels
    title: "Random Number Generator"  // Title displayed in the window's title bar

    // Text field for entering the minimum value
    TextField {
        id: minField         // Unique ID for referencing this field
        placeholderText: "Min value"  // Placeholder text shown when empty
        x: 50               // X position (from the left edge of the window)
        y: 50               // Y position (from the top edge of the window)
        width: 300          // Width of the text field
        inputMethodHints: Qt.ImhDigitsOnly  // Restricts input to digits only
    }

    // Text field for entering the maximum value
    TextField {
        id: maxField         // Unique ID for referencing this field
        placeholderText: "Max value"  // Placeholder text shown when empty
        x: 50               // X position
        y: 100              // Y position (50 pixels below minField)
        width: 300          // Width of the text field
        inputMethodHints: Qt.ImhDigitsOnly  // Restricts input to digits only
    }

    // Button to generate a random number
    Button {
        text: "Generate number"  // Text displayed on the button
        x: 135              // X position (roughly centered relative to text fields)
        y: 150              // Y position
        width: 130          // Button width
        height: 40          // Button height
        onClicked: {        // Function triggered when the button is clicked
            let minValue = parseInt(minField.text);  // Convert minField text to an integer
            let maxValue = parseInt(maxField.text);  // Convert maxField text to an integer
            // Check if values are valid numbers and min <= max
            if (!isNaN(minValue) && !isNaN(maxValue) && minValue <= maxValue) {
                // Call the generateNumber method from RandomNumberGenerator
                randomNumberGenerator.generateNumber(minValue, maxValue);
            }
        }
    }

    // Label to display the generated random number
    Label {
        // Text combines a static string with the dynamic randomNumber value
        text: "Generated number: " + randomNumberGenerator.randomNumber
        x: 120              // X position (approximately centered)
        y: 210              // Y position
        font.pixelSize: 18  // Font size in pixels
    }
}
