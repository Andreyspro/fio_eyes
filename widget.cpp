#include <QListView>
#include <iostream>
#include <fstream>
#include <string>
#include "widget.h"

Widget::Widget(QString file_path, QWidget *parent)
    : QWidget(parent),
      m_file_path(file_path)
{
    m_view = new QListView();
    m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
    std::ifstream log_file(file_path.toStdString(), std::ios::in);
    if (!log_file)
    {
        qDebug() << "Open file failed.\n";
        exit(1);
    }
    qDebug() << "File opened ok.\n";
    size_t i = 0;
    for (std::string line; std::getline(log_file, line);)
    {
        ++i;
        m_log_data << QString::fromStdString(std::to_string(i) + ". " + line);
    }

    m_model = new QStringListModel(m_log_data, this);
    m_view->setModel(m_model);

    m_v_box = new QVBoxLayout();
    m_v_box->addWidget(m_view);
    setLayout(m_v_box);
}

Widget::~Widget() {}

