//
// Created by koco on 15/05/2023.
//

#include "commands.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


/*
 * Fonction qui crée une commande pour recupérer la saisi de l'utilisateur
 */

Command* create_command() {
    Command* cmd = (Command*) malloc(sizeof(Command));
    cmd->name[0] = '\0';
    cmd->int_size = 0;
    cmd->str_size = 0;
    cmd->color_size = 0;
    return cmd;
}

/*
 * Fonction qui recuperer tous les caracteres saisi par l'utilisateur apres la commande principale
 */
void add_str_param(Command* cmd,  char* p) {
    cmd->str_params[cmd->str_size] = p;
    cmd->str_size++;
}
void add_str_color(Command* cmd,  char* p) {
    cmd->str_color[cmd->str_size] = p;
    cmd->color_size++;
}

/*
 * Fonction qui recuperer tous les nombres saisi par l'utilisateur apres la commande principale
 */
void add_int_param(Command* cmd, int p) {

    cmd->int_params[cmd->int_size++] = p;

}
/*
 * Fonction l'espace allouer pour la commande
 */
void free_cmd(Command* cmd) {
    for (int i = 0; i < cmd->str_size; i++) {
        free(cmd->str_params[i]);
    }
    free(cmd);
}

/*
 * Fonction qui permet d'afficher l'ensemble des formes se trouvant dans area
 */
void afficher_formes(Area* area){
    if (area->nb_shape==0){
        printf("\n>> Il n'y a pas de forme dans la liste \n\n");
    }else{
        printf("\n>> Liste des formes : \n\n");
        for (int i = 0; i < area->nb_shape; i++) {
            printf("%d) ",i+1);
            print_shape(area->shapes[i]);
            printf("\n");
    }
    }
}

/*
 * Fonction qui éxécute la commande taper par l'utilisateur
 * regarde la commande principale et execute le bon code
 */
int read_exec_command(Command* cmd,Area* area) {

    enum CommandName name;
    if (strcmp(cmd->name, "point") == 0) {
        name = point;
    } else if (strcmp(cmd->name, "line") == 0) {
        name = line;
    } else if (strcmp(cmd->name, "square") == 0) {
        name = square;
    } else if (strcmp(cmd->name, "rectangle") == 0) {
        name = rectangle;
    } else if (strcmp(cmd->name, "circle") == 0) {
        name = circle;
    } else if (strcmp(cmd->name, "polygon") == 0) {
        name = polygon;
    } else if (strcmp(cmd->name, "clear") == 0) {
        name = clear;
    } else if (strcmp(cmd->name, "plot") == 0) {
        name = plot;
    } else if (strcmp(cmd->name, "list") == 0) {
        name = list;
    } else if (strcmp(cmd->name, "erase") == 0) {
        name = erase;
    } else if (strcmp(cmd->name, "quit") == 0) {
        name = quit;
    } else if (strcmp(cmd->name, "delete") == 0) {
        name = delete;
    } else if (strcmp(cmd->name, "help") == 0) {
        name = help;
    } else {
        name= error;
    }

    Shape* s;
    int liste_sommet [100];
    switch (name) {
        case point:
            for (int i=0;i<2;i++){
                if (cmd->int_params[i]<=0 || cmd->int_params[i]>area->width  ){
                    printf("\033[0;31m>> Valeur manquantes ou impossible\n\033[0m");
                    return 0;}
            }
            s= create_point_shape(cmd->int_params[0],cmd->int_params[1],cmd->str_color[0]);
            add_shape_to_area(area,s);
            draw_area(area);

            break;
        case circle:
            for (int i=0;i<3;i++){
                if (cmd->int_params[i]<=0 || cmd->int_params[i]>area->width  ){
                    printf("\033[0;31m>> Valeur manquantes ou impossible\n\033[0m");
                    return 0;}
            }
            s= create_circle_shape(cmd->int_params[0],cmd->int_params[1],cmd->int_params[2],cmd->str_color[0]);
            add_shape_to_area(area,s);
            draw_area(area);
            break;
        case line:
            for (int i=0;i<4;i++){
                if (cmd->int_params[i]<=0 || cmd->int_params[i]>area->width  ){
                    printf("\033[0;31m>> Valeur manquantes ou impossible\n\033[0m");
                    return 0;}
            }
            s= create_line_shape(cmd->int_params[0],cmd->int_params[1],cmd->int_params[2],cmd->int_params[3],cmd->str_color[0]);
            add_shape_to_area(area,s);
            draw_area(area);
            break;

        case square:
            for (int i=0;i<3;i++){
                if (cmd->int_params[i]<=0 || cmd->int_params[i]>area->width  ){
                    printf("\033[0;31m>> Valeur manquantes ou impossible\n\033[0m");
                    return 0;}
            }
            s= create_square_shape(cmd->int_params[0],cmd->int_params[1],cmd->int_params[2],cmd->str_color[0]);
            add_shape_to_area(area,s);
            draw_area(area);
            break;
        case rectangle:
            for (int i=0;i<4;i++){
                if (cmd->int_params[i]<=0 || cmd->int_params[i]>area->width  ){
                    printf("\033[0;31m>> Valeur manquantes ou impossible\n\033[0m");
                    return 0;}
            }
            s= create_rectangle_shape(cmd->int_params[0],cmd->int_params[1],cmd->int_params[2],cmd->int_params[3],cmd->str_color[0]);
            add_shape_to_area(area,s);

            draw_area(area);
            break;
        case polygon:
            for (int i=0;i<1;i++){
                if (cmd->int_params[i]<=0 || cmd->int_params[i]>area->width  ){
                    printf("\033[0;31m>> Valeur manquantes ou impossible\n\033[0m");
                    return 0;}
            }
            s= create_polygon_shape( liste_sommet,cmd->int_params[0],cmd->str_color[0]);
            add_shape_to_area(area,s);
            draw_area(area);

            while (getchar() != '\n');// libere la mémoire de la saisi pris par scanf
            break;
        case clear:
            system("cls");// clear si mac
            break;
        case quit:
            return 1 ;
        case plot:

            print_area(area);
            break;
        case list:
            afficher_formes(area);
            break;
        case delete:
            if (area->nb_shape==0){
                printf("\033[0;31m\n>> Il n'y a pas de forme à supprimer !! \n\033[0m");
            }
            else if (cmd->int_params[0] < 1 || cmd->int_params[0] > area->nb_shape) {
                printf("\n>> Indice de forme invalide !! \n");
            }else{
                printf("\n>> Supression de la forme %d \n\n",cmd->int_params[0]);

                delete_shape(area->shapes[cmd->int_params[0]-1]);
                clear_area(area);

                for(int i= cmd->int_params[0]-1;i<(area->nb_shape);i++){
                    area->shapes[i]=area->shapes[i+1];
                }
                area->nb_shape--;

            }draw_area(area);

            break;
        case erase:
            if (area->nb_shape==0){
                printf("\033[0;31m\n>> Il n'y a pas de forme a supprimer !!\n\n\033[0m");
            }
            else{
                printf("\n>> Supression de toutes les formes !!\n\n");
                erase_area(area);
                clear_area(area);
                draw_area(area);
            }
            break;
        case help:

            printf(" - \033[0;32mclear\033[0m : effacer l'ecran\n"
                   " - \033[0;32mquit\033[0m : quitter le programme\n"
                   " - \033[0;32mpoint\033[0m x y : ajouter un point\n"
                   " - \033[0;32mline\033[0m x1 y1 x2 y2 : ajouter un segment reliant deux points (x1, y1) et (x2, y2)\n"
                   " - \033[0;32mcircle\033[0m x y radius : ajouter un cercle de centre (x, y) et de rayon radius\n"
                   " - \033[0;32msquare\033[0m x y length : ajouter un carre dont le coin superieur gauche est (x, y) et de cote length.\n"
                   " - \033[0;32mrectangle\033[0m x y width height : ajouter un rectangle dont le coin superieur gauche est (x, y), de\n"
                   "   largeur width et de longueur height\n"
                   " - \033[0;32mpolygon\033[0m x1 y1 x2 y2 x3 y3 ... ... : ajouter un polygone avec la liste des points donnes\n"
                   " - \033[0;32mplot\033[0m : rafraichir l'ecran pour afficher toutes les formes geometriques de l'image (en fonction des\n"
                   "   regles d'affichage)\n"
                   " - \033[0;32mlist\033[0m : afficher la liste de l'ensemble des formes geometriques qui composent l'image ainsi que\n"
                   "   toutes leurs informations\n"
                   " - \033[0;32mdelete\033[0m id : supprimer une forme a partir de son identifiant id.\n"
                   " - \033[0;32merase\033[0m : supprimer toutes les formes d'une image.\n"
                   " - \033[0;32mhelp\033[0m : afficher la liste des commandes ainsi qu'un mini mode d'emploi permettant a l'utilisateur\n"
                   "   d'utiliser les commandes correctement.\n\n"
                   " \033[0;34mPS: Vous pouvez rajouter une couleur : red, green, black, yellow, blue ou white apres le nom de la forme pour changer la couleur des formes. La couleur par defaut est le blanc.\033[0m\n\n");
            break;
        case error:
            printf("\033[0;31m>> Commande inconue\n\033[0m");

            break;
    }

    return 0;
}


/*
 * Fonction qui lit la commande taper par l'utilisateur
 * et sépare la saisie en commande principale et nombre/ caracteres en plus
 */

void read_from_stdin(Command* cmd) {
    char *p = (char*) malloc(100 * sizeof(char));
    int p_len = 0,max_len=0;

    printf("\033[33mEntrez une commande :\033[0m");
    fgets( p, 100, stdin);

    // Supprimer le caractère de retour à la ligne à la fin de la saisie
    while (p[max_len] != '\0') {
        max_len++;
    }

    while (p[p_len]!=' ' && p[p_len]!='\n') {
        cmd->name[p_len] = p[p_len];
        p_len++;
    }

    cmd->name[p_len] = '\0';

    int i =p_len;

    while (i < max_len) {

        // Si le caractère suivant est un espace, passer au paramètre suivant
        if (p[i] == ' ') {
            i++;
           continue;
        }

        // Si le caractère suivant est un chiffre, récupérer l'entier suivant
        if (isdigit(p[i])) {
            int tmp = i;
            while (isdigit(p[tmp])) {
                tmp++;
            }
            char entier[tmp - i + 1];
            strncpy(entier, p + i, tmp - i);
            entier[tmp - i] = '\0';
            add_int_param(cmd, strtol(entier, NULL, 10));
            i = tmp;
        }
            // Sinon, récupérer la chaîne de caractères suivante
        else {
            int tmp = i;
            while (p[tmp] != ' ' && p[tmp] != '\0') {
                tmp++;
            }
            char* chaine = (char*) malloc(tmp - i + 1);
            strncpy(chaine, p + i, tmp - i);
            chaine[tmp - i] = '\0';


            if (strcmp(chaine, "red") == 0  || strcmp(chaine, "white") == 0 || strcmp(chaine, "black") == 0 || strcmp(chaine, "yellow") == 0 || strcmp(chaine, "blue") == 0|| strcmp(chaine, "green") == 0){
                add_str_color(cmd, chaine);

            }
            else{
                add_str_param(cmd, chaine);
            }

            i = tmp;

        }
    }
    if(cmd->color_size==0){
        cmd->str_color[0]="white";
    }


}
