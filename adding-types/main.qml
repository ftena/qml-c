import QtQuick 2.5
import QtQuick.Window 2.2
import CustomItem 1.0

Window {
    visible: true

    TextInput  {
        id: mySize
        x: 0
        y: 0
        text: "100"
    }

    CustomItem {
        id: customItem
        size: mySize.text

        onSizeChanged: console.log("size changed:", size)
        onClicked: console.log("onClicked!")
    }

    Rectangle {
        id: rect
        x: 50
        y: 50
        width: customItem.size
        height: customItem.size
        color: "red"

        MouseArea {
            anchors.fill: parent
            onClicked: { customItem.mouseClick() }
        }
    }
}
