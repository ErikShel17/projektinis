# Automobilių duomenų valdymo sistema

## Projekto tikslas
Sukurti C++ konsolinę programą automobilių duomenims valdyti, pritaikant struktūras (`struct`), dinaminius masyvus (`std::vector`) ir darbą su tekstiniais failais.

## Pasirinktos temos aprašymas
Programa imituoja automobilių parko informacinę sistemą. Kiekvienas automobilis bazėje turi šešis atributus: unikalų ID, markę, modelį, gamybos metus, kainą ir kuro tipą.

## Programos funkcionalumo aprašymas
Programoje realizuotas pilnas **CRUD** duomenų valdymas ir apsauga:
* **Create:** Naujo automobilio pridėjimas, ID sugeneruojamas automatiškai.
* **Read:** Visų automobilių išvedimas lentelėje arba vieno paieška pagal ID.
* **Update:** Esamo automobilio duomenų redagavimas (rodomos senos reikšmės).
* **Delete:** Automobilio šalinimas iš sistemos naudojant iteratorius.
* **Apsauga:** Įvesties validacija (`cin.fail()`), apsauganti programą nuo pakibimo įvedus raidę vietoje skaičiaus.

## Naudojamų failų aprašymas
* **`automobiliai.txt`** – pagrindinis duomenų failas (virš 15 įrašų). Laukai atskirti skyrikliu `;`. Nuskaitomas paleidus programą, atnaujinamas ją išjungiant.
* **`ataskaita.txt`** – tekstinis failas, sugeneruojamas automatiškai paleidus statistikos funkciją.

## Programos paleidimo instrukcija
1. Įkelkite `automobiliai.txt` failą į tą patį aplanką, kuriame guli `main.cpp`.
2. Atidarykite projektą per C++ IDE (pvz., Visual Studio) ir paleiskite (F5 / Run).
3. Konsolėje pasirinkite norimą veiksmą skaičiais nuo `0` iki `7`.
4. **Svarbu:** Norėdami išsaugoti pakeitimus faile, programą pabaikite pasirinkę punktą `0`.

## Papildomų funkcijų aprašymas
1. **Filtravimas:** Automobilių atranka ir išvedimas ekrane pagal vartotojo įvestą markę.
2. **Statistika:** Ataskaitos kūrimas – programa apskaičiuoja bendrą automobilių skaičių, vidutinę kainą, naujausius metus, brangiausią modelį ir įrašo duomenis į `ataskaita.txt`.
