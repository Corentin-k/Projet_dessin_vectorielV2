//
// Created by koco on 21/04/2023.
//

#include "Menu.h"
#include <stdio.h>
#include "Shape.h"

Shape* liste_shape[255];
int Taille_liste_shape;
void menu(){

    char choix;
    printf("Veuillez choisir une action :\n");
    printf("    A- Ajouter une forme \n");
    printf("    B- Afficher la liste des formes \n");
    printf("    C- Supprimer une forme \n");
    printf("    D- Tracer le dessin \n");
    printf("    E- Aide\n");
    printf(">> ");
    scanf(" %c",&choix);


    switch (choix) {

        case 'A': {
            int choix_forme = 0;
            while (choix_forme != 7) {
                printf("Veuillez choisir une action :\n");
                printf("    1- Ajouter un point\n");
                printf("    2- Ajouter une ligne\n");
                printf("    3- Ajouter cercle\n");
                printf("    4- Ajouter un carre\n");
                printf("    5- Ajouter un rectangle\n");
                printf("    6- Ajouter un polygone\n");
                printf("    7- Revenir au menu precedent\n");
                printf(">> ");
                scanf(" %d", &choix_forme);


                liste_choix_formes(choix_forme);
            }
            printf("Retour au menu\n");
            menu();

        }
        case 'B': {
            if (Taille_liste_shape==0){
                printf("\nIl n'y a pas de forme à afficher !! \n\n");
            }
            else{
                printf("\nListe des formes : \n\n");
                afficher_formes();
            }
            menu();
        }
        case 'C': {
            if (Taille_liste_shape==0){
                printf("\nIl n'y a pas de forme à supprimer !! \n\n");
            }
            else{
                printf("\nSupression des formes : \n\n");
                afficher_formes();
                printf("Quelle formes voulez vous supprimer : \n");
                int numero_forme;
                scanf("%d",&numero_forme);
                delete_shape(liste_shape[numero_forme-1]);
                for(int i= numero_forme-1;i<Taille_liste_shape;i++){
                    liste_shape[i]=liste_shape[i+1];
                }Taille_liste_shape--;
            }
            menu();
        }
        case 'D': {
            printf("Voici le dessin !!");
            menu();
        }
        case 'E': {
            printf("Help!!");
            menu();
        }
        default:
            printf("Cette lettre n'existe pas !!!\n");
            menu();

    }
}


void liste_choix_formes(int choix_forme){
/* Mettre une condition que le nombre de forme possible n'est pas depasse*/
    switch (choix_forme) {

        case 1: {int x,y;

            printf("Saisir les informations du point :\n");
            printf("Saisir le  point x y :\n >>");
            scanf(" %d %d", &x, &y);
            Shape* p= create_point_shape(x,y);
            liste_shape[Taille_liste_shape++]=p;
            break;
        }

        case 2: { int x1,x2, y1,y2;

            printf("Saisir les informations de la ligne :\n");
            printf("Saisir le premier point x1 y1 :\n>>");
            scanf(" %d %d", &x1, &y1);
            printf(">> Saisir le deuxieme point x2 y2 :\n>>");
            scanf(" %d %d", &x2,&y2 );
            Shape* l= create_line_shape(x1,x2, y1,y2);
            liste_shape[Taille_liste_shape++]=l;
            break;
        }
        case 3: { int x,y,rayon;

            printf("Saisir les informations du cercle :\n");

            printf("Saisir le premier point x y :\n>>");
            scanf(" %d %d", &x, &y);
            printf("Saisir le rayon :\n >>");
            scanf(" %d",&rayon);
            Shape* c= create_circle_shape(x,y,rayon);
            liste_shape[Taille_liste_shape++]=c;
            break;
        }
        case 4: {int x, y, length;

            printf("Saisir les informations du carre :\n");
            printf("Saisir le point x y :\n>>");
            scanf(" %d %d", &x, &y);
            printf("Saisir la longueur\n>>");
            scanf(" %d",&length);
            Shape* s= create_square_shape(x,y,length);
            liste_shape[Taille_liste_shape++]=s;
            break;
        }
        case 5: {int x, y, witdh,height;

            printf("Saisir les informations du rectangle :\n");
            printf("Saisir le point x y :\n>>");
            scanf(" %d %d", &x, &y);
            printf("Saisir la largeur\n>>");
            scanf(" %d",&witdh);
            printf("Saisir la hauteur\n>>");
            scanf(" %d",&height);
            Shape* r= create_rectangle_shape(x,y,witdh,height);
            liste_shape[Taille_liste_shape++]=r;
            break;
        }
        case 6: {int nb_sommets;

            printf("Saisir les informations du polygone :\n");
            printf("Saisir le nombre de sommet :\n>>");
            scanf(" %d",&nb_sommets);
            int liste_sommet [100];
            Shape* p= create_polygon_shape( liste_sommet,nb_sommets);
            liste_shape[Taille_liste_shape++]=p;
            break;
        }
        case 7: {

            break;
        }
        default:
            printf("Ce nombre n'existe pas !!!\n");
            break;

    }
}

