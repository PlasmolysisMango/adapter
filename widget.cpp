#include "widget.h"
#include "pxr/imaging/hd/engine.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    
}

OpenGLWidget::~OpenGLWidget()
{
    
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
}

void OpenGLWidget::paintGL()
{
    
}

void OpenGLWidget::resizeGL(int w, int h)
{
    
}