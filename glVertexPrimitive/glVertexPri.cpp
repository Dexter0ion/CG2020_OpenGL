#include<GL/glut.h>
#include<math.h>

/*
	图形输出原语 graphics output primitive
	简称图元 primitive
*/


class glPoint2D {
public:
	GLfloat x, y;
};

/*
	glVertex***
	参数1-维度
	参数2-数据结构
		i-整数 s-短整数 f-浮点数 d-双精度浮点整数

	如显式表示
	glVertex3i(1,10,2);
	若矩阵形式表示 参数3-v
	int point1 []  = {50,100};
	glVertex2iv(point1);
*/

void init() {
	glClearColor(0.5, 1.0, 1.0,0);
	glMatrixMode(GL_PROJECTION);
	//重建坐标系？以物体中心为原点？
	//glLoadIdentity();
	//xmin,xmax,ymin,ymax
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawpoint() {
	//刷新窗口
	//glClear(GL_COLOR_BUFFER_BIT);
	//设置线段为蓝绿色
	glColor3f(0.0, 0.4, 0.2);

	int point1[] = { 50,100 };
	int point2[] = { 60,120 };
	int point3[] = { 70,130 };

	glBegin(GL_POINTS);
	glVertex2iv(point1);
	glVertex2iv(point2);
	glVertex2iv(point3);
	glEnd();

	glPoint2D pointPos;
	pointPos.x = 120.75;
	pointPos.y = 45.30;
	glBegin(GL_POINTS);
	glVertex2f(pointPos.x, pointPos.y);
	glEnd();

	//glFlush();
}

void drawLine() {
	//刷新窗口
	//glClear(GL_COLOR_BUFFER_BIT);
	//设置线段为红色

	
	glColor3f(1.0, 0.0, 0.0);

	int point1[] = { 10,230 };
	int point2[] = { 20,240 };
	int point3[] = { 30,220 };

	//直线段
	glBegin(GL_LINES);
	glVertex2iv(point1);
	glVertex2iv(point2);
	glVertex2iv(point3);
	glEnd();

	glPoint2D pts[8] = {
		{100,250},{180,280},{150,320},{120,240}
		,{50,250},{40,280}, {100,320},{80,240}
	};
	//折现polyline
	glBegin(GL_LINE_STRIP);
	glVertex2i(pts[0].x, pts[0].y);
	glVertex2i(pts[1].x, pts[1].y);
	glVertex2i(pts[2].x, pts[2].y);
	glVertex2i(pts[3].x, pts[3].y);
	glEnd();

	//封闭折线closed polyline
	glBegin(GL_LINE_LOOP);
	glVertex2i(pts[4].x, pts[4].y);
	glVertex2i(pts[5].x, pts[5].y);
	glVertex2i(pts[6].x, pts[6].y);
	glVertex2i(pts[7].x, pts[7].y);
	glEnd();
	glFlush();
}

void drawPolygon() {
	//glClear(GL_COLOR_BUFFER_BIT);

	//color:purple
	glColor3f(1.0, 0.0, 1.0);

	/*
		glReact*(x1,y1,x2,y2);
	*/
	glRecti(10, 80, 40, 120);

	//多边形填充图元GL_POLYGON 逆时针次序
	/*
	A(2, 0), B(1, √3),C(-1, √3),
	D(-2, 0）, E(-1, -√3), F(1, -√3).
	*/

	int OX = 75;
	int OY = 100;
	int LEN = 15;
	glBegin(GL_POLYGON);
	glVertex2i(OX + 2 * LEN, OY);
	glVertex2i(OX + LEN, OY + LEN * sqrt(3));
	glVertex2i(OX - LEN, OY + LEN * sqrt(3));

	glVertex2i(OX - 2 * LEN, OY);
	glVertex2i(OX - LEN, OY - LEN * sqrt(3));
	glVertex2i(OX + LEN, OY - LEN * sqrt(3));
	glEnd();

	
	int MODX = 70;
	//两个分开的三角形填充区 GL_TRIANGLES
	glBegin(GL_TRIANGLES);
	glVertex2i(OX + 2 * LEN + MODX, OY);
	glVertex2i(OX+ LEN + MODX, OY + LEN * sqrt(3));
	glVertex2i(OX - LEN + MODX, OY + LEN * sqrt(3));

	glVertex2i(OX - 2 * LEN + MODX, OY);
	glVertex2i(OX - LEN + MODX, OY - LEN * sqrt(3));
	glVertex2i(OX + LEN + MODX, OY - LEN * sqrt(3));
	glEnd();

	//一组连接三角形 GL_TRIANGLE_STRIP
	int MODEY = 75;
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(OX + 2 * LEN + MODX, OY + MODEY);
	glVertex2i(OX + LEN + MODX, OY + LEN * sqrt(3) + MODEY);
	glVertex2i(OX - LEN + MODX, OY + LEN * sqrt(3) + MODEY) ;

	glVertex2i(OX - 2 * LEN + MODX, OY + MODEY);
	glVertex2i(OX - LEN + MODX, OY - LEN * sqrt(3) + MODEY);
	glVertex2i(OX + LEN + MODX, OY - LEN * sqrt(3) + MODEY);
	glEnd();

	//一组三角形扇形拼接 GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(OX + 2 * LEN + MODX, OY - MODEY);
	glVertex2i(OX + LEN + MODX, OY + LEN * sqrt(3) - MODEY);
	glVertex2i(OX - LEN + MODX, OY + LEN * sqrt(3) - MODEY);

	glVertex2i(OX - 2 * LEN + MODX, OY - MODEY);
	glVertex2i(OX - LEN + MODX, OY - LEN * sqrt(3) - MODEY);
	glVertex2i(OX + LEN + MODX, OY - LEN * sqrt(3) - MODEY);
	glEnd();

	
	glFlush();
}


/*
	GL_QUADS
	GL_QUAD_STRIP

	两种四边形图元

	P1                            P8        
	        P4       P5                 

	P2         P3         P6         P7
*/
void drawQuad() {

	glColor3f(1.0, 0.5, 1.0);
	int OX = 200;
	int OY = 200;
	int L = 20;

	glPoint2D quads[8] = {
	{OX,OY+L*2},{OX,OY-L*1.5},{OX+L*3,OY-L*1.5},{OX+L*1.7,OY+L*1.7},
	{OX + L * 4,OY + L * 1.8},{OX + L * 5,OY - L * 1.5}, 
	{OX + L * 10,OY - L * 2},{OX + L * 9,OY + L * 2}
	};

	glBegin(GL_QUADS);
	glVertex2i(quads[0].x, quads[0].y);
	glVertex2i(quads[1].x, quads[1].y);
	glVertex2i(quads[2].x, quads[2].y);
	glVertex2i(quads[3].x, quads[3].y);
	glVertex2i(quads[4].x, quads[4].y);
	glVertex2i(quads[5].x, quads[5].y);
	glVertex2i(quads[6].x, quads[6].y);
	glVertex2i(quads[7].x, quads[7].y);
	glEnd();

	glFlush();
}

void drawQuadStrip() {

	glColor3f(1.0, 0.5, 1.0);
	int OX = 200;
	int OY = 100;
	int L = 15;

	glPoint2D quads[8] = {
	{OX,OY + L * 2},{OX,OY - L * 1.5},{OX + L * 3,OY - L * 1.5},{OX + L * 1.7,OY + L * 1.7},
	{OX + L * 4,OY + L * 1.8},{OX + L * 5,OY - L * 1.5},
	{OX + L * 10,OY - L * 2},{OX + L * 9,OY + L * 2}
	};

	glBegin(GL_QUAD_STRIP);
	glVertex2i(quads[0].x, quads[0].y);
	glVertex2i(quads[1].x, quads[1].y);
	glVertex2i(quads[3].x, quads[3].y); //最后连个结点顺序颠倒
	glVertex2i(quads[2].x, quads[2].y);
	glVertex2i(quads[4].x, quads[4].y);
	glVertex2i(quads[5].x, quads[5].y);
	glVertex2i(quads[7].x, quads[7].y);
	glVertex2i(quads[6].x, quads[6].y); //最后连个结点顺序颠倒
	glEnd();

	glFlush();
}
void drawPrimitive() {
	drawLine();
	drawPolygon();
	drawQuad();
	drawQuadStrip();
	/*
		使用平面片濑显示曲面，因为平面方程是线性的，比二次或类曲线方程快得多。
	*/

}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 200);
	glutInitWindowSize(400, 300);

	glutCreateWindow("glVertex Primitive");

	init();

	//glutDisplayFunc(drawpoint);
	glutDisplayFunc(drawPrimitive);

	glutMainLoop();
}