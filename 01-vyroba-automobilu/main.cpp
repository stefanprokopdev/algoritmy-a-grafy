/**
 * BI-AG1 - 01. progtest - Vyroba automobilu
 * @author Stefan Prokop <prokoste@fit.cvut.cz>
 *
 * Zadani:
 *      Prototyp nového modelu auta sice těší designéry a manažery místní automobilky, ale inženýrům zodpovědným za
 *      plánování průběhu výroby nepřináší nic než noční můry. Designéři se totiž na novém modelu náležitě vyřádili a
 *      ke kompletaci vozu je zapotřebí postupně smontovat velmi vysoké množství dílčích součástek. Navíc mnohdy nastává
 *      případ, kdy nelze některou součástku smontovat dříve, než jsou smontovány jiné součástky, na kterých montáž
 *      závisí (např. pro smontování dveří je zapotřebí mít připravený zámek a kliku, mechanismus stahování okének,
 *      okénko, těsnění, atp.).
 *
 *      Kvůli komplexnosti konstrukce nového modelu auta je tak zapotřebí průběh výroby auta precizně naplánovat.
 *      Jinak by totiž hrozilo, že doba potřebná pro kompletaci jednoho vozu bude dlouhodobě nerentabilní. Vzhledem k
 *      tomu, že se nejedná o úlohu, kterou by bylo možno vzhledem k objemu součástek vyřešit ručně, byli jste na
 *      řešení tohoto problému povoláni vy. Konkrétně je zapotřebí pro daný výrobní plán, určující závislosti součástek
 *      při montáži, a pro dané doby nutné pro montáž součástek určit, kdy přesně se ta která součástka má začít
 *      montovat tak, aby celková doba potřebná pro sestavení jednoho vozu byla minimální (k sestavení vozu je zapotřebí
 *      smontovat všechny součástky uvedené ve výrobním plánu).
 *
 *      K dispozici máte na vstupu počet součástek, časy nutné pro montáž jednotlivých součástek a výrobní plán, který
 *      pro každou součástku určuje součástky, které je zapotřebí smontovat před její montáží. Nelze začít montovat
 *      konkrétní součástku předtím, než jsou smontovány všechny součástky, na kterých její výroba závisí. Nezáleží-li
 *      montáž součástky na montáži žádné jiné součástky, lze ji začít montovat okamžitě. Pokud je součástka smontována
 *      v čase x, lze jí okamžitě použít pro montáž jiné součástky také v čase x. Předpokládejte, že pro montování
 *      součástek je vyčleněno neomezené množství dělníků, tj. v jeden okamžik lze montovat libovolné množství
 *      součástek. Může nastat situace, kdy designéři při honbě za perfektním návrhem vozu sestaví nevalidní výrobní
 *      plán, který z nějakého důvodu nelze realizovat. Takový případ musíte detekovat. Také je možné, že existuje více
 *      řešení, které minimalizují dobu pro kompletaci vozu, ale liší se časy pro montáž součástek. V takovém případě
 *      vypište libovolné z těchto řešení.
 *
 *      Vzhledem k aféře dieselgate je v automobilkách zakázán veškerý software, který byl použit pro podvody při měření
 *      emisí. Toto opatření se týká i knihovny STL a nelze ji tak při řešení této úlohy použít.
 *
 *      Formát vstupu:
 *          Na prvním řádku je číslo N udávající počet součástek nutných ke kompletaci jednoho vozu.
 *          Součástky jsou číslovány od nuly, mají tedy čísla 0, 1, ..., N - 1.
 *          Na dalším řádku je N čísel t0, t1, ..., tn-1, 0 < ti < 109. i-té číslo ti udává čas, který je potřeba pro
 *          montáž i-té součástky.
 *          Poté následuje N řádků, postupně pro součástky 0 až N - 1. Na začátku řádku je číslo udávající počet
 *          součástek potřebných k montáži dané součástky (toto číslo může být i 0), a následuje mezerami oddělený
 *          seznam čísel těchto součástek.
 *          Žádná součástka není uvedena ve svém vlastním seznamu závislostí a žádná součástka není uvedena v seznamu
 *          závislostí vícekrát.
 *          Výrobní plán se vždy skládá z alespoň jedné součástky, ale mezi součástkami nemusí existovat žádná závislost.
 *          Z toho vyplývá, že mohou existovat dvojice součástek, které na sobě vzájemně nezávisí (a to ani tranzitivně
 *          přes jiné součástky).
 *          Můžete předpokládat, že vstup je korektní.
 *
 *      Formát výstupu:
 *          Pokud nelze sestavit výrobní plán pro zadané závislosti součástek, program má vypsat na samostatný řádek
 *          řetězec "No solution." (bez uvozovek).
 *          Pokud řešení existuje, výstup sestává ze dvou řádků. Na prvním řádku program vypíše minimální dobu potřebnou
 *          pro smontování všech součástek auta. Na druhém řádku následuje N mezerami oddělených čísel, kde i-té z nich
 *          udává čas, kdy se má začít montovat i-tá součástka.
 *
 *      Bodové podmínky:
 *          Pro splnění povinných testů (test základními a malými daty) je zapotřebí, aby program fungoval korektně pro
 *          výrobní plány o nejvýše 10 součástkách a 20 závislostech.
 *          Pro splnění testu středními daty musí program splnit časový a paměťový limit pro plány o nejvýše 100
 *          součástkách a 1 000 závislostech.
 *          Pro splnění testu velkými daty musí program splnit časový a paměťový limit pro plány o nejvýše 100 000
 *          součástkách a 1 000 000 závislostech.
 *
 *      Ukázka práce programu:
 *          Příklad vstupu 1:
 *              6
 *              3 5 7 2 2 4
 *              0
 *              0
 *              2 0 1
 *              2 2 1
 *              0
 *              1 4
 *          Příklad výstupu 1:
 *              14
 *              0 0 5 12 0 2
 *          Příklad vstupu 2:
 *              4
 *              6 3 5 4
 *              0
 *              2 0 3
 *              1 1
 *              1 2
 *          Příklad výstupu 2:
 *              No solution.
 */

#include <iostream>

using namespace std;

long int min_solution_time = 0, dfs_result, dfs_help_counter;
long int * solution_times;

/**
 * Trida soucastek
 */
class Component
{
public:
    // found - zda uz byla soucastka navstivena, created - zda uz byla soucastka vytvorena
    bool found = false, created = false;
    // pole zavislych komponent
    Component ** dependencies;
    // oznacuje, kdy se dana komponenta zacne vyrabet, kdy se zacne vyrabet nasledujici komponenta
    long int start_time = 0, next_time = 0;

    /**
     * Component constructor
     */
    Component()
    {
        dependency_count = 0;
    }

    /**
     * Component destructor
     */
    ~Component()
    {
        if(dependency_count > 0) {
            delete [] dependencies;
        }
    }

    /**
     * Metoda inicializujici pole zavislosti (na cem je dana soucastka zavisla)
     *
     * @param count
     */
    void initDependencies(long int count)
    {
        if(count > 0) {
            dependency_count = count;
            dependencies = new Component*[count];
        }
    }

    /**
     * dependency_count getter
     *
     * @return long int
     */
    long int getDependency_count() const
    {
        return dependency_count;
    }

    /**
     * time getter
     *
     * @return long int
     */
    long int getTime() const
    {
        return time;
    }

    /**
     * time setter
     *
     * @param time
     */
    void setTime(long int time)
    {
        Component::time = time;
    }

    /**
     * id setter
     *
     * @param id
     */
    void setId(long int id)
    {
        Component::id = id;
    }

    /**
     * id getter
     *
     * @return long int
     */
    long int getId() const
    {
        return id;
    }

private:
    // id zavislosti, doba trvani vyroby, pocet zavislosti
    long int id, time, dependency_count;
};

// globalni promenna - pole komponent
Component * components;

/**
 * Funkce vyhodnocujici pruchod grafu - symbolizuje algoritmus DFS
 *
 * @param number_of_components
 * @return long int
 */
long int dfs_start(Component * start_component)
{
    long int result = 0;

    if(!start_component->created && start_component->found) {
        // pokud byla nalezena, ale nebyla vytvorena, pak mame cyklus
        return -1;
    }

    // vraci cas, kdy se zacala vyrabet + svuj vlastni cas
    if(start_component->created) {
        // pokud nema zavislosti, vracim jeji cas, jinak vracim nejvyssi nascitany cas z jejich zavislosti
        if(start_component->getDependency_count() <= 0) {
            return start_component->getTime();
        }

        return start_component->start_time + start_component->getTime();
    }

    start_component->found = true;

    // projdu rekurzivne vsechny zavislosti dane komponenty
    for (long int i = 0; i < start_component->getDependency_count(); i++) {
        // pro kazdou ze zavislosti pustim DFS
        result = dfs_start(start_component->dependencies[i]);

        // pokud jsme odhalili cyklus, je nutne skoncit s chybou
        if(result < 0) {
            return -1;
        }

        if(start_component->start_time < result) {
            // pokud je vysledek DFS zavislosti mensi nez soucasny start_time, pak se prepise (komponenta se vytvari dele)
            start_component->start_time = result;
        }
    }

    start_component->created = true;
    return start_component->start_time + start_component->getTime();
}

/**
 * Funkce nacitajici pocatecni vstupni hodnoty
 *
 * @param number_of_components
 */
void readInput(long int number_of_components)
{
    for (long int i = 0; i < number_of_components; i++) {
        Component component;
        long int time;

        scanf("%ld", &time);
        component.setId(i);
        component.setTime(time);
        components[i] = component;
    }

    for (long int i = 0; i < number_of_components; i++) {
        // pocet soucastek nutnych k montazi dane soucastky
        long int dependency_components;

        scanf("%ld", &dependency_components);
        components[i].initDependencies(dependency_components);

        // nacteni indexu soucastek nutnych k sestaveni dane soucastky
        for (long int j = 0; j < dependency_components; j++) {
            long int component;

            scanf("%ld", &component);
            components[i].dependencies[j] = &components[component];
        }
    }
}

int main() {
    // pocet soucastek
    long int number_of_components, response = 0;

    scanf("%ld", &number_of_components);
    solution_times = new long int[number_of_components];
    components = new Component[number_of_components];
    readInput(number_of_components);

    // zaverecne vyhodnoceni
    for (long int i = 0; i < number_of_components; i++) {
        dfs_result = 0;
        dfs_help_counter = 0;

        response = dfs_start(&components[i]);

        if(response == -1) {
            break;
        }

        if(min_solution_time < response) {
            min_solution_time = response;
        }

        response -= components[i].getTime();

        solution_times[components[i].getId()] = response;
    }

    // vypis reseni
    if(response == -1) {
        cout << "No solution.";
    } else {
        cout << min_solution_time << endl;

        for (long int i = 0; i < number_of_components; i++) {
            if(i != 0) {
                cout << " ";
            }

            cout << solution_times[i];
        }
    }

    cout << endl;

    delete [] components;
    delete [] solution_times;
    return 0;
}