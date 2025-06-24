#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QListView>
#include <QStringListModel>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(const QString file_path, QWidget *parent=nullptr);
    ~Widget();
private:
    QString m_file_path;
    QStringList m_log_data;
    QListView *m_view;
    QStringListModel *m_model;
    QVBoxLayout *m_v_box;
};
#endif // WIDGET_H
