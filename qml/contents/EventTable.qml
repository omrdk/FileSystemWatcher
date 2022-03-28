import QtQuick
import QtQuick.Layouts
import Qt.labs.qmlmodels


/**
  Table model, keeps track and displays all event of watched paths(created, deleted, edited)
  */
Item {
  id: root

  Rectangle {
    id: background
    anchors.fill: parent

    border {
      width: 2
      color: theme.borderColor
    }

    radius: 10

    color: theme.backgroundColor
  }

  Component {
    id: contactDelegate

    Item {
      id: contactItem

      implicitWidth: tableview.width
      implicitHeight: 30

      Rectangle {
        id: bgEventType

        height: 50

        anchors.fill: parent

        border {
          color: theme.borderColor
          width: 2
        }

        color: (heading === true) ? theme.secondaryBackgroundColor : theme.backgroundColor

        Text {
          id: eventType

          anchors.centerIn: parent

          text: model.display
        }
      }
    }
  }

  TableView {
    id: tableview
    required model

    property var columnWidths: [100, 290, 80, 150]

    anchors.fill: parent

    clip: true

    model: EventTableModel

    delegate: contactDelegate

    columnWidthProvider: function (column) {
      return columnWidths[column]
    }
  }
}
