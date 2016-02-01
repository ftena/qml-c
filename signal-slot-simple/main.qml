import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal qmlSignal(string msg)

    Button {
        id: add
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("add")
        onClicked: qmlSignal(text)
    }
}
