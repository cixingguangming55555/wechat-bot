#pragma once

#include <QWidget>
#include "ui_mask.h"

class Mask : public QWidget
{
	Q_OBJECT

public:
	Mask(QWidget *parent = Q_NULLPTR);
	~Mask();

private:
	Ui::Mask ui;
};
