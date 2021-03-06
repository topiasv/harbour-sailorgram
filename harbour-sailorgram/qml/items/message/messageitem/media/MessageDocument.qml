import QtQuick 2.1
import Sailfish.Silica 1.0
import harbour.sailorgram.TelegramQml 1.0
import "../../../../models"
import "../../../../components"
import "../../../../components/message"
import "../../../../js/TelegramHelper.js" as TelegramHelper
import "../../../../js/ColorScheme.js" as ColorScheme

MessageMediaItem
{
    property FileLocation fileLocation: context.telegram.locationOfDocument(message.media.document)

    id: messagedocument
    contentWidth: imgpreview.width + Math.max(lblinfo.calculatedWidth, lblmimesize.calculatedWidth) + Theme.paddingMedium
    contentHeight: row.height

    Row
    {
        id: row
        width: parent.width
        height: Math.max(info.height, imgpreview.height)
        spacing: Theme.paddingMedium

        MessageThumbnail
        {
            id: imgpreview
            height: Theme.iconSizeMedium
            width: Theme.iconSizeMedium
            anchors.verticalCenter: info.verticalCenter
            source: fileHandler.thumbPath

            Rectangle {
                border.width: 1
                border.color: ColorScheme.colorizeLink(message, context)
                anchors { fill: parent; margins: -Theme.paddingSmall }
                color: "transparent"
            }
        }

        Column
        {
            id: info
            width: parent.width - imgpreview.width
            spacing: Theme.paddingSmall

            ResizableLabel
            {
                id: lblinfo
                width: parent.width - Theme.paddingSmall
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: Theme.fontSizeExtraSmall
                text: fileHandler.fileName
                color: ColorScheme.colorizeText(message, context)
                wrapMode: Text.NoWrap
                elide: Text.ElideRight
            }

            ResizableLabel
            {
                id: lblmimesize
                width: parent.width - Theme.paddingSmall
                color: ColorScheme.colorizeText(message, context)
                font.pixelSize: Theme.fontSizeExtraSmall
                text: TelegramHelper.formatBytes(mediaSize, 2) + " " + message.media.document.mimeType
                wrapMode: Text.NoWrap
                elide: Text.ElideRight
            }

            MessageMediaProgressBar
            {
                id: progressbar
                width: parent.width - Theme.paddingSmall
                barHeight: Theme.paddingSmall
                barColor: ColorScheme.colorizeText(message, context)
                border { color: ColorScheme.colorizeLink(message, context); width: 1 }
                visible: messagedocument.transferInProgress
                value: messagedocument.fileHandler.progressPercent
            }
        }
    }
}
