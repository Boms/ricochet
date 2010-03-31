#include "main.h"
#include "HomeScreen.h"
#include <QBoxLayout>
#include <QLabel>
#include <QToolButton>

HomeScreen::HomeScreen(QWidget *parent)
	: QWidget(parent)
{
	QBoxLayout *layout = new QVBoxLayout(this);

	QBoxLayout *topLayout = new QHBoxLayout;
	layout->addLayout(topLayout);

	createAvatar();
	topLayout->addWidget(avatar);

	topLayout->addLayout(createButtons());

	topLayout->addStretch();
	layout->addStretch();
}

void HomeScreen::createAvatar()
{
	avatar = new QLabel;
	avatar->setAlignment(Qt::AlignTop | Qt::AlignLeft);

	QImage image = config->value("core/avatar").value<QImage>();
	if (!image.isNull())
		avatar->setPixmap(QPixmap::fromImage(image));
	else
		avatar->setPixmap(QPixmap(":/graphics/avatar-placeholder.png"));
}

QLayout *HomeScreen::createButtons()
{
	QBoxLayout *layout = new QVBoxLayout;

	QToolButton *btn = new QToolButton;
	btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btn->setText(tr("Add New Contact"));
	btn->setIcon(QIcon(":/icons/user-add"));
	btn->setAutoRaise(true);
	layout->addWidget(btn);

	btn = new QToolButton;
	btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btn->setText(tr("Change Avatar"));
	btn->setIcon(QIcon("C:/Users/John/Documents/Icons/Fugue/icons-shadowless/image--pencil.png"));
	btn->setAutoRaise(true);
	layout->addWidget(btn);

	layout->addStretch();

	return layout;
}
