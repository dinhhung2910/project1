#ifndef SHOWDETAIL_H
#define SHOWDETAIL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include "inkdrop.h"

class ShowDetail : public QTableWidget
{
public:
    ShowDetail();

    void setInkDrop(InkDrop* inkdrop);

    // Cập nhật thông tin về giọt mực để đưa vào bảng
    void updateContent();

private:
    InkDrop* inkdrop;
};

#endif // SHOWDETAIL_H
