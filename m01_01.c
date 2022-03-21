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
    int i = 0;
    char *data;
    do
    {
        scanf("\n");    // untuk membuat sebuah baris baru
        fgets(input, sizeof(input), stdin); //menyimpan nilai input
        if (strstr(input, "student-show-all")!=NULL) {  // strstr berfungsi untuk menemukan sebuah string dalam string
            for (int j = 0; j < jlhmahasiswa; j++)
            {
                printf("%s|%s|%.2f\n", Mahasiswa[j].id, Mahasiswa[j].name, Mahasiswa[j].gpa);
            } 
        } else if (strstr(input, "student-add")!=NULL){
            data = strtok(input, "#");  //strtok untuk memisahkan string dengan tanda #
            data = strtok(NULL, "#");
            strcpy(Mahasiswa[i].id, data);  //strcpy untuk mengcopy suatu string ke string lainnya
            data = strtok(NULL, "#");
            strcpy(Mahasiswa[i].name, data);
            data = strtok(NULL, "#");
            Mahasiswa[i].gpa = atof(data);  //atof meengubah string menjadi float
            jlhmahasiswa = i+1;
            i++;
        }
    } while (strcmp(input, "---")!=0 && i<100);
    return 0;
}
