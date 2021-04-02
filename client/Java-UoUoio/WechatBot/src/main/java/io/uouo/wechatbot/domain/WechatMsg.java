package io.uouo.wechatbot.domain;

/**
 * @author: [青衫] 'QSSSYH@QQ.com'
 * @Date: 2021-03-16 18:48
 * @Description: < 描述 >
 */
public class WechatMsg {
    /** 消息id */
    private String id;
    /** 接收消息人的 微信原始id */
    private String wxid;
    /** 消息内容 */
    private String content;
    /** 群组id 群组内发送@消息时使用 */
    private String roomid;
    /** 发送消息类型 */
    private Integer type;
    /** 昵称 */
    private String nickname;
    /** 图片消息的图片地址(绝对路径 D:/xxx.jpg) */
    private String path;

    private String ext;


    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getWxid() {
        return wxid;
    }

    public void setWxid(String wxid) {
        this.wxid = wxid;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getRoomid() {
        return roomid;
    }

    public void setRoomid(String roomid) {
        this.roomid = roomid;
    }

    public Integer getType() {
        return type;
    }

    public void setType(Integer type) {
        this.type = type;
    }

    public String getNickname() {
        return nickname;
    }

    public void setNickname(String nickname) {
        this.nickname = nickname;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }

    public String getExt() {
        return ext;
    }

    public void setExt(String ext) {
        this.ext = ext;
    }
}
