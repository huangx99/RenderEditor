#pragma once

#include <QtGui/QPixmap>

#include <QtNodes/NodeData>

using QtNodes::NodeData;
using QtNodes::NodeDataType;


class REPixmapData : public NodeData
{
public:
    REPixmapData() {}

    REPixmapData(QPixmap const &pixmap)
        : _pixmap(pixmap)
    {}

    NodeDataType type() const override
    {
        //       id      name
        return {"image", "image"};
    }

    QPixmap pixmap() const { return _pixmap; }

private:
    QPixmap _pixmap;
};
