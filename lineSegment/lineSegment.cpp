#include<GL/glut.h>

void init(void) {
	//将背景设置为白色 颜色分量RGB 1：255 α参数0.0为完全不透明
	glClearColor(1.0, 1.0, 1.0, 0.0);

	//设置为投影模式
	glMatrixMode(GL_PROJECTION);
	//投影范围为 左下角(0,0),右上角(200,150) 200宽度 150高度
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);

}

void lineSegment(void) {
	//刷新窗口
	glClear(GL_COLOR_BUFFER_BIT);
	//设置线段为蓝绿色
	glColor3f(0.0, 0.4, 0.2);
	//从证书笛卡尔端点坐标(180,15)到(10,145)的二维直线段
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);

	//只画N/2条线段 N为坐标点
	glVertex2i(50, 50);
	glVertex2i(20, 20);
	glEnd();

	glFlush();

}
void main(int argc, char** argv) {
	//初始化GLUT
	glutInit(&argc, argv);
	//设置单个缓存 RGB颜色模型 显示模式
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//设置窗口位置 从左往右50像素 从上往下100像素
	glutInitWindowPosition(50, 100);
	//设置窗口大小 宽度400 高度300
	glutInitWindowSize(400, 300);
	//创建窗口
	glutCreateWindow("An Example OpenGL Program");

	//初始化图像流程
	init();
	//将图像发送至显示窗口
	glutDisplayFunc(lineSegment);

	glutMainLoop();



}