import QtQuick
import QtMultimedia
import QtQuick.Controls
import QtQuick.Layouts
import Qt.labs.platform
import Qt.labs.qmlmodels
import com.mycompany.CsvClass

Window {
    width: 700
    height: 500
    visible: true
    title: qsTr("Task 2")
    color: "black"

    CsvClass{
        id:cppCsvClass;
    }

    Component.onCompleted: {
        camera.start();
    }

    property bool preview: false
    property bool showViewBtn: false

    GridLayout {
        id:grid
        rows: 2
        columns: 4
        anchors.fill: parent

        CaptureSession {
            id: captureSession
            camera: Camera {
                id: camera
            }
            imageCapture: ImageCapture {
                id: imageCapture
            }
            videoOutput: viewfinder
        }

        Rectangle{
            width:500
            height: 300
            color:"black"
            Layout.row: 0
            Layout.column: 0
            Layout.columnSpan: 2
            VideoOutput {
                id: viewfinder
                anchors.fill:parent
                visible: !preview
            }
            Image {
                id: name
                fillMode: Image.PreserveAspectFit
                anchors.fill:parent
                source: imageCapture.preview
                visible: preview
            }
        }
        Button {
            text: "Capture Image"
            onClicked: {
                imageCapture.captureToFile("");
                showViewBtn = true
            }
            Layout.maximumHeight: 150
            Layout.maximumWidth: Layout.width/2
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.row: 1
            Layout.column: 0
        }
        Button{
            visible: showViewBtn
            text: "View Image"
            onClicked: {
                preview = !preview
            }
            Layout.maximumHeight: 150
            Layout.maximumWidth: Layout.width/2
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.row: 1
            Layout.column: 1
        }
        Rectangle{
            width: 400
            height: 400
            color:"black"
            Layout.row: 0
            Layout.column: 2
            Text{
                text:cppCsvClass.csvFile;
                color:"white"
            }
        }
    }

}
