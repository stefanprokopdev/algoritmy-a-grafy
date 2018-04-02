/**
 * BI-AG1 - 02. progtest - Predvolebni debaty
 * @author Stefan Prokop <prokoste@fit.cvut.cz>
 *
 * Zadani:
 *      Ve velmi vzdálené zemi již několik týdnů panuje vzrušená atmosféra. Blíží se totiž volby a celý národ tak s
 *      napětím očekává, že opět po několika letech může přijít změna k lepšímu. Na nohou však nejsou pouze občané, ale
 *      také politici, kteří v nejbližších dnech v předvolebních debatách svedou tvrdé souboje o politické body. Zejména
 *      těžkou pozici mají členové vlády, kteří by velmi rádi obhájili svůj mandát. U těch se totiž volební přízeň odvíjí
 *      zejména od úspěchů či neúspěchů v předešlém funkčním období.
 *
 *      Asi nejtěžší situaci má stávající ministr financí. Není totiž žádným tajemstvím, že jeho působení ve vládě by se
 *      dalo shrnout v nejlepším jako tristní. Konkrétně za jeho působení takřka všem klesly příjmy, což spoustu lidí
 *      posunulo pod hranici životního minima. S takovými výsledky by v předvolebních debatách ministr jistě neokouzlil,
 *      a tak se svými poradci vymyslel záchranný plán. Kdyby přeci mohl v debatách ukazovat nějakou hodnotu, která není
 *      vylhaná, vychází z reálných příjmů, nevypadá na první pohled tak zle, ale u které zároveň lidé nerozumí způsobu
 *      jejího výpočtu, to by byla výhra! Jako první padla volba na aritmetický průměr, ale průzkum ukázal, že lidé této
 *      hodnotě rozumí. Z toho důvodu byl zvolen medián, který se v obecném povědomí vyskytuje výrazně méně. Konkrétně
 *      by tak ministr pro úspěch v debatách potřeboval následující - kdykoliv se moderátor či politický oponent zeptají
 *      na příjmy v daném finančním rozpětí, ministr odpoví mediánem příjmů všech lidí, kteří v daném rozpětí mají
 *      příjem. Situace je však ztížená tím, že příjmy lidí se neustále mění. To znamená, že ze seznamu příjmů všech
 *      lidí mohou být některé příjmy odstraněny, a naopak některé příjmy mohou do seznamu přibýt (změna příjmu se dá
 *      představit jako kombinace odstranění staré a přibytí nové hodnoty). Je tedy nutné, aby ministr měl rychle k
 *      dispozici mediány pro daná rozpětí příjmů v rámci dynamicky se měnícího seznamu příjmů.
 *
 *      Jelikož se jedná o velmi riskantní předvolební pokus, musel být pro efektivní a správné řešení úlohy vybrán
 *      ostřílený programátor, který se nebojí zhostit se úkolu takovéto podstaty. Volba padla na vás. Pro zadanou
 *      posloupnost přibývání/odstraňování příjmů a rozsahů pro hledání mediánu, musíte vytvořit program, který splní
 *      požadavky uvedené výše. Vzhledem k absolutnímu utajení nelze při řešení této úlohy používat takřka žádný cizí
 *      kód. Toto opatření se týká i knihovny STL, kterou tak použít nemůžete.
 *
 *      Formát vstupu a výstupu:
 *          Vstup sestává z určitého počtu řádek na vstupu, kde každá kóduje jeden příkaz, viz níže uvedené příkazy v
 *          uvozovkách:
 *
 *          "1 X"
 *          kde X je přirozené číslo, 1 ≤ X ≤ 109, znamená přidej do seznamu příjmů příjem o hodnotě X.
 *
 *          "2 X"
 *          kde X je přirozené číslo, 1 ≤ X ≤ 109, znamená odeber ze seznamu příjmů příjem o hodnotě X.
 *
 *          "3 X Y"
 *          kde X, Y jsou přirozená čísla, 1 ≤ X, Y ≤ 109, X ≤ Y, znamená nalezni medián (viz definice níže) čísel v
 *          rozsahu od X do Y (včetně) ze stávajícího seznamu příjmů a vypiš jej na samostatný řádek.
 *
 *          "4"
 *          znamená, že již začaly volby a že žádný další příkaz již následovat nebude; tento příkaz je zaručeně jako
 *          poslední na vstupu.
 *
 *          Můžete se spolehnout, že vstup je zadán korektně.
 *
 *          Dále:
 *              Medián čísel v rozsahu od X do Y ze stávajícího seznamu příjmu definujeme takto: je-li ve stávajícím
 *              seznamu příjmů k příjmů s hodnotou v rozsahu mezi X a Y (včetně), je medián ⌈k⁄2⌉-tý nejmenší z těchto
 *              příjmů.
 *
 *              Nenachází-li se pro daný rozsah v seznamu příjmů žádný příjem, vypište na výstup řádek s řetězcem
 *              "notfound" (bez uvozovek).
 *
 *              Může se stát, že vzhledem k úřednické chybě dostane váš program požadavek na smazání takového příjmu,
 *              který se v seznamu příjmů nevyskytuje. V takovém případě požadavek ignorujte.
 *
 *              Naopak se nikdy nestane, že by se v seznamu najednou vyskytovalo (po příslušných požadavcích na přidání)
 *              více příjmů o stejné hodnotě. Pokud však bude příjem o určité hodnotě ze seznamu v nějaký moment odebrán,
 *              může být později do seznamu znovu přidán.
 *
 *          Bodové podmínky:
 *              Pro splnění povinných testů je zapotřebí, aby program fungoval korektně pro vstupy o nejvýše 1 000
 *              příkazech. Příkazy budou pouze typu 1, 3 a 4.
 *
 *              Pro splnění testu velkými daty #1 musí program splnit časový limit pro vstupy o nejvýše 1 000 000
 *              příkazech. Příkazy budou pouze typu 1, 3 a 4.
 *
 *              Pro splnění testu velkými daty #2 musí program splnit časový limit pro vstupy o nejvýše 1 000 000
 *              příkazech. Příkazy mohou být všech typů.
 *
 *              Testy podle ukázky jsou z důvodu omezení typů příkazů na vstupu provedeny ve dvou různých testech.
 *              První z nich testuje ukázkové vstupy 1 a 2 a je povinný. Druhý testuje ukázkový vstup 3 a je nepovinný.
 *
 *      Ukázka práce programu:
 *          Příklad vstupu 1:
 *              1 13
 *              1 4
 *              1 17
 *              1 6
 *              1 9
 *              1 14
 *              3 4 9
 *              3 3 10
 *              3 14 14
 *              3 1 20
 *              4
 *
 *          Příklad výstupu 1:
 *              6
 *              6
 *              14
 *              9
 *
 *          Příklad vstupu 2:
 *              1 2
 *              1 3
 *              1 1
 *              3 15 20
 *              3 2 2
 *              3 4 4
 *              4
 *
 *          Příklad výstupu 2:
 *              notfound
 *              2
 *              notfound
 *
 *          Příklad vstupu 3:
 *              1 4
 *              1 8
 *              1 6
 *              1 12
 *              1 7
 *              2 10
 *              3 10 13
 *              3 8 15
 *              3 1 100
 *              3 2 7
 *              2 6
 *              3 2 7
 *              2 4
 *              3 2 7
 *              2 7
 *              3 2 7
 *              4
 *
 *          Příklad výstupu 3:
 *              12
 *              8
 *              7
 *              6
 *              4
 *              7
 *              notfound
 */

#include <iostream>

using namespace std;

/**
 * Symbolizuje list stromu
 */
struct List
{
    int value;
    int height;

    struct List * left;
    struct List * right;
};

struct List * data = nullptr;

/**
 * Funkce, ktera inicializuje novy list
 *
 * @param value
 * @return List
 */
struct List * createList(int value)
{
    auto * list = (struct List *) malloc(sizeof(struct List));
    list->height = 1;
    list->value = value;
    list->left = nullptr;
    list->right = nullptr;

    return list;
}

/**
 * Funkce, ktera vraci hloubku stromu
 *
 * @param list
 * @return int
 */
int height(struct List * list)
{
    if(list == nullptr) {
        return 0;
    } else {
        return list->height;
    }
}

/**
 * Funkce, ktera hleda maximum ze dvou zadanych cisel
 *
 * @param x
 * @param y
 * @return int
 */
int max(int x, int y)
{
    return (x > y) ? x : y;
}

/**
 * Funkce, ktera provadi pravou / levou rotaci
 *
 * @param list
 * @param type
 * @return List
 */
struct List * rotate(struct List * list, int type = 0)
{
    if(type == 0) {
        // prava rotace

        struct List * list2 = list->left;
        struct List * tmp = list2->right;

        list2->right = list;
        list->left = tmp;

        list->height = max(height(list->left), height(list->right));
        list2->height = max(height(list2->left), height(list2->right));

        return list2;
    } else {
        // leva rotace

        struct List * list2 = list->right;
        struct List * tmp = list2->left;

        list2->left = list;
        list->right = tmp;

        list->height = max(height(list->left), height(list->right));
        list2->height = max(height(list2->left), height(list2->right));

        return list2;
    }
}

/**
 * Funkce, ktera vraci balancni faktor stromu
 *
 * @param list
 * @return int
 */
int getBalance(struct List * list)
{
    if(list == nullptr) {
        return 0;
    } else {
        return height(list->left) - height(list->right);
    }
}

/**
 * Funkce, ktera obstarava vlozeni hodnoty do stromu
 *
 * @param list
 * @param value
 * @return List
 */
struct List * insert(struct List * list, int value)
{
    if(list == nullptr) {
        return createList(value);
    }

    if(value < list->value) {
        list->left = insert(list->left, value);
    } else if(value > list->value) {
        list->right = insert(list->right, value);
    } else {
        return list;
    }

    list->height = 1 + max(height(list->left), height(list->right));
    int balance = getBalance(list);

    if(balance > 1 && value < list->left->value) {
        return rotate(list);
    }

    if(balance < -1 && value > list->right->value) {
        return rotate(list, 1);
    }

    if(balance > 1 && value > list->left->value) {
        list->left = rotate(list, 1);

        return rotate(list);
    }

    if(balance < -1 && value < list->right->value) {
        list->right = rotate(list);

        return rotate(list, 1);
    }

    return list;
}

/**
 * Funkce, ktera cte uzivatelsky vstup
 *
 * @return int
 */
int readInput()
{
    int function = 0, response = 0;
    int salary, from, to;
    scanf("%d", &function);

    switch (function) {
        case 1:
            scanf("%d", &salary);
            data = insert(data, salary);
            break;
        case 2:
            scanf("%d", &salary);
            //remove(getIndexByValue(salary));
            break;
        case 3:
            scanf("%d %d", &from, &to);
            //findMedian(from, to);
            break;
        default:
            response = 1;
            break;
    }

    return response;
}

/**
 * Funkce, ktera vypise obsah stromu
 *
 * @param list
 */
void print(struct List * list)
{
    if(list != nullptr) {
        cout << list->value << " ";
        print(list->left);
        print(list->right);
    }
}

/**
 * Funkce, ktera smaze naalokovanou pamet struktury
 *
 * @param list
 */
void freeMemory(struct List * list)
{

}

int main() {
    // TODO: https://codereview.stackexchange.com/questions/104525/the-median-of-the-given-avl-tree
    
    while (readInput() != 1) {
        /*
        print(data);
        cout << endl << "-------------------" << endl;
         */
    }

    return 0;
}