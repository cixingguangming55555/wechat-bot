package pro.mickey.wechatpush.service.dto;

import com.alibaba.fastjson.JSON;
import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class WeChatMsgDTO {
    private String id;
    private String wxid;
    private String content;
    private int type;

    public String toJson() {
        return JSON.toJSONString(this);
    }
}
