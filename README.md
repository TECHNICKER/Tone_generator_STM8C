# STM8 Tools

Šablona projektu k vývoji firmware pro mikrokontroléry STM8S.

## Použití

Následují ukázky často používaných akcí / příkazů.

### Klonování

Příkaz, který naklonuje (stáhne) tento repozitář.

```bash
git clone https://gitlab.com/wykys/stm8-tools.git
```

### Přejmenování

Doporučuji si každý projekt vhodně nejlépe popisně pojmenovat, usnadní vám to život v budoucnu. Při výběru jména se preventivně vyvarujte použití diaktitiky. K přejmenování budeme používat příkaz `mv` (__Move__), který slouží k přejmenování, případně přesunu souborů.

```bash
mv stm8-tools blikac
```

### Změna složky

Příkaz `cd` (__Change Directory__) změní aktuální složku, vekteré se nacházíme za jinou. Tedy nám to umožní pohybu mezi složkami.

```bash
# přejdeme do složky cesta_ke_slozce
cd cesta_ke_slozce
# přejdeme o adresář víš
cd ..
# přejdeme do domovské složky
cd
```

### VS Code

Otevřeme editor VS Code v aktuální složce. Tečka symbolizuje aktuální adresář, můžeme však zadat cestu k libovolné složce nebo osuboru.

```bash
code .
```

### Kompilace projektu

Vytvoří složku `build` a vní soubor `firmware.elf`, který obsahuje náš program.

```bash
make
```

### Nahrání FW do MCU

Ze souboru `build/firmware.elf` zapíše obsah programové paměti do mikrokontroléru.

```bash
make flash
```

### Kompilace s nahráním FW do MCU v jednom

Tento příkaz se chová stejnějako posloupnost příkazů `make` následovaným `make flash`. Může vám tedy ušetřit psaní.

```bash
make build_and_flash
```
