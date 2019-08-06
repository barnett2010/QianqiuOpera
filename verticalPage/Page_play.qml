import QtQuick 2.9

Rectangle {
    width: 960
    height: 540

    Rectangle {
        anchors.fill: parent
        color: "white"
    }
    ListView {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: 490
        height: 150
        model: 2
        orientation: ListView.Horizontal
        delegate: Rectangle{
            id: cardDelegate
            width: 70
            height: 100
            border.width: 2
            border.color: "black"
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    cardDelegate.y -= 20
                    cardDelegate.border.color = "yellow"
                }
                onExited: {
                    cardDelegate.y += 20
                    cardDelegate.border.color = "black"
                }
            }
        }
    }
}
