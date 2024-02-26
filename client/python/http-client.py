# pip install requests

import requests
import json
from datetime import datetime

url = 'http://127.0.0.1:5555'
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
ATTATCH_FILE = 5003

def get_id():
    return str(int(datetime.now().timestamp() * 1000))

def send_at_msg():
    jpara = {
        'id': get_id(),
        'type': AT_MSG,
        'roomid': '23023281066@chatroom',
        'wxid': 'zhanghua_cd',
        'content': 'at msg test,hello world，真的有一套',
        'nickname': '老张',
        'ext': 'null'
    }
    response = requests.post(url + '/api/sendatmsg', json={'para': jpara})
    return response.json()

def send_pic():
    jpara = {
        'id': get_id(),
        'type': PIC_MSG,
        'wxid': '23023281066@chatroom',
        'roomid': 'null',
        'content': 'C:\\tmp\\2.jpg',
        'nickname': "null",
        'ext': 'null'
    }
    response = requests.post(url + '/api/sendpic', json={'para': jpara})
    return response.json()

def get_member_nick(wx_id, roomid):
    jpara = {
        'id': get_id(),
        'type': CHATROOM_MEMBER_NICK,
        'wxid': 'zhanghua_cd',
        'roomid': '23023281066@chatroom',
        'content': 'null',
        'nickname': "null",
        'ext': 'null'
    }
    response = requests.post(url + '/api/getmembernick', json={'para': jpara})
    return response.json()

def get_memberid():
    jpara = {
        'id': get_id(),
        'type': CHATROOM_MEMBER,
        'wxid': 'null',
        'content': 'op:list member'
    }
    response = requests.post(url + '/api/getmemberid', json={'para': jpara})
    return response.json()

def get_contact_list():
    jpara = {
        'id': get_id(),
        'type': USER_LIST,
        'roomid': 'null',
        'wxid': 'null',
        'content': 'null',
        'nickname': 'null',
        'ext': 'null'
    }
    response = requests.post(url + '/api/getcontactlist', json={'para': jpara})
    return response.json()

def get_chatroom_member_list():
    jpara = {
        'id': get_id(),
        'type': CHATROOM_MEMBER,
        'roomid': 'null',
        'wxid': 'null',
        'content': 'null',
        'nickname': 'null',
        'ext': 'null'
    }
    response = requests.post(url + '/api/get_charroom_member_list', json={'para': jpara})
    return response.json()

def send_txt_msg():
    jpara = {
        'id': get_id(),
        'type': TXT_MSG,
        'wxid': '23023281066@chatroom',
        'roomid': 'null',
        'content': 'hello word',
        'nickname': "null",
        'ext': 'null'
    }
    response = requests.post(url + '/api/sendtxtmsg', json={'para': jpara})
    return response.json()

def send_attatch():
    jpara = {
        'id': get_id(),
        'type': ATTATCH_FILE,
        'wxid': '23023281066@chatroom',
        'roomid': 'null',
        'content': 'C:\\tmp\\log.7z',
        'nickname': "null",
        'ext': 'null'
    }
    response = requests.post(url + '/api/sendattatch', json={'para': jpara})
    return response.json()

def main():
    response = get_contact_list()
    # response = get_chatroom_member_list()
    # response = send_txt_msg()
    # response = get_member_nick("zhanghua_cd", "23023281066@chatroom")
    # response = send_at_msg()
    # response = send_attatch()
    # response = get_member_nick()
    # print(response)
    # await send_destroy()
    # await refresh_memberlist()
    # print("test begin")
    # response = send_destroy()
    # response = send_attatch()
    print(json.dumps(response, indent=2))

if __name__ == '__main__':
    main()
