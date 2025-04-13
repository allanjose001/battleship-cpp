#ifndef BOARDCELL_H
#define BOARDCELL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QGraphicsEffect>

class BoardCell : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    //cada celula é composta por linha, coluna e sua respectiva textura
    BoardCell(int row, int col, const QPixmap& pixmap, QGraphicsItem* parent = nullptr);
    void handleCellClick(int row, int col);

    int getRow() const { return row; }
    int getCol() const { return col; }

    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override; //função do clique

signals:
    void cellClicked(int row, int col);

private:
    int row, col;

    //dos efeitos
    QGraphicsColorizeEffect* highlightEffect = nullptr;

};

#endif // BOARDCELL_H
