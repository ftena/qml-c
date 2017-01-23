import QtQuick 2.1
import QtQuick.Window 2.0
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function windowStateChange()
    {
        console.log("qml slot - windowStateChange");
        show();
    }
}
