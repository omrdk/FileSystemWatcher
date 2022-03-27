import QtQuick 2.0
import "contents"

Item {
  id: root

  // path input section
  QtObject {
    id: _

    property string selectedPath: ""
  }

  CustomTextField {
    id: pathInput

    width: 500
    height: 50

    anchors {
      top: parent.top
      left: parent.left
    }

    // place holder will be added
    onClicked: {
      _.selectedPath = AppManager.getFileOrDirectoryPath()
      text = _.selectedPath
    }
  }

  // add path button
  CustomButton {
    id: addButton

    width: 100
    height: 50
    text: "Add"

    anchors {
      left: pathInput.right
    }

    onClicked: {
      if (pathInput.text !== "") {
        PathListModel.addPathToList(_.selectedPath)
        AppManager.addPathToFileWatcher(_.selectedPath)
      }
    }
  }

  // watcher list
  PathList {
    id: pathList

    width: 600
    height: 200

    anchors {
      top: pathInput.bottom
    }
  }

  // log table
  EventTable {
    id: eventTable

    width: 600
    height: 200

    anchors {
      top: pathList.bottom
    }
  }

  // clear list button
  CustomButton {
    id: clearButton

    width: 100
    height: 50
    text: "Clear"

    anchors {
      left: parent.left
      bottom: parent.bottom
    }

    onClicked: {
      console.log("clear button pressed")
      // clear the table content
    }
  }

  // start wacther button
  CustomButton {
    id: startButton

    width: 100
    height: 50
    text: "Start"

    anchors {
      left: clearButton.right
      bottom: parent.bottom
    }

    onClicked: {
      AppManager.startFileWatcher()
    }
  }

  // stop watcher button
  CustomButton {
    id: stopButton

    width: 100
    height: 50
    text: "Stop"

    anchors {
      left: startButton.right
      bottom: parent.bottom
    }

    onClicked: {
      AppManager.stopFileWatcher()
    }
  }
}
