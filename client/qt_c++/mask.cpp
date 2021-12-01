#include "mask.h"
#include <QMovie>

Mask::Mask(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QMovie * mov = new QMovie(":/WeChatBot/loading.gif");
	ui.label->setMovie(mov);
	mov->start();
}

Mask::~Mask()
{
}
