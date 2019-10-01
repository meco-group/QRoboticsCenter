#include "qprintstitcher.h"

QPrintStitcher::QPrintStitcher(QObject *parent) : QObject(parent)
{
    // do nothing
}

bool QPrintStitcher::stitch(QString part, int size)
{
    _stream += part.left(size).remove('\n'); //append new string without line feeds
    if(!_stream.isEmpty()){
        _lines.append(_stream.split('\r',QString::SkipEmptyParts)); //split the string at CRs
        if(_stream[_stream.size()-1] != '\r') {
            _stream = _lines.last();
            _lines.removeLast();
        } else {
            _stream.clear();
        }
    }

    return hasLine();
}

bool QPrintStitcher::hasLine()
{
    return (_lines.size() > 0);
}

QString QPrintStitcher::getLine()
{
    if(!_lines.isEmpty()) {
        return _lines.takeFirst();
    } else {
        return "";
    }
}
