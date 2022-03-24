import QtQuick
import QtQuick.Controls

import "contents"

Window {
  id: root

  //* PROPERTIES DECLARATIONS
  // property string var: 0

  //* SIGNALS
  // signal blabla()
  QtObject {

    id: _ //  // Write your private and inaccessible vars & funcs//
  }

  //* ITEM PROPERTIES
  title: qsTr("ScytheCase")
  width: 800
  height: 800
  visible: true
  color: "lightgray"

  //* CHILD ITEMS
  PathList {
    id: addLine // ?
  }

  StyledButton {
    id: addButton
  }

  PathList {
    id: pathList
  }

  EventTable {
    id: eventTable
  }

  StyledButton {
    id: clearButton
  }

  StyledButton {
    id: startButton
  }

  StyledButton {
    id: stopButton
  }

  //* CONNECTIONS

  //* SLOTS (onSignalFunctions)

  //* FUNCTIONS
}
