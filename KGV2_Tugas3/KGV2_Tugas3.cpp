// KGV2_Tugas3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************************************************************
 * Buat 5 objek
 * Dua (2) objek dapat digerakkan keyboard atau mouse:
 * - Bentuk sama, boleh polygon (segitiga, dll.) beda warna.
 * - Posisi awal objek 1 & 2 di kiri-atas & kanan-bawah.
 * - Objek muncul setelah menekan salah satu tombol.
 *
 * Dua (2) objek segi empat, ukuran sama, di tengah:
 * - Ukuran disesuaikan dengan objek 1 & 2 agar dapat berada dalam segi empat.
 *
 * Satu (1) objek tulisan, muncul ketika objek 1 & 2 masuk dalam segiempat warna sama.
 * 
 * Kumpul
 * [KGV2_Tugas3_035.cpp] Source Code
 * [KGV2_Tugas3_035.mp4] Google Drive record program
 * https://drive.google.com/file/d/1T4vxD8oT1ZjhLk1ijnYa8t2hOo7uJLAl/view?usp=sharing
 ***************************************************************************************/

#include <glut.h>
#include <iostream>

using namespace std;

float objAX  = 0;
float objAY  = 0;
float objBX  = 0;
float objBY  = 0;

bool  objA   = 0;
bool  objB   = 0;

bool  start  = 0;
bool  replay = 0;

void write(float x, float y, float z, void* font, const char* string)
{
	const char* c;

	glColor3f(1, 1, 1);
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void boxA()
{
	/*****************************
	 *        Horizontal
	 *        640 x 640
	 *           320
	 *    190 310   330 450
	 * 
	 *  Vertical
	 *     640       380
	 *      x   320  
	 *     640       260
	 *****************************/

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(3);

	glBegin(GL_LINE_LOOP);
		glColor3ub(129, 245, 127);
		glVertex2f(190, 380);
		glVertex2f(310, 380);
		glVertex2f(310, 260);
		glVertex2f(190, 260);
	glEnd();
}

void boxB()
{
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(3);

	glBegin(GL_LINE_LOOP);
		glColor3ub(235, 204, 87);
		glVertex2f(330, 380);
		glVertex2f(450, 380);
		glVertex2f(450, 260);
		glVertex2f(330, 260);
	glEnd();
}

void objectA()
{
	glBegin(GL_POLYGON);
		glColor3ub(129, 245, 127);
		glVertex2f(50  + objAX, 620 + objAY); // atas
		glVertex2f(80  + objAX, 620 + objAY);

		glVertex2f(110 + objAX, 590 + objAY); // kanan
		glVertex2f(110 + objAX, 560 + objAY);

		glVertex2f(80  + objAX, 530 + objAY); // bawah
		glVertex2f(50  + objAX, 530 + objAY);

		glVertex2f(20  + objAX, 560 + objAY); // kiri
		glVertex2f(20  + objAX, 590 + objAY);
	glEnd();
}

void objectB()
{
	glBegin(GL_POLYGON);
		glColor3ub(235, 204, 87);
		glVertex2f(560 + objBX, 110 + objBY); // atas
		glVertex2f(590 + objBX, 110 + objBY);

		glVertex2f(620 + objBX, 80 + objBY); // kanan
		glVertex2f(620 + objBX, 50 + objBY);

		glVertex2f(590 + objBX, 20 + objBY); // bawah
		glVertex2f(560 + objBX, 20 + objBY);

		glVertex2f(530 + objBX, 50 + objBY); // kiri
		glVertex2f(530 + objBX, 80 + objBY);
	glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: // Esc Key
			cout << "==========[ EXIT GAME ]==========\n";
			exit(0);
			break;
		case 32: // Space Key
			if (!start)
			{
				start = 1;
				cout << "==========[ START GAME ]==========\n";
			}
			break;
		case 13: // Enter Key
			if (objA && objB)
			{
				replay = 1;
				cout << "==========[ REPLAY GAME ]==========\n";
			}
			break;

		// Object A
		case 'h':
		case 'H':
			if (objAX > -20) objAX -= 5;
			cout << "A = (" << objAX << ", " << objAY << ")\n";
			break;
		case 'k':
		case 'K':
			if (objAX < 530) objAX += 5;
			cout << "A = (" << objAX << ", " << objAY << ")\n";
			break;
		case 'u':
		case 'U':
			if (objAY < 20) objAY += 5;
			cout << "A = (" << objAX << ", " << objAY << ")\n";
			break;
		case 'j':
		case 'J':
			if (objAY > -530) objAY -= 5;
			cout << "A = (" << objAX << ", " << objAY << ")\n";
			break;
	}

	/*
	(190, 380);
	(310, 380);
	(310, 260);
	(190, 260);
	*/

	if (objAX >= 170 && objAX <= 200 && objAY >= -270 && objAY <= -240)
	{
		objA = 1;
		cout << "Object A inside the Square\n";
	}
	else objA = 0;
}

void specialKey(int key, int x, int y)
{
	switch (key)
	{
		// Object B
		case GLUT_KEY_LEFT:
			if (objBX > -530) objBX -= 5;
			cout << "B = (" << objBX << ", " << objBY << ")\n";
			break;
		case GLUT_KEY_RIGHT:
			if (objBX < 20) objBX += 5;
			cout << "B = (" << objBX << ", " << objBY << ")\n";
			break;
		case GLUT_KEY_UP:
			if (objBY < 530) objBY += 5;
			cout << "B = (" << objBX << ", " << objBY << ")\n";
			break;
		case GLUT_KEY_DOWN:
			if (objBY > -20) objBY -= 5;
			cout << "B = (" << objBX << ", " << objBY << ")\n";
			break;
	}

	/*
	(330, 380);
	(450, 380);
	(450, 260);
	(330, 260);
	*/

	if (objBX >= -200 && objBX <= -170 && objBY >= 240 && objBY <= 270)
	{
		objB = 1;
		cout << "Object B inside the Square\n";
	}
	else objB = 0;
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	boxA();
	boxB();

	// Show Instruction before Game Started
	if (!start)
		write(183, 400, 0, GLUT_BITMAP_HELVETICA_18, "Press 'SPACE' to Start the Game");

	// Show both polygons
	if (start)
	{
		objectA(); objectB();
	}

	// Show Finish if both polygons inside the square
	if (objA && objB)
	{
		write(200, 225, 0, GLUT_BITMAP_HELVETICA_18, "Polygon is inside the Square!");
		write(225, 200, 0, GLUT_BITMAP_HELVETICA_18, "Press 'ENTER' to replay");

		if (replay)
		{
			start = 0;
			replay = 0;

			objAX = 0; objAY = 0;
			objBX = 0; objBY = 0;

			objA = 0;
			objB = 0;
		}
	}

	glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(128, 128);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("KGV2 - Tugas 3 - 201401035");
	gluOrtho2D(0, 640, 0, 640);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);
	glutMainLoop();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
