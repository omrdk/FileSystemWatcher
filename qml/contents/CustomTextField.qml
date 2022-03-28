import QtQuick
import QtQuick.Controls


/**
  Allows selection of the path that can be watched.
  Not editable, works like a button but keeps the path string on it
  */
Item {
  id: root

  property alias text: textFieldItem.text
  property alias placeHolderText: textFieldItem.placeholderText

  signal clicked

  TextField {
    id: textFieldItem

    anchors.fill: parent

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
