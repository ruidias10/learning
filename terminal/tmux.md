# [tmux] Guia básico


### PREFIXO
```
ctrl+b
```

### Básico $
```
$ tmux                                 # Cria nova sessão
$ tmux new                             # Cria nova sessão
$ tmux new -s <xxx>                    # Cria nova sessão com o nome xxx
$ tmux new -s <xxx> -d                 # Cria nova sessão com o nome xxx SEM ENTRAR

$ exit                                 # Sai e destroi a sessão 

$ tmux ls                              # Listar sessões já abertas

$ tmux kill-session -t 0               # Destroi a sessao 0
$ tmux kill-ses -t 0                   # Destroi a sessao 0
$ tmux kill-session -t <xxx>           # Destroi a sessao xxx
$ tmux kill-ses -t <xxx>               # Destroi a sessao xxx

$ tmux kill-server                     # Destroi todas as sessoes

$ tmux a                               # Voltar para ultima sessao ATTACH
$ tmux a -t <xxx>                      # Voltar para sessao xxx  ATTACH
$ tmux a -t 0                          # Voltar para sessao 0 ATTACH
$ tmux attach -t teste                 # Voltar para sessao teste ATTACH
$ tmux attach -t 0                     # Voltar para sessao 0 ATTACH

$ tmux rename-session -t <xxx> <aaa>   # Altera nome da sessao de xxx para aaa
```

### Básico tmux
```
PREFIXO ?                              # Ajuda/help
PREFIXO + x                            # Sai e destroi a sessão 
PREFIXO + &                            # Sai e destroi a sessão 
ctrl+d                                 # Sai e destroi a sessão 

PREFIXO + d                            # Sai da sessão sem a destruir DETACHED

PREFIXO + c                            # Cria uma nova janela

PREFIXO + 0                            # Vai para a janela 0
PREFIXO + 1                            # Vai para a janela 1
PREFIXO + 2                            # Vai para a janela 2

PREFIXO + n                            # Vai janela seguinte 0->1->2->0->1->2
PREFIXO + p                            # Vai janela anterior 0<-2<-1<-0<-2<-1

PREFIXO + $                            # Vai alterar nome da sessão
PREFIXO + ,                            # Vai alterar nome da janela

PREFIXO + s                            # Navega entre varias sessoes e janelas
PREFIXO + w                            # Navega entre varias sessoes e janelas (lista aberto)
```

### Janelas
```
PREFIXO + %                            # Divide janela vertical PAINEL
PREFIXO + "                            # Divide janela horizontal PAINEL

PREFIXO + o                            # Navega entre paineis

PREFIXO + [dir]                        # Navega para a janela à direita PAINEL
PREFIXO + [esq]                        # Navega para a janela à esquerda PAINEL
PREFIXO + [cima]                       # Navega para a janela de cima PAINEL
PREFIXO + [baixo]                      # Navega para a janela de baixo PAINEL

PREFIXO + q                            # Mostra o nomero de cada PAINEL

PREFIXO + z                            # Entra e sai do modo zoom no PAINEL
```