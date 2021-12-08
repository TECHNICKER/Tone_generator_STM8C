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

Doporučuji si každý projekt vhodně nejlépe popisně pojmenovat, usnadní vám to život v budoucnu. Při výběru jména se preventivně vyvarujte použití diakritiky. K přejmenování budeme používat příkaz `mv` (__Move__), který slouží k přejmenování, případně přesunu souborů.

```bash
mv stm8-tools blikac
```

### Změna složky

Příkaz `cd` (__Change Directory__) změní aktuální složku, ve které se nacházíme za jinou. Tedy nám to umožní pohyb mezi složkami.

```bash
# přejdeme do složky cesta_ke_slozce
cd cesta_ke_slozce
# přejdeme o adresář víš
cd ..
# přejdeme do domovské složky
cd
```

### VS Code

Otevřeme editor VS Code v aktuální složce. __Tečka__ symbolizuje aktuální adresář, můžeme však zadat cestu k libovolné složce nebo souboru.

```bash
code .
```

### Kompilace projektu

Cílem kompilace je vytvořit binární soubor, obsahující náš program, který budeme moci nahrát do mikrokontroléru. Pokud bude kompilace úspěšná, vytvoří se nám složka `build` a vní soubor `firmware.elf`, který obsahuje náš program. Kompilaci provedeme příkazem `make`.

```bash
make
```

### Nahrání FW do MCU

Ze souboru `build/firmware.elf` zapíše obsah programové paměti do mikrokontroléru.

```bash
make flash
```

### Kompilace s nahráním FW do MCU v jednom

Tento příkaz se chová stejně jako posloupnost příkazů `make` následovaný `make flash`. Může nám tedy ušetřit psaní.

```bash
make build_and_flash
```

## Doporučený pracovní postup

1. Naklonovat šablonu projektu
2. Přejmenovat šablonu na jméno projektu
3. Přejít do složky s projektem
4. Otevřít projektovou složku ve VS Code
5. Ve VS Code si otevřu terminál (a pokud jsme na Win zkontroluji si shell)
6. Kontrola konfigurace našeptávání `.vscode/c_cpp_properties.json`
7. Můžu začít programovat

```bash
git clone https://gitlab.com/wykys/stm8-tools.git
mv stm8-tools jmeno_projektu
cd jmeno_projektu
code .
```

## Tipy k VS Code

VS Code je mocný textový editor, který se snadno přizpůsobí a rozšíří o další funkce díky rozšířením. Rozšíření se dají instalovat pomocí ikony bedny v postranním panelu.

### Integrovaný terminál

Přímo ve VS Code se dá vytvořit terminál a ten používat ke kompilaci a nahrávání FW. To může ušetřit čas ztrávený přepínáním mezi okny. Zároveň nám to umožní mít "všechno" v jedné aplikaci. Nový terminál spustíme pomocí klávesové zkratky `Ctrl` + `Shift` + `P`. To vyvolá příkazovou lištu, do které zadáme `Create New Terminal`.

⚠️ Pokud se s nějakého záhadného důvodu nacházíte na platformě MS Windows, je třeba přepnout shell terminálu na `Git Bash`. To lze provést pomocí malé rozevírací šiky v pravé části terminálu.

### Jak na našeptávání?

Doporučuji nainstalovat si rozšíření C/C++ od firmy Microsoft s podnadpisem _C/C++ IntelliSense, debugging, and code browsing._. Odkaz na [market place](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).

Toto rozšíření zpřístupní mocnou funkci našeptávání, číž můžeme rapidně zvýšit produktivitu naší práce i usnadnit hledání chyb.

Aby našeptávání fungovalo korektně, je třeba zkontrolovat soubor `.vscode/c_cpp_properties.json` a případně jej upravit dle používané platformy. Následují ukázky tohoto souboru:

<details>
<summary> Ukázková verze pro Linux </summary>

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
<summary> Ukázková verze pro MS Windows </summary>

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

## Instalace na MS Windows

Pro korektní funkci toolchainu je třeba do systému nainstalovat tyto programy:

* git
* bash
* make
* openocd
* sdcc
* vscode

Vřele doporučuji k instalaci využít správce balíčků https://chocolatey.org/, ten obsahuje vše co potřebujeme krom kompilátoru SDCC.

### Instalace Chocolatey

Doporučuji použít oficiální postup, ten v době psaní tohoto manuálu byl následující:

Spusťit Windows PowerShell jako administrátor systému a do příkazové řádky zadat tento příkaz, který nainstaluje Chocolatey:

```ps
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

Po  úspěšné instalaci bude v systému dostupný příkaz `choco`. Díky němu můžeme nainstalovat většinu potřebného SW.

### Instalace dostupného SW pomocí správce balíčků Chocolatey

Do administrátorského PowerShellu zadat tyto příkazy:

```ps
choco install git
choco install make
choco install openocd
choco install vscode
```

Balíček `git` obsahuje i `bash`, ten tedy není v samostatném balíčku.

### Instalace kompilátoru SDCC

Nakonec je třeba stáhnout a nainstalovat kompilátor `SDCC`, který sídlí na adrese http://sdcc.sourceforge.net/. Instalace probíhá prostřednictvím klasického klikacího formuláře.


