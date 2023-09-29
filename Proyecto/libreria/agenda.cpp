#include "agenda.h"
#include <iostream>

bool hayEspacio(sAgenda* miAgenda) {
    return (miAgenda->CantMaxima - miAgenda->CantContactos > 0);
}

/**
 * @brief Función agregar contacto a la agenda
 * @return Error: ErrAgrEspacio, sino ExitoAgregar
 */
eAgrContacto agregarContacto(sAgenda* miAgenda, sContacto miContacto) {
    if (!hayEspacio(miAgenda))
        return eAgrContacto::ErrAgrEspacio;

    miAgenda->CantContactos++;
    miAgenda->misContactos[miAgenda->CantContactos - 1] = miContacto;
    return eAgrContacto::ExitoAgregar;
}

/**
 * @brief Función actualiza el contacto con los datos recibidos dentro de sContacto
 * @return Error: ErrUpdContacto, ErrUpdIndex, sino ExitoModificar
 */
eUpdContacto actualizarContacto(sAgenda* miAgenda, sContacto miContacto) {
    sContacto* aux = miAgenda->misContactos,
             * ultimo = (miAgenda->misContactos) + miAgenda->CantContactos - 1;
    while(true) {
        if ((aux->Nombre == miContacto.Nombre && aux->Apellido == miContacto.Apellido) ||
            (aux->Correo == miContacto.Correo)) {
            *aux = miContacto;
            return eUpdContacto::ExitoModificar;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eUpdContacto::ErrUpdContacto;
}
/**
 * @brief Función actualiza el contacto en el indice indicado con los datos recibidos dentro de sContacto
 * @return Error: ErrUpdContacto, ErrUpdIndex, sino ExitoModificar
 */
eUpdContacto actualizarContacto(sAgenda* miAgenda, u_int indexContacto, sContacto miContacto) {
    if (indexContacto >= miAgenda->CantMaxima)
        return eUpdContacto::ErrUpdIndex;

    sContacto* aux = miAgenda->misContactos + indexContacto;

    if ((aux->Nombre == miContacto.Nombre && aux->Apellido == miContacto.Apellido) ||
        (aux->Correo == miContacto.Correo)) {
        *aux = miContacto;
        return eUpdContacto::ExitoModificar;
    }

    return eUpdContacto::ErrUpdContacto;
}

/**
 * @brief Función remueve al contacto indicado por nombre y apellido
 * @return Error: ErrSrchValor, ErrSrchIndex, sino ExitoBuscar
 */
eRmContacto removerContacto(sAgenda* miAgenda, str Nombre, str Apellido) {
    sContacto* aux = miAgenda->misContactos,
        * ultimo = (miAgenda->misContactos) + miAgenda->CantContactos - 1;
    while(true) {
        if ((aux->Nombre == Nombre && aux->Apellido == Apellido)) {
            *aux = ContactoNulo;
            return eRmContacto::ExitoRemover;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eRmContacto::ErrRmNomApe;
}
/**
 * @brief Función remueve al contacto indicado por sContacto
 * @return Error: ErrSrchValor, ErrSrchIndex, sino ExitoBuscar
 */
eRmContacto removerContacto(sAgenda* miAgenda, sContacto miContacto) {
    sContacto* aux = miAgenda->misContactos,
        * ultimo = (miAgenda->misContactos) + miAgenda->CantContactos - 1;
    while(true) {
        if ((aux->Nombre == miContacto.Nombre && aux->Apellido == miContacto.Apellido) ||
            (aux->Correo == miContacto.Correo)) {
            *aux = ContactoNulo;
            return eRmContacto::ExitoRemover;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eRmContacto::ErrRmContacto;
}
/**
 * @brief Función remueve al contacto indicado por indice
 * @return Error: ErrSrchValor, ErrSrchIndex, sino ExitoBuscar
 */
eRmContacto removerContacto(sAgenda* miAgenda, u_int indexContacto) {
    if (indexContacto >= miAgenda->CantMaxima)
        return eRmContacto::ErrRmIndex;

    sContacto* aux = miAgenda->misContactos + indexContacto;
    *aux = ContactoNulo;
    return eRmContacto::ExitoRemover;
}

/**
 * @brief Función de buscar contacto por Nombre Y Apellido o email
 * @return Error: Nullptr, sino Contacto
 */
sContacto buscarContacto(sAgenda* miAgenda, str valorBusqueda) {
    sContacto* aux = miAgenda->misContactos,
        * ultimo = (miAgenda->misContactos) + miAgenda->CantContactos - 1;
    while(true) {
        if (((aux->Nombre + " " + aux->Apellido) == valorBusqueda) ||
            (aux->Correo == valorBusqueda)) {
            return *aux;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return ContactoNulo;
}
/**
 * @brief Función de buscar contacto por indice
 * @return Error: Nullptr, sino Contacto
 */
sContacto buscarContacto(sAgenda* miAgenda, u_int indexContacto) {
    return indexContacto >= miAgenda->CantContactos - 1 ? ContactoNulo : miAgenda->misContactos[indexContacto];
}

eRmContacto removerContacto(sAgenda* miAgenda, eGrupo grupoContacto) {//ESTA ES LA REMOVER POR GRUPO

    sContacto* aux = miAgenda->misContactos,
        * ultimo = (miAgenda->misContactos) + miAgenda->CantContactos - 1;// sirve para saber cuantos son porque con esto tengo apuntada la 1era pos y la ultima

       while(true) {
        if (aux->Grupo == miAgenda->misContactos->Grupo) {//busco el contacto que tenga el mismo grupo que el pasado a la funcion
            *aux = ContactoNulo;
            return eRmContacto::ExitoRemover;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eRmContacto::ErrRmGrupo;//?!!!!!!!!!!!!!!????????????????
}


