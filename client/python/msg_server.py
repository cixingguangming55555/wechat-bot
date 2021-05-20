"""
把通过ws接收到的消息直接通过http协议发到一个指定的callback地址。运行在wechat server端可以发消息给client这边的一个server接收器。
"""
import json
import requests
import websocket


class WechatBotMessageServer:
    def __init__(self, ip='127.0.0.1', port=5555, url='https://127.0.0.1:8888/wechat/msg/receiver/'):
        self.ws_url = f'ws://{ip}:{port}'
        self.url = url

    def start(self):
        websocket.enableTrace(True)
        ws = websocket.WebSocketApp(
            self.ws_url,
            on_open=self.on_open,
            on_message=self.on_message,
            on_error=self.on_error,
            on_close=self.on_close
        )
        ws.run_forever()

    def on_open(self, ws):
        print(f'{self.ws_url} opened successfully.')

    def on_message(self, ws, message):
        print(message)
        res = requests.post(self.url, json=json.loads(message))
        print(f'resp: {res.json()}')

    def on_error(self, ws, error):
        print(error)

    def on_close(self, ws):
        print(f'{self.ws_url} closed gracefully.')


wms = WechatBotMessageServer('127.0.0.1', port=5555, url='https://www.httpbin.org/anything')
wms.start()
