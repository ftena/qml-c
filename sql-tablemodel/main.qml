import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    TableView {
        id: tableView

        anchors.fill: parent

        TableViewColumn {
            role: "name"
            title: "Name"
            width: 200
        }

        TableViewColumn {
            role: "salary"
            title: "Salary"
            width: 200
        }

        model: myModel
    }

    Button {
        id: addButton

        anchors.verticalCenter: parent.verticalCenter

        text: "Add item"

        onClicked: {
            if (nameBox.text || salaryBox.text) {
                myModel.addItem(nameBox.text, salaryBox.text)
            }
        }
    }
    TextField {
        id: nameBox
        placeholderText: "name"

        anchors.verticalCenter: parent.verticalCenter
        anchors.left: addButton.right
        anchors.leftMargin: 5
    }

    TextField {
        id: salaryBox
        placeholderText: "salary"

        anchors.verticalCenter: parent.verticalCenter
        anchors.left: nameBox.right
        anchors.leftMargin: 5
    }
}
