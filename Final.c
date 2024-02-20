#include "stdio.h"
#include "stdbool.h"
#include <stdlib.h>

typedef struct Node {
    struct Down *value;
    struct Node *next;
} Spisok;
typedef struct TwoNode {
    struct Stroka *value;
    struct TwoNode *next;
    struct TwoNode *prev;
} TwoSpisok;
typedef struct TwoNodeDek {
    struct Middle *value;
    struct TwoNodeDek *next;
    struct TwoNodeDek *prev;
} TwoSpisokDek;
//---------------------------------------------------
typedef struct Up{
    TwoSpisokDek *nachalo_Dek;
    TwoSpisokDek *konec_Dek;
    TwoSpisokDek *rab_Dek;
    int razreshenie;
    int razmer_Dek;
    struct Middle* zapas;
} Dek;
typedef struct Middle{
    Spisok *head_Posledovatelnost;
    Spisok *konec_Posledovatelnost;
    Spisok *rab_Posledovatelnost;
    int flag_Posledovatelnost;
    int razreshenie;
    int razmer_Posledovatelnost;
    struct Up *Vverh;
} Posledovatelnost;
typedef struct Down{
    TwoSpisok *nachalo_Sentence;
    TwoSpisok *konec_Sentence;
    TwoSpisok *rab_Sentence;
    int flag_Sentence;
    int razreshenie;
    struct Up *Vverh;
    struct Stroka *zapas;
} Sentence;
typedef struct Stroka{
    char value;
    struct Stroka *next;
}Slova;
//---------------------------------------------------
void menuDown(Sentence *);
void menuMiddle(Posledovatelnost *);
void menu(Dek*);
void operationsSentence(Sentence *, int);
void operationsPosledovatelnost(Posledovatelnost *, int);
void posl8(Posledovatelnost*);
//---------------------------------------------------
bool provercachisla(char a) {
    if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' ||
        a == '6' || a == '7' || a == '8' || a == '9')
        return true;
    else
        return false;
}
int perevodchisla(char a) {
    switch (a) {
        case ('0'):
            return 0;
        case ('1'):
            return 1;
        case ('2'):
            return 2;
        case ('3'):
            return 3;
        case ('4'):
            return 4;
        case ('5'):
            return 5;
        case ('6'):
            return 6;
        case ('7'):
            return 7;
        case ('8'):
            return 8;
        case ('9'):
            return 9;
        default:
            printf("Нечто странное из perevodchisla()");
            return 0;
    }
}
int vvodInt() {
    char a = ' ';
    int chisl = 0, hap, i = 0;
    while (a != '\n') {
        a = getchar();
        if (provercachisla(a)) {
            hap = perevodchisla(a);
            if (i == 0) {
                if (a != 0) {
                    chisl = hap;
                    i++;
                }
            } else {
                chisl = chisl * 10 + hap;
            }
        } else {
            if (a == '\n') {
                break;
            }
            printf("Неверный ввод введите заново\n");
            while (a != '\n') {
                a = getchar();
            }
            chisl = vvodInt();
            a = '\n';
        }
    }
    return chisl;
}
Slova* vvodChar() {
    char a = ' ';
    a = getchar();
    Slova *tmp = (Slova*)malloc(sizeof(Slova));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    if(a!='\n'){
        tmp->value = a;
        tmp->next = vvodChar();
    }
    else{
        free(tmp);
        return NULL;
    }
    return tmp;
}
void printChar(Slova* data){
    Slova *head = data;
    while(head != NULL) {
        printf("%c", head->value);
        head = head->next;
    }
}
Sentence *setSentence(Dek*);
//---------------------------------------------------
void printOperationsDEK() {
    printf("\n");
    printf("1\tначать работу\n");
    printf("2\tсделать дек пустым\n");
    printf("3\tпроверка на пустоту\n");
    printf("4\tзначение в начале дека\n");
    printf("5\tпоказать значение в конце\n");
    printf("6\tудалить начало дека\n");
    printf("7\tудалить конец дека\n");
    printf("8\tвзять элемент из начала дека\n");
    printf("9\tвзять элемент из конца дека\n");
    printf("10\tизменить значение начала\n");
    printf("11\tизменить значение конца\n");
    printf("12\tдобавить элемент в начало дека\n");//setPosledovatelnost
    printf("13\tдобавить элемент в конец дека\n");//setPosledovatelnost и ссылка на операции мидла
    printf("14\tраспечатать структуру\n");
    printf("15\tзакончить работу с деком\n");
    printf("16\tзакончить работу с программой\n");
    printf("Функции для спуска на 1 структуру ниже\n");
    printf("17\tустановить рабочий указатель на начало\n");
    printf("18\tустановить рабочий указатель на конец\n");
    //printf("19\tпередвинуть рабочий указатель вперёд на 1 позицию\n");
    //printf("20\tпередвинуть рабочий указатель назад на 1 позицию\n");
    printf("21\tперейти к работе с последовательностью на которую указывает рабочий указатель\n");

}
void printOperationsPosledovatelnost() {
    printf("\n");
    printf("1\tначать работу\n");
    printf("2\tсделать пустой\n");
    printf("3\tпроверка на пустоту\n");
    printf("4\tпоказать значение очередного элемента\n");
    printf("5\tпропустить очередной элемент(указатель на 1 позицию)(он как бы прочитывается)\n");
    printf("6\tпрочитать очередной элемент последовательности(очередной элемент запоминается указатель идёт дальше)\n");
    printf("7\tизменить значение очередного элемента(указатель не изменяется)\n");
    printf("8\tдобавить элемент в конец последовательности\n");
    printf("9\tустановить указатель очередного элемента в начало последовательности\n");
    printf("10\tпроверка есть ли не прочитанные элементы\n");
    printf("11\tраспечатать структуру\n");
    printf("12\tконец работы с очередью\n");
    printf("13\tзакончить работу с программой\n");
    printf("Функции для перехода\n");
    printf("14\tперейти к работе с предложением на которую указывает рабочий указатель\n");
    printf("15\tпродолжить работу с деком\n");
}
void printOperationsSentence(){
    printf("\n");
    printf("\n1\tНачать работу со списком\n");
    printf("2\t Сделать список пустым\n");
    printf("3\t Проверить список на пустоту\n");
    printf("4\t Установить рабочий указатель начала списка\n");
    printf("5\t Установить рабочий указатель конца списка\n");
    printf("6\t Проверить в конце ли рабочий указатель\n");//
    printf("7\t Проверить в начале ли рабочий указатель\n");
    printf("8\t Передвинуть рабочий указатель вперёд на 1 позицию\n");
    printf("9\t Передвинуть рабочий указатель назад на 1 позицию\n");
    printf("10\t Показать значение элемента списка до указателя\n");
    printf("11\t Показать значение элемента списка за указателем\n");
    printf("12\t Удалить элемент списка до указателя\n");
    printf("13\t Удалить элемент списка за указателем\n");
    printf("14\t Взять элемент списка до указателя\n");
    printf("15\t Взять элемент списка за указкателем\n");
    printf("16\t Изменить значение элемента до указателя\n");
    printf("17\t Изменить значение элемента за указателем\n");
    printf("18\t Добавить элемент до указателя\n");
    printf("19\t Добавить элемент за указателем\n");
    printf("20\t Распечатать структуру данных с начала\n");
    printf("21\t Распечатать структуру данных с конца\n");
    printf("22\t Закончить работу со списком\n");
    printf("23\t Закончить работу с программой\n");
    printf("Функции для перехода\n");
    printf("24\t Продолжить работу с последовательностью\n");
}
//---------------------------------------------------
void remove_all_Posledovatelnost(Posledovatelnost *);
void remove_all_Sentence(Sentence *);
//---------------------------------------------------
void printstruct(TwoSpisok *,TwoSpisok* );
void printPosledovatelnost(Spisok *,Spisok *);
Posledovatelnost *setPosledovatelnost(Dek* );
//----------------------------------------------------
Dek *setDek(){
    Dek *tmp = (Dek*)malloc(sizeof(Dek));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    tmp->nachalo_Dek=NULL;
    tmp->konec_Dek=NULL;
    tmp->rab_Dek = NULL;
    tmp->razreshenie=0;
    tmp->razmer_Dek = 0;
    tmp->zapas = NULL;
    return(tmp);
}
void remove_all_Dek(Dek *uk)
{
    while (uk->nachalo_Dek != NULL)
    {
        TwoSpisokDek *p = uk->nachalo_Dek;
        uk->nachalo_Dek = uk -> nachalo_Dek -> next;
        remove_all_Posledovatelnost(p->value);
    }
    uk->nachalo_Dek=NULL;
    uk->konec_Dek=NULL;
    uk->rab_Dek=NULL;
}
void remove_Dek(TwoSpisokDek*uk, Dek*uy){
    if(uy->rab_Dek == uk){
        if(uy->rab_Dek->next!=NULL)
            uy->rab_Dek = uy->rab_Dek->next;
        if(uy->rab_Dek->prev!=NULL)
            uy->rab_Dek = uy->rab_Dek->prev;
        else
            uy->rab_Dek = NULL;
    }
    remove_all_Posledovatelnost(uk->value);
    uk->value =NULL;
}
void create_elem_dek(Dek* uk){
    TwoSpisokDek *tmp = (TwoSpisokDek*)malloc(sizeof(TwoSpisokDek));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    uk->nachalo_Dek= tmp;
    uk->konec_Dek = tmp;
}
void add_element_dek_nachalo(Dek *uk){
    Posledovatelnost *pp = setPosledovatelnost(uk);
        if (uk->nachalo_Dek == NULL)
            create_elem_dek(uk);
        else {
            TwoSpisokDek *tmp = (TwoSpisokDek *) malloc(sizeof(TwoSpisokDek));
            if (NULL== tmp){
                printf("Память не выделилась\n");
                exit(1);
            }
            tmp->next = uk->nachalo_Dek;
            uk->nachalo_Dek->prev = tmp;
            uk->nachalo_Dek = tmp;
        }
        uk->nachalo_Dek->value = pp;
        pp->razreshenie=1;
        posl8(pp);
        pp->razreshenie=0;
    }
void add_element_dek_konec(Dek *uk){
    Posledovatelnost *p = setPosledovatelnost(uk);

        if (uk->konec_Dek == NULL)
            create_elem_dek(uk);
        else {
            TwoSpisokDek *tmp = (TwoSpisokDek *) malloc(sizeof(TwoSpisokDek));
            if (NULL== tmp){
                printf("Память не выделилась\n");
                exit(1);
            }
            tmp->prev = uk->konec_Dek;
            uk->konec_Dek->next = tmp;
            uk->konec_Dek = tmp;
        }
        uk->konec_Dek->value = p;
        p->razreshenie=1;
        posl8(p);
        p->razreshenie=0;
}
void print_Dek(Dek *uk){
    if(uk->nachalo_Dek!=NULL) {
        TwoSpisokDek *p = uk->nachalo_Dek;
        int flag = 0;
        while (1) {
            if(uk->rab_Dek==p) {
                flag = 1;
                printf("\033[31m\033[1m");
            }
            printf("|");
            printf("\033[0m");
            {
                if (p->value != NULL)
                    printPosledovatelnost(NULL, p->value->head_Posledovatelnost);
                else {
                    printf("\033[34m\033[1m");
                    printf("|");
                    printf("|");
                    printf("\033[0m");
                }
                if (p == uk->konec_Dek) {
                    if(flag==1) {
                        flag = 0;
                        printf("\033[31m\033[1m");
                    }
                    printf("|");
                    printf("\033[0m");
                    break;
                }
                p = p->next;
            }
            if(flag==1) {
                printf("\033[31m\033[1m");
                flag = 0;
            }
            printf("|");
            printf("\033[0m");
        }
    }
    else
        printf("Дек пуст\n");
}
//---------------------------------------------------
Posledovatelnost *setPosledovatelnost(Dek* uk){
    Posledovatelnost *tmp = (Posledovatelnost*)malloc(sizeof(Posledovatelnost));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    tmp->head_Posledovatelnost=NULL;
    tmp->konec_Posledovatelnost =NULL;
    tmp->rab_Posledovatelnost =NULL;
    tmp->razreshenie =0;
    tmp->flag_Posledovatelnost = 0;
    tmp->razmer_Posledovatelnost = 0;
    tmp->Vverh = uk;
    return(tmp);
}
void create_elem_Posl(Posledovatelnost * uk){
    Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    uk->head_Posledovatelnost= tmp;
    uk->konec_Posledovatelnost = tmp;
    uk->rab_Posledovatelnost = tmp;
}
void remove_all_Posledovatelnost(Posledovatelnost *uk)
{
    while (uk->head_Posledovatelnost != NULL)
    {
        Spisok *p = uk->head_Posledovatelnost;
        uk->head_Posledovatelnost = uk -> head_Posledovatelnost -> next;
        remove_all_Sentence(p->value);
    }
    uk->head_Posledovatelnost = NULL;
    uk->rab_Posledovatelnost = NULL;
    uk->konec_Posledovatelnost = NULL;
}
void printPosledovatelnost(Spisok *rab,Spisok * heed){
    Spisok*head = heed;
    int flag = 0;
    while (head != NULL) {
        if(rab == head)
            flag = 1;
        if (flag) {
            printf("\033[31m\033[1m");
            printf("|");
            printf("\033[0m");
            printstruct(NULL,head->value->nachalo_Sentence);
            printf("\033[31m\033[1m");
            printf("|");
            printf("\033[0m");
            flag = 0;
        }
        else
            printstruct(NULL,head->value->nachalo_Sentence);
        head = head->next;
    }
}
void sen19(Sentence*);
void add_element_Posled_konec(Posledovatelnost *uk){
    Sentence *p = setSentence(uk->Vverh);
    if (uk->konec_Posledovatelnost == NULL) {
        create_elem_Posl(uk);
    }
    else{
        Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));
        if (NULL== tmp){
            printf("Память не выделилась\n");
            exit(1);
        }
        uk->konec_Posledovatelnost->next = tmp;
        uk->konec_Posledovatelnost = uk->konec_Posledovatelnost->next;
        uk->konec_Posledovatelnost->next=NULL;

    }
    uk->konec_Posledovatelnost->value = p;
        p->razreshenie=1;
        sen19(p);
        if(p->konec_Sentence!=p->nachalo_Sentence)
            p->rab_Sentence = p->rab_Sentence->next;
        p->razreshenie=0;
    printf("\nЕсли ввести в предложение нажмите 1\n");
        int r = vvodInt();
        while (r == 1) {
            p->razreshenie = 1;
            sen19(p);
            p->razreshenie = 0;
            printf("\nЕсли хотите продолжить ввод в предложение нажмите 1\n");
            if(p->rab_Sentence->next!=NULL){
                p->rab_Sentence = p->rab_Sentence->next;
            }
            r = vvodInt();
        }

}
void add_Posl(Posledovatelnost* ukPosl){
    if (ukPosl->razmer_Posledovatelnost < 5) {
            printf("Чтоб ввести новый элемент последовательности заполните предложение");
            add_element_Posled_konec(ukPosl);
            ukPosl->razmer_Posledovatelnost = ukPosl->razmer_Posledovatelnost + 1;
            ukPosl->konec_Posledovatelnost->next = NULL;
        } else
            printf("Переполнение последовательности - нельзя добавить\n");
}
bool permission(int);
void posl8(Posledovatelnost* ukPosl) {
    if (permission(ukPosl->razreshenie)) {
        add_Posl(ukPosl);
        printf("Если хотите добавить предложение нажмите 1\n");
        int a = vvodInt();
        while (a == 1) {
            if (ukPosl->razmer_Posledovatelnost < 5) {
                add_Posl(ukPosl);
                ukPosl->konec_Posledovatelnost->next = NULL;
            } else
                printf("Переполнение последовательности - нельзя добавить\n");
            if (ukPosl->razmer_Posledovatelnost < 5) {
                printf("Если хотите добавить предложение нажмите 1\n");
                a = vvodInt();
            } else
                a = 0;
        }
    }
}
//---------------------------------------------------
Sentence *setSentence(Dek* uk){
    Sentence *tmp = (Sentence*)malloc(sizeof(Sentence));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    tmp->nachalo_Sentence=NULL;
    tmp->konec_Sentence=NULL;
    tmp->rab_Sentence = NULL;
    tmp->razreshenie=0;
    tmp->Vverh = uk;
    tmp->zapas = NULL;
    return(tmp);
}
TwoSpisok *createSentence(Slova *data)
{
    TwoSpisok *tmp = (TwoSpisok*)malloc(sizeof(TwoSpisok));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    tmp -> value = data;
    tmp -> next = NULL;
    tmp -> prev = NULL;
    return(tmp);
}
void add_element_posl(Slova *data, TwoSpisok *heed)
{
    TwoSpisok *tmp = (TwoSpisok*)malloc(sizeof(TwoSpisok));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    tmp -> value = data;
    tmp -> next = heed->next;
    if (heed->next!=NULL)
        tmp -> next -> prev = tmp;
    tmp -> prev = heed;
    heed-> next = tmp;
}
void add_element_pered(Slova *data, TwoSpisok *heed)
{
    TwoSpisok *tmp = (TwoSpisok*)malloc(sizeof(TwoSpisok));
    if (NULL== tmp){
        printf("Память не выделилась\n");
        exit(1);
    }
    tmp -> value = data;
    tmp -> next = heed;
    tmp -> prev = heed->prev;
    heed -> prev = tmp;
    if (tmp->prev!=NULL)
        tmp->prev->next = tmp;
}
void remove_el_Stroka(Slova * uk){
    while(uk!=NULL) {
        Slova *p = uk->next;
        free(uk);
        uk = p;
    }
}
void remove_all_Sentence(Sentence *uk)
{
    while (uk->nachalo_Sentence != NULL)
    {
        TwoSpisok *p = uk->nachalo_Sentence;
        uk->nachalo_Sentence = uk -> nachalo_Sentence -> next;
        if(p==uk->konec_Sentence){
            uk->konec_Sentence=NULL;
            uk->rab_Sentence = NULL;
        }
        remove_el_Stroka(p->value);
    }
}
TwoSpisok *remove_element(TwoSpisok *uk2) {
    TwoSpisok *uk1 = uk2->prev;
    if (uk2 == NULL) {
        printf("\nнеправильно - след элемента нету вы в конце\n");
        return(uk1);
    }
    if (uk1 == NULL) {
        uk1 = uk2;
        uk2 = uk2->next;
        remove_el_Stroka(uk1->value);
        //printf("\nудаление первого\n");
        return (uk2);
    } else {
        uk1->next = uk2->next;
        remove_el_Stroka(uk2->value);
        return (uk1->next);
    }
}
void printstruct(TwoSpisok *rabot,TwoSpisok* heed){
    TwoSpisok*head = heed;
    TwoSpisok*rab = rabot;
    printf("\033[32m\033[1m");
    printf("|");
    printf("\033[0m");
    while (head != NULL)
    {
        if (rab == head) {
            printf("\033[31m\033[1m");
            printChar(head->value);
            printf("\033[0m");
            head = head->next;
            if (head != NULL) {
                printf("\033[36m\033[1m");
                printf("-");
                printf("\033[0m");
            }
        }
        else{
            printChar(head -> value);
            head = head -> next;
            if (head != NULL) {
                printf("\033[36m\033[1m");
                printf("-");
                printf("\033[0m");
            }
        }
    }
    printf("\033[32m\033[1m");
    printf("|");
    printf("\033[0m");
}
void printstructObrat(TwoSpisok *rabot,TwoSpisok* taal){
    TwoSpisok*tail = taal;
    TwoSpisok*rab = rabot;
    while (tail != NULL)
    {
        if (rab == tail) {
            printf("\033[31m\033[1m");
            printChar(tail->value);
            printf("\033[0m");
            tail = tail->prev;
            if (tail != NULL) {
                printf("\033[36m\033[1m");
                printf("-");
                printf("\033[0m");
            }
        }
        else{
            printChar(tail -> value);
            tail = tail -> prev;
            if (tail != NULL) {
                printf("\033[36m\033[1m");
                printf("-");
                printf("\033[0m");
            }
        }
    }
}
void print_v_Obe(TwoSpisok *rabot,TwoSpisok* heed){
    TwoSpisok*head = heed;
    TwoSpisok*rab = rabot;
    if (head!=NULL) {
        printf("С начала:\n");
        printstruct(rab, head);
        printf("\n");
        printf("С конца:\n");
        while (head->next != NULL)
            head = head->next;
        printstructObrat(rab, head);
    }
}
bool ifExisingNext(Sentence *mass){
    if(mass ->nachalo_Sentence == NULL){
        printf("Не создан список создайте через функцию 18 или 19\n");
        return false;
    }
    else if (mass->rab_Sentence->next!=NULL)
        return true;
    else {
        printf("\nНе существует след элемента\n");
        return false;
    }
}
bool ifExisingPrev(Sentence *mass){
    if(mass ->nachalo_Sentence == NULL){
        printf("Не создан список создайте через функцию 11\n");
        return false;
    }
    else if (mass->rab_Sentence->prev!=NULL)
        return true;
    else {
        printf("\nНе существует пред элемента\n");
        return false;
    }
}
//---------------------------------------------------
bool permission(int tmp){
    if(tmp)
        return true;
    else
        printf("Получите разрешение\n");
    return false;
}
void sen19(Sentence *ukSen){
    if(permission(ukSen->razreshenie)) {
        printf("\nВведите значение\n");
        Slova *aa=vvodChar();
        if (ukSen->nachalo_Sentence == NULL){
            ukSen->nachalo_Sentence = createSentence(aa);
            ukSen ->rab_Sentence = ukSen->nachalo_Sentence;
            ukSen ->konec_Sentence = ukSen->nachalo_Sentence;
        }
        else {
            add_element_posl(aa, ukSen->rab_Sentence);
            if (ukSen->rab_Sentence == ukSen->konec_Sentence) {
                ukSen->konec_Sentence = ukSen->rab_Sentence->next;
            }
        }
        if(ukSen->nachalo_Sentence!=NULL){
            print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
        }
    }
}
void operationsDek(Dek* ukDek, int input){
    switch (input) {
        case(1):
            if(!(ukDek->razreshenie))
                ukDek->razreshenie = 1;
            else
                printf("Работа уже начата\n");
            break;
        case (2)://переделать функцию чтоб внутренние функции последовательность и предложение они не удаляются
            if(permission(ukDek->razreshenie)){
                remove_all_Dek(ukDek);
                printf("Список очищен\n");
            }
            break;
        case (3):
            if(permission(ukDek->razreshenie)){
                if (ukDek->nachalo_Dek == NULL)
                    printf("Список пуст\n");
                else
                    printf("Список не пуст\n");
            }
            break;
        case (4):
            if(permission(ukDek->razreshenie)) {
                if (ukDek->nachalo_Dek != NULL) {
                    if (ukDek->nachalo_Dek->value!=NULL)
                        printPosledovatelnost(NULL, ukDek->nachalo_Dek->value->head_Posledovatelnost);
                    else
                        printf("Cоздайте элемент\n");
                }
                else
                    printf("Создайте Дек\n");
            }
            break;
        case (5):
            if(permission(ukDek->razreshenie)) {
                if (ukDek->konec_Dek != NULL) {
                    if (ukDek->konec_Dek->value!=NULL)
                        printPosledovatelnost(NULL, ukDek->konec_Dek->value->head_Posledovatelnost);
                    else
                        printf("Cоздайте элемент\n");
                }
                else
                    printf("Создайте Дек\n");
            }
            break;
        case (6):
            if(permission(ukDek->razreshenie)){
                int flag = 0;
                if (ukDek->nachalo_Dek != NULL) {
                    TwoSpisokDek *p = ukDek->nachalo_Dek;
                    if (ukDek->nachalo_Dek->next != NULL) {
                        ukDek->nachalo_Dek = ukDek->nachalo_Dek->next;
                        ukDek->nachalo_Dek->prev = NULL;
                    }
                    else{
                        flag = 1;
                    }
                    if(ukDek->rab_Dek==p)
                        ukDek->rab_Dek = ukDek->nachalo_Dek;
                    remove_Dek(p, ukDek);
                    printf("Элемент удалён\n");
                    ukDek->razmer_Dek--;
                    if(ukDek->nachalo_Dek->value==NULL) {
                        ukDek->nachalo_Dek=NULL;
                        ukDek->konec_Dek=NULL;
                    }
                } else
                    printf("Не существует первого элемента\n");
            }
            ukDek->rab_Dek = NULL;
            break;
        case (7):
            if(permission(ukDek->razreshenie)){
                if (ukDek->konec_Dek != NULL) {
                    TwoSpisokDek *p = ukDek->konec_Dek;
                    if (ukDek->konec_Dek->prev != NULL) {
                        ukDek->konec_Dek = ukDek->konec_Dek->prev;
                        ukDek->konec_Dek->next = NULL;
                    }
                    if(ukDek->rab_Dek==p)
                        ukDek->rab_Dek = ukDek->konec_Dek;
                    remove_Dek(p, ukDek);
                    printf("Элемент удалён\n");
                    ukDek->razmer_Dek--;
                    if(ukDek->konec_Dek->value==NULL) {
                        ukDek->nachalo_Dek=NULL;
                        ukDek->konec_Dek=NULL;
                    }
                } else
                    printf("Не существует последнего элемента\n");
            }
            ukDek->rab_Dek = NULL;
            break;
        case (8):
            if(permission(ukDek->razreshenie)) {
                if (ukDek->nachalo_Dek != NULL) {
                    if(ukDek->nachalo_Dek->value!=NULL)
                        printPosledovatelnost(NULL, ukDek->nachalo_Dek->value->head_Posledovatelnost);
                    ukDek->zapas = ukDek->nachalo_Dek->value;
                }
                operationsDek(ukDek, 6);
            }
            break;
        case (9):
            if(ukDek->konec_Dek!=NULL) {
                if(ukDek->konec_Dek->value->head_Posledovatelnost!=NULL)
                    printPosledovatelnost(NULL, ukDek->konec_Dek->value->head_Posledovatelnost);
                ukDek->zapas = ukDek->konec_Dek->value;
            }

            operationsDek(ukDek, 7);
            break;
        case (10)://!!!!!!!!!!
            if(permission(ukDek->razreshenie)) {
                if(ukDek->nachalo_Dek!=NULL) {
                    if(ukDek->nachalo_Dek->value!=NULL){
                        add_element_dek_nachalo(ukDek);
                        if(ukDek->nachalo_Dek->next == ukDek->konec_Dek)
                            ukDek->konec_Dek = ukDek->nachalo_Dek;
                        ukDek->nachalo_Dek->next = ukDek->nachalo_Dek->next->next;
                        if(ukDek->nachalo_Dek->next!=NULL)
                            ukDek->nachalo_Dek->next->prev = ukDek->nachalo_Dek;
                    }
                    else
                        printf("Не создан элемент последовательности\n");
                }
                else
                    printf("Соаздайте Дек\n");
            }
            break;
        case (11)://!!!!!!!!!!
            if(permission(ukDek->razreshenie)) {
                if(ukDek->konec_Dek!=NULL) {
                    if(ukDek->konec_Dek->value!=NULL){
                        add_element_dek_konec(ukDek);
                        if(ukDek->konec_Dek->prev == ukDek->nachalo_Dek)
                            ukDek->nachalo_Dek = ukDek->konec_Dek;
                        ukDek->konec_Dek->prev = ukDek->konec_Dek->prev->prev;
                        if(ukDek->konec_Dek->prev!=NULL)
                            ukDek->konec_Dek->prev->next = ukDek->konec_Dek;
                    }
                    else
                        printf("Не создан элемент последовательности\n");
                }
                else
                    printf("Соаздайте Дек\n");
            }
            break;
        case (12):
            if(permission(ukDek->razreshenie)) {
                if(ukDek->razmer_Dek<5) {
                    add_element_dek_nachalo(ukDek);
                    ukDek->razmer_Dek++;
                }
                else
                    printf("Переполнение Дека - нельзя добавить\n");
            }
            ukDek->rab_Dek = NULL;
            break;
        case(13):
            if(permission(ukDek->razreshenie)) {
                if(ukDek->razmer_Dek<5) {
                    add_element_dek_konec(ukDek);
                    ukDek->razmer_Dek++;
                }
                else
                    printf("Переполнение Дека - нельзя добавить\n");
            }
            ukDek->rab_Dek = NULL;
            break;
        case (14):
            if(permission(ukDek->razreshenie))
                print_Dek(ukDek);
            break;
        case (15):
            if(permission(ukDek->razreshenie))
                ukDek->razreshenie = 0;
            else
                printf("С начала начните работу\n");
            break;
        case (16):
            if(ukDek->razreshenie==0) {
                ukDek->razreshenie = 1;
                operationsDek(ukDek, 2);
                exit(1);
            }
            else
                printf("Закончите работу с деком\n");
            break;
        case(17):
            if(permission(ukDek->razreshenie)){
                ukDek->rab_Dek = ukDek->nachalo_Dek;
            }
            break;
        case(18):
            if(permission(ukDek->razreshenie)){
                ukDek->rab_Dek = ukDek->konec_Dek;
            }
            break;
            //case(19):
            //    if(permission(ukDek->razreshenie)){
            //        if(ukDek->rab_Dek->next!=NULL){
            //            ukDek->rab_Dek = ukDek->rab_Dek->next;
            //        }
            //        else
            //            printf("Не существует следующего элемента\n");
            //    }
            //    break;
            //case(20):
            //    if(permission(ukDek->razreshenie)){
            //        if(ukDek->rab_Dek->prev!=NULL){
            //            ukDek->rab_Dek = ukDek->rab_Dek->prev;
            //        }
            //        else
            //            printf("Не существует предыдущего элемента\n");
            //    }
            //    break;
        case(21):
            if(permission(ukDek->razreshenie)) {
                if(ukDek->rab_Dek!=NULL) {
                    if(ukDek->rab_Dek->value==NULL)
                            ukDek->rab_Dek->value = setPosledovatelnost(ukDek);
                    ukDek->rab_Dek->value->flag_Posledovatelnost=1;
                    menuMiddle(ukDek->rab_Dek->value);
                    ukDek->rab_Dek->value->flag_Posledovatelnost=0;
                }
                else
                    printf("рабочий указатель не создан\n");
            }
            break;
        default:
            printf("Такого пункта не существует или введён Enter\n");
            break;
    }
}
void operationsPosledovatelnost(Posledovatelnost* ukPosl, int input){
    switch (input) {
        case(1):
            if(!(ukPosl->razreshenie))
                ukPosl->razreshenie = 1;
            else
                printf("Работа уже начата\n");
            break;
        case (2)://переделать функцию чтоб внутренние функции последовательность и предложение они не удаляются
            if(permission(ukPosl->razreshenie)){
                remove_all_Posledovatelnost(ukPosl);
                printf("Список очищен\n");
            }
            break;
        case (3):
            if(permission(ukPosl->razreshenie)){
                if (ukPosl->head_Posledovatelnost == NULL)
                    printf("Список пуст\n");
                else
                    printf("Список не пуст\n");
            }
            break;
        case (4):
            if(permission(ukPosl->razreshenie)) {
                if (ukPosl->rab_Posledovatelnost != NULL)
                    printstruct(NULL, ukPosl->rab_Posledovatelnost->value->nachalo_Sentence);
                else
                    printf("Пустая последовательность\n");
            }
            break;
        case(5):
            if(permission(ukPosl->razreshenie)) {
                if(ukPosl->rab_Posledovatelnost!=NULL){
                    if (ukPosl->rab_Posledovatelnost->next != NULL)
                        ukPosl->rab_Posledovatelnost = ukPosl->rab_Posledovatelnost->next;
                    else
                        printf("Нет следующего элемента\n");
                }
                else
                    printf("Пустая последовательность\n");
            }
            break;
        case(6)://???????????????????????
            if(permission(ukPosl->razreshenie)) {
                if(ukPosl->rab_Posledovatelnost!=NULL){
                    if (ukPosl->rab_Posledovatelnost->next != NULL) {
                        printstruct(NULL, ukPosl->rab_Posledovatelnost->value->nachalo_Sentence);
                        ukPosl->rab_Posledovatelnost = ukPosl->rab_Posledovatelnost->next;
                    } else
                        printf("Нет элемента\n");
                }
                else
                    printf("Пустая последовательность\n");
            }
            break;
        case(7):
            if(permission(ukPosl->razreshenie)) {
                if(ukPosl->rab_Posledovatelnost!=NULL){
                    ukPosl->razmer_Posledovatelnost--;
                    Spisok *tuy = ukPosl->konec_Posledovatelnost;
                    add_Posl(ukPosl);
                    Sentence* deliting = ukPosl->rab_Posledovatelnost->value;
                    ukPosl->rab_Posledovatelnost->value = ukPosl->konec_Posledovatelnost->value;
                    ukPosl->konec_Posledovatelnost = tuy;
                    ukPosl->konec_Posledovatelnost->next=NULL;
                    remove_all_Sentence(deliting);
                }
                else
                    printf("Пустая последовательность\n");
            }
            break;
        case(8):
            posl8(ukPosl);
            break;
        case(9):
            if(permission(ukPosl->razreshenie)) {
                ukPosl->rab_Posledovatelnost = ukPosl->head_Posledovatelnost;
            }
            break;
        case(10):
            if(permission(ukPosl->razreshenie)) {
                if(ukPosl->rab_Posledovatelnost == ukPosl->konec_Posledovatelnost)
                    printf("все элементы прочитаны\n");
                else{
                    printf("Есть не прочитанные элементы\n");
                }
            }
            break;
        case(11):
            if(permission(ukPosl->razreshenie)) {
                printPosledovatelnost(ukPosl->rab_Posledovatelnost, ukPosl->head_Posledovatelnost);
            }
            break;
        case(12):
            if(permission(ukPosl->razreshenie))
                ukPosl->razreshenie = 0;
            else
                printf("С начала начните работу с программой\n");
            break;
        case(13):
            if(!permission(ukPosl->razreshenie))
                remove_all_Dek(ukPosl->Vverh);
            else
                printf("С начала закончите работу с программой\n");
            break;
        case(14):
            if(permission(ukPosl->razreshenie)) {
                if(ukPosl->rab_Posledovatelnost!=NULL){
                    if(ukPosl->rab_Posledovatelnost->value==NULL)
                        ukPosl->rab_Posledovatelnost->value = setSentence(ukPosl->Vverh);
                    ukPosl->rab_Posledovatelnost->value->flag_Sentence = 1;
                    menuDown(ukPosl->rab_Posledovatelnost->value);
                    ukPosl->rab_Posledovatelnost->value->flag_Sentence = 0;
                }
                else
                    printf("Нет рабочего указателя\n");
            }
            break;
        case(15):
            if(permission(ukPosl->razreshenie)) {
                ukPosl->flag_Posledovatelnost = 0;
            }
            break;
        default:
            printf("Такого пункта не существует или введён Enter\n");
    }
}
void operationsSentence(Sentence * ukSen, int input){//не забыть печать после каждого действия в menu
    switch(input) {
        case(1):
            if(!(ukSen->razreshenie))
                ukSen->razreshenie = 1;
            else
                printf("Работа уже начата\n");
            if(ukSen->nachalo_Sentence!=NULL)
                print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
            break;
        case(2):
            if(permission(ukSen->razreshenie)){
                remove_all_Sentence(ukSen);
                ukSen->rab_Sentence = NULL;
                ukSen->nachalo_Sentence = NULL;
                ukSen->konec_Sentence = NULL;}
            break;
        case(3):
            if(permission(ukSen->razreshenie)){
                if (ukSen->nachalo_Sentence == NULL)
                    printf("Пустой\n");
                else{
                    printf("Не пустой\n");
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);}
            }
            break;
        case(4):
            if(permission(ukSen->razreshenie)){
                ukSen->rab_Sentence = ukSen->nachalo_Sentence;
                print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
            }
            break;
        case(5):
            if(permission(ukSen->razreshenie)){
                ukSen->rab_Sentence = ukSen->konec_Sentence;
                print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
            }
            break;
        case(6):
            if(permission(ukSen->razreshenie)) {
                if (ukSen->rab_Sentence == ukSen->konec_Sentence)
                    printf("Рабочий указатель в конце\n");
                else
                    printf("Рабочий указатель не в конце\n");
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(7):
            if(permission(ukSen->razreshenie)) {
                if (ukSen->rab_Sentence == ukSen->nachalo_Sentence)
                    printf("Рабочий указатель в начале\n");
                else
                    printf("Рабочий указатель не в начале\n");
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(8):
            if(permission(ukSen->razreshenie)) {
                if (ifExisingNext(ukSen)){
                    ukSen->rab_Sentence = ukSen->rab_Sentence->next;
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
                else
                    printf("Нет элементов\n");
            }
            break;
        case(9):
            if(permission(ukSen->razreshenie)) {
                if (ifExisingPrev(ukSen)){
                    ukSen->rab_Sentence = ukSen->rab_Sentence->prev;
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
                else
                    printf("Нет элементов\n");
            }
            break;
        case(10)://подправил на существование пред
            if(permission(ukSen->razreshenie)) {
                if (ifExisingPrev(ukSen)){//существует элемент
                    printChar(ukSen->rab_Sentence->prev->value);
                    printf("\n");
                }
                else{
                    if (ukSen->rab_Sentence == ukSen->nachalo_Sentence){
                        if (ukSen->nachalo_Sentence==NULL)
                            printf("\nНет элементов\n");
                        else
                            printf("\nВы не начале\n");
                    }
                }
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(11)://подправил на существование след
            if(permission(ukSen->razreshenie)){
                if (ifExisingNext(ukSen)){//существует элемент
                    printChar(ukSen->rab_Sentence->next->value);
                    printf("\n");
                }
                else{
                    if (ukSen->rab_Sentence == ukSen->nachalo_Sentence){
                        if (ukSen->nachalo_Sentence==NULL)
                            printf("\nНет элементов\n");
                        else
                            printf("\nВы в конце\n");
                    }
                }
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(12)://подправил на существование след
            if(permission(ukSen->razreshenie)) {
                if (ifExisingPrev(ukSen)) {
                    printf("Элемент удалён\n");
                    ukSen->rab_Sentence = remove_element(ukSen->rab_Sentence->prev);
                    if (ukSen->rab_Sentence->prev == NULL){
                        ukSen->nachalo_Sentence = ukSen->rab_Sentence;
                    }
                }
                else
                    printf("Не существует предыдущего элемента\n");
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(13)://подправил на существование след
            if(permission(ukSen->razreshenie)) {
                if (ifExisingNext(ukSen)) {
                    printf("Элемент удалён\n");
                    ukSen->rab_Sentence = remove_element(ukSen->rab_Sentence->next);
                    if (ukSen->rab_Sentence->next == NULL){
                        ukSen->konec_Sentence = ukSen->rab_Sentence;
                    }
                }
                else
                    printf("Не существует следующего элемента\n");
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(14)://доделать вывод элемента
            if(permission(ukSen->razreshenie)) {
                ukSen->zapas = ukSen->rab_Sentence->value;
                operationsSentence(ukSen, 12);
            }
            break;
        case(15)://!!!!!!!!!!!!!!
            if(permission(ukSen->razreshenie)) {
                operationsSentence(ukSen, 13);
            }
            break;
        case(16)://подправил на существование пред
            if(permission(ukSen->razreshenie)) {
                if (ifExisingPrev(ukSen)) {
                    printf("\nВведите значение\n");
                    Slova *a = vvodChar();
                    ukSen->rab_Sentence->prev->value = a;
                    //while(a!='\n'){
                    //    a = getchar();
                    //}
                }
                else
                    printf("Не существует предыдущего элемента");
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(17)://подправил на существование след
            if(permission(ukSen->razreshenie)) {
                if (ifExisingNext(ukSen)) {
                    printf("\nВведите значение\n");
                    Slova *a = vvodChar();
                    ukSen->rab_Sentence->next->value = a;
                    //while(a!='\n'){
                    //    a = getchar();
                    //}
                }
                else
                    printf("Не существует следующего элемента");
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(18):
            if(permission(ukSen->razreshenie)) {
                printf("\nВведите значение\n");
                Slova *aa=vvodChar();
                if (ukSen->nachalo_Sentence == NULL){
                    ukSen->nachalo_Sentence = createSentence(aa);
                    ukSen -> rab_Sentence = ukSen -> nachalo_Sentence;
                    ukSen -> konec_Sentence = ukSen -> nachalo_Sentence;
                }
                else {
                    add_element_pered(aa, ukSen->rab_Sentence);
                    if (ukSen->rab_Sentence == ukSen->nachalo_Sentence) {
                        ukSen->nachalo_Sentence = ukSen->rab_Sentence->prev;
                    }
                }
                if(ukSen->nachalo_Sentence!=NULL){
                    print_v_Obe(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(19):
            sen19(ukSen);
            break;
        case(20):
            if(permission(ukSen->razreshenie)) {
                if (ukSen->nachalo_Sentence!=NULL){
                    printstruct(ukSen->rab_Sentence,ukSen->nachalo_Sentence);}
                else
                    printf("Нет элементов добавьте через пункт 18 или 19");
            }
            break;
        case(21):
            if(permission(ukSen->razreshenie)) {
                if (ukSen->nachalo_Sentence!=NULL){
                    printstructObrat(ukSen->rab_Sentence,ukSen->konec_Sentence);}
                else
                    printf("Нет элементов добавьте через пункт 18 или 19");
            }
            break;
        case(22):
            if(permission(ukSen->razreshenie)) {
                printf("\nЗакончена работа со списком\n");
                ukSen->razreshenie = 0;
                if(ukSen->nachalo_Sentence!=NULL){
                    printstruct(ukSen->rab_Sentence, ukSen->nachalo_Sentence);
                }
            }
            break;
        case(23):
            if(!permission(ukSen->razreshenie)){
                printf("\nЗакончена работа с программой\n");
                remove_all_Dek(ukSen->Vverh);
                exit(1);}
            else{
                printf("В начале закончите работу со списком");
            }
            break;
        case(24):
            ukSen->flag_Sentence = 0;
            break;
        default:
            printf("\nВведён Enter или некорректный пункт\n");
            printf("\nНе правильный ввод, повторите ввод\n");
            break;
    }
}
//---------------------------------------------------
void menuDown(Sentence *ukkk){
    while (ukkk->flag_Sentence) {
        printOperationsSentence();
        printf("Введите номер пункта\n");
        int a = vvodInt();
        operationsSentence(ukkk, a);
    }
}
void menuMiddle(Posledovatelnost * ukk){
    while (ukk->flag_Posledovatelnost) {
        printOperationsPosledovatelnost();
        printf("Введите номер пункта\n");
        int a = vvodInt();
        operationsPosledovatelnost(ukk, a);
    }
}
void menu(Dek* uk){
    while(true){
        printOperationsDEK();
        printf("Введите номер пункта\n");
        int a = vvodInt();
        operationsDek(uk,a);
        //печать списка if(mass[1] != NULL)
    }
}
void vhod(){
    Dek* uk;
    uk = setDek();
    menu(uk);
}
void nachat(){
    printf("Чтоб начать программу нажмите Enter\n");
    char a = ' ';
    while(a!='\n'){
        a=getchar();
    }
    printf("\n");
}
int main(){
    nachat();
    vhod();
    return 0;
}