import QtQuick 2.5
import QtQuick.Window 2.2
import CustomItem 1.0

Window {
    visible: true

    CustomItem {
        id: customItem
        x: 50
        y: 50
    }

    Rectangle {
        id: rect
        x: customItem.x
        y: customItem.y
        width: 100; height: 100
        color: "red"
    }

}

