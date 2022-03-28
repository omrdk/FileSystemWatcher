import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


/**
  List model, keeps paths that can be watched.
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

      implicitWidth: listView.width

      implicitHeight: 30

      RowLayout {
        id: rowLayout

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
          height: 30

          text: "Remove"

          onClicked: {
            AppManager.removePathFromMap(index)

            PathListModel.removePathFromList(index)
          }
        }
      }
    }
  }

  Text {
    id: label

    anchors.bottom: listView.top

    text: "Watched paths"

    font.pointSize: 16
  }

  ListView {
    id: listView
    required model

    anchors.fill: parent

    clip: true

    model: PathListModel

    delegate: contactDelegate
  }
}
