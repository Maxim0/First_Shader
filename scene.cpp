#include <QMatrix4x4>
#include <QDebug>
#include <QTimer>
#include "scene.h"

Scene::Scene(QWidget* parent) : QGLWidget(parent)
{
	this->setFocusPolicy(Qt::StrongFocus);

//	QTimer* timer = new QTimer;
//	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
//	timer->start(100);
}

void Scene::initializeGL()
{
	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

	QOpenGLShader vShader(QOpenGLShader::Vertex);
	vShader.compileSourceFile(":/Shaders/vShader.glsl");
	QOpenGLShader fShader(QOpenGLShader::Fragment);
	fShader.compileSourceFile(":/Shaders/fShader.glsl");

	m_shader_program.addShader(&vShader);
	m_shader_program.addShader(&fShader);

	if(!m_shader_program.link())
	{
		qWarning("Error: unable to link a shader program");
		return;
	}

	m_vertAttr = m_shader_program.attributeLocation("vertexAttr");
	m_colorAttr = m_shader_program.attributeLocation("colorAttr");
	m_matrixUniform = m_shader_program.uniformLocation("matrix");

	m_triangle = new Triangle(&m_shader_program, m_vertAttr, m_colorAttr);

}

void Scene::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if(!m_shader_program.bind())
		return;

	QMatrix4x4 matrix;
	matrix.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);
//	matrix.perspective( 60.0f, 4.0f/3.0f, 0.1f, 100.0f );
//	matrix.translate( 0.0f, 0.0f, -2.0f );
	m_shader_program.setUniformValue(m_matrixUniform, matrix);

	m_triangle->draw();

	m_shader_program.release();
}

void Scene::resizeGL(int _w, int _h)
{
	glViewport(0, 0, _w, _h);
}

void Scene::keyPressEvent(QKeyEvent* event)
{
	const float step = 0.1f;

	switch(event->key())
	{
		case Qt::Key_Up:
			qDebug() << "keyPressEvent() " << "Key_Up";
			m_triangle->setY0(m_triangle->y0() + step);
			break;
		case Qt::Key_Left:
			qDebug() << "keyPressEvent() " << "Key_Left";
			m_triangle->setX0(m_triangle->x0() - step);
			break;
		case Qt::Key_Down:
			qDebug() << "keyPressEvent() " << "Key_Down";
			m_triangle->setY0(m_triangle->y0() - step);
			break;
		case Qt::Key_Right:
			qDebug() << "keyPressEvent() " << "Key_Right";
			m_triangle->setX0(m_triangle->x0() + step);
			break;
	}
	angle += step;

	updateGL();
}

Scene::~Scene()
{
	delete m_triangle;
}
