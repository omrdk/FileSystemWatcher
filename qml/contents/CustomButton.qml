import QtQuick
import QtQuick.Controls


/**
  Costumized button
  */
Item {
  id: root

  property alias text: textItem.text

  signal clicked

  QtObject {
    id: _
  }

  Rectangle {
    id: background
    anchors.fill: parent

    border {
      width: 2
      color: theme.borderColor
    }

    radius: 5
    color: theme.backgroundColor
  }

  Text {
    id: textItem
    anchors.centerIn: parent
  }

  MouseArea {
    id: clickArea
    anchors.fill: parent
    onClicked: {
      root.clicked()
    }
  }

  //* CHILD ITEMS

  //* CONNECTIONS

  //* SLOTS (onSignalFunctions)

  //* FUNCTIONS
}
