#include "wechatbot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WeChatBot w;
	w.show();
	return a.exec();
}
