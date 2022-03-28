import QtQuick
import QtQuick.Controls


/**
  Costumized button for; add paths to listview, start/stop file watcher & clear tableview
  */
Item {
  id: root

  property alias text: textItem.text

  signal clicked

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

    onPressed: {
      background.color = theme.secondaryBackgroundColor

      textItem.color = theme.textColor
    }

    onReleased: {
      background.color = theme.backgroundColor

      textItem.color = theme.textColor
    }
  }
}
