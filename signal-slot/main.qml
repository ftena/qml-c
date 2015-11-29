import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: mainwindow
    width: 500; height: 500
    visible: true

    signal qmlWindowDataSignal(var anObject)

    onActiveFocusItemChanged: {
        console.log("onActiveFocusItemChanged: " + activeFocusItem.text)
        qmlWindowDataSignal(mainwindow);
    }

    TextField {
        id: txtupleft
        y: 50
        KeyNavigation.down: txtdownleft
    }

    TextField {
        id: txtdownleft
        y: 100
        KeyNavigation.up: txtupleft
    }

    Item {
        id: anItem
        objectName: "item"
        width: 100; height: 100
        y: 200

        property int someNumber: 100

        TextEdit {
            id: textedit
            objectName: "textEdit"
            width: 240
            font.pointSize: 20
            text: anItem.someNumber
            focus: true
        }
    }

    Rectangle {
        width: 50; height: 50
        y: 300
        color: focus ? "red" : "lightgray"

        MouseArea {
            id: mainButtonMouseArea
            objectName: "mainButtonMouseArea"

            signal qmlItemDataSignal(string msg, var anObject)
            signal qmlSignalMain(string msg)

            anchors.fill: parent
            onClicked: {
                console.log("clicked")
                qmlItemDataSignal("Sending an item from QML", anItem)
                qmlSignalMain("Hello from QML - connected in main function")
            }
        }
    }
}

