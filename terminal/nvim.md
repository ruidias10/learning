# [vim] Guia básico

[spacevim](https://spacevim.org/documentation/#core-pillars)

### Basico
```
:q!          # Força a saida
:q           # Sair
:w           # Gravar
:wq          # Grava e sair
```


### Navegação
```
h            # Esquerda
l            # Direita
j            # Baixo
k            # Cima

w            # Salta uma palavra para a frente
b            # Salta uma palavra para tras

shift + {    # Cima paragrafos
shift + }    # Baixo parafragos

o            # Salta para a linha de baixo e ativa modo INSERT
shift + o    # Salta para linha a cima e ativa o modo INSERT

a            # Salta para a proxima letra e ativa modo INSERT
shift + a    # Salta para o fim da linha e ativa modo INSERT

i            # Salta para a letra anterior e ativa modo INSERT
shift + i    # Salta para inicio da linha e ativa modo INSERT

s            # Apaga o caracter selecionado e entra no modo INSERT
shift + s    # Apaga a linha inteira e entra no modo INSERT
```


### Apagar
```
x            # Apaga caracter
u            # Volta (ctrl + z)
ctrl + r     # Refaz

d + w        # Apaga a palavra desde a letra selecionada ate ao fim
d + d        # Cut a linha selecionada

yy           # Copia linha selecionada
p            # Past

d + j        # Apaga a linha selecionada e a de baixo
d + k        # Apaga a linha selecionada e a de cima
```
