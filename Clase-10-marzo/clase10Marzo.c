#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nombre[80];
    char apellido[80];
    char curso[80];
    char codigo[10];
    int ID;
    float calificacion;
} estudiante;

int main() {
    // TAREA: streams / text streams
    // Apuntador al archivo
    FILE *fp; 
    // Crear el archivo que hará las veces de base de datos
    //fp = fopen("DatosEstudiantes.csv", "a+");

    /* ================================================
       == Variables Creadas en Tiempo de Compilación ==
       ================================================
    
    // String de almacenamiento temporal;
    char temp[80];
    char *ptemp = &temp[0];
    // Almacenamiento temporal de datos numéricos
    int xTemp = 0;
    float yTemp = 0;
    */
    char *ptemp = malloc(80 * sizeof(char));
    int *xTemp = malloc(sizeof(int));
    float *yTemp = malloc(sizeof(float));

    /*  ===================================
        == Escritura de datos en archivo == 
        ===================================
    */
    // Datos del usuario, leídos desde "stdin"
    /*printf("Nombre: ");
    scanf("%s", ptemp);
    fprintf(fp, "%s,", ptemp);
    
    printf("Apellido: ");
    scanf("%s", ptemp);
    fprintf(fp, "%s,", ptemp);
    
    printf("ID: ");
    scanf("%d", xTemp);
    fprintf(fp, "%d,", *xTemp);

    printf("Espacio académico: ");
    scanf("%s", ptemp);
    fprintf(fp, "%s,", ptemp);
    
    printf("Código espacio académico: ");
    scanf("%s", ptemp);
    fprintf(fp, "%s,", ptemp);

    printf("Calificación: ");
    scanf("%f", yTemp);
    fprintf(fp, "%f\n", *yTemp);

    free(ptemp);
    free(xTemp);
    free(yTemp);
    fclose(fp);*/

    /*  =================================
        == Lectura de datos en archivo == 
        ==================================
    */
    fp = fopen("DatosEstudiantes.csv", "r+");
    estudiante e1;
    char datoleido[100];
    //fscanf(fp, "%s %s %d %s %s %f", e1.nombre, e1.apellido, &e1.ID, e1.curso, e1.codigo, &e1.calificacion);
    fscanf(fp, "%s", datoleido);
    printf("Dato leido: %s\n", datoleido);
    fclose(fp);
    //printf("Nombre estudiante %s\n", e1.nombre);
    //printf("Calificación: %f\n", e1.calificacion);

    

    return 0;
}