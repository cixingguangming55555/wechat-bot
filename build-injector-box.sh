#!/usr/bin/env bash
mkdir docker_buiding || true
# update injector-box
if [ ! -d docker_buiding/injector-box ]; then
    git clone https://github.com/ChisBread/injector-box docker_buiding/injector-box
else
    cd docker_buiding/injector-box
    git pull
    cd -
fi
if [ ! -d docker_buiding/injector-box/target ]; then
    git clone https://github.com/ChisBread/wechat-box docker_buiding/injector-box/target
else
    cd docker_buiding/injector-box/target
    git pull
    cd -
fi
if [ ! -f docker_buiding/injector-box/target/root/WeChatSetup-v3.6.0.18.exe ]; then
    wget -P docker_buiding/injector-box/target/root https://github.com/ChisBread/wechat-box/releases/download/binary-resource/WeChatSetup-v3.6.0.18.exe
fi

cp funtool/funtool_3.6.0.18-1.0.0015非注入版.exe docker_buiding/injector-box/root/bin/
cp funtool/inject-dll docker_buiding/injector-box/root/bin/
cp funtool/inject-monitor docker_buiding/injector-box/root/bin/

cd docker_buiding/injector-box
# docker rm -f wechat-bot
# docker rmi -f chisbread/wechat-bot:1.0
sudo docker build -t chisbread/wechat-bot:1.0 .
# sudo docker run -itd --name wechat-bot  \
#     -e HOOK_PROC_NAME=WeChat \
#     -e TARGET_AUTO_RESTART="yes" \
#     -e INJ_CONDITION="[ \"\`ps -aux | grep funtool | grep -v grep\`\" != '' ] && exit 0" \
#     -e TARGET_CMD=wechat-start \
#     -p 8080:8080 -p 5555:5555 -p 5900:5900 \
#     --add-host=dldir1.qq.com:127.0.0.1 \
#     chisbread/wechat-bot:1.0

# sudo docker run -itd --name wechat-service --rm  \
#     -e HOOK_PROC_NAME=WeChat \
#     -e HOOK_DLL=auto.dll \
#     -e TARGET_AUTO_RESTART="yes" \
#     -e INJ_CONDITION="[ \"\`sudo netstat -tunlp | grep 5555\`\" != '' ] && exit 0 ; sleep 5 ; curl 'http://127.0.0.1:8680/hi' 2>/dev/null | grep -P 'code.:0'" \
#     -e TARGET_CMD=wechat-start \
#     -p 8080:8080 -p 5555:5555 -p 5900:5900 \
#     --add-host=dldir1.qq.com:127.0.0.1 \
#     chisbread/wechat-service:latest
