import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    id: mainwindow
    visible: true

    Item {
        id: rootitem
        objectName: "item"
        width: 100; height: 100

        property int someNumber: 100

        Text {
            text: rootitem.someNumber
        }

        MouseArea {
            id: mainButtonMouseArea
            objectName: "mainButtonMouseArea"

            signal qmlSignal(string msg, var anObject)
            signal qmlSignalMain(string msg)

            anchors.fill: parent
            onClicked: {
                console.log("clicked")
                qmlSignal("Hello from QML", rootitem)
                qmlSignalMain("Hello from QML - connected in main function")

            }
        }
    }
}
