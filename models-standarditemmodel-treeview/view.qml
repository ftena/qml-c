import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("")

    toolBar: ToolBar {
        style: ToolBarStyle {
            padding {
                left: 20
                right: 20
                top: 15
                bottom: 15
            }
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                border.color: "#999"
                gradient: Gradient {
                    GradientStop { position: 0 ; color: "#fff" }
                    GradientStop { position: 1 ; color: "#aaa" }
                }
            }
        }
        ColumnLayout{
            spacing: 2
            RowLayout {
                Button {
                    id: addButton

                    anchors.verticalCenter: parent.verticalCenter

                    text: "Add item"

                    onClicked: {
                        if (typeBox.text || sizeBox.text) {
                            myModel.addAnimal(typeBox.text, sizeBox.text)
                        }
                    }
                }
                TextField {
                    id: typeBox
                    placeholderText: "type"

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: addButton.right
                    anchors.leftMargin: 5
                }

                TextField {
                    id: sizeBox
                    placeholderText: "size"

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: typeBox.right
                    anchors.leftMargin: 5
                }
            }
        }
    }

    TreeView  {
        id: treeView

        frameVisible: false
        sortIndicatorVisible: true

        anchors.fill: parent

        Layout.minimumWidth: 400
        Layout.minimumHeight: 240
        Layout.preferredWidth: 600
        Layout.preferredHeight: 400

        TableViewColumn {
            role: "type"
            title: "Type"
        }

        TableViewColumn {
            role: "size"
            title: "Size"
        }

        model: myModel
    }
}
