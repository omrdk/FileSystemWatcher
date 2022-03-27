import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


/**
  It contains watched paths
  */
Item {
  id: root

  //* PROPERTIES DECLARATIONS

  //* SIGNALS
  QtObject {
    id: _
  }

  //* CHILD ITEMS
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
      width: listView.width
      height: 50

      RowLayout {
        width: parent.width

        TextField {
          id: pathDelegate

          Layout.fillWidth: true

          text: model.path

          background: Rectangle {
            id: background
            anchors.fill: parent

            radius: 5
            color: theme.backgroundColor
          }
          onEditingFinished: model.path = text
        }

        CustomButton {
          id: removeButton

          width: 100
          height: 50

          text: "Remove"

          onClicked: {
            console.log("item removed from list")
            PathListModel.removePathFromList(index)
            // send event to table
          }
        }
      }
    }
  }

  ListView {
    id: listView
    required model

    anchors.fill: parent

    clip: true

    model: PathListModel

    delegate: contactDelegate
  }

  //* CONNECTIONS

  //* SLOTS (onSignalFunctions)

  //* FUNCTIONS
}
