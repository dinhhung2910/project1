#include "showdetail.h"
#include "singledrop.h"

ShowDetail::ShowDetail()
{
    //this = new QTableWidget(0, 2);
    this->setRowCount(0);
    this->setColumnCount(6);

    QStringList labels;
    labels << ("ID") << ("x") << ("y") << ("Tốc độ") << ("Góc") << ("SChọn");

    this->setHorizontalHeaderLabels(labels);

    this->setStyleSheet("color: #374353; font-family: 'SF Pro Text'; selection-background-color: #25bea0;");
    this->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
    this->verticalHeader()->hide();
    this->setShowGrid(false);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);


    //this->setItem(row, 1, sizeItem);
}

void ShowDetail::setInkDrop(InkDrop* inkdrop) {
    this->inkdrop = inkdrop;
}

void ShowDetail::updateContent() {

    SingleDrop* single = inkdrop->getSingleDrop();
    int n = inkdrop->getAmount();
    this->clearContents();

    for (int i=0; i<n; i++) {
        int row = this->rowCount();
        this->insertRow(row);
        this->setItem(row, 0, new QTableWidgetItem("Hello"));
    }

}
