import QtQuick 2.9
import "./verticalPage"

Item {
    width: 960
    height: 540
    visible: true

    Rectangle {
        anchors.fill: parent
        color: "black"
        z: -1
    }

    Item {
        id:root

        property double widthRatio: parent.width/width
        property double heightRatio: parent.height/height

//        width: Screen.width
//        height: Screen.height
        width: 960
        height: 540
        anchors.centerIn: parent
        scale: Math.min(widthRatio,heightRatio)

        Page_play {
            anchors.fill: parent
            visible: true
        }

    }
}
