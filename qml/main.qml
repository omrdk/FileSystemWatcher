import QtQuick
import QtQuick.Controls

import "contents"

Window {
  id: root
  visible: true
  width: 800
  height: 800
  title: qsTr("ScytheCase")
  color: "lightgray"

  // property string var: 0

  // signal blabla()
  QtObject {

    id: _
    //  // Write your private and inaccessible vars & funcs//
  }

  Theme {
    id: theme
  }

  MainView {
    id: mainView

    anchors.fill: parent
  }

  //* ITEM PROPERTIES

  //* CHILD ITEMS

  //* CONNECTIONS

  //* SLOTS (onSignalFunctions)

  //* FUNCTIONS
}
