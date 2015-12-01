import QtQuick 2.0

ListView {
    id:devicesList
    objectName:"devicesList"
    width: 100; height: 300
    model: myModel
    delegate: Rectangle {
        height: 50
        width: 100

        Text { text: modelData }
    }
}
