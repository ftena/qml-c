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

    ColumnLayout {
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

        RowLayout {
            Button {
                id: deleteButton
                anchors.verticalCenter: parent.verticalCenter

                text: "Delete item"

                onClicked: {
                    myModel.removeAnimal(myCombobox.currentIndex)
                }
            }
        }
        ColumnLayout {
            spacing: 2
            RowLayout {
                ComboBox {
                    id: myCombobox
                    model: myModel
                    textRole : "type"
                }

                Button {
                    id: printvaluesButton
                    anchors.verticalCenter: parent.verticalCenter

                    text: "Print values"

                    onClicked: {
                        console.debug(myCombobox.currentIndex)
                        comboboxManagement.printValues(myModel,
                                                       myModel.index(myCombobox.currentIndex, 0))
                    }
                }
            }
        }
    }
}

