# -*- coding:utf-8 -*-

import websocket,time,json,requests,os
from bs4 import BeautifulSoup
websocket._logging._logger.level = -99

ip='127.0.0.1'
port=5555

SERVER=f'ws://{ip}:{port}'
HEART_BEAT=5005
RECV_TXT_MSG=1
RECV_TXT_CITE_MSG=49
RECV_PIC_MSG=3
USER_LIST=5000
GET_USER_LIST_SUCCSESS=5001
GET_USER_LIST_FAIL=5002
TXT_MSG=555
PIC_MSG=500
AT_MSG=550
CHATROOM_MEMBER=5010
CHATROOM_MEMBER_NICK=5020
PERSONAL_INFO=6500
DEBUG_SWITCH=6000
PERSONAL_DETAIL=6550
DESTROY_ALL=9999
JOIN_ROOM=10000

# 'type':49 带引用的消息
#########################################################################################
def getid():
	return time.strftime("%Y%m%d%H%M%S")

def output(msg):
	now=time.strftime("%Y-%m-%d %X")
	print(f'[{now}]:{msg}')

################################### HTTP ################################################
def send(uri,data):
	base_data={
		'id':getid(),
		'type':'null',
		'roomid':'null',
		'wxid':'null',
		'content':'null',
		'nickname':'null',
		'ext':'null',
	}
	base_data.update(data)
	url=f'http://{ip}:{port}/{uri}'
	res=requests.post(url,json={'para':base_data},timeout=5)
	return res.json()

def get_member_nick(roomid,wxid):
	# 获取指定群的成员的昵称 或 微信好友的昵称
	uri='api/getmembernick'
	data={
		'type':CHATROOM_MEMBER_NICK,
		'wxid':wxid,
		'roomid':roomid or 'null'
	}
	respJson=send(uri,data)
	return json.loads(respJson['content'])['nick']

def get_personal_info():
	# 获取本机器人的信息
	uri='/api/get_personal_info'
	data={
		'id':getid(),
		'type':PERSONAL_INFO,
		'content':'op:personal info',
		'wxid':'null',
	}
	respJson=send(uri,data)
	print(respJson)

################################### websocket ################################################
def get_chat_nick_p(roomid):
	qs={
		'id':getid(),
		'type':CHATROOM_MEMBER_NICK,
		'content':roomid,
		'wxid':'ROOT',
	}
	return json.dumps(qs)

def debug_switch():
	qs={
		'id':getid(),
		'type':DEBUG_SWITCH,
		'content':'off',
		'wxid':'ROOT',
	}
	return json.dumps(qs)

def handle_nick(j):
	data=j.content
	i=0
	for d in data:
		output(f'nickname:{d.nickname}')
		i+=1

def hanle_memberlist(j):
	data=j.content
	i=0
	for d in data:
		output(f'roomid:{d.roomid}')
		i+=1

def get_chatroom_memberlist():
	qs={
		'id':getid(),
		'type':CHATROOM_MEMBER,
		'wxid':'null',
		'content':'op:list member',
	}
	return json.dumps(qs)

def get_personal_detail(wxid):
	qs={
		'id':getid(),
		'type':PERSONAL_DETAIL,
		'content':'op:personal detail',
		'wxid':wxid,
	}
	return json.dumps(qs)

def send_wxuser_list():
	'''
	获取微信通讯录用户名字和wxid
	获取微信通讯录好友列表
	'''
	qs={
		'id':getid(),
		'type':USER_LIST,
		'content':'user list',
		'wxid':'null',
	}
	return json.dumps(qs)

def handle_wxuser_list(j):
	# i=0
	# for item in j['content']:
	# 	i+=1
	# 	output(f"{i} {item['wxid']} {item['name']}")
	output('启动完成')

###################################################################################
def heartbeat(msgJson):
	output(msgJson['content'])

def on_open(ws):
	#初始化
	ws.send(send_wxuser_list())

def on_error(ws,error):
	output(f'on_error:{error}')

def on_close(ws):
	output("closed")

###################################################################################
def destroy_all():
	qs={
		'id':getid(),
		'type':DESTROY_ALL,
		'content':'none',
		'wxid':'node',
	}
	return json.dumps(qs)

def send_msg(msg,wxid='null',roomid=None,nickname='null'):
	if msg.endswith('tmp.png'):
		msg_type=PIC_MSG
		if roomid:
			wxid=roomid
			roomid=None
			nickname='null'
	elif roomid:
		msg_type=AT_MSG
	else:
		msg_type=TXT_MSG
	if roomid==None:roomid='null'
	qs={
		'id':getid(),
		'type':msg_type,
		'roomid':roomid,
		'wxid':wxid,
		'content':msg,
		'nickname':nickname,
		'ext':'null'
	}
	output(f'发送消息: {qs}')
	return json.dumps(qs)
###################################################################################
def welcome_join(msgJson):
	output(f'收到消息:{msgJson}')
	if '邀请' in msgJson['content']['content']:
		roomid=msgJson['content']['id1']
		nickname=msgJson['content']['content'].split('"')[-2]
		ws.send(send_msg(f'欢迎新进群的老色批',roomid=roomid,wxid='null',nickname=nickname))

def handleMsg_cite(msgJson):
	# 处理带引用的文字消息
	msgXml=msgJson['content']['content'].replace('&amp;','&').replace('&lt;','<').replace('&gt;','>')
	soup=BeautifulSoup(msgXml,'lxml')
	msgJson={
		'content':soup.select_one('title').text,
		'id':msgJson['id'],
		'id1':msgJson['content']['id2'],
		'id2':'wxid_fys2fico9put22',
		'id3':'',
		'srvid':msgJson['srvid'],
		'time':msgJson['time'],
		'type':msgJson['type'],
		'wxid':msgJson['content']['id1']
	}
	handle_recv_msg(msgJson)

def handle_recv_msg(msgJson):
	output(f'收到消息:{msgJson}')
	keyword=msgJson['content'].replace('\u2005','')
	if '@chatroom' in msgJson['wxid']:
		roomid=msgJson['wxid'] #群id
		senderid=msgJson['id1'] #个人id
	else:
		roomid=None
		nickname='null'
		senderid=msgJson['wxid'] #个人id
	nickname=get_member_nick(roomid,senderid)

	if roomid:
		if keyword=='ding':
			ws.send(send_msg('dong',roomid=roomid,wxid=senderid,nickname=nickname))
		elif keyword=='dong':
			ws.send(send_msg('ding',roomid=roomid,wxid=senderid,nickname=nickname))
	else:
		if keyword=='ding':
			ws.send(send_msg('dong',roomid=roomid,wxid=senderid))
		elif keyword=='dong':
			result='ding'
			ws.send(send_msg(result,roomid=roomid,wxid=senderid))

###################################################################################
def on_message(ws,message):
	j=json.loads(message)
	resp_type=j['type']
	# switch结构
	action={
		CHATROOM_MEMBER_NICK:handle_nick,
		PERSONAL_DETAIL:handle_recv_msg,
		AT_MSG:handle_recv_msg,
		DEBUG_SWITCH:handle_recv_msg,
		PERSONAL_INFO:handle_recv_msg,
		TXT_MSG:handle_recv_msg,
		PIC_MSG:handle_recv_msg,
		CHATROOM_MEMBER:hanle_memberlist,
		RECV_PIC_MSG:handle_recv_msg,
		RECV_TXT_MSG:handle_recv_msg,
		RECV_TXT_CITE_MSG:handleMsg_cite,
		HEART_BEAT:heartbeat,
		USER_LIST:handle_wxuser_list,
		GET_USER_LIST_SUCCSESS:handle_wxuser_list,
		GET_USER_LIST_FAIL:handle_wxuser_list,
		JOIN_ROOM:welcome_join,
	}
	action.get(resp_type,print)(j)

# websocket.enableTrace(True)
ws=websocket.WebSocketApp(SERVER,on_open=on_open,on_message=on_message,on_error=on_error,on_close=on_close)
ws.run_forever()
