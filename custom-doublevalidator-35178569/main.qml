import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import TextFieldDoubleValidator 1.0

Window {
    visible: true

    // DoubleValidator doesn't clear the TextField when
    // text > 359.9 or < -359.9
    TextField {
        text: "0.0"
        validator: DoubleValidator {
            bottom: -359.9;
            top: 359.9;
            decimals: 1;
            notation: DoubleValidator.StandardNotation
        }
    }

    // Solution: use your own DoubleValidator.
    // This works OK and text is cleared out when
    // text > 359.9 or < -359.9
    TextField {
        y: 50
        text: "0.0"
        validator: TextFieldDoubleValidator {
            bottom: -359.9;
            top: 359.9;
            decimals: 1;
            notation: DoubleValidator.StandardNotation
        }
    }
}

