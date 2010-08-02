#ifndef QMLJSCONTEXTCRUMBLEPATH_H
#define QMLJSCONTEXTCRUMBLEPATH_H

#include <utils/crumblepath.h>
#include <QStringList>

namespace QmlJSInspector {
namespace Internal {

class ContextCrumblePath : public Utils::CrumblePath
{
    Q_OBJECT
public:
    ContextCrumblePath(QWidget *parent = 0);
    virtual ~ContextCrumblePath();

public slots:
    void updateContextPath(const QStringList &path);

};

} // namespace Internal
} // namespace QmlJSInspector

#endif // QMLJSCONTEXTCRUMBLEPATH_H
