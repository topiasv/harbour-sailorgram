import QtQuick 2.1
import Sailfish.Silica 1.0
import harbour.sailorgram.TelegramQml 1.0
import "../../models"
import "../conversation"
import "../../js/TelegramHelper.js" as TelegramHelper

Item
{
    property Context context
    property Dialog dialog
    property Chat chat
    property User user

    id: peeritem

    PeerImage
    {
        id: peerimage
        anchors { left: parent.left; top: parent.top }
        width: peeritem.height
        height: peeritem.height
        context: peeritem.context
        dialog: peeritem.dialog
        chat: peeritem.chat
        user: peeritem.user
    }

    Column
    {
        anchors { left: peerimage.right; top: parent.top; right: parent.right; leftMargin: Theme.paddingSmall }

        Label
        {
            id: lbltitle
            width: parent.width
            elide: Text.ElideRight
            text: TelegramHelper.isChat(dialog) ? chat.title : TelegramHelper.userName(user)
        }

        Row
        {
            height: peeritem.height - lbltitle.contentHeight

            Label
            {
                id: lblinfo
                font.pixelSize: Theme.fontSizeExtraSmall
                color: Theme.highlightColor

                text: {
                    if(TelegramHelper.isChat(dialog))
                        return chat.participantsCount === 1 ? qsTr("%1 member").arg(chat.participantsCount) : qsTr("%1 members").arg(chat.participantsCount);

                    return TelegramHelper.userStatus(user);
                }
            }
        }
    }
}
