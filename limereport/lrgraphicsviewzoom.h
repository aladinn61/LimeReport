#ifndef GRAPHICSVIEWZOOM_H
#define GRAPHICSVIEWZOOM_H

#include <QObject>
#include <QGraphicsView>

namespace LimeReport {

class GraphicsViewZoomer : public QObject {
  Q_OBJECT
public:
  GraphicsViewZoomer(QGraphicsView* view);
  void gentleZoom(double factor);
  void setModifiers(Qt::KeyboardModifiers modifiers);
  void setZoomFactorBase(double value);
private:
  QGraphicsView* m_view;
  Qt::KeyboardModifiers m_modifiers;
  double m_zoomFactorBase;
  QPointF m_targetScenePos, m_targetViewportPos;
  bool eventFilter(QObject* object, QEvent* event);
signals:
  void zoomed();
};

} // namespace LimeReport

#endif // GRAPHICSVIEWZOOM_H
