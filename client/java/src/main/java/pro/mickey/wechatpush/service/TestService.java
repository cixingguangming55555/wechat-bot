package pro.mickey.wechatpush.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

@Service
public class TestService {

    @Autowired
    private WeChatPushService weChatService;

    @Scheduled(fixedRate = 1000 * 60 * 10)
    public void showNews() {
        weChatService.sendMsg("你的测试微信", "我用Java发送的微信！");
        weChatService.getContact();
    }
}
