### Equipe (T02 Tarde)
Luiz Henrique Nunes Sena - 568584 </br>
Emilly Paiva Belo - 563639</br>
Emilly Wictoria Pinheiro Ferreira - 567253</br>

### Build
Este projeto utilizada a ferramenta Make e compila o programa através de um Makefile. Um executável "program.exe" será gerado na pasta "output".
Bibliotecas utilizadas:
- <stdio.h>
- <stdlib.h>
- <stdint.h>
- <stdbool.h>
- <string.h>
- <math.h>

### Arquivos de entrada
O programa recebe como argumento o caminho do arquivo de texto com as intruções que serão executadas.
- arquivos CRLF funcionam em Windows;
- arquivos LF funcionam em Linux;
- outras configurações têm comportamento desconhecido.

### Execução
Vale ressaltar que o programa busca o arquivo a partir do diretório atual no terminal. </br>Imagine um arquivo "file.txt" na raíz do projeto e os seguintes exemplos:
- /c:/usuario/projetos/simulador$ ./program.exe file.txt (não encontra o executável)
- /c:/usuario/projetos/simulador/output$ ./program.exe file.txt (não encontra o arquivo)
- /c:/usuario/projetos/simulador$ ./output/program.exe file.txt (funciona)
- /c:/usuario/projetos/simulador/output$ ./program.exe ../file.txt (funciona)
