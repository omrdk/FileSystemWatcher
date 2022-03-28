import QtQuick
import QtQuick.Controls

import "contents"

Window {
  id: root

  visible: true

  width: 700
  height: 650

  title: qsTr("File System Watcher")

  color: theme.backgroundColor

  Theme {
    id: theme
  }

  MainView {
    id: mainView

    anchors.fill: parent
  }
}
