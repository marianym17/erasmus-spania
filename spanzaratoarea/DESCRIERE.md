# 🎮 JOCUL SPÂNZURĂTOAREI - Ghid de Joc

## 📜 Descriere Generală
Spânzurătoarea este un joc clasic de ghicire a cuvintelor. Trebuie să descoperi un cuvânt secret introducând litere, dar ai un număr limitat de încercări greșite.

## 🎯 Obiectivul Jocului
- **Ghicește cuvântul secret** înainte să fii eliminat
- **Fiecare literă corectă** îți dezvăluie pozițiile sale în cuvânt
- **Fiecare literă greșită** te apropie de finalul jocului

## 📊 Cum Funcționează

### Faza de Inițializare
1. Calculatorul alege **aleatoriu** un cuvânt din banca de 20 cuvinte informatice
2. Cuvântul este ascuns - vezi doar **liniuțe (_)** pentru fiecare literă
3. Ai maxim **6 greșeli** înainte de a pierde

### Faza de Joc
1. **Introduci o literă** - doar o literă la o dată
2. Calculatorul verifică dacă litera este în cuvânt:
   - ✅ **CORECT**: Literele se dezvăluie pe pozițiile loro
   - ❌ **GREȘIT**: Se adaugă la lista de litere greșite și crește desenul

### Urmărire Progres
- **Cuvântul parțial**: Arată literele ghicite și liniuțele pentru necunoscute
- **Greseli rămase**: Ți se arată câte încercări țial mai ai
- **Litere greșite**: Lista cu toate literele pe care le-ai ghicit greșit
- **Desenul spânzurătoarei**: Se actualizează vizual cu fiecare greșeală

### Etapele Spânzurătoarei
```
Greseli 0:  Doar cadrul
Greseli 1:  Se adaugă capul (O)
Greseli 2:  Se adaugă trupul (|)
Greseli 3:  Se adaugă braț stâng (/)
Greseli 4:  Se adaugă braț drept (\)
Greseli 5:  Se adaugă picior stâng (/)
Greseli 6:  Se adaugă picior drept (\) - GAME OVER!
```

## 🏆 Condiții de Victorie și Înfrângere

### ✨ CÂȘTIGI dacă:
- Ghicești **toate literele** din cuvânt **înainte** de a 7-a greșeală
- Vei vedea mesajul: **"FELICITĂRI! AI CÂȘTIGAT!"**
- Cuvântul secret va fi dezvăluit

### 💀 PIERZI dacă:
- Faci **6 greșeli** (desenul se completează)
- Vei vedea mesajul: **"GAME OVER! AI PIERDUT!"**
- Cuvântul secret va fi dezvăluit

## 📝 Reguli Importante

1. **O literă la o dată** - Trebuie să introduci doar o singură literă
2. **Doar litere** - Numerele și alte caractere nu sunt acceptate
3. **Fără maiuscule** - Programul convertește automat în minuscule
4. **Nu poți repeta** - Dacă ai ghicit deja o literă, vei fi avertizat

## 🎓 Cuvinte din Joc
Jocul conține cuvinte legate de **informatică și programare**:
- programare
- calculator
- informatica
- algoritm
- variabila
- functie
- structura
- terminal
- fisier
- baza
- python
- debug
- compiler
- runtime
- software
- hardware
- memorie
- procesor
- database
- aplicatie

## 🚀 Cum să Rulez Jocul

### Compilare
```bash
g++ spanzuratoarea.cpp -o spanzuratoare
```

### Rulare
```bash
./spanzuratoare
```

## 💡 Sfaturi și Strategii

1. **Început bun**: Încearcă mai întâi vocalele (a, e, i, o, u)
2. **Litere frecvente**: În limba română, folosește litere frecvente ca 'n', 'r', 't'
3. **Pattern recognition**: Dacă vezi `progra_are`, e probabil `programare`
4. **Calcul de risc**: Alege cu grijă când ai puține încercări rămase

## 📌 Exemplu de Joc

```
Cuvântul: _________ (9 litere)
Greseli ramase: 6

Introduceți o literă: a
Corect! Litera este în cuvânt.
Cuvântul: pr_gra_are

Introduceți o literă: x
Greșit! Litera nu este în cuvânt.
Greseli ramase: 5

... și așa mai departe
```

---
**Distracte cu jocul! 🎉**
