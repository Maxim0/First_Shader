#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "triangle.h"

class Scene : public QGLWidget
{
private:
	Triangle*					m_triangle;
	QOpenGLShaderProgram		m_shader_program;

	int							m_vertAttr;
	int							m_colorAttr;
	int							m_matrixUniform;

	GLfloat						angle;

	void		initializeGL();
	void		paintGL();
	void		resizeGL(int _w, int _h);

	void		keyPressEvent(QKeyEvent* event);

public:
				Scene(QWidget* parent = 0);
				~Scene();

};

#endif // SCENE_H
