import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    id: mainwindow
    visible: true

    signal qmlWindowDataSignal(var anObject)

    Item {
        id: rootitem
        objectName: "item"
        width: 100; height: 100

        property int someNumber: 100

        TextEdit {
            id: textedit
            objectName: "textEdit"
            width: 240
            font.pointSize: 20
            text: rootitem.someNumber
            focus: true
        }

        MouseArea {
            id: mainButtonMouseArea
            objectName: "mainButtonMouseArea"

            signal qmlItemDataSignal(string msg, var anObject)
            signal qmlSignalMain(string msg)

            anchors.fill: parent
            onClicked: {
                console.log("clicked")
                qmlItemDataSignal("Hello from QML", rootitem)
                qmlWindowDataSignal(mainwindow)
                qmlSignalMain("Hello from QML - connected in main function")

            }
        }
    }
}
