import websocket
import time
import json

SERVER = 'ws://127.0.0.1:5555'

HEART_BEAT = 5005
RECV_TXT_MSG = 1
RECV_PIC_MSG = 3
USER_LIST = 5000
GET_USER_LIST_SUCCSESS = 5001
GET_USER_LIST_FAIL = 5002
TXT_MSG = 555
PIC_MSG = 500
AT_MSG = 550
CHATROOM_MEMBER = 5010
CHATROOM_MEMBER_NICK = 5020
PERSONAL_INFO = 6500
DEBUG_SWITCH = 6000
PERSONAL_DETAIL = 6550
DESTROY_ALL = 9999


def getid():
    id = int(time.time() * 1000)
    return id


def get_chat_nick_p(roomid):
    qs = {
        'id': getid(),
        'type': CHATROOM_MEMBER_NICK,
        'content': roomid,
        'wxid': 'ROOT',
    }
    s = json.dumps(qs)
    return s


def debug_switch():
    qs = {
        'id': getid(),
        'type': DEBUG_SWITCH,
        'content': 'off',
        'wxid': 'ROOT',
    }
    s = json.dumps(qs)
    return s


def handle_nick(j):
    data = j.content
    i = 0
    for d in data:
        print(d.nickname)
        i += 1


def hanle_memberlist(j):
    data = j.content
    i = 0
    for d in data:
        print(d.roomid)
        i += 1


def get_chatroom_memberlist():
    qs = {
        'id': getid(),
        'type': CHATROOM_MEMBER,
        'wxid': 'null',
        'content': 'op:list member ',
    }
    s = json.dumps(qs)
    return s


def send_at_meg():
    qs = {
        'id': getid(),
        'type': AT_MSG,
        'roomid': 'Your roomid', # not null
        'content': '我能吞下玻璃而不伤身体',
        'nickname': '[微笑]Python',
    }
    s = json.dumps(qs)
    return s


def destroy_all():
    qs = {
        'id': getid(),
        'type': DESTROY_ALL,
        'content': 'none',
        'wxid': 'node',
    }
    s = json.dumps(qs)
    return s


def send_pic_msg():
    qs = {
        'id': getid(),
        'type': PIC_MSG,
        'content': 'C:\\Users\\14988\\Desktop\\temp\\2.jpg',
        'wxid': '获取的wxid',
    }
    s = json.dumps(qs)
    return s


def get_personal_detail():
    qs = {
        'id': getid(),
        'type': PERSONAL_DETAIL,
        'content': 'op:personal detail',
        'wxid': '获取的wxid',
    }
    s = json.dumps(qs)
    return s


def get_personal_info():
    qs = {
        'id': getid(),
        'type': PERSONAL_INFO,
        'content': 'op:personal info',
        'wxid': 'ROOT',
    }
    s = json.dumps(qs)
    return s


def send_txt_msg():
    '''
    发送消息给好友
    '''
    qs = {
        'id': getid(),
        'type': TXT_MSG,
        'content':'【汽车新闻】\n1、2月中国汽车经销商库存预警指数为81.2%\n  https://auto.sina.com.cn/news/hy/2020-03-02/detail-iimxyqvz7206147.shtml\n2、2020年1月合资品牌插混车型上牌量超自主 今年或将全面超越\n  https://auto.sina.com.cn/news/zz/2020-03-02/detail-iimxyqvz7204399.shtml\n3、2月汽车经销商库存预警指数81.2% 同比上升27.7%\n  https://auto.sina.com.cn/news/hy/2020-03-02/detail-iimxyqvz7212598.shtml\n4、车谭|推进数字化转型 比亚迪与西门子达成战略合作\n  https://auto.sina.com.cn/news/hy/2020-03-02/detail-iimxxstf5752750.shtml\n5、业务量下滑，有员工被停工待岗，优信称经营遇到困难\n  https://auto.sina.com.cn/news/zz/2020-03-02/detail-iimxyqvz7183264.shtml\n6、外媒：中国电动车制造商正纷纷转向磷酸铁锂电池 以大幅降低成本\n  https://auto.sina.com.cn/news/hy/2020-03-02/detail-iimxyqvz7194871.shtml\n7、苹果自动驾驶项目裁员190人\n  https://auto.sina.com.cn/news/zz/2020-03-02/detail-iimxxstf5750692.shtml\n8、二手车复工率不足五成  车商盼消除壁垒提振消费\n  https://auto.sina.com.cn/news/zz/2020-03-02/detail-iimxxstf5742747.shtml\n9、车谭|天天拍车：2月份二手车交易逐渐回暖\n  https://auto.sina.com.cn/news/hy/2020-03-02/detail-iimxyqvz7187012.shtml\n10、因“货不对版”特斯拉停止全国交付？ 特斯拉：并未收到相关消息\n  https://auto.sina.com.cn/news/hy/2020-03-02/detail-iimxyqvz7171968.shtml\n',  # 文本消息内容
        'wxid': '获取的wxid'   # wxid,
    }
    s = json.dumps(qs)
    return s


def send_wxuser_list():
    '''
    获取微信通讯录用户名字和wxid
    '''
    qs = {
        'id': getid(),
        'type': USER_LIST,
        'content': 'user list',
        'wxid': 'null',
    }
    s = json.dumps(qs)
    return s


def handle_wxuser_list(j):
    j_ary = j.content
    i = 0
    for item in j_ary:
        i += 1
        id = item.wxid
        m = id.find('@')
        if m != -1:
            print(i, item.wxid, item.name)


def handle_recv_msg(j):
    print(j)


def heartbeat(j):
    print(j.content)


def on_open(ws):
    ws.send(send_wxuser_list())     # 获取微信通讯录好友列表
    ws.send(send_txt_msg())     # 向你的好友发送微信文本消息


def on_message(ws, message):
    print(ws)
    j = json.loads(message)
    resp_type = j.type
    # switch结构
    action = {
        CHATROOM_MEMBER_NICK: handle_nick,
        PERSONAL_DETAIL: print,
        AT_MSG: print,
        DEBUG_SWITCH: print,
        PERSONAL_INFO: print,
        TXT_MSG: print,
        PIC_MSG: print,
        CHATROOM_MEMBER: hanle_memberlist,
        RECV_PIC_MSG: handle_recv_msg,
        RECV_TXT_MSG: handle_recv_msg,
        HEART_BEAT: heartbeat,
        GET_USER_LIST_SUCCSESS: handle_wxuser_list,
        GET_USER_LIST_FAIL: handle_wxuser_list,
    }
    action.get(resp_type, print)(j)


def on_error(ws, error):
    print(ws)
    print(error)


def on_close(ws):
    print(ws)
    print("closed")


websocket.enableTrace(True)
ws = websocket.WebSocketApp(SERVER,
                            on_open=on_open,
                            on_message=on_message,
                            on_error=on_error,
                            on_close=on_close)
ws.run_forever()
