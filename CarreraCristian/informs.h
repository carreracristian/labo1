#ifndef INFORMS_H_INCLUDED
#define INFORMS_H_INCLUDED



#endif // INFORMS_H_INCLUDED

int menuInformes();
void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarImporteCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC);
void clientesSinAlquilar(eCliente cliente[],int tam, eAlquiler alq[],int tamAl);
void juegosSinAlquilar(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarImporteJuego(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarImporteCategoria(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void cantidadDeAlquileresPorJuegos(eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarCantidadDeAlquileresPorJuego(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
void mostrarAlquileresDeTodosJuegos( eCliente cliente[],int tam, eAlquiler alq[], eCliente vec,int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ);
