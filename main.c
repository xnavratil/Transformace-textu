#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define MAXZNAKOV 50
#define MAXOPERATOROV 50

/**
 * @brief nacitajCislo funkcia ktorou nacitam cislo ak ho treba (operand != ~)

 * @param pocetOp  aby som vedel kolko znakov vo formuli mam

 * @param argI argument I kvoli bonusu, ak argI = 1,
 * tak sa funkcie na upravu dat spravaju inac, miesto cisla pouziju I

 * @return cislo ak som nacital cislo,
 * tak ho zo stringu ulozim cez atoi do 'cislo' a to potom vratim,
 * inac vratim string s hodnotou 'i'
 */


uint8_t nacitajCislo(short int *pocetOp, int *argI){
    uint8_t cislo = 0;
    char cisloS[4] = "";
    int i = 0;

    scanf("%3s",cisloS);
    while(cisloS[i] != '\0'){
        if (cisloS[0] == 'i'){
            *argI = 1;
            return cisloS[1];
        }
        if ((cisloS[i] < 48)||(cisloS[i]>57)){
            printf("neplatny vstup\n");
            exit(0);
        }
        (*pocetOp)++;
        i++;
        // v zadani je ze netreba riesit ze dostanem viac ako 50 znakov do formule inac by som to tu upravil
    }

    cislo = atoi(cisloS);
    return cislo;

}
/**
 * @brief power knizna funkcia pow vracia double tak aby som mal istotu ze vysledok je korektny tak som si spravil vlastnu funkciu
 * potrebujem kvoli bitovemu posunu, dalo by sa aj inac ale toto sa mi najviac pacilo

 * @param base  zaklad ^ exponent
 * @param exponent

 * @return vraciam umocnene cislo
 */
int power(int base, int exponent){
    int result = 1;
    for (int i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}
/**
 * @brief scitaj dalej nasleduju funkcie ktore su na jedno kopyto, vsetky sa spustia,
 * ked nacitam dany operand a v cykle sa uplatnia na vsetky znaky ulozene v datach
 * iba funkcia neguj je odlisna, lebo je to skoro to iste len tam nemam parametre
 * cislo a argI
 *
 * @param string string kde mam ulozene data ktore budem menit
 *
 * @param cislo toto je cislo s ktorym budem pracovat
 *
 * @param pocet je dlzka dat aby som mohol ist vo for cykle a nie vo while, stringy nemam ukoncene '\0',
 * lebo mi to prislo zbytocne ked si viem posielat pocet prvkov v stringu
 * inac by to bola otazka jedneho prikazu medzi nacitavanim znakov a operandov
 *
 * @param argI ak som nacital 'i' tak sa kazda funkcia sprava inac, nech nemam 1 000 000 funkcii tak som to vyriesil takto
 */

void scitaj(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
            string[i] += cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] += i;
        }
    }
}

void odcitaj(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
            string[i] -= cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] -= i;
        }
    }
}

void nasob(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
            string[i] *= cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] *= i;
        }
    }
}

void vydel(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
            string[i] /= cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] /= i;
        }
    }
}

void zvysok(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
            string[i] %= cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] %= i;
        }
    }
}

void sucin(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
          string[i] = string[i] & cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] = string[i] & i;
        }
    }
}

void sucet(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
           string[i] |= cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] |= i;
        }
    }
}
void exkluziv(uint8_t *string, uint8_t cislo, int pocet, int argI){
    if (argI == 0){
        for(int i = 0; i < pocet; i++){
            string[i] ^= cislo;
        }
    }else{
        for(int i = 0; i < pocet; i++){
            string[i] ^= i;
        }
    }
}

void neguj(uint8_t *string, int pocet){

     for(int i = 0; i < pocet; i++){
        string[i] = ~string[i];
    }
}

/**
 * @brief vyberAkciu funkcia kde vyberem a spustim pozadovanu opraciu,
 * popripade spustim nacitavanie znakov ak mam binarni operand
 *
 * @param string data ktore som si poslal z minulej funkcie
 *
 * @param znak premena do ktorej cez getchar nacitavam znaky v minulej funkcii
 * a tu to iba pouzivam
 *
 * @param pocetOp stale si strazim pocet operandov aby som nepresiahol 50
 *
 * @param pocetZnakov aby som mohol mat vsade for cykly
 * tak si posielam stale ze kolko mam prvkov v datach
 */

void vyberAkciu(uint8_t *string, int znak, short int *pocetOp, int pocetZnakov){
    uint8_t cislo = 0;
    int argI = 0;
    if (znak != '~'){
        cislo = nacitajCislo(pocetOp, &argI);
    }
    switch(znak){
        case '+':{
            scitaj(string, cislo, pocetZnakov, argI);
            break;
        }
        case '-':{
            odcitaj(string, cislo, pocetZnakov, argI);
            break;
        }
        case '*':{
            nasob(string, cislo, pocetZnakov, argI);
            break;
        }
        case '/':{
            vydel(string, cislo, pocetZnakov, argI);
            break;
        }
        case '%':{
            zvysok(string, cislo, pocetZnakov, argI);
            break;
        }
        case '&':{
            sucin(string, cislo, pocetZnakov, argI);
            break;
        }
        case '|':{
            sucet(string, cislo, pocetZnakov, argI);
            break;
        }
        case '^':{
            exkluziv(string, cislo, pocetZnakov, argI);
            break;
        }
        case '<':{
            cislo = power(2,cislo);
            nasob(string, cislo, pocetZnakov, argI);
            break;
        }
        case '>':{
            cislo = power(2,cislo);
            vydel(string, cislo, pocetZnakov, argI);
            break;
        }
        case '~':{
            neguj(string, pocetZnakov);
            break;
        }
    }
}

/**
 * @brief nacitaj funkcia na nacitanie dat a operandu z formule
 *
 * @param data tymto si posielam pole ktore naplnim a upravim avratim mainu
 * pretoze tam podlo podla argc a argv spustam spravny vypis
 *
 * @return posielam si pocet znakov opat aby som mohol pouzivat for cyklus
 */

short int nacitaj(uint8_t *data){
    short int pocetOperatorov = 0;
    short int pocetZnakov = 0;
    uint8_t znak;

    while(pocetZnakov < MAXZNAKOV){
        znak = getchar();
        if (isspace(znak) != 0){
            break;
        }
        data[pocetZnakov] = znak;
        pocetZnakov++;
    }

    while(pocetOperatorov < MAXOPERATOROV){
        znak = getchar();
        if (znak == '\n'){break;}
        if (isspace(znak) == 0){
            vyberAkciu(data,znak,&pocetOperatorov,pocetZnakov);
            pocetOperatorov++; //priratam znak
        }
        pocetOperatorov++; // medzeru
    }
    return pocetZnakov;
}

/**
 * @brief vypisX vsetky 3 vypisy, ide len o to ze to cele prejdem od zaciatku
 * do konca a vypisem to ako je pozadovane dekadicky/hexadecimalne/znakom
 *
 * @param string pole dat ktore vypisujem
 *
 * @param pocet kolko prvkov mam v stringu dat
 */

void vypisX(uint8_t *string, int pocet){
    for(int i = 0; i < pocet; i++){
        printf("%02X",string[i]);
        }
    printf("\n");
}

void vypisC(uint8_t *string, int pocet){
    for(int i = 0; i < pocet; i++){
        printf("%d",string[i]);
    }
    printf("\n");
}

void vypisZ(uint8_t *string, int pocet){
    for(int i = 0; i < pocet; i++){
        printf("%c",string[i]);
    }
    printf("\n");
}

/**
 * @brief main inicializujem data spustim nacitanie dat a podla argumentov
 * vyberem potrebny vypis
 *
 * @param argc pocet argumentov
 *
 * @param argv pole ulozenych argumentov, [0] je meno [1] je prepinac -i alebo -s
 * @return 0
 */
int main(int argc, char *argv[])
{
    uint8_t data[MAXZNAKOV+1] = {0};
    short int pocetZnakov = 0;
    pocetZnakov = nacitaj(data);
    if (argc > 1){
        if (strcmp(argv[1],"-i") == 0){
            vypisC(data,pocetZnakov);
        }
        if (strcmp(argv[1],"-s") == 0){
            vypisZ(data,pocetZnakov);
        }
    }else{
        vypisX(data,pocetZnakov);
    }
    return 0;
}
