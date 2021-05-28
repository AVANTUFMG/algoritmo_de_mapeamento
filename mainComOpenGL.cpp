#include <windows.h>
#include <gl/glut.h>
#include "MissaoMapeamento.h"

Poligono* pol;
MissaoMapeamento* missao1;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é amarelo
    glColor3f(1.0f, 1.0f, 0.0f);

    // Desenha um quadrado preenchido com a cor corrente
    glBegin(GL_POLYGON);
    for (Point it : pol->getVertices()) {
        glVertex2i(it.get_x()*20, it.get_y()*20);
    }
    glEnd();

    // Especifica que a cor corrente é vermelho
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(3.5f);
    glBegin(GL_POINTS);
    for (Point it : pol->getVertices()) {
        glVertex2i(it.get_x() * 20, it.get_y() * 20);
    }
    glEnd();

    // Especifica que a cor corrente é azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(2.5f);
    glBegin(GL_POINTS);
    for (Point it: missao1->getRota()) {
        glVertex2i(it.get_x()*20, it.get_y()*20);
    }
    glEnd();

    // Executa os comandos OpenGL
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if (h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    if (w <= h)
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
    else
        gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}


void criarMissao() {
    int numeroPontos;
    vector<Point> pontos;

    cout << "Digite o numero de vertices do poligo: ";
    cin >> numeroPontos;
    cout << "Agora, entre com as coordenadas de cada vertice em sentido anti-horario: ";

    double x = 0; double y = 0;

    for (int i = 0; i != numeroPontos; i++) {
        Point pnt(NULL, NULL, 0);
        cin >> x;
        cin >> y;
        pnt.set_x(x);
        pnt.set_y(y);
        pontos.push_back(pnt);
    }

    pol = new Poligono(pontos);

    missao1 = new MissaoMapeamento(*pol);
    missao1->gerarRota();
    missao1->mostrarRota();
}

void liberarMemoria() {
    delete pol;
    delete missao1;
}

// Programa Principal 
int main(void)
{
    criarMissao();
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Quadrado");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
    liberarMemoria();
}