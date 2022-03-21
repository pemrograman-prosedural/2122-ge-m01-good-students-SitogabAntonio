// 12S21015 - Sitogab Antonio Octavianus Girsang
// 12S21049 - Jesika Audina Purba

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
    char id[10];
    char name[50];
    float gpa;
} _Mahasiswa;


int main(){
    _Mahasiswa Mahasiswa[100];
    char input[100];
    int jlhmahasiswa;
    int i = 0, id=0;
    char *data;
    do
    {
        scanf("\n");
        gets(input);
        if (strstr(input, "student-show-all")!=NULL) {
            for (int j = 0; j < jlhmahasiswa; j++)
            {
                printf("%s|%s|%.2f\n", Mahasiswa[j].id, Mahasiswa[j].name, Mahasiswa[j].gpa);
            } 
        } else if (strstr(input, "student-add")!=NULL){
            data = strtok(input, "#");
            data = strtok(NULL, "#");
            strcpy(Mahasiswa[i].id, data);
            data = strtok(NULL, "#");
            strcpy(Mahasiswa[i].name, data);
            data = strtok(NULL, "#");
            Mahasiswa[i].gpa = atof(data);
            jlhmahasiswa = i+1;
            i++;
        } else if (strstr(input, "student-show-best")!=NULL){
            for(int j = 0; j < jlhmahasiswa; j++){
                if(Mahasiswa[j].gpa < Mahasiswa[j+1].gpa){
                    id=j+1;
                    
                }
            }
            printf("%s|%s|%.2f\n", Mahasiswa[id].id, Mahasiswa[id].name, Mahasiswa[id].gpa);
        }
        
    } while (strcmp(input, "---")!=0 && i<100);
    return 0;
}
