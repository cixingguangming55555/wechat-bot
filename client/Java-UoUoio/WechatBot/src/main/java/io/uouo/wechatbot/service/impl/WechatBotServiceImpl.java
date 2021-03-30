package io.uouo.wechatbot.service.impl;

import com.alibaba.fastjson.JSONObject;
import io.uouo.wechatbot.client.WechatBotClient;
import io.uouo.wechatbot.common.WechatBotCommon;
import io.uouo.wechatbot.domain.WechatMsg;
import io.uouo.wechatbot.service.WechatBotService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @author: [青衫] 'QSSSYH@QQ.com'
 * @Date: 2021-03-18 20:55
 * @Description: <  >
 */
@Service
public class WechatBotServiceImpl implements WechatBotService, WechatBotCommon {


    /** 注入微信客户端 */
    @Autowired
    private WechatBotClient wechatBotClient;

    /**
     * 描述: 发送文字消息
     *
     * @param wechatMsg 微信消息体
     * @return void
     * @Author 青衫 [2940500@qq.com]
     * @Date 2021-3-18
     */
    @Override
    public void sendTextMsg(WechatMsg wechatMsg) {
        // 消息类型
        wechatBotClient.sendMsgUtil(TXT_MSG, wechatMsg);
    }

    /**
     * 描述: 发送图片消息
     *
     * @param wechatMsg 微信消息体
     * @return void
     * @Author 青衫 [2940500@qq.com]
     * @Date 2021-3-18
     */
    @Override
    public void sendImgMsg(WechatMsg wechatMsg) {
        wechatBotClient.sendMsgUtil(PIC_MSG, wechatMsg);
    }

    /**
     * 描述: 群组内发送@指定人消息
     *
     * @param wechatMsg
     * @return io.uouo.wechatbot.common.util.AjaxResult
     * @Author 青衫 [2940500@qq.com]
     * @Date 2021-3-26
     */
    @Override
    public void sendATMsg(WechatMsg wechatMsg) {
        wechatBotClient.sendMsgUtil(AT_MSG, wechatMsg);
    }


    /**
     * 描述: 获取微信群组,联系人列表
     *
     * @param
     * @return io.uouo.wechatbot.common.util.AjaxResult
     * @Author 青衫 [2940500@qq.com]
     * @Date 2021-3-29
     */
    @Override
    public void getWeChatUserList() {
        WechatMsg wechatMsg = new WechatMsg();
        wechatMsg.setWxid(NULL_MSG);
        wechatMsg.setContent(CONTACT_LIST);
        wechatBotClient.sendMsgUtil(USER_LIST, wechatMsg);
    }

    /**
     * 描述:
     *
     * @param
     * @return void
     * @Author 青衫 [2940500@qq.com]
     * @Date 2021-3-29
     */
    @Override
    public void getPersonalDetail(String wxid) {
        WechatMsg wechatMsg = new WechatMsg();
        wechatMsg.setWxid(wxid);
        wechatMsg.setContent(PERSONAL_DETAIL_CONTENT);
        wechatBotClient.sendMsgUtil(PERSONAL_DETAIL, wechatMsg);
    }
}
