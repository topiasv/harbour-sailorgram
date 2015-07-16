import QtQuick 2.1
import Sailfish.Silica 1.0
import harbour.sailorgram.TelegramQml 1.0
import "../models"
import "../components"
import "../js/Settings.js" as Settings

Page
{
    property Context context

    id: connectionpage
    allowedOrientations: defaultAllowedOrientations

    onStatusChanged: {
        if(connectionpage.status !== PageStatus.Active)
            return;

        var phonenumber = Settings.get("phonenumber");

        if(phonenumber === false) {
            pageStack.replace(Qt.resolvedUrl("PhoneNumberPage.qml"), { "context": connectionpage.context });
            return;
        }

        context.telegram.phoneNumber = phonenumber;
    }

    Timer
    {
        id: timlogin
        interval: 30000 // 30s
        running: true
    }

    Timer
    {
        id: timdisplaystatus
        interval: context.heartbeat.interval / 2
        running: true
    }

    Row
    {
        anchors { top: parent.top; right: parent.right }
        height: csitem.height

        Label
        {
            text: qsTr("Telegram Status")
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignLeft
            anchors.verticalCenter: csitem.verticalCenter
        }

        ConnectionStatus
        {
            id: csitem
            context: connectionpage.context
            forceActive: timdisplaystatus.running
        }
    }

    Label
    {
        anchors { bottom: indicator.top; bottomMargin: Theme.paddingMedium }
        width: parent.width
        font.pixelSize: Theme.fontSizeExtraLarge
        horizontalAlignment: Text.AlignHCenter
        color: Theme.secondaryHighlightColor
        text: qsTr("Connecting")
    }

    BusyIndicator
    {
        id: indicator
        anchors.centerIn: parent
        size: BusyIndicatorSize.Large
        running: true
    }

    Button
    {
        anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: Theme.paddingLarge }
        text: qsTr("Login Again")
        visible: !timlogin.running
    }
}
