package pro.mickey.wechatpush.service;

import lombok.extern.slf4j.Slf4j;
import org.java_websocket.client.WebSocketClient;
import org.java_websocket.handshake.ServerHandshake;
import pro.mickey.wechatpush.service.dto.WeChatMsgDTO;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.Date;

@Slf4j
public class WeChatPushService extends WebSocketClient {


    public WeChatPushService(String url) throws URISyntaxException {
        super(new URI(url));
    }

    @Override
    public void onOpen(ServerHandshake serverHandshake) {
        log.info("正在打开链接....");
    }

    @Override
    public void onMessage(String s) {
        log.info("收到消息：" + s);
    }

    @Override
    public void onClose(int i, String s, boolean b) {
        log.info("关闭链接");
    }

    @Override
    public void onError(Exception e) {
        log.info("异常");
    }

    public void sendMsg(String wxid, String text) {
        String id = String.valueOf(new Date().getTime());
        String json = WeChatMsgDTO.builder()
                .content(text)
                .wxid(wxid)
                .type(555)
                .id(id)
                .build()
                .toJson();
        log.info("sendMsg:" + json);
        sendMsg(json);
    }

    public void getContact() {
        String id = String.valueOf(new Date().getTime());
        String json = WeChatMsgDTO.builder()
                .content("op:list member")
                .wxid("null")
                .type(5010)
                .id(id)
                .build()
                .toJson();
        log.info("getContact:" + json);
        sendMsg(json);
    }

    private void sendMsg(String json) {
        try {
            send(json);
        } catch (Exception e) {
            /**
             * 这块我本来用于发送微信失败补偿邮件
             */
        }
    }
}
