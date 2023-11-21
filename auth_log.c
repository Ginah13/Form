
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

    int main(){

        FILE* fich=fopen("/var/log/auth.log","r");  //le contenu dans ce fichier est dans le fich
        char* contenu = malloc(2000);

        printf("Content-type:text/html\n\n");
        printf("<!DOCTYPE html>\n\n");
        printf("<html>\n");
        printf("<head> <title> /var/log/auth.log </title> <meta charset=\"utf-8\"> </head>\n");
        printf("<body style=\"background-color: rgb(196, 248, 248);  \"> \n");
        printf("<br><h1 align=\"center\"><b>/VAR/LOG/AUTH.LOG</b></h1></br>\n");
        
        
        if(fich == NULL){
            printf("erreur d'allocation\n");
            exit(1);
        }

/// Initialisation des donnees
        char mois[100];
        char day[20];
        char hour[100];
        char session[100];
        char user[100];

         printf("<p><style type=\"text/css\">");
         printf("td{padding-left: 50px;padding-right: 50px;padding-bottom: 20px;padding-top: 20px;}");
         printf("</style>");   
         printf("<center><table border>");
         printf("<tr>");
         printf("<td><b style=\"color: red;\">MONTH</b></td>");
         printf("<td><b style=\"color: red;\">DAY</b></td>");
         printf("<td><b style=\"color:red;\"><b>TIME</b></td>");
         printf("<td><b style=\"color: red;\">SESSION</b></td>");
         printf("<td><b style=\"color: red;\"><b>USER</b></td>");
         printf("</tr></p>");

    
        while(feof(fich)!=1){
            fgets(contenu,2000,fich);    // on met le truc dans le fich dans le contenu
            sscanf(contenu,"%[^ ]  %[^ ]  %[^ ]  %*[^:]: %*[^ ]  session %[^ ] for user %[^ ]  %*[\n]",mois, day, hour ,session, user);
        // printf("%s<br>", contenu);

        if(strstr( contenu,"session opened")!=NULL || strstr( contenu,"session closed")!=NULL){   // on cherche <opened et closed> dans le chaine de caractères
            char couleur[20];
            (strcmp(session,"opened")==0)?strcpy(couleur,"blue"):strcpy(couleur,"green");
            printf("<tr> <td>%s</td> <td>%s</td> <td>%s</td> <td style=\"color: %s\";>%s</td> <td>%s</td> </tr>", mois, day, hour, couleur , session, user);

             }
        }
    
         printf("</table></center>");
         printf("</body>\n");
         printf("</html>\n");
         fclose(fich);
        return 0;
}