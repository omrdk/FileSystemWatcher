import QtQuick


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

      Row {

        Rectangle {
          id: pathDelegate

          width: 500
          height: 50
          color: theme.backgroundColor

          Text {
            id: path

            //required property string path
            //required property string imagePath
            anchors {
              verticalCenter: parent.verticalCenter
            }

            text: model.path // + model.imagePath

            // elide: Text.ElideRight
          }
        }

        CustomButton {
          id: removeButton

          width: 100
          height: 50

          text: "Remove"

          onClicked: {
            console.log("item removed from list")
            // delete from list
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

    model: PathListModel

    delegate: contactDelegate

    //    highlight: Rectangle {
    //      color: "lightsteelblue"
    //      radius: 5
    //    }
    //    focus: true
  }

  //* CONNECTIONS

  //* SLOTS (onSignalFunctions)

  //* FUNCTIONS
  ListModel {
    id: dakmodal
    ListElement {
      imagePath: "2.jpg"
      imageName: "house"
    }
    ListElement {
      imagePath: "1.jpg"
      imageName: "flower"
    }

    ListElement {
      imagePath: "3.jpg"
      imageName: "water"
    }
  }
}
