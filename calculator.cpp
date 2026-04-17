#include <iostream> // Neste código, tentei tirar os acentos das palavras, pois no meu terminal estes estavam a aparecer como outros caracteres especiais. 
#include <windows.h>
using namespace std;
const int numDisciplinas=10; 
const int maxModulos=10; 
string nomeDisciplinas[numDisciplinas] = 
{
    "Portugues", "Matematica", "Ingles", "Fisico-Quimica",
    "Educaçao Fisica", "Área de Integração", "Sistemas Operativos",
    "Redes", "TIC", "Programaçao"
};
struct notas
{
    float valor[numDisciplinas]; 
}d[numDisciplinas];
void inserirNotas()
{
    int i, c, opc, mod;
    float mediaCurso=0, somaCurso=0, mediaDisciplina[numDisciplinas]={0}, somaDisciplinas[numDisciplinas]={0}; 
    do
    {
        cout<<"1 - Calcular Medias"<<endl;
        cout<<"2 - Sair"<<endl;
        cin>>opc;
        switch(opc)
        {
            case 1:
            {
                somaCurso = 0;
                mediaCurso = 0;
                for(int z=0; z<numDisciplinas; z++) 
                {
                    somaDisciplinas[z] = 0;
                    mediaDisciplina[z] = 0;
                }
                for(i=0; i<numDisciplinas; i++)
                {
                    system("cls");
                    cout<<nomeDisciplinas[i]<<endl;
                    cout<<"Quantos modulos?"<<endl;
                    cin>>mod;
                    while(mod>maxModulos || mod<0)
                    {
                        cout<<"Quantidade de modulos invalida, tente novamente"<<endl;
                        cin>>mod;
                    }
                    for(c=0; c<mod; c++)
                    {
                        cout<<"Indique a nota"<<endl;
                        cin>>d[i].valor[c];
                        while(d[i].valor[c]>20 || d[i].valor[c]<0)
                        {
                            cout<<"Nota invalida, tente novamente"<<endl;
                            cin>>d[i].valor[c];
                        }
                        somaDisciplinas[i]=somaDisciplinas[i]+d[i].valor[c];
                    }
                    mediaDisciplina[i]=somaDisciplinas[i]/mod;
                }
                for(i=0; i<numDisciplinas; i++)
                {
                    somaCurso=somaCurso+mediaDisciplina[i];
                }
                mediaCurso=somaCurso/numDisciplinas;
                system("cls");
                for(i=0; i<numDisciplinas; i++)
                {
                    cout<<""<<endl;
                    cout<<nomeDisciplinas[i]<<" = "<<mediaDisciplina[i]<<endl;
                }
                cout<<""<<endl;
                cout<<"Media do curso = "<<mediaCurso<<endl;
                cout<<""<<endl;
                system("pause");
                system("cls");
            }
            break;
            case 2:
            {
                return;
            }
            break;
            default: 
            {
                cout<<"Opção invalida. Tente novamente"<<endl;
                cin>>opc;
            }
            break;
        }
    }while(opc!=2);
}
int main() 
{
    setlocale(LC_ALL, "Portuguese");
    inserirNotas();
    return 0;
}