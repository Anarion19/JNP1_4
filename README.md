# JNP1_4

Celem zadania jest stworzenie programu symulujÄcego bitwy gwiezdne. Bitwa
rozgrywa siÄ w przestrzeni miÄdzygwiezdnej pomiÄdzy siĹami Rebelii a Imperium.
PoniewaĹź chcemy symulowaÄ rĂłĹźne bitwy, naleĹźy przygotowaÄ rozwiÄzanie ogĂłlne.

StwĂłrz nastÄpujÄce typy szablonowe.

= Plik rebelfleet.h =

Klasy Explorer<typename U>, StarCruiser<typename U> i XWing<typename U>
reprezentujÄce statki Rebelii, gdzie U jest typem pĂłl przechowujÄcych
wytrzymaĹoĹÄ tarczy oraz prÄdkoĹÄ, a w przypadku XWing oraz StarCruiser rĂłwnieĹź
siĹÄ ataku statku.

Klasa Explorer przyjmuje w konstruktorze parametry shield oraz speed typu U,
a StarCruiser oraz XWing dodatkowo parametr attackPower teĹź typu U. Klasa
StarCruiser moĹźe przyjmowaÄ speed w zakresie od 99999 do 299795 wĹÄcznie,
a klasy Explorer oraz XWing w zakresie od 299796 do 2997960 wĹÄcznie. PoprawnoĹÄ
wartoĹci parametru speed naleĹźy sprawdzaÄ za pomocÄ asercji.

Klasy Explorer, StarCruiser i XWing udostÄpniajÄ metody publiczne:
U getShield() â zwraca wytrzymaĹoĹci tarczy,
U getSpeed() â zwraca prÄdkoĹÄ,
void takeDamage(U damage) â zmniejsza wytrzymaĹoĹci tarczy o damage, ale nie
wiÄcej niĹź statek ma aktualnie.

Klasy StarCruiser oraz XWing majÄ dodatkowo metodÄ publicznÄ:
U getAttackPower() â zwraca siĹÄ ataku statku.

Klasy Explorer, StarCruiser i XWing majÄ publicznÄ skĹadowÄ valueType
reprezentujÄcÄ typ U, ktĂłrym zostaĹy sparametryzowane.

Szablony klas Explorer, StarCruiser i XWing powinny byÄ specjalizacjÄ
ogĂłlniejszego szablonu RebelStarship<typename U, ...>.

= Plik imperialfleet.h =

Klasy DeathStar<typename U>, ImperialDestroyer<typename U>
i TIEFighter<typename U> reprezentujÄ statki imperium, gdzie U jest typem pĂłl
przechowujÄcych wytrzymaĹoĹÄ tarczy i siĹÄ ataku statku.

Klasy DeathStar, ImperialDestroyer i TIEFighter przyjmujÄ w konstruktorze
parametry shield oraz attackPower typu U.

Klasy DeathStar, ImperialDestroyer i TIEFighter udostÄpniajÄ metody publiczne:
U getShield() â zwraca wytrzymaĹoĹci tarczy,
U getAttackPower() â zwraca siĹÄ ataku statku,
void takeDamage(U damage) â zmniejsza wytrzymaĹoĹci tarczy o damage, ale nie
wiÄcej niĹź statek ma aktualnie.

Klasy DeathStar, ImperialDestroyer i TIEFighter majÄ publicznÄ skĹadowÄ
valueType reprezentujÄcÄ typ U, ktĂłrym zostaĹy sparametryzowane.

Dodatkowo trzeba stworzyÄ funkcjÄ, ktĂłra umoĹźliwi statkowi Imperium zaatakowanie
wybranego statku Rebelii:
void attack<I, R>(I imperialShip, R rebelShip) â wykonuje atak na statek
Rebelii, obniĹźajÄc wytrzymaĹoĹÄ jego tarczy. NaleĹźy teĹź uwzglÄdniÄ specjalny
przypadek, gdy R = StarCruiser<T> lub R = XWing<T> â wtedy atak nastÄpuje w dwie
strony â wytrzymaĹoĹÄ tarczy jest obniĹźana zarĂłwno statkowi Rebelii, jak
i statkowi Imperium.

Szablony klas DeathStar, ImperialDestroyer i TIEFighter powinny byÄ
specjalizacjÄ ogĂłlniejszego szablonu ImperialStarship<typename U, ...>.

= Plik battle.h =

Klasa SpaceBattle<typename T, t0, T t1, typename... S>, gdzie:
T â typ przechowujÄcy czas,
t0 â czas startowy,
t1 â czas koĹcowy, po ktĂłrego przekroczeniu nastÄpuje wyzerowanie licznika,
S... â typy statkĂłw.
NaleĹźy sprawdzaÄ poprawnoĹÄ parametrĂłw t0 i t1 w czasie kompilacji.

Klasa SpaceBattle przyjmuje w konstruktorze kolejno obiekty reprezentujÄce
statki biorÄce udziaĹ w bitwie.

Klasa SpaceBattle udostÄpnia metody publiczne:
size_t countImperialFleet() â zwraca liczbÄ niezniszczonych statkĂłw Imperium;
size_t countRebelFleet() - zwraca liczbÄ niezniszczonych statkĂłw Rebelii;
void tick(T timeStep) â na poczÄtku sprawdza aktualny czas; jeĹli jest to
czas ataku, to nastÄpuje atak statkĂłw Imperium na statki Rebelii; na koniec czas
przesuwa siÄ o timeStep.

SpaceBattle rozgrywa siÄ w czasie miÄdzygwiezdnym. Czas liczony jest
w sekundach, od sekundy 0 do sekundy t1 i potem znĂłw od sekundy 0, i tak
cyklicznie. Pierwsze odliczanie zaczyna siÄ od sekundy t0. Ze wzglÄdu na
zakĹĂłcenia magnetyczne statki mogÄ atakowaÄ tylko w sekundach bÄdÄcych
kwadratami liczb caĹkowitych. Obliczenie wszystkich potrzebnych liczb
reprezentujÄcych sekundy ataku i ich zapamiÄtanie w odpowiedniej kolekcji musi
odbyÄ siÄ w czasie kompilacji.

Ataki podczas bitwy odbywajÄ siÄ sekwencyjnie. W sekundzie ataku kaĹźdy
niezniszczony statek imperialny po kolei atakuje wszystkie niezniszczone statki
rebelianckie, czyli ma miejsce nastÄpujÄca sekwencja zdarzeĹ:

dla kaĹźdego statku Imperium
  dla kaĹźdego statku Rebelii
    jeĹli oba statki nie nie zostaĹy jeszcze zniszczone,
      statek Imperium atakuje statek Rebelii.

KolejnoĹÄ atakowania (iterowania) jest zgodna z kolejnoĹciÄ, w jakiej statki
zostaĹy przekazane w konstruktorze. JeĹli zaatakowana jednostka rebeliancka moĹźe
siÄ broniÄ (ma parametr attackPower), to wtedy obraĹźenia zadawane sÄ
âjednoczeĹnieâ i oba statki odnoszÄ odpowiednie obraĹźenia zgodnie z siĹami ataku.
Statek zostaje zniszczony, jeĹli wytrzymaĹoĹÄ jego tarczy spadnie do zera.

WywoĹanie tick() na bitwie, podczas gdy wszystkie statki Imperium zostaĹy
zniszczone, powoduje wypisanie na standardowe wyjĹcie napisu "REBELLION WON\n".
WywoĹanie tick() na bitwie, podczas gdy wszystkie statki Rebelii zostaĹy
zniszczone, powoduje wypisanie na standardowe wyjĹcie napisu "IMPERIUM WON\n".
JeĹli wszystkie statki zarĂłwno Imperium jak i Rebelii sÄ zniszczone, to zostaje
wypisany napis "DRAW\n".

= Wymagania formalne =

W tym zadaniu wymagane jest uĹźycie kompilatora Clang, ktĂłry wypisuje bardzo
szczegĂłĹowe komunikaty o bĹÄdach w przypadku korzystania z szablonĂłw
i metaprogramowania. RozwiÄzanie bÄdzie kompilowane za pomocÄ polecenia

clang -Wall -Wextra -std=c++17 -O2 -lstdc++

PrzykĹad uĹźycia znajduje siÄ w pliku starwars_example.cc.

RozwiÄzanie powinno zawieraÄ pliki rebelfleet.h, imperialfleet.h, battle.h.
Pliki te naleĹźy umieĹciÄ w repozytorium w katalogu

grupaN/zadanie4/ab123456+cd123456

lub

grupaN/zadanie4/ab123456+cd123456+ef123456

gdzie N jest numerem grupy, a ab123456, cd123456, ef123456 sÄ identyfikatorami
czĹonkĂłw zespoĹu umieszczajÄcego to rozwiÄzanie. Katalog z rozwiÄzaniem nie
powinien zawieraÄ innych plikĂłw, ale moĹźe zawieraÄ podkatalog prywatne, gdzie
moĹźna umieszczaÄ rĂłĹźne pliki, np. swoje testy. Pliki umieszczone w tym
podkatalogu nie bÄdÄ oceniane. Nie wolno umieszczaÄ w repozytorium plikĂłw
duĹźych, binarnych, tymczasowych (np. *.o) ani innych zbÄdnych.
