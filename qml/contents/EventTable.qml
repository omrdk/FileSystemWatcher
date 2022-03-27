import QtQuick
import QtQuick.Layouts

import Qt.labs.qmlmodels


/**
  Keeps track and displays all event
  */
Item {
  id: root

  QtObject {
    id: _
    // Write your private and inaccessible vars & funcs
  }

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
    id: contactDelegate2

    Item {
      width: tableview.width

      implicitHeight: 50
      implicitWidth: 150

      Rectangle {
        id: bgEventType

        anchors.fill: parent

        color: (heading === true) ? "gray" : "lightgray"

        border {
          color: theme.borderColor
          width: 2
        }

        height: 50

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

    anchors.fill: parent

    //columnSpacing: 1
    rowSpacing: 1

    clip: true

    model: EventTableModel

    //    model: TableModel {
    //      TableModelColumn {
    //        display: "name"
    //      }
    //      TableModelColumn {
    //        display: "color"
    //      }
    //      TableModelColumn {
    //        display: "type"
    //      }
    //      TableModelColumn {
    //        display: "size"
    //      }

    //      rows: [{
    //          "name": "cat",
    //          "color": "black",
    //          "type": "5",
    //          "size": "10"
    //        }
    //        /* {
    //          "name": "dog",
    //          "color": "brown"
    //        }, {
    //          "name": "bird",
    //          "color": "white"
    //        }*/ ]
    //    }
    delegate: contactDelegate2

    //* PROPERTIES DECLARATIONS
    // property string var: 0

    //* SIGNALS

    // signal blabla()

    //* CHILD ITEMS

    //* CONNECTIONS

    //* SLOTS (onSignalFunctions)

    //* FUNCTIONS
  }
}
