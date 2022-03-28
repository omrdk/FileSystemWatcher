import QtQuick

import "contents"

Item {
  id: root

  QtObject {
    id: _

    property string selectedPath: ""
  }

  CustomTextField {
    id: pathInput

    width: 500
    height: 40

    anchors {
      top: parent.top
      left: parent.left
      topMargin: 10
      leftMargin: 10
    }

    placeHolderText: "Add path to watch"

    onClicked: {
      text = "if"

      _.selectedPath = AppManager.getFileOrDirectoryPath()

      text = _.selectedPath
    }
  }

  // add path button
  CustomButton {
    id: addButton

    width: 100
    height: 40

    anchors {
      top: parent.top
      left: pathInput.right
      topMargin: 10
      leftMargin: 10
    }

    text: "Add"

    onClicked: {
      if (pathInput.text !== "") {
        AppManager.addPathToListInterface(_.selectedPath)

        AppManager.addPathToFileWatcher(_.selectedPath)
      }
    }
  }

  // watcher list
  PathList {
    id: pathList

    width: 610
    height: 200

    anchors {
      top: pathInput.bottom
      left: parent.left
      topMargin: 40
      leftMargin: 10
    }
  }

  // log table
  EventTable {
    id: eventTable

    width: 620
    height: 200

    anchors {
      top: pathList.bottom
      left: parent.left
      topMargin: 40
      leftMargin: 10
    }
  }

  // clear list button
  CustomButton {
    id: clearButton

    width: 100
    height: 40

    anchors {
      left: parent.left
      top: eventTable.bottom
      leftMargin: 10
      topMargin: 10
    }

    text: "Clear"

    onClicked: {
      AppManager.clearTableInterface()
    }
  }

  // start wacther button
  CustomButton {
    id: startButton

    width: 100
    height: 40

    anchors {
      left: clearButton.right
      top: eventTable.bottom
      leftMargin: 10
      topMargin: 10
    }

    text: "Start"

    onClicked: {
      AppManager.startFileWatcher()
    }
  }

  // stop watcher button
  CustomButton {
    id: stopButton

    width: 100
    height: 40

    anchors {
      left: startButton.right
      top: eventTable.bottom
      leftMargin: 10
      topMargin: 10
    }

    text: "Stop"

    onClicked: {
      AppManager.stopFileWatcher()
    }
  }
}
