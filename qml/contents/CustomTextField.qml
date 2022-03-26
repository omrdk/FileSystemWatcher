import QtQuick
import QtQuick.Controls

Item {
  id: root

  property alias text: textFieldItem.text

  signal clicked

  QtObject {
    id: _
  }

  TextField {
    id: textFieldItem

    anchors.fill: parent

    //focus: true
    background: Rectangle {
      id: background
      anchors.fill: parent

      border {
        width: 2
        color: theme.borderColor
      }

      radius: 5
      color: theme.backgroundColor
    }

    MouseArea {
      id: clickArea
      anchors.fill: parent
      onClicked: {
        root.clicked()
      }
    }
  }
}
