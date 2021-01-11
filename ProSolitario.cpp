/*
Nombre: ALST_Solitario.cpp
Autor: Adrián Leonardo Soto Tequida
*/

#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <conio.h>

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ENTER 13
#define ESPACIO 32
#define ESCAPE 27

using namespace std;

struct DatosCasillas{
    int n;
    int x;
    int y;
    bool c;
};

//---------------------------------------------------------------------------------------------------------------------

enum simbDoble{BVD = 186, ESDD, EIDD, EIID = 200, ESID, BHD = 205};
enum estadoCursor{APAGADO, ENCENDIDO};
enum miColor{NEGRO,AZUL,VERDE,AGUAMARINA,ROJO,PURPURA,AMARILLO,GRISCLARO,GRIS,AZULCLARO,VERDECLARO,AGUAMARINACLARO,ROJOCLARO,PURPURACLARO,
    AMARILLOCLARO,
    BLANCO
};
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja un marco doble
 *
 * @param ancho El ancho del marco.
 * @param alto El alto del marco.
 * @param x La posición en el eje x de la esquina superior izquierda del marco.
 * @param y La posición en el eje y de la esquina superior izquierda del marco.
 *
 * @pre Todos los parámetros deben ser mayores a cero
 *
*/
void CrearMarcoDoble(int ancho, int alto, int x, int y);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Captura de manera segura un entero.
 *
 * @param solicitud El mensaje que se despliegará para solicitar un número al usuario.
 *
 * @return El número entero introducido por el usuario.
 *
*/
int CapturaEntero(const char solicitud[]);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Mueve el cursor a la coordenada indicada
 *
 * @param x La posición en el eje x a donde se moverá el cursor.
 * @param y La posición en el eje y a donde se moverá el cursor.
 *
 * @pre Todos los parámetros deben ser mayores a cero
 *
*/
void gotoxy(int x,int y);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Pinta una carta de la baraja
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero
 *
*/
void PintarCarta(int ancho, int alto, int x, int y, int identificadorCarta);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja los caracteres de las esquinas de la carta
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param carta El número de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. carta <= 13. 3 <= palo >= 6
 *
*/
void CaracteresEsquinas(int ancho, int alto, int x, int y, int carta, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Selecciona el centro de la carta correspondiente y lo dibuja
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param carta El número de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. carta <= 13. 3 <= palo >= 6
 *
*/
void CentroCarta(int ancho, int alto, int x, int y, int carta, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta A
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void CartaA(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 2
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta2(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 3
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta3(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 4
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta4(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 5
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta5(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 6
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta6(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 7
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta7(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 8
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta8(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 9
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta9(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número 10
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void Carta10(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta número J
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void CartaJ(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta Q
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void CartaQ(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Dibuja el centro de la carta K
 *
 * @param ancho El ancho de la carta
 * @param alto El alto de la carta
 * @param x La posición en el eje x de la esquina superior izquierda de la carta
 * @param y La posición en el eje y de la esquina superior izquierda de la carta
 * @param palo El palo de la carta
 *
 * @pre Todos los parámetros deben ser mayores a cero. 3 <= palo >= 6
 *
*/
void CartaK(int ancho, int alto, int x, int y, int palo);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Establece el color del texto y fondo de la consola
 *
 * @param colorFondo El color a poner para el fondo
 * @param colorTexto El color a poner para el texto
 *
*/
void EstableceColor(miColor colorFondo, miColor colorTexto);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Establece los colores de la consola
 *
 * @param colorEst Los colores a establecer
 *
*/
void EstableceColor(WORD colorEst);

//---------------------------------------------------------------------------------------------------------------------
/** @brief Obtiene los colores originales de la consola
 *
 * @return Los colores originales de la consola
 *
*/
WORD ObtenerColorOriginal();

//---------------------------------------------------------------------------------------------------------------------
/** @brief Cambia el estado y modo del cursor
 *
 * @param estado El estado del cursor
 * @param modo El modo del cursor
 *
*/
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

void CrearMarcoSeleccionador(int ancho, int alto, int x, int y, int figura);
void CrearMarcoDoble2(int ancho, int alto, int x, int y);
void BarajeaDistribuyeCartas(int MazoA[],DatosCasillas TabCom[][7], int &posMazo);
void ImprimeColumnaTablero(DatosCasillas TabCom[][7], int nCol, int PosCol[], int ancho, int alto);
void ImprimeTablero(DatosCasillas TabCom[][7],int MazoA[],int MazoB[],int colB,int PosCol[],int ColumnasAs[][4],int colAS[],int ancho,int alto);
void LlenaCasillas(DatosCasillas TabCom[][7]);
void ActualizaCasillas(DatosCasillas TabCom[][7], int MazoA[], int colA, int MazoB[], int colB, int ColumnasAs[][4], int colAS[], int PosCol[]);
void LimpiaColumna(int nCol, int ancho, int alto);
void gotoxy(int x,int y) ;

void menu() ;

void InicioJugar() ;

void InicioInstrucciones() ;

void InicioSalir() ;

int Salir() ;

void InicioCreditos() ;

void Win() ;

void Credito() ;

void Instrucciones();

void ImprimeSalir();

//---------------------------------------------------------------------------------------------------------------------
int main()
{

    system("mode con: cols=150 lines=90");
    const int ancho = 11, alto = 11;

    menu();

    int MazoA[52], MazoB[24] = {}, ColumnasAs[13][4] = {};

    DatosCasillas TabCom[19][7] = {};

    int colA = 0, colB = 0;

    int PosCol[7] = {}, colAS[4] = {};

    BarajeaDistribuyeCartas(MazoA,TabCom,colA);

    MazoB[colB] = -MazoA[colA];
    MazoA[colA--] = 0;

    ImprimeTablero(TabCom,MazoA,MazoB,colB,PosCol,ColumnasAs,colAS,ancho,alto);

    LlenaCasillas(TabCom);

    ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);

    int px,py;
    px = 0;
    py = 0;

    EstableceColor(BLANCO,AGUAMARINA);
    CrearMarcoSeleccionador(ancho,alto,TabCom[py][px].x,TabCom[py][px].y, 219);

    char tecla;
    int guardaX = -1,guardaY = -1, auxiliar = 0, auxx = -1, auxy = -1;
    while(true){
        if (ColumnasAs[12][0] != 0 && ColumnasAs[12][1] != 0 && ColumnasAs[12][2] != 0 && ColumnasAs[12][3] != 0) break;
        if(kbhit()){
            for (int i = 0; i <7; ++i){
                if(TabCom[1][i].n == 0){
                    TabCom[1][i].c = true;
                    PosCol[i] = 1;
                }
            }
            tecla = getch();
            gotoxy(100,5);
            if ((px >= 0 && px <= 6 && py == 1 && TabCom[py][px].n == 0)) {
                    EstableceColor(VERDE,VERDE);
                    CrearMarcoDoble(ancho,alto,TabCom[py][px].x,TabCom[py][px].y);
            }

            if (tecla != ENTER){
                EstableceColor(VERDE,BLANCO);
                if ((px == 0 && py == 0 && TabCom[0][0].n == 0)||px == 1 && py == 0 && TabCom[0][1].n == 0) {
                    EstableceColor(VERDE,VERDE);
                    CrearMarcoDoble(ancho,alto,TabCom[py][px].x,TabCom[py][px].y);
                }else if(guardaX != px || guardaY != py)
                        PintarCarta(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,TabCom[py][px].n);

                if (py < PosCol[px] && py > 0){
                    for (int i = py; i <= PosCol[px]; ++i)
                        PintarCarta(ancho,alto,TabCom[i][px].x,TabCom[i][px].y,TabCom[i][px].n);
                    if((guardaX != -1 || guardaY != -1) && guardaY>0){
                        EstableceColor(BLANCO,AMARILLO);
                        CrearMarcoSeleccionador(ancho,alto+3*(PosCol[guardaX]-guardaY),TabCom[guardaY][guardaX].x,TabCom[guardaY][guardaX].y,219);
                    }
                }

                if (px > 2 && px < 7 && py == 0 && TabCom[py][px].n == 0){
                        CrearMarcoDoble2(ancho,alto,TabCom[py][px].x,2);
                    }

                EstableceColor(VERDE,BLANCO);
                if(py >= 0 &&(tecla == FLECHA_ARRIBA || tolower(tecla) == 'w')){

                        if (py == 0)py = PosCol[px];
                        else{
                            if (py == 0 && px > 2 && TabCom[py][px].n == 0) CrearMarcoDoble2(ancho,alto,TabCom[py][px].x,2);
                            --py;
                            while(!TabCom[py][px].c)--py;
                            if (py == 0 && px == 2) px = 1;
                        }
                }
                if(tecla == FLECHA_IZQ    || tolower(tecla) == 'a'){
                        if (px >0){
                            if (py == 0 && px > 2 && TabCom[py][px].n == 0) CrearMarcoDoble2(ancho,alto,TabCom[py][px].x,2);
                            --px;
                            if (!TabCom[py][px].c)py = PosCol[px];

                            if (py == 0 && px == 2) px = 1;
                        }else {
                            px = 6;
                            if (!TabCom[py][px].c)py = PosCol[px];
                        }
                }
                if(py <= PosCol[px] &&(tecla == FLECHA_ABAJO  || tolower(tecla) == 's')){

                        if (py == PosCol[px]) py = 0;
                        else{
                            if (py == 0 && px > 2 && TabCom[py][px].n == 0) CrearMarcoDoble2(ancho,alto,TabCom[py][px].x,2);
                            ++py;
                            while(!TabCom[py][px].c)++py;
                        }
                }
                if(tecla == FLECHA_DER    || tolower(tecla) == 'd'){
                    if (px < 6){
                        if (px == 1 && py == 0) ++px;
                        if (py == 0 && px > 2 && TabCom[py][px].n == 0) CrearMarcoDoble2(ancho,alto,TabCom[py][px].x,2);
                        ++px;
                        if (!TabCom[py][px].c)py = PosCol[px];

                    }else{
                        if (py == 0 && px > 2 && TabCom[py][px].n == 0) CrearMarcoDoble2(ancho,alto,TabCom[py][px].x,2);
                        px = 0;
                        if (!TabCom[py][px].c)py = PosCol[px];
                    }
                }

                if(guardaX != px || guardaY != py){
                    if (px != 0 || py != 0)PintarCarta(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,TabCom[py][px].n);

                }

                if(guardaX != -1 || guardaY != -1 ){
                    EstableceColor(BLANCO,AMARILLO);
                    CrearMarcoSeleccionador(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,219);
                }

                if((guardaX != -1 || guardaY != -1) && guardaY>0){
                        EstableceColor(BLANCO,AMARILLO);
                        CrearMarcoSeleccionador(ancho,alto+3*(PosCol[guardaX]-guardaY),TabCom[guardaY][guardaX].x,TabCom[guardaY][guardaX].y,219);
                    }


                if (px == 2 && py == 0) --px;
                if(guardaX != px || guardaY != py){
                    EstableceColor(BLANCO,AGUAMARINA);
                    CrearMarcoSeleccionador(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,219);
                }
            }


            if (tecla == ENTER  && px == 0 && py == 0 ){
                guardaX = -1;
                guardaY = -1;
                if (MazoA[0] != 0){
                    MazoB[++colB] = -MazoA[colA];
                    MazoA[colA--] = 0;
                    ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);
                    if (MazoA[0] == 0) {
                            TabCom[0][0].n = 0;
                            EstableceColor(VERDE,VERDE);
                            CrearMarcoDoble(ancho,alto,TabCom[py][px].x,TabCom[py][px].y);
                    }
                    if(MazoB[colB]!= 0) PintarCarta(ancho,alto,17,2,MazoB[colB]);
                }else {
                    for (int i = 0; i <= colB; ++i){
                        MazoA[i] = -MazoB[colB-i];
                        MazoB[colB-i] = 0;
                    }
                    colA = colB;
                    colB = -1;
                    EstableceColor(VERDE,VERDE);
                    CrearMarcoDoble(ancho,alto,17,2);
                    PintarCarta(ancho,alto,3,2,-1);
                    ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);
                }
            EstableceColor(BLANCO,AGUAMARINA);
            CrearMarcoSeleccionador(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,219);
            }
            if (tecla == ENTER && (px != 0 || py != 0)){

                    if (guardaX == -1 && guardaY == -1){
                        if ((py == 0 && px == 1)||(py > 0)){
                            guardaX = px;
                            guardaY = py;


                            EstableceColor(BLANCO,AMARILLO);
                            CrearMarcoSeleccionador(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,219);
                        }
                    }else{
                        if ((py == 0 && px > 2)||py>0){
                            int valor = TabCom[guardaY][guardaX].n;

                            if (py == 0){
                                bool si = false;
                                switch(px){
                                case 3: if(valor == colAS[px-3]*4 + 1)si = true;
                                        break;
                                case 4: if(valor == colAS[px-3]*4 + 3)si = true;
                                        break;
                                case 5: if(valor == colAS[px-3]*4 + 2)si = true;
                                        break;
                                case 6: if(valor == colAS[px-3]*4 + 4)si = true;
                                        break;

                                }
                                if (si && (guardaX != 1 || guardaY != 0)){
                                    ColumnasAs[colAS[px-3]][px-3] = valor;
                                    --PosCol[guardaX];
                                    TabCom[guardaY-1][guardaX].n = (TabCom[guardaY-1][guardaX].n>0)?TabCom[guardaY-1][guardaX].n:-TabCom[guardaY-1][guardaX].n;
                                    TabCom[guardaY-1][guardaX].c = true;
                                    TabCom[guardaY][guardaX].n = 0;
                                    TabCom[guardaY][guardaX].c = false;
                                    ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);
                                    LimpiaColumna(guardaX,ancho,alto);
                                    ImprimeColumnaTablero(TabCom,guardaX,PosCol, ancho, alto);
                                    PintarCarta(ancho,alto,3 +px*14,2,ColumnasAs[colAS[px-3]][px-3]);
                                    ++colAS[px-3];
                                    guardaX = -1;
                                    guardaY = -1;
                                }
                                if (si && guardaX == 1 && guardaY == 0){
                                    ColumnasAs[colAS[px-3]][px-3] = valor;
                                    MazoB[colB--] = 0;
                                    ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);
                                    PintarCarta(ancho,alto,3 +px*14,2,ColumnasAs[colAS[px-3]][px-3]);
                                    if(MazoB[colB]!= 0) PintarCarta(ancho,alto,17,2,MazoB[colB]);
                                    else{
                                        EstableceColor(VERDE,VERDE);
                                        CrearMarcoDoble(ancho,alto,17,2);
                                    }
                                    si = false;
                                    ++colAS[px-3];

                                    guardaX = -1;
                                    guardaY = -1;
                                }



                            }
                            if (py > 0){
                                bool si = false;

                                switch(valor%4){
                                case 1: if ((valor == TabCom[py][px].n - 7) || (valor == TabCom[py][px].n - 5)) si = true;
                                        break;
                                case 2:if ((valor == TabCom[py][px].n - 3) || (valor == TabCom[py][px].n - 5)) si = true;
                                        break;
                                case 3:if ((valor == TabCom[py][px].n - 5) || (valor == TabCom[py][px].n - 3)) si = true;
                                        break;
                                case 0:if ((valor == TabCom[py][px].n -1) || (valor == TabCom[py][px].n - 3)) si = true;
                                        break;
                                }
                                if (valor >= 49 && valor <= 52 && TabCom[py][px].n == 0)si = true;
                                if (si && (guardaX != 1 || guardaY != 0)){
                                    if (TabCom[guardaY+1][guardaX].n==0){
                                        if (TabCom[py][px].n == 0)TabCom[PosCol[px]][px].n = valor;
                                        else TabCom[++PosCol[px]][px].n = valor;
                                        --PosCol[guardaX];
                                        TabCom[guardaY-1][guardaX].n = (TabCom[guardaY-1][guardaX].n>0)?TabCom[guardaY-1][guardaX].n:-TabCom[guardaY-1][guardaX].n;
                                        TabCom[guardaY-1][guardaX].c = true;
                                        TabCom[guardaY][guardaX].n = 0;
                                        TabCom[guardaY][guardaX].c = false;
                                        ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);
                                        LimpiaColumna(px,ancho,alto);
                                        LimpiaColumna(guardaX,ancho,alto);
                                        ImprimeColumnaTablero(TabCom,px,PosCol, ancho, alto);
                                        ImprimeColumnaTablero(TabCom,guardaX,PosCol, ancho, alto);
                                        si = false;
                                    }
                                    if (TabCom[guardaY+1][guardaX].n!=0 && TabCom[py+1][px].n == 0){
                                        int a=0,b=0;
                                        for (int i = guardaY; i <= PosCol[guardaX]; ++i){
                                            if (TabCom[py][px].n == 0)TabCom[PosCol[px]][px].n = TabCom[i][guardaX].n;
                                            else TabCom[++PosCol[px]][px].n = TabCom[i][guardaX].n;
                                            TabCom[PosCol[px]][px].c = 1;
                                            TabCom[i][guardaX].c = false;
                                            TabCom[i][guardaX].n = 0;
                                            a = i;
                                            b = guardaX;
                                        }
                                        if (guardaY != 1)TabCom[guardaY-1][guardaX].n = (TabCom[guardaY-1][guardaX].n>0)?TabCom[guardaY-1][guardaX].n:-TabCom[guardaY-1][guardaX].n;
                                        if (TabCom[2][guardaX].n == 0) PosCol[guardaX] = 1;
                                        TabCom[guardaY-1][guardaX].c = true;
                                        TabCom[guardaY][guardaX].n = 0;
                                        TabCom[guardaY][guardaX].c = false;
                                        ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);
                                        TabCom[a][b].c = false;;
                                        LimpiaColumna(px,ancho,alto);
                                        LimpiaColumna(guardaX,ancho,alto);
                                        ImprimeColumnaTablero(TabCom,px,PosCol, ancho, alto);
                                        ImprimeColumnaTablero(TabCom,guardaX,PosCol, ancho, alto);
                                    }
                                }

                                if (si && guardaX == 1 && guardaY == 0){
                                    if (TabCom[py][px].n == 0)TabCom[PosCol[px]][px].n = valor;
                                    else TabCom[++PosCol[px]][px].n = valor;
                                    MazoB[colB--] = 0;
                                    ActualizaCasillas(TabCom, MazoA, colA, MazoB, colB, ColumnasAs,colAS,PosCol);
                                    LimpiaColumna(px,ancho,alto);
                                    ImprimeColumnaTablero(TabCom,px,PosCol, ancho, alto);
                                    if(MazoB[colB]!= 0) PintarCarta(ancho,alto,17,2,MazoB[colB]);
                                    else{
                                        EstableceColor(VERDE,VERDE);
                                        CrearMarcoDoble(ancho,alto,17,2);
                                    }
                                    si = false;
                                }


                                PintarCarta(ancho,alto,TabCom[guardaY][guardaX].x,TabCom[guardaY][guardaX].y,TabCom[guardaY][guardaX].n);
                                guardaX = -1;
                                guardaY = -1;

                            }




                        }
                    }

            }
            if (guardaX == -1 && auxy<PosCol[auxx] && auxx != -1){
                for (int i = auxy; i <= PosCol[auxx]; ++i)
                        PintarCarta(ancho,alto,TabCom[i][auxx].x,TabCom[i][auxx].y,TabCom[i][auxx].n);
            }
            auxx = guardaX;
            auxy = guardaY;


            if(guardaX != px || guardaY != py){
                    if (px != 0 || py != 0)PintarCarta(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,TabCom[py][px].n);

            }
            if(guardaX != px || guardaY != py){
                    EstableceColor(BLANCO,AGUAMARINA);
                    CrearMarcoSeleccionador(ancho,alto,TabCom[py][px].x,TabCom[py][px].y,219);
            }


        }
    }

    Win();
    system("pause");
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------
void ActualizaCasillas(DatosCasillas TabCom[][7], int MazoA[], int colA, int MazoB[], int colB, int ColumnasAs[][4], int colAS[], int PosCol[])
{
    TabCom[0][0].n = MazoA[colA];

    TabCom[0][1].n = MazoB[colB];

    TabCom[0][2].n = MazoB[colB];

    TabCom[0][3].n = ColumnasAs[colAS[0]][0];

    TabCom[0][4].n = ColumnasAs[colAS[1]][1];

    TabCom[0][5].n = ColumnasAs[colAS[2]][2];

    TabCom[0][6].n = ColumnasAs[colAS[3]][3];

    for (int i = 0; i < 7; i++){
        TabCom[PosCol[i]][i].c = true;

        int k = 1;

        int valor = TabCom[PosCol[i]][i].n;
        switch(valor%4){
        case 1: while(TabCom[PosCol[i]-k][i].n == valor + 4*k + 1 || TabCom[PosCol[i]-k][i].n == valor + 4*k + 3){
                    TabCom[PosCol[i]-k][i].c = true;
                    k++;
                }
                break;
        case 2: while(TabCom[PosCol[i]-k][i].n == valor + 4*k + 1 || TabCom[PosCol[i]-k][i].n == valor + 4*k - 1){
                    TabCom[PosCol[i]-k][i].c = true;
                    k++;
                }
                break;
        case 3: while(TabCom[PosCol[i]-k][i].n == valor + 4*k + 1 || TabCom[PosCol[i]-k][i].n == valor + 4*k - 1){
                    TabCom[PosCol[i]-k][i].c = true;
                    k++;
                }
                break;
        case 4: while(TabCom[PosCol[i]-k][i].n == valor + 4*k - 1 || TabCom[PosCol[i]-k][i].n == valor + 4*k - 3){
                    TabCom[PosCol[i]-k][i].c = true;
                    k++;
                }
                break;
        }
        k = 0;

    }
}

void LlenaCasillas(DatosCasillas TabCom[][7])
{
    for (int i = 0; i < 7; i++){
        TabCom[0][i].x = 3+14*i;
        TabCom[0][i].y = 2;
        TabCom[0][i].c = true;
    }

    TabCom[0][2].x = 17;

    for (int i = 1; i < 19; i++){
        for (int j = 0; j < 7; j++){
            TabCom[i][j].x = 3+14*j;
            TabCom[i][j].y = 18+3*(i-1);
            TabCom[i+1][j].c = false;
        }
    }
}

void ImprimeTablero(DatosCasillas TabCom[][7],int MazoA[],int MazoB[],int colB,int PosCol[],int ColumnasAs[][4],int colAS[],int ancho,int alto){

        EstableceColor(VERDE,VERDE);
        system("cls");

        EstableceColor(VERDE,BLANCO);
        CrearMarcoDoble(ancho,alto,17,2);

        for (int i = 45; i<=87; i+=14){
                CrearMarcoDoble(ancho,alto,i,2);
                CartaA(ancho,alto,i,2,(i-45)/14+3);
        }
        for (int i = 3; i<= 87; i+=14) CrearMarcoDoble(ancho,alto,i,18);
        if(MazoA[0]!= 0) PintarCarta(ancho,alto,3,2,-1);
        if(MazoB[colB]!= 0) PintarCarta(ancho,alto,17,2,MazoB[colB]);

        for (int j = 0; j < 7; ++j) ImprimeColumnaTablero(TabCom,j,PosCol, ancho, alto);

        if(ColumnasAs[colAS[0]][0]!= 0) PintarCarta(ancho,alto,45,2,ColumnasAs[colAS[0]][0]);
        if(ColumnasAs[colAS[1]][0]!= 0) PintarCarta(ancho,alto,59,2,ColumnasAs[colAS[1]][1]);
        if(ColumnasAs[colAS[2]][0]!= 0) PintarCarta(ancho,alto,73,2,ColumnasAs[colAS[2]][2]);
        if(ColumnasAs[colAS[3]][0]!= 0) PintarCarta(ancho,alto,87,2,ColumnasAs[colAS[3]][3]);
    }

void LimpiaColumna(int nCol,int ancho, int alto){
    for (int i = 0; i <16; ++i){
        EstableceColor(VERDE,VERDE);
        CrearMarcoDoble(ancho,alto,3+(nCol)*14,18+(i-1)*3);
    }
}

void ImprimeColumnaTablero(DatosCasillas TabCom[][7], int nCol, int PosCol[],int ancho,int alto)
{
    int i = 0;
    while (TabCom[++i][nCol].n != 0) PintarCarta(ancho,alto,3+(nCol)*14,18+(i-1)*3,TabCom[i][nCol].n);
    PosCol[nCol] = i-1;
    i = 0;
}

void BarajeaDistribuyeCartas(int MazoA[],DatosCasillas TabCom[][7], int &posMazo )
{
    srand(time(NULL));

    for (int i = 0; i < 52; ++i ) MazoA[i] = -i-1;

    int pos, aux;
    for (int i = 0; i < (52-1); ++i){
            pos = rand()%(52-i-1) + i + 1;
            aux = MazoA[i];
            MazoA[i] = MazoA[pos];
            MazoA[pos] = aux;

    }

    posMazo = 51;

    for (int i = 6; i >= 0; --i){
        for (int j = 0; j < i; ++j){
            TabCom[j+1][i].n = MazoA[posMazo];
            MazoA[posMazo--] = 0;
        }
        TabCom[i+1][i].n = -MazoA[posMazo];
        MazoA[posMazo--] = 0;
    }
}

void PintarCarta(int ancho, int alto, int x, int y, int identificadorCarta)
{
    WORD original = ObtenerColorOriginal();

    if (identificadorCarta != 0){
        if (identificadorCarta > 0){
            int palo,carta;


            CambiaCursor(APAGADO,NORMAL);

            EstableceColor(NEGRO,BLANCO);

            int manejador = identificadorCarta%4;

            switch(manejador){
                case 1: palo = 3;
                break;
                case 2: palo = 5;
                break;
                case 3: palo = 4;
                break;
                case 0: palo = 6;
                break;
            }
            carta = (identificadorCarta + (4-manejador))/4;
            if (manejador == 0) carta--;

            EstableceColor(BLANCO,NEGRO);
            CrearMarcoDoble(ancho,alto,x,y);

            if ((palo) <= 4 ) EstableceColor(BLANCO,ROJO);
            else EstableceColor(BLANCO,NEGRO);

            CaracteresEsquinas(ancho,alto,x,y,carta,palo);

            CentroCarta(ancho,alto,x,y,carta,palo);

        }else{
            EstableceColor(BLANCO,ROJO);
            CrearMarcoDoble(ancho,alto,x,y);
            EstableceColor(BLANCO,ROJO);
            for (int i = x+1; i < x+ancho-1; ++i){
                for (int j = y+1; j < y+alto-1; ++j){
                    gotoxy(i,j);
                    cout << char(176);
                }
            }
        }
    }

    EstableceColor(original);


}

//---------------------------------------------------------------------------------------------------------------------
void CaracteresEsquinas(int ancho, int alto, int x, int y, int carta, int palo)
{
    //Esquina superior izquierda
    gotoxy(x+1,y+1);
    if (carta > 1 && carta < 11) cout << carta;
    else switch(carta){
            case 1: cout << "A"; break;
            case 11: cout << "J"; break;
            case 12: cout << "Q"; break;
            case 13: cout << "K"; break;
    }
    gotoxy(x+1,y+2);
    cout << (char)palo;

    //Esquina inferior derecha
    gotoxy(x+ancho-2,y+alto-2);
    if (carta > 1 && carta < 10) cout << carta;
    else switch(carta){
            case 1: cout << "A"; break;
            case 10: cout <<"\b10"; break;
            case 11: cout << "J"; break;
            case 12: cout << "Q"; break;
            case 13: cout << "K"; break;
    }
    gotoxy(x+ancho-2,y+alto-3);
    cout << (char)palo;
}
void CrearMarcoSeleccionador(int ancho, int alto, int x, int y, int figura)
{
    gotoxy(x,y);
    for(int i = 1 ; i <= ancho ; ++i) cout << (char)figura;

    for(int i = 2 ; i < alto ; ++i){
        gotoxy(x,++y);
        cout << (char)figura;
        gotoxy(x+ancho-1,y);
        cout << (char)figura;
    }


    gotoxy(x,++y);
    for(int i = 1 ; i <= ancho ; ++i) cout << (char)figura;
}


//---------------------------------------------------------------------------------------------------------------------
void CrearMarcoDoble(int ancho, int alto, int x, int y)
{
    // Parte superior
    gotoxy(x,y);
    cout << (char)ESID;
    for(int i = 2 ; i < ancho ; ++i) cout << (char)BHD;
    cout << (char)ESDD;
    // Parte media
    for(int i = 2 ; i < alto ; ++i){
        gotoxy(x,++y);
        cout << (char)BVD;
        for(int j = 2 ; j < ancho ; ++j) cout << ' ';
        cout << (char)BVD;
    }
    // Parte inferior
    gotoxy(x,++y);
    cout << (char)EIID;
    for(int i = 2 ; i < ancho ; ++i) cout << (char)BHD;
    cout << (char)EIDD;
}

void CrearMarcoDoble2(int ancho, int alto, int x, int y)
{
    // Parte superior
    gotoxy(x,y);
    cout << (char)ESID;
    for(int i = 2 ; i < ancho ; ++i) cout << (char)BHD;
    cout << (char)ESDD;
    // Parte media
    for(int i = 2 ; i < alto ; ++i){
        gotoxy(x,++y);
        cout << (char)BVD;
        gotoxy(x+ancho-1,y);
        cout << (char)BVD;
    }
    // Parte inferior
    gotoxy(x,++y);
    cout << (char)EIID;
    for(int i = 2 ; i < ancho ; ++i) cout << (char)BHD;
    cout << (char)EIDD;
}
//---------------------------------------------------------------------------------------------------------------------
void CentroCarta(int ancho, int alto, int x, int y, int carta, int palo)
{
    switch (carta){
        case 1: CartaA(ancho,alto,x,y,palo); break;
        case 2: Carta2(ancho,alto,x,y,palo); break;
        case 3: Carta3(ancho,alto,x,y,palo); break;
        case 4: Carta4(ancho,alto,x,y,palo); break;
        case 5: Carta5(ancho,alto,x,y,palo); break;
        case 6: Carta6(ancho,alto,x,y,palo); break;
        case 7: Carta7(ancho,alto,x,y,palo); break;
        case 8: Carta8(ancho,alto,x,y,palo); break;
        case 9: Carta9(ancho,alto,x,y,palo); break;
        case 10: Carta10(ancho,alto,x,y,palo); break;
        case 11: CartaJ(ancho,alto,x,y,palo); break;
        case 12: CartaQ(ancho,alto,x,y,palo); break;
        case 13: CartaK(ancho,alto,x,y,palo); break;
    }
}

//---------------------------------------------------------------------------------------------------------------------
int CapturaEntero(const char solicitud[])
{
    int numero;
    while(true){
            cout << solicitud;
            cin >> numero;

            if (cin.bad()){
                cout << "Error fatal. El programa se cerrar\240.";
                system("pause");
                exit(1); //Termina el programa completo. No es buena práctica.
            }

            if (cin.fail()){
                cout << "Introduce solo n\243meros." << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(),'\n');
                continue;
            }

            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
            return numero;
        }
}

//---------------------------------------------------------------------------------------------------------------------
void gotoxy(int x,int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x-1,y-1};
    SetConsoleCursorPosition(handle,coord);
}

//---------------------------------------------------------------------------------------------------------------------
void CartaA(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = -2; i <= 3; i++){
        gotoxy(x+ancho-2,y+alto+i);
        cout << (char)palo;
    }
    for (int i = -2; i <= 3; i++){
        gotoxy(x+ancho+2,y+alto+i);
        cout << (char)palo;
    }
    for (int i = -1; i <= 1; i++ ){
        gotoxy(x+ancho+i,y+alto-3);
        cout << (char)palo;
    }
    for (int i = -1; i <= 1; i++ ){
        gotoxy(x+ancho+i,y+alto);
        cout << (char)palo;
    }
}

//---------------------------------------------------------------------------------------------------------------------
void Carta2(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    gotoxy(x+ancho,y+alto+3);
    cout << (char)palo;
    gotoxy(x+ancho,y+alto-3);
    cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void Carta3(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for(int i = 3; i >= -3; i -= 3){
        gotoxy(x+ancho,y+alto+i);
        cout << (char)palo;
    }
}

//---------------------------------------------------------------------------------------------------------------------
void Carta4(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    gotoxy(x+ancho-2,y+alto+3);
    cout << (char)palo;
    gotoxy(x+ancho+2,y+alto+3);
    cout << (char)palo;
    gotoxy(x+ancho-2,y+alto-3);
    cout << (char)palo;
    gotoxy(x+ancho+2,y+alto-3);
    cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void Carta5(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    gotoxy(x+ancho,y+alto);
    cout << (char)palo;
    gotoxy(x+ancho-2,y+alto+3);
    cout << (char)palo;
    gotoxy(x+ancho+2,y+alto+3);
    cout << (char)palo;
    gotoxy(x+ancho-2,y+alto-3);
    cout << (char)palo;
    gotoxy(x+ancho+2,y+alto-3);
    cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void Carta6(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = 3; i >= -3; i -= 3){
        gotoxy(x+ancho-2,y+alto-i);
        cout << (char)palo;
        gotoxy(x+ancho+2,y+alto-i);
        cout << (char)palo;
    }
}

//---------------------------------------------------------------------------------------------------------------------
void Carta7(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = 3; i >= -3; i -= 3){
        gotoxy(x+ancho-2,y+alto-i);
        cout << (char)palo;
        gotoxy(x+ancho+2,y+alto-i);
        cout << (char)palo;
    }

    gotoxy(x+ancho,y+alto-2);
    cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void Carta8(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = 3; i >= -3; i -= 3){
        gotoxy(x+ancho-2,y+alto-i);
        cout << (char)palo;
        gotoxy(x+ancho+2,y+alto-i);
        cout << (char)palo;
    }

    gotoxy(x+ancho,y+alto-2);
    cout << (char)palo;
    gotoxy(x+ancho,y+alto+2);
    cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void Carta9(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = 3; i >= -3; i -= 2){
        gotoxy(x+ancho-2,y+alto-i);
        cout << (char)palo;
        gotoxy(x+ancho+2,y+alto-i);
        cout << (char)palo;
    }

    gotoxy(x+ancho,y+alto);
    cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void Carta10(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = 3; i >= -3; i -= 2){
        gotoxy(x+ancho-2,y+alto-i);
        cout << (char)palo;
        gotoxy(x+ancho+2,y+alto-i);
        cout << (char)palo;
    }

    gotoxy(x+ancho,y+alto+2);
    cout << (char)palo;
    gotoxy(x+ancho,y+alto-2);
    cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void CartaJ(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = -2; i <= 2; i++ ){
        gotoxy(x+ancho+i,y+alto-3);
        cout << (char)palo;
    }
    for (int i = -2; i <= 2; i++ ){
        gotoxy(x+ancho+1,y+alto+i);
        cout << (char)palo;
    }

    gotoxy(x+ancho,y+alto+3);
        cout << (char)palo;
    gotoxy(x+ancho-1,y+alto+3);
        cout << (char)palo;
    gotoxy(x+ancho-2,y+alto+2);
        cout << (char)palo;
}

//---------------------------------------------------------------------------------------------------------------------
void CartaQ(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = -1; i <= 1; i++ ){
        gotoxy(x+ancho+i,y+alto-3);
        cout << (char)palo;
    }
    for (int i = -2; i <= 2; i++ ){
        gotoxy(x+ancho+2,y+alto+i);
        cout << (char)palo;
    }
    for (int i = -2; i <= 2; i++ ){
        gotoxy(x+ancho-2,y+alto+i);
        cout << (char)palo;
    }
    for (int i = -1; i <= 3; i++ ){
        gotoxy(x+ancho+i,y+alto+3);
        cout << (char)palo;
    }

    gotoxy(x+ancho+1,y+alto+2);
    cout << (char)palo;
    gotoxy(x+ancho+1,y+alto+3);
    cout << " ";
}

//---------------------------------------------------------------------------------------------------------------------
void CartaK(int ancho, int alto, int x, int y, int palo)
{
    ancho = ancho/2;
    alto = alto/2;

    for (int i = -3; i <= 3; i++){
        gotoxy(x+ancho-2,y+alto+i);
        cout << (char)palo;
    }

    gotoxy(x+ancho-1,y+alto);
    cout << (char)palo;

    for (int i = 1; i <= 3; i++){
        gotoxy(x+ancho+i-1,y+alto-i);
        cout << (char)palo;
        gotoxy(x+ancho+i-1,y+alto+i);
        cout << (char)palo;
    }
}

//---------------------------------------------------------------------------------------------------------------------
void EstableceColor(miColor colorFondo, miColor colorTexto)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}

//---------------------------------------------------------------------------------------------------------------------
void EstableceColor(WORD colorEst)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorEst);
}

//---------------------------------------------------------------------------------------------------------------------
WORD ObtenerColorOriginal()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
    WORD original = ConsoleInfo->wAttributes;
    delete ConsoleInfo;
    return original;
}

//---------------------------------------------------------------------------------------------------------------------
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void menu(){
    system("mode con: cols=180 lines=80");
    miColor Fondo, Texto;

    Fondo = VERDE ;
    Texto = BLANCO ;
    EstableceColor(Fondo,Texto);
    system("cls") ;

  //  char soundfile[] = "8Bit soundtrack - Calm.wav" ;                            PARA REPRODUCIR SONIDO
   // cout<<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );

    cout << endl << endl << endl ;
cout << setw(120) << " ######   #######  ##       #### ########    ###    ########  ####  ####### "  <<endl ;
cout << setw(120) << "##    ## ##     ## ##        ##     ##      ## ##   ##     ##  ##  ##     ##"  <<endl ;
cout << setw(120) << "##       ##     ## ##        ##     ##     ##   ##  ##     ##  ##  ##     ##"  <<endl ;
cout << setw(120) << " ######  ##     ## ##        ##     ##    ##     ## ########   ##  ##     ##"  <<endl ;
cout << setw(120) << "      ## ##     ## ##        ##     ##    ######### ##   ##    ##  ##     ##"  <<endl ;
cout << setw(120) << "##    ## ##     ## ##        ##     ##    ##     ## ##    ##   ##  ##     ##"  <<endl ;
cout << setw(120) << " ######   #######  ######## ####    ##    ##     ## ##     ## ####  ####### "  <<endl ;

    for(int i = 1 ; i < 6; i++) cout << endl ;

    int i = 1 ;
    char tecla;
    Texto = VERDECLARO ;
    WORD original = ObtenerColorOriginal();
bool Menu = true ;
while(Menu){
    if((kbhit)){
        if( i == 1){
                gotoxy(20,20) ;
        //Jugar
            EstableceColor(Fondo, Texto);
            cout << setw(71) << "_ _  _ ____ ____ ____"  <<endl ;
            cout << setw(90) << " | |  | | __ |__| |__/" <<endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"<<endl ;
            EstableceColor(original);

            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Instrucciones
            cout << setw(110) <<"_ _  _ ____ ___ ____ _  _ ____ ____ _ ____ _  _ ____ ____" << endl ;
            cout << setw(109) <<"| |\\ | [__   |  |__/ |  | |    |    | |  | |\\ | |___ [__" << endl ;
            cout << setw(110) <<"| | \\| ___]  |  | \\  |__| |___ |___ | |__| | \\| |___ ___]" << endl ;


            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Salir Letra js stick letter
           ImprimeSalir();


            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Creditos
            cout << setw(95) << " __   __   ___  __    ___  __   __"  << endl ;
            cout << setw(96) << "/  ` |__) |__  |  \\ |  |  /  \\ /__`"  << endl ;
            cout << setw(96) << "\\__, |  \\ |___ |__/ |  |  \\__/ .__/"  << endl ;
            tecla = getch();

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 4 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 4){
                    i++ ;
                } else i = 1 ;
            }else if(tecla == ENTER) return ;

        }else if( i == 2){
            gotoxy(20,20) ;
        //Jugar
            cout << setw(71) << "_ _  _ ____ ____ ____" << endl ;
            cout << setw(90) << " | |  | | __ |__| |__/"  << endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"   << endl ;

            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Instrucciones
            EstableceColor(Fondo, Texto);
            cout << setw(110) << "_ _  _ ____ ___ ____ _  _ ____ ____ _ ____ _  _ ____ ____"  <<endl ;
            cout << setw(109) << "| |\\ | [__   |  |__/ |  | |    |    | |  | |\\ | |___ [__"  <<endl ;
            cout << setw(110) << "| | \\| ___]  |  | \\  |__| |___ |___ | |__| | \\| |___ ___]" <<endl ;
            EstableceColor(original);

            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Salir Letra js stick letter
            ImprimeSalir();


            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Creditos
            cout << setw(95) << " __   __   ___  __    ___  __   __"  << endl ;
            cout << setw(96) << "/  ` |__) |__  |  \\ |  |  /  \\ /__`"  << endl ;
            cout << setw(96) << "\\__, |  \\ |___ |__/ |  |  \\__/ .__/"  << endl ;

            tecla = getch();

            if(tecla == ENTER){
                Menu = false ;
                Instrucciones() ;
            }

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 4 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 4){
                    i++ ;
                } else i = 1 ;
            }

        }else if( i == 3){
            gotoxy(20,20) ;
            //Jugar
            cout << setw(71) << "_ _  _ ____ ____ ____" << endl ;
            cout << setw(90) << " | |  | | __ |__| |__/"  << endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"   << endl ;

            for(int i = 1 ; i < 3; i++) cout << endl ;

            //Instrucciones
            cout << setw(110) <<"_ _  _ ____ ___ ____ _  _ ____ ____ _ ____ _  _ ____ ____" << endl ;
            cout << setw(109)<<"| |\\ | [__   |  |__/ |  | |    |    | |  | |\\ | |___ [__" << endl ;
            cout << setw(110) <<"| | \\| ___]  |  | \\  |__| |___ |___ | |__| | \\| |___ ___]" << endl ;


            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Salir Letra js stick letter

            EstableceColor(Fondo, Texto);
            ImprimeSalir();
            EstableceColor(original);

            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Creditos
            cout << setw(95) << " __   __   ___  __    ___  __   __"  << endl ;
            cout << setw(96) << "/  ` |__) |__  |  \\ |  |  /  \\ /__`"  << endl ;
            cout << setw(96) << "\\__, |  \\ |___ |__/ |  |  \\__/ .__/"  << endl ;

            tecla = getch();

            if(tecla == ENTER){
                Menu = false ;
                Salir() ;
            }

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 4 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 4){
                    i++ ;
                } else i = 1 ;
            }

        }else if( i == 4){
            gotoxy(20,20) ;
        //Jugar
            cout << setw(71) << "_ _  _ ____ ____ ____" << endl ;
            cout << setw(90) << " | |  | | __ |__| |__/"  << endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"   << endl ;

            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Instrucciones
            cout << setw(110) <<"_ _  _ ____ ___ ____ _  _ ____ ____ _ ____ _  _ ____ ____" << endl ;
            cout << setw(109)<<"| |\\ | [__   |  |__/ |  | |    |    | |  | |\\ | |___ [__" << endl ;
            cout << setw(110) <<"| | \\| ___]  |  | \\  |__| |___ |___ | |__| | \\| |___ ___]" << endl ;


            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Salir Letra js stick letter
            ImprimeSalir();

            for(int i = 1 ; i < 3; i++) cout << endl ;

        //Creditos
            EstableceColor(Fondo, Texto);
            cout << setw(95)  << " __   __   ___  __    ___  __   __"   <<endl ;
            cout << setw(96)  << "/  ` |__) |__  |  \\ |  |  /  \\ /__`"   <<endl ;
            cout << setw(96)  << "\\__, |  \\ |___ |__/ |  |  \\__/ .__/"   <<endl ;
            EstableceColor(original);

            tecla = getch();

            if(tecla == ENTER){
                Menu = false ;
                Credito() ;
            }

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 4 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 4){
                    i++ ;
                } else i = 1 ;
            }
        }
    }
}

}




void Win(){
    system("cls");
    gotoxy(1,1);
    EstableceColor(VERDECLARO);
    for(int l = 1 ; l < 160  ; l++){
        cout << endl ;
    }
    gotoxy(1,1);
    for(int i = 1 ; i < 3 ; i++) cout << endl  ;
    cout << setw(113) << " ######      ###    ##    ##    ###     ######  ######## ########"  << endl ;
    cout << setw(113) << "##    ##    ## ##   ###   ##   ## ##   ##    ##    ##    ##      "  << endl ;
    cout << setw(113) << "##         ##   ##  ####  ##  ##   ##  ##          ##    ##      "  << endl ;
    cout << setw(113) << "##   #### ##     ## ## ## ## ##     ##  ######     ##    ######  "  << endl ;
    cout << setw(113) << "##    ##  ######### ##  #### #########       ##    ##    ##      "  << endl ;
    cout << setw(113) << "##    ##  ##     ## ##   ### ##     ## ##    ##    ##    ##      "  << endl ;
    cout << setw(113) << " ######   ##     ## ##    ## ##     ##  ######     ##    ########"  << endl ;
    for(int i = 1 ; i < 6; i++) cout << endl ;
}




void Credito(){

gotoxy(1,1);

for(int l = 1 ; l < 140  ; l++){
    for(int y = 1 ; y < 18 ; y++)cout << "  " ;
    cout << endl ;
}
gotoxy(1,1);
//Equipo
cout << setw(97)<<"Universidad de Sonora " << endl ;

for(int i = 1 ; i < 3; i++) cout << endl ;

cout << setw(92) <<  "Proyecto Final" << endl ;

for(int i = 1 ; i < 4; i++) cout << endl ;

cout << setw(95) <<  "THE DEVELOPMENT TEAM" << setw(95) << endl ;
    cout << endl << endl ;

cout << setw(99) << "Adri\240n Leonardo Soto Tequida"  <<  endl ;

cout << setw(99) << "Hugo Alberto Eguino Ar\240mbula" <<setw(74) <<  endl ;

cout << setw(100) << "Luis Ernesto Thomson Mart\241nez" << setw(74) << endl ;



    for(int i = 1 ; i < 4; i++) cout << endl ;

cout << setw(97) << "Maestra. Irene Rodr\241guez" << endl ;

    for(int i = 1 ; i < 3; i++) cout << endl ;

cout << setw(105) << "Materia: Programaci\242n de Computadoras" << endl << endl  ;

    int i = 1 ;
    char tecla;
    miColor Fondo, Texto;
    Fondo = VERDE ;
    Texto = VERDECLARO ;
    WORD original = ObtenerColorOriginal();
    bool ins = true;

while(ins){
    if((kbhit)){
        if( i == 1){
            gotoxy(20,25) ;
            //Jugar
            EstableceColor(Fondo,Texto);
            cout << setw(71) << "_ _  _ ____ ____ ____"  <<endl ;
            cout << setw(90) << " | |  | | __ |__| |__/" <<endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"<<endl ;
            EstableceColor(original);

            for(int i = 1 ; i < 3; i++) cout << endl ;

            //Salir
            ImprimeSalir();

            tecla = getch();

            if(tecla == ENTER){
                ins = false ;
                //jugar() ;
            }

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 2 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 2 ){
                    i++ ;
                }else i = 1;
            }

        }else if( i == 2){
            gotoxy(20,25) ;
                    //Jugar
            cout << setw(71) << "_ _  _ ____ ____ ____" << endl ;
            cout << setw(90) << " | |  | | __ |__| |__/"  << endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"   << endl ;


            for(int i = 1 ; i < 3; i++) cout << endl ;

            //Salir
            EstableceColor(Fondo, Texto);
            ImprimeSalir();
            EstableceColor(original);

            tecla = getch();

            if(tecla == ENTER){
                ins = false ;
                menu() ;
            }

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 2 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 2 ){
                    i++ ;
                }else i = 1;
            }

        }
    }
}

}

void Instrucciones(){
    gotoxy(1,1);

    for(int l = 1 ; l < 140  ; l++){
        for(int y = 1 ; y < 18 ; y++)cout << "  " ;
            cout << endl ;
    }
    gotoxy(1,1);

    cout << setw(110) <<"_ _  _ ____ ___ ____ _  _ ____ ____ _ ____ _  _ ____ ____" << endl ;
    cout << setw(109) <<"| |\\ | [__   |  |__/ |  | |    |    | |  | |\\ | |___ [__" << endl ;
    cout << setw(110) <<"| | \\| ___]  |  | \\  |__| |___ |___ | |__| | \\| |___ ___]" << endl ;

    cout << endl << setw(120) << left << "* Jugadores: 1" << endl;
    cout << endl << setw(120)  << "El juego consiste en lograr completar las pilas de Ases en orden ascendente reservando";
     cout << endl << setw(120)  << "cada pila para un palo exclusivo, debemos hacer esto siguiendo las reglas de traslaci\2442";
     cout << endl << setw(120)  << "de cartas, podemos escoger una carta de la pila principal o una que este en las \243ltimas ";
     cout << endl << setw(120) << "posiciones de las columnas inferiores. Las cartas que son seleccionables las podemos desplazar";
    cout << endl << setw(120)  << "a una posici\242n en otra columna, tal que su carta inferior sea ascendente en 1 seg\243un la jerarqu\241a ";
    cout << endl << setw(120)  << "de cartas, y que su color sea alterno, se pueden desplazar una carta junto con sus cartas inferiores ";
    cout << endl << setw(120)   << "si estas siguen un orden descendente y alternando colores, la pila principal puede usarse para tomar ";
    cout << endl << setw(120)  << "la carta superior si no se puede tomar ninguna en el \240rea de las columnas\n\n\nLas pilas de ases que debemos";
    cout << endl << setw(120)  << "llenar para ganar solo se pueden llenar en orden ascendente empezando en la A, recordando que es un palo exclusivo";
    cout << endl << setw(120)  << "para cada pila."<< endl;
    cout << endl << setw(120)  << "  \n\n\n\n\n Usa las flechas direccionales o W A S y D para moverte, y presiona enter para seleccionar la carta";
    cout << endl << setw(120) << "o imprimir una carta seleccionada"<< endl;
    cout << endl << endl << endl << endl << endl;
    cout << right;


    int i = 1 ;
    char tecla;
    miColor Fondo, Texto;
    Fondo = VERDE ;
    Texto = VERDECLARO ;
    WORD original = ObtenerColorOriginal();
    bool ins = true;

while(ins){
    if((kbhit)){
        if( i == 1){
            gotoxy(20,40) ;
            //Jugar
            EstableceColor(Fondo,Texto);
            cout << setw(71) << "_ _  _ ____ ____ ____"  <<endl ;
            cout << setw(90) << " | |  | | __ |__| |__/" <<endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"<<endl ;
            EstableceColor(original);

            for(int i = 1 ; i < 3; i++) cout << endl ;

            //Salir
            ImprimeSalir();

            tecla = getch();

            if(tecla == ENTER){
                ins = false ;
                //jugar() ;
            }

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 2 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 2 ){
                    i++ ;
                }else i = 1;
            }

        }else if( i == 2){
            gotoxy(20,40) ;
                    //Jugar
            cout << setw(71) << "_ _  _ ____ ____ ____" << endl ;
            cout << setw(90) << " | |  | | __ |__| |__/"  << endl ;
            cout << setw(90) << "_| |__| |__] |  | |  \\"   << endl ;


            for(int i = 1 ; i < 3; i++) cout << endl ;

            //Salir
            EstableceColor(Fondo, Texto);
            ImprimeSalir();
            EstableceColor(original);

            tecla = getch();

            if(tecla == ENTER){
                ins = false ;
                menu() ;
            }

            if(tecla == FLECHA_ARRIBA){
                if(i > 1){
                    i-- ;
                }else i = 2 ;
            }else if(tecla == FLECHA_ABAJO ){
                if(i < 2 ){
                    i++ ;
                }else i = 1;
            }

        }
    }
}
}

int Salir(){
    gotoxy(1,1);

    for(int l = 1 ; l < 140  ; l++){
        for(int y = 1 ; y < 18 ; y++)cout << "  " ;
            cout << endl ;
    }
    gotoxy(1,1);

    cout << setw(95) << "Gracias por jugar" << endl ;

    Sleep(100);
    return 0 ;
}

void ImprimeSalir(){
    cout << setw(88) << "__               __"  << endl ;
    cout << setw(89) <<"/__`  /\\  |    | |__)" << endl ;
    cout << setw(90) <<".__/ /--\\ |___ | |  \\ " << endl ;
}
