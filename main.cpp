#include "widget.h"

#include <QApplication>
#include <filesystem>

int main(int argc, char *argv[])
{
    QString file_path;
    if (argc >= 2)
    {
        file_path = argv[1];
        if (!std::filesystem::exists(file_path.toStdString()))
        {
            qDebug() << "File '" << file_path << "' not exists!";
            exit(1);
        }
    }
    else
    {
        qDebug() << "No argument 1 - file_name.";
        exit(1);
    }
    qDebug() << "Filename is '" << file_path << "'";
    QApplication a(argc, argv);
    Widget window(file_path);
    window.setWindowTitle("FIO eyes");
    window.resize(800, 600);
    window.show();
    return a.exec();
}
