cmake_minimum_required(VERSION 3.27)
project(Proyectoll_Progra_CLion)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyectoll_Progra_CLion main.cpp
        Curso.cpp
        Profesor.h
        Profesor.cpp
        Grupo.h
        Grupo.cpp
        ListaCursos.h
        ListaCursos.cpp
        NodoCursos.h
        NodoCursos.cpp
        ListaGrupos.h
        ListaGrupos.cpp
        NodoGrupos.h
        NodoGrupos.cpp
        NodoProfesores.h
        NodoProfesores.cpp
        ListaProfesores.h
        ListaProfesores.cpp
        Menu.h
        Menu.cpp
        Universidad.cpp
        Universidad.h)
