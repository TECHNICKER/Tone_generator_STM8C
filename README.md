# STM8 Tools

Šablona projektu k vývoji firmware pro mikrokontroléry STM8S.

## Jak to používat, základní info

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

## Typy k VS Code

VS Code jemocný textový editor, který se snadno přizpůsobí a rozšíří o další funkce pomocírozšíření. Rozříšení se dají instalovat pomocí ikony bedny v postranním panelu.

### Integrovaný terminál

Přímo ve VS Code si můžete vytvořit terminál a ten používat ke kompilaci a nahrávání FW. To může ušetřit čas ztrávený přepínánm mezi okny, zároveň nám to umožní mít "všechno" v jedné aplikaci. Nový terminál spustíme pomocí klávesové skratky `Ctrl` + `Shift` + `P`. To vyvolá přákazovou lištu, do které zadáme `Create New Terminal`.

⚠️ Pokud se s njakého záhadného důvodu nacházíte na platformě MS Windows, je třeba přepnout shell terminálu na `Git Bash`. To lzep rovést pomocí malé rozevírací šipecky v pravé části terminálu.

### Jak na našeptávání?

Doporučuji nainstlaovat si rozšíření C/C++ od firmy Microsoft s podnadpisem _C/C++ IntelliSense, debugging, and code browsing._. Odkaz na [market place](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).

Toto rozšíření vám zpřístupní mocnou funkci našeptávání, číž může rapidně zvíšit produktivitu práce i hledání chyb.

Aby našeptávání funkovalo korektně, je třeba zkontrolovat soubor `.vscode/c_cpp_properties.json` a případně jej upravit dle vaší platformy. Následují ukázky tohoto souboru:

<details>
<summary>Ukázková verze pro Linux</summary>

```json
{
    "configurations": [
        {
            "name": "STM8",
            "includePath": [
                "${workspaceFolder}/**",
                "/opt/sdcc/share/sdcc/include/**",
                "app/inc/**",
                "drivers/inc/**"
            ],
            "defines": [
                "STM8S208",
                "USE_STDPERIPH_DRIVER",
                "_SDCC_"
            ],
            "compilerPath": "/opt/sdcc/bin/sdcc",
            "cStandard": "c99",
            "cppStandard": "c++11",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```

</details>

<details>
<summary>Ukázková verze pro MS Windows</summary>

```json
{
    "configurations": [
        {
            "name": "STM8",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/Program Files/SDCC/include/**",
                "app/inc/**",
                "drivers/inc/**"
            ],
            "defines": [
                "STM8S208",
                "USE_STDPERIPH_DRIVER",
                "_SDCC_"
            ],
            "compilerPath": "C:/ProgramData/chocolatey/bin/gcc.exe",
            "cStandard": "c99",
            "cppStandard": "c++11",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}

```

</details>
