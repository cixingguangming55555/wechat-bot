package io.uouo.wechatbot.common;

import io.uouo.wechatbot.client.WechatBotClient;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.net.URISyntaxException;

/**
 * @author: [青衫] 'QSSSYH@QQ.com'
 * @Date: 2021-03-26 8:57
 * @Description: < 描述 >
 */
@Configuration
public class WechatBotConfig {

    /** 微信bot 链接地址*/
    @Value("${wechatBot.url}")
    private String wechatBotUrl;

    /** 初始化 */
    @Bean
    public WechatBotClient initWechatBotClient() throws URISyntaxException {
        WechatBotClient botClient = new WechatBotClient(wechatBotUrl);
        // 建立连接
        botClient.connect();
        return botClient;
    }

}
