# pip install websocket-client

import json
import websocket
import _thread
import time

# 定义常量
HEART_BEAT = 5005
RECV_TXT_MSG = 1
RECV_PIC_MSG = 3
USER_LIST = 5000
GET_USER_LIST_SUCCESS = 5001
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
NEW_FRIEND_REQUEST = 37  # 微信好友请求消息
AGREE_TO_FRIEND_REQUEST = 10000  # 同意微信好友请求消息
ATTATCH_FILE = 5003

def on_message(ws, message):
    # 处理接收到的消息
    print(message)
    j = json.loads(message)
    type = j.get('type')
    if type == CHATROOM_MEMBER_NICK:
        pass  # 处理具体的逻辑
    elif type == PERSONAL_DETAIL:
        pass
    # ... 处理其他消息类型
    else:
        pass

def on_error(ws, error):
    print(error)

def on_close(ws, close_status_code, close_msg):
    print("### closed ###")

def on_open(ws):
    def run(*args):
        # 发送数据
        # ws.send(json.dumps(...))
        pass
    _thread.start_new_thread(run, ())


if __name__ == "__main__":
    websocket.enableTrace(True)
    ws = websocket.WebSocketApp("ws://127.0.0.1:5555",
                                on_message=on_message,
                                on_error=on_error,
                                on_close=on_close)
    ws.on_open = on_open
    ws.run_forever()
