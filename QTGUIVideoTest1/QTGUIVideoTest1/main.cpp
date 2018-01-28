#include "QTGUIVideoTest1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTGUIVideoTest1 w;
	w.show();
	return a.exec();
}
